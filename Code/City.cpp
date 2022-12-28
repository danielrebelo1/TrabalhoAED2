//
// Created by Jaime on 28/12/2022.
//

#include "City.h"

City::City(std::string name,std::string country){
    this->name = name;
    this->country = country;
}

void City::setName(std::string name) {
    this->name = name;
}

void City::setCountry(std::string country){
    this->country = country;
}

std::string City::getName() const{
    return this->name;
}

std::string City::getCountry() const{
    return this->country;
}

bool City::operator==(const City &city) const{
    return name == city.getName();
}