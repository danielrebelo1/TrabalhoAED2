//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRLINE_H
#define UNTITLED_AIRLINE_H

#include <iostream>
#include "Location.h"
#include <unordered_set>


class Airline {
private:
    std::string code;
    std::string name;
    std::string callSign;
    Location location;
public:
    Airline(std::string code, std::string name, std::string callSign, Location location);
    void setCode(std::string code) ;
    void setName( std::string name) ;
    void setCallSign(std::string callSign) ;
    void setCountry(std::string country) ;
    void setLocation(Location location);

    Location getLocation() const;
    std::string getCode() const;
    std::string getName() const;
    std::string getCallSign() const;
    std::string getCountry() const;
};

struct HashF {
    int operator()(const Airline &otherAirline) const {
        std::string code = otherAirline.getCode();
        int res = 0;
        for (int i = 0; i < code.size(); i++) {
            res = res * 23 + code[i];
        }
        return res;
    }

    bool operator()(const Airline &a1, const Airline &a2) const {
        return a1.getCode() == a2.getCode();
    }
};

typedef std::unordered_set<Airline, HashF, HashF> tabHAirline;



#endif //UNTITLED_AIRLINE_H
