//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_CITY_H
#define UNTITLED_CITY_H

#include <iostream>
#include <string>

class City{

private:
    std::string name;
    std::string country;
public:
    City(std::string name,std::string country);
    void setName(std::string name) ;
    void setCountry(std::string country) ;
    std::string getName() const;
    std::string getCountry() const;
    bool operator==(const City &city) const;
};


#endif //UNTITLED_CITY_H


