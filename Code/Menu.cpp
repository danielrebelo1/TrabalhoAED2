//
// Created by helde on 04/01/2023.
//

#include <map>
#include "Menu.h"
#include "Manager.h"

using namespace std;

int Menu::auxMenu(int maxOption, int minOption){
    int op;
    while (true) {
        std::cin >> op;
        if (std::cin.fail() || (op > maxOption || op < minOption)) {  // input is not an integer
            std::cout << "Please enter a valid integer: " ;
            std::cin.clear();  // clear the error flag
            std::cin.ignore(10000, '\n');  // ignore the invalid input
        } else {
            break;  // input is valid, break the loop
        }
    }
    return op;
}

int Menu::mainMenu() {
    cout << "\n";
    cout << "MAIN MENU\n\n";
    cout << "1.Route selection helper" << '\n' << "2.Airport information" << '\n' << "3.About us" << '\n' << "0.Quit" << "\n\n";
    cout << "Choose an option: ";
    return auxMenu(3, 0);
}

int Menu::AboutUsMenu(){
    cout << "\nHelp platform for the use of air transports created in favor of the Algorithms and Data Structure course\n" << endl;
    cout << "Meet the team: \n";
    cout << left << setw(16) <<  "Carlos Daniel Rebelo\t" << "Student number: " << setw(9) << "202108885\n";
    cout << left << setw(20)  << "Hélder Costa\t" << setw(20) << "Student number: " << setw(9) << "202108719\n";
    cout << left << setw(20)  << "Jaime Fonseca\t" << setw(20) << "Student number: " << setw(9) << "202108789\n";
    cout << "0.Return to main menu\n" << endl;
    return auxMenu(0,0);
}

int Menu::flightMenu(){
    string origAir, destAir;
    cout << endl << "ROUTE SELECTION HELP MENU\n" << endl;
    cout << "Flight origin: "; cin >> origAir; cout << endl;
    //find  airport ?
    cout << "Flight destination: "; cin >> destAir; cout << endl;
    //find airport ?
    //correr função e adicionar print se necessário
    cout << "1.New route\n" << "0.Return to main menu\n" << endl;
    cout << "Choose an option: ";
    return auxMenu(1,0);

}

int Menu::findChoiceMenu(){
    cout << endl << "How do you want to search for the airport:\n";
    cout << endl << "1.Search by airport code\n";
    cout << "2.Search by city\n";
    cout << "0.Return to main menu\n";
    cout <<endl << "Choose an option: ";
    return auxMenu(2,0);

}

string Menu::findByCode(Manager& manager){
    string airport;
    cout << endl << "Insert airport code: ";
    cin >> airport;
    while(!manager.checkAirportExists(airport)){
        cin >>airport;
    }
    cout << endl << "Airport found!\n" << manager.getAirports().at(airport).getCode() << " - " << manager.getAirports().at(airport).getName() << endl;

    return airport;
}

string Menu::findbyCity(Manager& manager){
    string city, r;
    int i = 1;
    cout << endl << "Insert the city: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, city);
    airportMap airports = manager.airports_filter_by_city(city);
    if (airports.empty()) { cout << "No airport in " << city << "." ;
        return "";}
    map<int,string> m;
    for (auto a: airports){
        cout << i << ". " << a.second.getCode() << " - " << a.second.getName() << endl;
        m.insert({i,a.second.getCode()});
        i++;
    }
    int input;
    while (true){
    cout << "Choose(0 to return to previous menu): ";
    try{
        cin >> input;
        if (input >= 0 && input <= m.size()) break;
    }
    catch (exception e){ cout << "Invalid input" << endl;}
    }

    switch (input) {
        case 0:
            return "";
        default:
            return m.at(input);
    }

}

int Menu::infoChoiceMenu(){
    cout << "\nChoose the desired information:";
    cout << endl << "1.Airport Report\n";
    cout<< "2.How many countries can you get to with X flights\n";
    cout<< "3.How many cities can you get to with X flights\n";
    cout<< "4.How many airports can you get to with X flights\n";
    cout<< "5.Choose new airport\n";
    cout<< "0.Return to main menu\n";
    cout << "Choose an option: ";
    return auxMenu(5,0);

}

int Menu::nrFlights(){
    int x;
    cout << endl << "Choose the number of desired flights: ";
    cin >> x;
    return x;
}

void Menu::menuController(Manager& manager) {
    int op;
    cout << endl << "Welcome to the support platform for the use of air transports!\n";
    do {
        int temp;
        op = mainMenu();
        do {
            int temp2;

            switch (op) {
                case 1:{
                    temp = flightMenu();
                    break;
                }

                case 2:{
                    int control;
                    string str, airport;
                    do{
                        control = 1;
                        do{
                            temp2 = findChoiceMenu();
                            switch(temp2){
                                case 1:{
                                    airport = findByCode(manager);
                                    temp2 = 0;
                                    break;
                                }

                                case 2:{
                                    airport = findbyCity(manager);
                                    // airport = findByCode(manager);
                                    if (airport == ""){ control = 0; temp = 0;}
                                    else {temp2 = 0;}
                                    break;
                                }

                                case 0:{
                                    control = 0;
                                    temp = 0;
                                    break;
                                }
                            }
                        } while (temp2 != 0);
                        if(control != 0)
                        while(control != 0) {
                            temp = infoChoiceMenu();
                            switch (temp) {
                                int x;
                                case 1: {
                                    manager.airportReport(airport);
                                    cout << endl << "Press Enter to continue.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 2: {
                                    x = nrFlights();
                                    cout << "\n***países atingiveis***\n";
                                    cout << endl << "Press Enter to continue.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 3: {
                                    x = nrFlights();
                                    cout << "\n***cidades atingiveis***";
                                    cout << endl << "Press Enter to continue.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 4: {
                                    x = nrFlights();
                                    cout << "\n***aeroportos atingiveis***";
                                    cout << endl << "Press Enter to continue.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 5: {
                                    control = 0;
                                    temp = 10;
                                    break;
                                }

                                case 0:{
                                    temp = 0;
                                    control = 0;
                                    break;
                                }
                            }
                        }
                    } while(temp != 0);
                    break;
                }

                case 3:{
                    temp = AboutUsMenu();
                    break;
                }

                case 0:{
                    temp = 0;
                    break;
                }

            }

        } while (temp != 0);

    } while (op != 0);
    cout << "\n";
    cout << "Thank you for using our platform! :) " << endl;

}

