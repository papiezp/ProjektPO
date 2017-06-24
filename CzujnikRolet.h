#pragma once
#include "Czujnik.h"

class CzujnikRolet : public Czujnik {
public:
    CzujnikRolet(const std::string& nazwa);
    void wypiszInformacje(std::ostream& out);
};

