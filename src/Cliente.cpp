#include "Cliente.hpp"


Cliente::Cliente(){
    cout << "Novo cadastro" << endl << endl;
    cout << "CPF :" << endl << endl;
    while(1){
        cout << "Input -> ";
        cin >> CPF;
        int teste = 0; 
        if (CPF.length() == 11){
            for(int i=0;i<11;i++){
                if (!(CPF[i] >= '0' && CPF[i] <= '9'))
                    teste = 1;
            }
        }
        else {
            teste = 1;
        }
        if (teste == 0){
            break;
        }
        else {
            cout << endl << "Entrada Inválida" << endl << endl;
        }
    }
    cout << endl;
    cout << "Senha :" << endl << endl;
    cout << "Input : ";
    cin >> senha;
    cout << endl;
    socio = 0;
}
int Cliente::getSocio(){
    return socio;
}
void Cliente::setSocio(){
    socio = 1;
}
string Cliente::getCPF(){
    return CPF;
}
int Cliente::login(){
    //Implementar
    return 1;
}
