#include "Cliente.hpp"


Cliente::Cliente(){
    this->logado = false;
}
Cliente::~Cliente(){
}
void Cliente::reset(){
    this->logado = false;
    this->categoriasRecentes.clear();
}
bool Cliente::getSocio(){
    return socio;
}
void Cliente::tornarSocio(string buscaCPF){
    fstream clientes,temp;
    string CPF, linha;
    clientes.open("clientes.txt",ios::in);
    temp.open("temp.txt",ios::out|ios::app);
    while(getline(clientes,CPF,';')){
        if (clientes.eof())
                break;
        temp << CPF << ";";
        getline(clientes,linha,';');
        temp << linha << ";";
        getline(clientes,linha,';');
        if(CPF == buscaCPF){
            temp << "1;";
        }
        else
            temp << linha << ";";
        getline(clientes,linha);
        temp << linha << endl;
    }
    clientes.close();
    std::remove("clientes.txt");
    temp.close();
    std::rename("temp.txt","clientes.txt");
    std::remove("temp.txt");
}
string Cliente::getCPF(){
    return CPF;
}
bool Cliente::getLogado(){
    return this->logado;
}
void Cliente::login(){
    string buscaCPF, CPF, senha, senhaBusca,linha, modo;
    bool encontrado= false, tentativa = true;
    fstream clientes;
    while (tentativa == true){
        tentativa = false;
        std::cout << "(Login)" << endl << endl;
        std::cout << "CPF :" << endl << endl;
        std::cout << "Input -> ";
        std::cin >> buscaCPF;
        std::cout << endl;
        clientes.open("clientes.txt",ios::in);
        while(getline(clientes,CPF,';')){
            if (clientes.eof())
                break;
            getline(clientes,senha,';');
            getline(clientes,linha,';');
            this->socio = stoi(linha);
            getline(clientes,linha);
            if (CPF == buscaCPF){
                encontrado = true;
                this->CPF = CPF;
                break;
            }
        }
        clientes.close();
        if (encontrado == false){
            std::cout << "CPF não cadastrado. Deseja cadastrar ?[S/N]" << endl << endl;
            std::cout << "Input -> ";
            std::cin >> modo;
            std::cout << endl;
            if (modo == "s" || modo == "S"){
                this->cadastrar(buscaCPF);
                this->logado = true;
                this->CPF = buscaCPF;
                this->socio = 0;
            }
        }
        else if (encontrado == true){
            while(1){
                std::cout << "Senha :" << endl << endl;
                std::cout << "Input -> ";
                std::cin >> senhaBusca;
                std::cout << endl << endl << endl;
                if(senhaBusca == senha){
                    std::istringstream iss(linha);
                    for(; iss >> linha; )
                    this->categoriasRecentes.push_back(linha);
                    this->logado = true;
                    break;
                }
                else{
                    std::cout << "Senha incorreta. Tentar novamente ?" << endl << endl;
                    std::cout << "1- Digitar senha novamente" << endl;
                    std::cout << "2- Digitar CPF novamente" << endl;
                    std::cout << "3- Sair" << endl;
                    std::cout << "Input -> ";
                    std::cin >> modo;
                    std::cout << endl;
                    if (modo == "1")
                        continue;
                    else if (modo == "2"){
                        tentativa = true;
                        break;
                    }
                    else if (modo == "3")
                        break;
                    else
                        std::cout << "Entrada inválida" << endl << endl;
                }
            }
        }
    }
}
void Cliente::cadastrar(string CPF){
    fstream clientes;
    clientes.open("clientes.txt",ios::out|ios::app);
    std::cout << "Novo Cadastro" << endl << endl;
    while(1){
        int teste = 0; 
        if (CPF.length() == 11){
            for(int i=0;i<11;i++){
                if (CPF[i] < '0' || CPF[i] > '9')
                    teste = 1;
            }
        }
        else {
            teste = 1;
        }
        if (teste == 0){
            break;
        }
        else {
            std::cout << endl << "CPF Inválido" << endl << endl;
            std::cout << "CPF : " << CPF << endl;
            std::cout << "Input -> ";
            std::cin >> CPF;
            std::cout << endl;

        }
    }
    std::cout << "CPF : " << CPF << endl;
    std::cout << "Senha :" << endl << endl;
    std::cout << "Input -> ";
    std::cin >> this->senha;
    std::cout << endl << endl << endl;
    clientes << CPF << ";" << this->senha << ";0;Nenhuma" << endl;
    clientes.close();
}
void Cliente::pagar(float total){
    std::cout << "Total Real : R$" << total << endl;
    std::cout << "Compra efetuada" << endl;
}
void Cliente::setCategorias(vector<string> categorias){
    fstream clientes,temp;
    string CPF, linha;
    clientes.open("clientes.txt",ios::in);
    temp.open("temp.txt",ios::out|ios::app);
    while(getline(clientes,CPF,';')){
        if (clientes.eof())
                break;
        temp << CPF << ";";
        getline(clientes,linha,';');
        temp << linha << ";";
        getline(clientes,linha,';');
        temp << linha << ";";
        getline(clientes,linha);
        if(CPF == this->CPF){
            for(unsigned int i=0;i<categorias.size();i++)
                temp << categorias[i] << " ";
            temp << endl;
        }
        else
            temp << linha << endl;
    }
    clientes.close();
    std::remove("clientes.txt");
    temp.close();
    std::rename("temp.txt","clientes.txt");
    std::remove("temp.txt");
}

