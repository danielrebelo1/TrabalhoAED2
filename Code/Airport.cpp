//
// Created by Jaime on 28/12/2022.
//

#include "Airport.h"
using namespace std;

Airport::Airport(string code, string name, Location location, double latitude, double longitude){
    this->code = code;
    this->name = name;
    this->location = location;
    this->latitude = latitude;
    this->longitude = longitude;
}

std::string Airport::getCode() const{
    return code;
}

std::string Airport::getName() const{
    return name;
}
Location Airport::getLocation() const {
    return location;
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

void Airport::setLocation(Location location) {
    this->location = location;
}

void Airport::setLatitude(double latitude) {
    this->latitude =latitude;
}

void Airport::setLongitude(double longitude) {
    this->longitude = longitude;
}

