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
Produto::~Produto(){
}
void Produto::addLista(){
    fstream produtos,temp;
    string nome, preco, linha;
    int estoque;
    bool encontrado = false;

    produtos.open("arquivos/produtos.txt",ios::in);
    temp.open("arquivos/temp.txt",ios::out|ios::app);

    //Procura o produto na lista

    while(getline(produtos,nome,';')){
        if (produtos.eof())
            break;
        getline(produtos,preco,';');
        getline(produtos,linha,';');
        estoque = stoi(linha);
        getline(produtos,linha);
            if (nome == this->nome){
                encontrado = true;
                string opc;
                temp << nome << ";" << this->preco << ";" << estoque+this->estoque << ";";
                cout << "Deseja alterar as categorias do produto existente?[S/N]" << endl << "Input -> ";
                cin >> opc;
                if(opc == "S" || opc == "s"){
                    for(unsigned int i=0;i<this->categorias.size();i++){
                        temp << this->categorias[i] << " ";
                    }
                }
                else 
                    temp << linha;
                temp << endl;
            }
            else 
                temp << nome << ";" << preco << ";" << estoque << ";" << linha << endl;
    }
    if (encontrado == false){
        temp << this->nome << ";" << this->preco << ";" << this->estoque << ";";
        for(unsigned int i=0;i<this->categorias.size();i++){
            temp << this->categorias[i] << " ";
        }
        temp << endl;
    }
    produtos.close();
    remove("arquivos/produtos.txt");
    temp.close();
    rename("arquivos/temp.txt","arquivos/produtos.txt");
    remove("arquivos/temp.txt");

}
void Produto::addCategoria(string categoria){
        this->categorias.push_back(categoria);
}