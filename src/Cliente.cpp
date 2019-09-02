#include "Cliente.hpp"


Cliente::Cliente(){
    cout << "Novo cadastro" << endl << endl;
    cout << "CPF :";
    cin >> CPF;
    cout << endl;
    cout << "Senha :";
    cin >> CPF;
    cout << endl;
    socio = 0;
}
int Cliente::getSocio(){
    return socio;
}
void Cliente::setSocio(){
    socio = 1;
}
int Cliente::login(){
    //Implementar
    return 1;
}
