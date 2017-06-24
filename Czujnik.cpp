#include "Czujnik.h"

Czujnik::Czujnik(TypCzujnika t, const std::string& nazwa) : typ(t), nazwa(nazwa) {

}

double Czujnik::pobierzStan() const {
    return stan;
}

void Czujnik::ustawStan(double wartosc) {
    stan = wartosc;
}

std::string Czujnik::pobierzNazwe() const {
    return nazwa;
}

void Czujnik::ustawNazwe(const std::string& n) {
    nazwa = n;
}

TypCzujnika Czujnik::pobierzTypCzujnika() const {
    return typ;
}
