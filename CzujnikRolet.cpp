#include "CzujnikRolet.h"

#include <iostream>

CzujnikRolet::CzujnikRolet(const std::string& nazwa) : Czujnik(CZUJNIK_ROLET, nazwa) {

}

void CzujnikRolet::wypiszInformacje(std::ostream& out) {
    double aktualnyStan = pobierzStan();

    out << "Czujnik rolet: " << pobierzNazwe() << std::endl;
    if(aktualnyStan > 3.0) {
        out << "Rolety sa zasloniete.\n\n";
    } else {
        out << "Rolety sa odsloniete.\n\n";
    }
}
