#include "CzujnikTemperatury.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

CzujnikTemperatury::CzujnikTemperatury(const std::string& nazwa) : Czujnik(CZUJNIK_TEMPERATURY, nazwa) {

}

void CzujnikTemperatury::wypiszInformacje(std::ostream& out) {

    double liczba = (double)((rand() % 100) + 200)/10.0;
    ustawStan(liczba);

    out << "Czujnik temperatury: " << pobierzNazwe() << std::endl;
    out << "Aktualna temperatura w pomieszczeniu to: " << pobierzStan() << std::endl << std::endl;
}
