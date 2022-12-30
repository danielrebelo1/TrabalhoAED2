//
// Created by Daniel Rebelo on 30/12/2022.
//

#include "AuxiliarFunctions.h"
#include <string>
#include <limits>

using namespace std;

string tolowerString(string s){
    string newstr;
    for (char &c : s){
        newstr.push_back(tolower(c));
    }
    return newstr;
}

string searchEngine(){
    string search;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin , search);
    tolowerString(search);
    return search;
}