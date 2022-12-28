//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRLINE_H
#define UNTITLED_AIRLINE_H

#include <iostream>
#include <string>

class Airline {
private:
    std::string code;
    std::string name;
    std::string callSign;
    std::string country;
public:
    Airline(std::string code, std::string name, std::string callSign, std::string country);
    void setCode(std::string code) ;
    void setName( std::string name) ;
    void setCallSign(std::string callSign) ;
    void setCountry(std::string country) ;
    std::string getCode() const;
    std::string getName() const;
    std::string getCallSign() const;
    std::string getCountry() const;
    bool operator==(const Airline &airline)const;
};


#endif //UNTITLED_AIRLINE_H
