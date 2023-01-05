//
// Created by Jaime on 30/12/2022.
//

#ifndef UNTITLED_COORDINATES_H
#define UNTITLED_COORDINATES_H


class Coordinates {
    private:
        double latitude;
        double longitude;
    public:
        Coordinates();
        Coordinates(double latitude, double longitude);
        double getLatitude();
        double getLongitude();
        void setLatitude(double latitude);
        void setLongitude(double longitude);


};


#endif //UNTITLED_COORDINATES_H
