#include "Cliente.hpp"


Cliente::Cliente(){
    this->logado = false;
}
bool Cliente::getSocio(){
    return socio;
}
void Cliente::setSocio(){
    socio = 1;
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
        cout << "(Login)" << endl << endl;
        cout << "CPF :" << endl << endl;
        cout << "Input -> ";
        cin >> buscaCPF;
        cout << endl;
        clientes.open("clientes.txt",ios::in);
        while(getline(clientes,CPF,';')){
            if (clientes.eof())
                break;
            getline(clientes,senha,';');
            getline(clientes,linha,';');
            //cout << "Lendo : " << CPF << " " << senha << " " << linha << " ";
            this->socio = stoi(linha);
            getline(clientes,linha);
            //cout << linha << endl;
            if (CPF == buscaCPF){
                encontrado = true;
                break;
            }
        }
        if (encontrado == false){
            cout << "CPF não cadastrado. Deseja cadastrar ?[S/N]" << endl << endl;
            cout << "Input -> ";
            cin >> modo;
            cout << endl;
            if (modo == "s" || modo == "S"){
                this->cadastrar(buscaCPF);
                this->logado = true;
            }
        }
        else if (encontrado == true){
            while(1){
                cout << "Senha :" << endl << endl;
                cout << "Input -> ";
                cin >> senhaBusca;
                if(senhaBusca == senha){
                    std::istringstream iss(linha);
                    for(; iss >> linha; )
                    this->categoriasRecentes.push_back(linha);
                    this->logado = true;
                    break;
                }
                else{
                    cout << "Senha incorreta. Tentar novamente ?" << endl << endl;
                    cout << "1- Digitar senha novamente" << endl;
                    cout << "2- Digitar CPF novamente" << endl;
                    cout << "3- Sair" << endl;
                    cout << "Input -> ";
                    cin >> modo;
                    cout << endl;
                    if (modo == "1")
                        continue;
                    else if (modo == "2"){
                        tentativa = true;
                        break;
                    }
                    else if (modo == "3")
                        break;
                    else
                        cout << "Entrada inválida" << endl << endl;
                }
            }
        }
    }
}
void Cliente::cadastrar(string CPF){
    fstream clientes;
    clientes.open("clientes.txt",ios::out|ios::app);
    cout << "Novo Cadastro" << endl << endl;
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
            cout << endl << "CPF Inválido" << endl << endl;
            cout << "CPF : " << CPF << endl;
            cout << "Input -> ";
            cin >> CPF;
            cout << endl;

        }
    }
    cout << "CPF : " << CPF << endl;
    cout << "Senha :" << endl << endl;
    cout << "Input -> ";
    cin >> this->senha;
    cout << endl;
    clientes << CPF << ";" << this->senha << ";0;Nenhuma" << endl;
    clientes.close();
}
