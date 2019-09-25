#ifndef CLIENTE_HPP_
#define CLIENTE_HPP_
#include <iostream> 
#include <vector>
#include <string>
using namespace std;

class Cliente{
    private:
        string CPF;
        string senha;
        int socio;
        vector<string> categoriasRecentes;
    public:
        Cliente();
        //~Cliente();
        int getSocio();
        void setSocio();
        string getCPF();
        int login();
};

#endif