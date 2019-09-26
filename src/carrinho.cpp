#include "carrinho.hpp"

Carrinho::Carrinho(){
    this->total = 0;
}
void Carrinho::addCarrinho(string buscaNome){
    fstream produtos, temp;
    string nome, linha;
    float preco;
    int estoque;
    vector<string> categorias;
    bool encontrado = false, falta = false;
    produtos.open("produtos.txt",ios::in);
    temp.open("temp.txt",ios::out|ios::app);
    //Busca dos produtos
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
        
        //Trocar
        
        if (nome == buscaNome && falta == false){
            //cout << nome << " " << preco << " " << estoque;
            this->total += preco;
            this->nomesProdutos.push_back(nome);
            for(unsigned int i=0;i<categorias.size();i++){
                this->categorias.push_back(categorias[i]);
            }
            /*for(unsigned int i=0;i<this->categorias.size();i++)
                cout << " " << this->categorias[i];
            cout << endl;
            */
            encontrado = true;
            categorias.clear();
        }
        else if (nome == buscaNome && falta == true)
            cout << "ERRO : Sem o item no estoque" << endl;
    }
    if (encontrado == false)
        cout << endl << "ERRO : Não foi possível encontrar o produto" << endl;
    produtos.close();
    remove("produtos.txt");
    temp.close();
    rename("temp.txt","produtos.txt");
    remove("temp.txt");

}
float Carrinho::getTotal(){
    return this->total;
}
void Carrinho::mostrarCarrinho(){
    cout << "Itens no carrinho:" << endl;
    for(unsigned int i=0;i<this->nomesProdutos.size();i++)
        cout << " -" << this->nomesProdutos[i] << endl;
    cout << "Total : " << this->total << endl;
}
void Carrinho::remCarrinho(string buscaNome){
    bool encontrado = false;
    for(unsigned int i=0;i<this->nomesProdutos.size();i++){
        if(this->nomesProdutos[i] == buscaNome){
            this->nomesProdutos.erase(this->nomesProdutos.begin()+i);
            fstream produtos, temp;
            string nome, linha;
            float preco;
            int estoque;
            vector<string> categorias;
            produtos.open("produtos.txt",ios::in);
            temp.open("temp.txt",ios::out|ios::app);
            encontrado = true;
            //Busca dos produtos
            while(getline(produtos,nome,';')){
                if (produtos.eof())
                    break;
                getline(produtos,linha,';');
                preco = stof(linha);
                getline(produtos,linha,';');
                estoque = stoi(linha);
                getline(produtos,linha);
                if (nome == buscaNome){
                    estoque += 1;
                    this->total -= preco;
                }
                temp << nome << ";" << preco <<";" << estoque << ";" << linha << endl;
            }
            produtos.close();
            remove("produtos.txt");
            temp.close();
            rename("temp.txt","produtos.txt");
            remove("temp.txt");
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