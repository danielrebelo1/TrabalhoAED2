//
// Created by Jaime on 28/12/2022.
//

#include "FileReader.h"
using namespace std;



FileReader::FileReader(istream &airportFile) {

    airportFile.ignore(numeric_limits<streamsize>::max(), '\n');
    while(airportFile.good()){

        string line, data;
        vector<string> lineVector;
        getline(airportFile, line);

        if(line.empty() || line == "\r") break;
        stringstream ss(line);

        while(getline(ss, data, ',')) lineVector.push_back(data);

        string code = lineVector[0],
                name = lineVector[1],
                city = lineVector[2],
                country = lineVector[3];

        double latitude = stod(lineVector[4]),
                longitude = stod(lineVector[5]);

        Airport airport = Airport(code, name, city, country, latitude, longitude);



    }


}

