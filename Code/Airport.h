//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRPORT_H
#define UNTITLED_AIRPORT_H
#include <iostream>
#include "Location.h"
#include <unordered_set>


class Airport {

    private:
        std::string code;
        std::string name;
        Location location;
        double latitude;
        double longitude;

    public:
        Airport(std::string code, std::string name, Location location, double latitude, double longitude);

        std::string getCode() const;
        std::string getName() const;
        Location getLocation() const;
        double getLatitude() const;
        double getLongitude() const;

        void setCode(std::string code);
        void setName(std::string);
        void setLocation(Location location);
        void setLatitude(double latitude);
        void setLongitude(double longitude);


};


struct HashFunction{

    int operator()(const Airport& otherAirport) const{
        std::string code = otherAirport.getCode();
        int res = 0;
        for(int i = 0; i < code.size(); i++){
            res = res * 13 + code[i];
        }
        return res;
    }

    bool operator()(const Airport &a1, const Airport &a2) const {
        return a1.getCode() == a2.getCode();
    }
};

typedef std::unordered_set<Airport, HashFunction, HashFunction> tabHAirport;

#endif //UNTITLED_AIRPORT_H
