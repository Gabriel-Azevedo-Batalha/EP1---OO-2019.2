#include "carrinho.hpp"

Carrinho::Carrinho(){
    this->total = 0.0;
}
Carrinho::~Carrinho(){
}
void Carrinho::reset(){
    this->total = 0.0;
    this->nomesProdutos.clear();
    this->categorias.clear();
}
void Carrinho::reset(vector<string> nomesProdutos){
    this->categorias.clear();
    for(unsigned int i=0;i<nomesProdutos.size();i++){
        this->remCarrinho(nomesProdutos[i]);
    }
    this->total = 0.0;
}
void Carrinho::addCarrinho(string buscaNome){
    fstream produtos, temp;
    string nome, linha;
    float preco;
    int estoque;
    vector<string> categorias;
    bool encontrado = false, falta = false;
    produtos.open("arquivos/produtos.txt",ios::in);
    temp.open("arquivos/temp.txt",ios::out|ios::app);
    while(getline(produtos,nome,';')){
        if (produtos.eof())
            break;
        getline(produtos,linha,';');
        preco = stof(linha);
        getline(produtos,linha,';');
        estoque = stoi(linha);
        getline(produtos,linha);
        if (nome == buscaNome){
            if (estoque > 0)
                estoque -= 1;
            else{
                falta = true;
                encontrado = true;
            }
        }
        temp << nome << ";" << preco <<";" << estoque << ";" << linha << endl;

         if (nome == buscaNome && falta == false){
            std::istringstream iss(linha);
            for(; iss >> linha; )
            categorias.push_back(linha);
        }
        if (nome == buscaNome && falta == false){
            this->total += preco;
            this->nomesProdutos.push_back(nome);
            for(unsigned int i=0;i<categorias.size();i++){
                this->categorias.push_back(categorias[i]);
            }
            encontrado = true;
            categorias.clear();
        }
        else if (nome == buscaNome && falta == true)
            cout << "ERRO : Sem o item no estoque" << endl;
    }
    if (encontrado == false)
        cout << endl << "ERRO : Não foi possível encontrar o produto" << endl;
    produtos.close();
    remove("arquivos/produtos.txt");
    temp.close();
    rename("arquivos/temp.txt","arquivos/produtos.txt");
    remove("arquivos/temp.txt");

}
float Carrinho::getTotal(){
    return this->total;
}
void Carrinho::mostrarCarrinho(){
    fstream produtos;
    string nome, linha;
    float preco;
    cout << "Itens no carrinho:" << endl;
    for(unsigned int i=0;i<this->nomesProdutos.size();i++){
        cout << " -" << this->nomesProdutos[i];
        produtos.open("arquivos/produtos.txt",ios::in);
        while(getline(produtos,nome,';')){
            if (produtos.eof())
                break;
            getline(produtos,linha,';');
            preco = stof(linha);
            if (nomesProdutos[i] == nome)
                cout << " R$" << preco << endl;
            getline(produtos,linha);
        }
        produtos.close();
    }
    cout << "Total : R$" << this->total << endl;
}
void Carrinho::remCarrinho(string buscaNome){
    bool encontrado = false;
    for(unsigned int i=0;i<this->nomesProdutos.size();i++){
        if(this->nomesProdutos[i] == buscaNome){
            this->nomesProdutos.erase(this->nomesProdutos.begin()+i);
            fstream produtos, temp;
            string nome, linha, linha2;
            float preco;
            int estoque;
            vector<string> categorias;
            produtos.open("arquivos/produtos.txt",ios::in);
            temp.open("arquivos/temp.txt",ios::out|ios::app);
            encontrado = true;
            while(getline(produtos,nome,';')){
                if (produtos.eof())
                    break;
                getline(produtos,linha,';');
                preco = stof(linha);
                getline(produtos,linha,';');
                estoque = stoi(linha);
                getline(produtos,linha);
                linha2 = linha;
                if (nome == buscaNome){
                    estoque += 1;
                    this->total -= preco;
                    std::istringstream iss(linha);
                    for(; iss >> linha; ){
                        this->remCategorias(linha);
                    }
                }
                temp << nome << ";" << preco <<";" << estoque << ";" << linha2 << endl;
            }
            produtos.close();
            remove("arquivos/produtos.txt");
            temp.close();
            rename("arquivos/temp.txt","arquivos/produtos.txt");
            remove("arquivos/temp.txt");
        }
    }
    if (encontrado == false)
        cout << endl << "ERRO : Não foi possível encontrar o produto" << endl;
}
vector<string> Carrinho::getNomesProdutos(){
    return this->nomesProdutos;
}
vector<string> Carrinho::getCategorias(){
    return this->categorias;
}
void Carrinho::remCategorias(string categoriasBusca){
    for(unsigned int i=0;i<this->categorias.size();i++){
        if (this->categorias[i] == categoriasBusca){
            this->categorias.erase(this->categorias.begin()+i);
            break;
        }
    }
}