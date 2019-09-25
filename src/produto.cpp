#include "produto.hpp"

Produto::Produto()
{
    cout << "Nome : ";
    cin.ignore();
    getline(cin,this->nome);
    cout << "Preço : ";
    cin >> this->preco;
    cout << "Estoque : ";
    cin >> this->estoque;
}
Produto::Produto(string nome, float preco, int estoque, vector<string> categorias){
    this->nome = nome;
    this->preco = preco;
    this->estoque = estoque;
    this->categorias = categorias;
}
void Produto::addLista(){
    ofstream produto;
    produto.open("produtos.txt",ios::app);
    produto << this->nome << ";" << this->preco << ";" << this->estoque << ";";
    for(unsigned int i=0;i<categorias.size();i++){
        produto << this->categorias[i] << " ";
    }
    produto << "\n";
    produto.close();
}
void Produto::addCategoria(string categoria){
        this->categorias.push_back(categoria);
}