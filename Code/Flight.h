//
// Created by Jaime on 28/12/2022.
//

#ifndef UNTITLED_FLIGHT_H
#define UNTITLED_FLIGHT_H
#include <string>



class Flight {

    private:
        std::string source;
        std::string dest;
        std::string airlineCode;
    public:
        Flight(void);
        Flight(std::string source, std::string dest, std::string airlineCode);
        std::string getSource() const;
        std::string getDest() const;
        std::string getAirlineCode() const;

};


#endif //UNTITLED_FLIGHT_H
