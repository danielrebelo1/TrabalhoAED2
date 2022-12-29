//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_LOCATION_H
#define UNTITLED_LOCATION_H

#include <iostream>
#include <string>

class Location{

private:
    std::string city;
    std::string country;
public:
    Location(void);
    Location(std::string city, std::string country);
    Location(std::string country);
    void setName(std::string name) ;
    void setCountry(std::string country) ;
    std::string getName() const;
    std::string getCountry() const;
    bool operator==(const Location &city) const;
};


#endif //UNTITLED_LOCATION_H


