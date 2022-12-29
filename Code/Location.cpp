//
// Created by Jaime on 28/12/2022.
//

#include "Location.h"

Location::Location() {}

Location::Location(std::string name, std::string country){
    this->city = name;
    this->country = country;
}

Location::Location(std::string country) {this->city = ""; this->country = country;}

void Location::setName(std::string city) {
    this->city = city;
}

void Location::setCountry(std::string country){
    this->country = country;
}

std::string Location::getName() const{
    return this->city;
}

std::string Location::getCountry() const{
    return this->country;
}

bool Location::operator==(const Location &location) const{
    return city == location.getName();
}

