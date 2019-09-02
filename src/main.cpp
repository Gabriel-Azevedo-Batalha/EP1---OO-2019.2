#include <iostream>
#include <fstream>
#include <vector>
#include "Cliente.hpp"
#include <string>
using namespace std;

int main(){
    // Interface
    while(1){
        cout << endl << "Modo de operação :" << endl;
        cout << "1-Modo Venda" << endl;
        cout << "2-Modo Recomendação" << endl;
        cout << "3-Modo Estoque" << endl;
        cout << "4-Encerrar Programa" << endl << endl;
        cout << "Input : ";

        string mode;    
        cin >> mode;
        cout << endl;

        //Modo Venda
        if(mode == "1"){
            while(1){
                cout << endl << "VENDA" << endl << endl;
                //Implementar
               	
                //Testes com arquivos
                /*
		ofstream myfile;
                myfile.open ("example.txt");
                myfile << test;
                myfile.close();
                vector<int> test = getline(myfile,line);
                test.push_back(25);
		*/

                break;
            }
        }

        //Modo Recomendação
        else if(mode == "2"){
            while(1){
                cout << "RECOMENDAÇÃO" << endl << endl;
                //Implementar

                break;
            }
        }

        //Modo Estoque
        else if(mode == "3"){
            while(1){
                cout << "ESTOQUE" << endl << endl;
                //Implementar

                break;
            }
        }

        //Fechar Programa
        else if(mode == "4")
            break;
        
        //Entrada Inválida
        else
            cout << "Entrada inválida" << endl << endl;
    }
    return 0;
}
