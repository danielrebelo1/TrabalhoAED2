//
// Created by helde on 04/01/2023.
//

#include "Menu.h"
#include "Manager.h"

using namespace std;

int Menu::auxMenu(int maxOption, int minOption){
    int op;
    do{
        cin >> op;
        if( op > maxOption || op < minOption)
            cout << "\nNúmero inválido. Introduza um valor válido: ";
    } while(op > maxOption || op < minOption);
    return op;
}

int Menu::mainMenu() {
    cout << "\n";
    cout << "MENU PRINCIPAL\n\n";
    cout << "1.Consultar rota" << '\n' << "2.Consultar informações" << '\n' << "3.Sobre nós" << '\n' << "0.Sair" << "\n\n";
    cout << "Escolha opção: ";
    return auxMenu(7, 0);
}

int Menu::AboutUsMenu(){
    cout << "\nPlataforma de ajuda ao uso de transportes aéreos criada em prol da disciplina de Algoritmos e Estrutura de Dados\n" << endl;
    cout << "Meet the team: \n";
    cout << left << setw(16) <<  "Carlos Daniel Rebelo\t" << "Número estudante: " << setw(9) << "202108885\n";
    cout << left << setw(20)  << "Hélder Costa\t" << setw(20) << "Número estudante: " << setw(9) << "202108719\n";
    cout << left << setw(20)  << "Jaime Fonseca\t" << setw(20) << "Número estudante: " << setw(9) << "202108789\n";
    cout << "0.Voltar" << endl;
    return auxMenu(0,0);
}

int Menu::flightMenu(){
    string origAir, destAir;
    cout << endl << "MENU DE AJUDA PARA SELEÇÃO DE VOOS\n" << endl;
    cout << "Qual é o aeroporto de origem ? "; cin >> origAir; cout << endl;
    //find  airport ?
    cout << "Qual é o aeroporto de destino ? "; cin >> destAir; cout << endl;
    //find airport ?
    //correr função e adicionar print se necessário
    cout << "1.Novo trajeto\n" << "0.Voltar\n" << endl;
    cout << "Escolha uma opção: ";
    return auxMenu(1,0);

}

int Menu::findChoiceMenu(){
    cout << endl << "Escolha a forma como pretende procurar pelo aeroporto:\n";
    cout << endl << "1.Procurar por código de aeroporto\n";
    cout << "2.Procurar por cidade\n";
    cout << "0.Voltar";
    cout <<endl << "Escolha uma opção: ";
    return auxMenu(2,0);

}

string Menu::findByCode(){
    string airport;
    cout << endl << "Insira o código do aeroporto: ";
    cin >> airport;
    return airport;
}

string Menu::findbyCity(){
    string city, r;
    int i = 1;
    Manager m;
    airportMap airports;
    cout << "Insira a cidade pretendida:" << endl;
    cin >> city;
    airports = m.airports_filter_by_city(city);
    cout << airports.size();
    for (auto a: airports){
        //r += i + ". " + a.second.getCode() + " - " + a.second.getName();
        cout << a.second.getName() << endl;
    }
    //cout << endl << "***print dos aeroportos***\n";
    return r ;
}

int Menu::infoChoiceMenu(){
    cout << endl << "\nEscolha a informação que pretende:";
    cout << endl << "1.Quantos voos saem deste aeroporto\n";
    cout<< "2.Quantas companhias aéreas diferentes têm voos a sair deste aeroporto\n";
    cout<< "3.Quantos destinos diferentes com partida deste aeroporto\n";
    cout<< "4.Quantos países diferentes têm voos com este aeroporto como destino\n";
    cout<< "5.Quantos países são atingiveis usando X voos\n";
    cout<< "6.Quantas cidades são atingiveis usando X voos\n";
    cout<< "7.Quantos aeroportos são atingiveis usando X voos\n";
    cout<< "8.Escolher novo aeroporto\n";
    cout<< "0.Voltar ao menu principal\n";
    cout << "Escolha uma opção: ";
    return auxMenu(8,0);

}

int Menu::nrFlights(){
    int x;
    cout << endl << "Escolha o número de voos pretendido: ";
    cin >> x;
    return x;
}

void Menu::menuController() {
    int op;
    cout << endl << "Bem-vindo à plataforma de apoio ao uso de transportes aéreos!\n";
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
                    string airport;
                    do{
                        control = 1;
                        do{
                            temp2 = findChoiceMenu();
                            switch(temp2){
                                case 1:{
                                    airport = findByCode();
                                    temp2 = 0;
                                    break;
                                }

                                case 2:{
                                    airport = findbyCity();
                                    cout << airport;
                                    temp2 = 0;
                                    break;
                                }

                                case 0:{
                                    control = 0;
                                    temp = 0;
                                    break;
                                }
                            }
                        } while (temp2 != 0);
                        if(control != 0) //cout << endl << airport;
                        while(control != 0) {
                            temp = infoChoiceMenu();
                            switch (temp) {
                                int x;
                                case 1: {
                                    cout << endl << "***voos a sair deste aeroporto***";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 2: {
                                    cout << "\n***companhias aereas diferentes***";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 3: {
                                    cout << "\n***destinos diferentes***";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 4: {
                                    cout << "\n***países diferentes***";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 5: {
                                    x = nrFlights();
                                    cout << "\n***países atingiveis***\n";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 6: {
                                    x = nrFlights();
                                    cout << "\n***cidades atingiveis***";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 7: {
                                    x = nrFlights();
                                    cout << "\n***aeroportos atingiveis***";
                                    cout << endl << "Pressione Enter para continuar.\n";
                                    system("pause > nul");
                                    break;
                                }

                                case 8: {
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
    cout << "Obrigado por usar a nossa plataforma! :) " << endl;

}

