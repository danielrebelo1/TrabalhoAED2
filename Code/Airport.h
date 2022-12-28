//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_AIRPORT_H
#define UNTITLED_AIRPORT_H
#include <iostream>


class Airport {

    private:
        std::string code;
        std::string name;
        std::string city;
        std::string country;
        double latitude;
        double longitude;

    public:
        Airport(std::string code, std::string name, std::string city, std::string country, double latitude, double longitude);

        std::string getCode() const;
        std::string getName() const;
        std::string getCity() const;
        std::string getCountry() const;
        double getLatitude() const;
        double getLongitude() const;

        void setCode(std::string code);
        void setName(std::string);
        void setCity(std::string);
        void setCountry(std::string);
        void setLatitude(double latitude);
        void setLongitude(double longitude);

        bool operator==(const Airport &otherAirport) const;
        struct HashFunction{
            size_t operator()(const Airport& otherAirport) const{

            }
        };

};


#endif //UNTITLED_AIRPORT_H
