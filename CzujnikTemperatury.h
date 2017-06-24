#pragma once

#include "Czujnik.h"

class CzujnikTemperatury : public Czujnik {
public:
    CzujnikTemperatury(const std::string& nazwa);
    void wypiszInformacje(std::ostream& out);
};
