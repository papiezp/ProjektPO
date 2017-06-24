#pragma once

#include "CzujnikRolet.h"
#include "CzujnikTemperatury.h"
#include "CzujnikWilgotnosci.h"

#include <vector>

class Dom {
    std::vector<Czujnik*> czujniki;

    void dodajCzujnik();
    void wypiszStanCzujnikow();
    void zasunRolety();
    void odsunRolety();
    void zapiszStanDoPliku() const ;
public:
    Dom();

    void steruj();

    ~Dom();
};
