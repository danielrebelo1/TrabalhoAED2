//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRPORT_H
#define UNTITLED_AIRPORT_H
#include <iostream>
#include "Location.h"
#include "Coordinates.h"
#include <unordered_set>
#include <unordered_map>


class Airport {

    private:
        std::string code;
        std::string name;
        Location location;
        Coordinates coordinates;

    public:
        Airport(std::string code, std::string name, Location location, Coordinates coordinates);

        std::string getCode() const;
        std::string getName() const;
        Location getLocation() const;
        Coordinates getCoordinates() const;

        void setCode(std::string code);
        void setName(std::string);
        void setLocation(Location location);
        void setCoordinates(Coordinates coordinates);


};


struct HashFunction{

    int operator()(const std::string &code) const{
        int res = 0;
        for(int i = 0; i < code.size(); i++){
            res = res * 13 + code[i];
        }
        return res;
    }

    bool operator()(const std::string &code1 , const std::string &code2) const {
        return code1 == code2;
    }
};

typedef std::unordered_map<std::string,Airport,HashFunction> airportMap;

#endif //UNTITLED_AIRPORT_H
