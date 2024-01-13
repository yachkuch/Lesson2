 #pragma once 
#include <vector>
#include "ipAdress.h"

inline std::vector<ipAdress>  filter_values_by_bytse(const std::vector<ipAdress>& Alladress, int numberBytesUouneed, int first=0, int second=0, int third=0, int fouth=0)
{
    std::vector<ipAdress> print;
    if (numberBytesUouneed == 1) {
        for (ipAdress ad : Alladress) {
            if (ad.get_first() == first) {
                print.push_back(ad);
            }
        }
    }
    else if (numberBytesUouneed == 2) {
        if (first < 0) {
            for (ipAdress ad : Alladress) {
                if (ad.get_second() == second) {
                    print.push_back(ad);
                }
            }
        }
        else {
            for (ipAdress ad : Alladress) {
                if (ad.get_second() == second && ad.get_first() == first) {
                    print.push_back(ad);
                }
            }

        }

    }
    else if (numberBytesUouneed == 3) {
        for (ipAdress ad : Alladress) {
            if (ad.get_second() == second || ad.get_first() == first || ad.get_third() == third || ad.get_fouth() == fouth) {
                print.push_back(ad);
            }
        }

    }
    return print;
}

inline int ass(){
    return 0;
}
