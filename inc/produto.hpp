#ifndef PRODUTO_HPP_
#define PRODUTO_HPP_
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Produto{
    private:
        string nome;
        float preco;
        int estoque;
        vector<string> categorias;
    public:
        Produto();
        Produto(string nome, float preco, int estoque, vector<string> categorias);
        ~Produto();
        float getPreco();
        void setPreco(float preco);
        vector<string> getCategorias();
        void addCategoria(string categoria);
        void removeCategoria(string categoria);
        int getEstoque();
        void addEstoque(int qtd);
        void removeEstoque(int qtd);
        void addLista();
};
#endif