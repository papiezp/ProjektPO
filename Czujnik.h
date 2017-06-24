#pragma once
#include <string>

enum TypCzujnika {
    CZUJNIK_ROLET,
    CZUJNIK_TEMPERATURY,
    CZUJNIK_WILGOTNOSCI
};

class Czujnik {
protected:
    double stan = 0.0;
    std::string nazwa;
    TypCzujnika typ;
public:
    Czujnik(TypCzujnika t, const std::string& nazwa); // stala referncja, zawartosc nie zostanie skopiowana ale nie bedziemy mogli jej zmodyfikowac
    double pobierzStan() const;
    void ustawStan(double wartosc);

    std::string pobierzNazwe() const;
    void ustawNazwe(const std::string& nazwa);

    TypCzujnika pobierzTypCzujnika() const;
    virtual void wypiszInformacje(std::ostream& out) = 0;
};
