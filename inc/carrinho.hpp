#ifndef CARRINHO_HPP_
#define CARRINHO_HPP_
#include <sstream>
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
using namespace std;

    class Carrinho{
        private:
            float total;
            vector<string> nomesProdutos, categorias;
        public:
            Carrinho();
            ~Carrinho();
            void addCarrinho(string buscaNome);
            void remCarrinho(string buscaNome);
            void mostrarCarrinho();
            float getTotal(); 
            void reset();
            vector<string> getNomesProdutos();
            vector<string> getCategorias();
    };
#endif
