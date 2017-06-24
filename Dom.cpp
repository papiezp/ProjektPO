#include "Dom.h"

#include <cstdlib>
#include <sstream>
#include <ctime>

#include <fstream>

Dom::Dom() {
    srand(time(0));
}

void Dom::dodajCzujnik() {
    std::string nazwa;
    std::string typ;

    std::cin.ignore(1000000, '\n'); // usuniecie entera z bufora
    std::cout << "Podaj nazwe czujnika: ";
    std::getline(std::cin, nazwa);

    std::cout << "Podaj typ czujnika [temperatura/rolety/wilgotnosc]: ";
    std::cin >> typ;

    Czujnik* tymczasowy;

    if(typ == "temperatura") {
        tymczasowy = new CzujnikTemperatury(nazwa);
    } else if(typ == "rolety") {
        tymczasowy = new CzujnikRolet(nazwa);
    } else {
        tymczasowy = new CzujnikWilgotnosci(nazwa);
    }

    czujniki.push_back(tymczasowy);
}

void Dom::wypiszStanCzujnikow() {
    for(Czujnik* czujnik : czujniki) {
        czujnik->wypiszInformacje(std::cout);
    }
}

void Dom::zasunRolety() {
    for(Czujnik* czujnik : czujniki) {
        if(czujnik->pobierzTypCzujnika() == CZUJNIK_ROLET) {
            czujnik->ustawStan(4.0);
        }
    }
}

void Dom::odsunRolety() {
    for(Czujnik* czujnik : czujniki) {
        if(czujnik->pobierzTypCzujnika() == CZUJNIK_ROLET) {
            czujnik->ustawStan(1.0);
        }
    }
}

void Dom::zapiszStanDoPliku() const {
    int t = time(0);

    std::stringstream ss;   // strumien string
    ss << t;                // wrzucenie do strumienia liczby

    std::string nazwaPliku = ss.str() + ".txt"; // str() zwraca zawartosc strumienia w postaci string

    std::ofstream out(nazwaPliku);

    for(Czujnik* czujnik : czujniki) {
        czujnik->wypiszInformacje(out);
    }

    out.close();
}
void Dom::steruj() {
    int wybor = 0;
    do {
        std::cout << "1) Dodaj nowy czujnik\n2) Wypisz stan czujnikow\n3) Zasun rolety\n4) Odslon rolety\n5) Zapisz raport do pliku\n6) Zamknij program\n";
        std::cin >> wybor;

        switch(wybor) {
        case 1:
            dodajCzujnik();
            break;
        case 2:
            wypiszStanCzujnikow();
            break;
        case 3:
            zasunRolety();
            break;
        case 4:
            odsunRolety();
            break;
        case 5:
            zapiszStanDoPliku();
            break;
        case 6:
            std::cout << "Zegnaj.\n";
            break;
        default:
            std::cout << "Nie ma takiej opcji w menu.\n";
        }

    } while(wybor != 6);
}

Dom::~Dom() {
    for(Czujnik* czujnik : czujniki) {
        delete czujnik;
    }
}

