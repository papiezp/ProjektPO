#pragma once
#include <iostream>
#include "Czujnik.h"

class CzujnikWilgotnosci : public Czujnik {
public:
    CzujnikWilgotnosci(const std::string& nazwa);
    void wypiszInformacje(std::ostream& out);
};
