//
// Created by Jaime on 28/12/2022.
//

#include "Airport.h"
using namespace std;

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude){
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

std::string Airport::getCode() const{
    return code;
}

std::string Airport::getName() const{
    return name;
}

std::string Airport::getCity() const{
    return city;
}

std::string Airport::getCountry() const{
    return country;
}

double Airport::getLatitude() const{
    return latitude;
}

double Airport::getLongitude() const{
    return longitude;
}

void Airport::setCode(string code){
    this->code = code;
}

void Airport::setName(string name) {
    this->name = name;
}

void Airport::setCity(string city) {
    this->city = city;
}

void Airport::setCountry(string country) {
    this->country = country;
}

void Airport::setLatitude(double latitude) {
    this->latitude =latitude;
}

void Airport::setLongitude(double longitude) {
    this->longitude = longitude;
}

