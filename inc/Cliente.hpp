#ifndef CLIENTE_HPP_
#define CLIENTE_HPP_
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Cliente{
    private:
        string CPF;
        string senha;
        vector<string> categoriasRecentes;
        bool logado;
        int socio;
    public:
        Cliente();
        ~Cliente();
        bool getSocio();
        void tornarSocio(string buscaCPF);
        string getCPF();
        bool getLogado();
        void login();
        void cadastrar(string CPF);
        void pagar(float total);
        vector<string> getCategorias();
        void setCategorias(vector<string> categorias);
        void reset();
        void recomendar();
};

#endif