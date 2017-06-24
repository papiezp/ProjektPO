#include "CzujnikWilgotnosci.h"
#include <cstdlib>

CzujnikWilgotnosci::CzujnikWilgotnosci(const std::string& nazwa) : Czujnik(CZUJNIK_WILGOTNOSCI, nazwa) {

}

void CzujnikWilgotnosci::wypiszInformacje(std::ostream& out) {
    double wartosc = (double)(rand() % 1000)/10.0;

    ustawStan(wartosc);

    out << "Czujnik wilgotnosci powietrza: " << pobierzNazwe() << std::endl;
    out << "Wilgotnosc powietrza wynosi: " << pobierzStan() << "%\n\n";

}
