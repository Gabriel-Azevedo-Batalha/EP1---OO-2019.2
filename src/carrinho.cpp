#include "carrinho.hpp"

Carrinho::Carrinho(){
    this->total = 0;
}
void Carrinho::addCarrinho(string buscaNome){
    fstream produtos;
    string nome ,linha;
    float preco;
    int estoque;
    vector<string> categorias;
    bool encontrado = false;
    produtos.open("produtos.txt",ios::in);
    //Busca dos produtos
    while(getline(produtos,nome,';')){
        getline(produtos,linha,';');
        if (nome == buscaNome)
            preco = stof(linha);
        getline(produtos,linha,';');
        if (nome == buscaNome)
            estoque = stoi(linha);
        getline(produtos,linha);
        if (nome == buscaNome){
            std::istringstream iss(linha);
            for(; iss >> linha; )
            categorias.push_back(linha);
        }
        if (nome == buscaNome){
            cout << nome << " " << preco << " " << estoque << " " << categorias[0] << " " << categorias[1] << endl;
            this->total += preco;
            this->nomesProdutos.push_back(nome);
            for(unsigned int i=0;i<categorias.size();i++)
                this->categorias.push_back(categorias[i]);
            encontrado = true;
            categorias.clear();
            break;
        }
    }
    if (encontrado == false)
        cout << endl << "Não foi possível encontrar o produto" << endl;
    produtos.close();

}
float Carrinho::getTotal(){
    return this->total;
}