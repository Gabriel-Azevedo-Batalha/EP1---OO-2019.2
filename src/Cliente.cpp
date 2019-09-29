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
        else{
            temp << linha << ";";
        getline(clientes,linha);
        temp << linha << endl;
        }
    }
    clientes.close();
    remove("clientes.txt");
    temp.close();
    rename("temp.txt","clientes.txt");
    remove("temp.txt");
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
            cout << "CPF não cadastrado. Deseja cadastrar ?[S/N]" << endl << endl;
            cout << "Input -> ";
            cin >> modo;
            cout << endl;
            if (modo == "s" || modo == "S"){
                this->cadastrar(buscaCPF);
                this->logado = true;
                this->CPF = buscaCPF;
                this->socio = 0;
            }
        }
        else if (encontrado == true){
            while(1){
                cout << "Senha :" << endl << endl;
                cout << "Input -> ";
                cin >> senhaBusca;
                cout << endl << endl << endl;
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
    cout << endl << endl << endl;
    clientes << CPF << ";" << this->senha << ";0;Nenhuma" << endl;
    this->categoriasRecentes.push_back("Nenhuma");
    clientes.close();
}
void Cliente::pagar(float total){
    cout << "Total Real : R$" << total << endl;
    cout << "Compra efetuada" << endl;
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
        if(CPF == this->CPF && linha == "Nenhuma"){
            for(unsigned int i=0;i<categorias.size();i++)
                temp << categorias[i] << " ";
            temp << endl;
        }
        else if (CPF == this->CPF){
            temp << linha;
            for(unsigned int i=0;i<categorias.size();i++)
                temp << categorias[i] << " ";
            temp << endl;
        }

        else
            temp << linha << endl;
    }
    clientes.close();
    remove("clientes.txt");
    temp.close();
    rename("temp.txt","clientes.txt");
    remove("temp.txt");
}
vector<string> Cliente::getCategorias(){
    return this->categoriasRecentes;
}
void Cliente::recomendar(){
    //
    //Declaração de variáveis
    //
    fstream produtos, ordenacao;
    vector<int> recomendacao, numeracao;
    vector<string>temp;
    string nome, preco, estoque, linha, nomeOrd, linhaOrd;
    int count = 1, n;
    //
    //Criando arquivo de numeração dos produtos
    //
    produtos.open("produtos.txt",ios::in);
    ordenacao.open("ordenacao.txt",ios::out|ios::app);
    while(getline(produtos,nome,';')){
        if (produtos.eof())
            break;
        ordenacao << nome << ";" << count << endl;
        getline(produtos,preco,';');
        getline(produtos,estoque,';');
        getline(produtos,linha);
        count += 1;
        recomendacao.push_back(0);
        numeracao.push_back(count-1);
    }
    produtos.close();
    ordenacao.close();
    //
    //Adicionando Graus de recomendação
    //
    for(unsigned int i=0;i<this->categoriasRecentes.size();i++){
        produtos.open("produtos.txt",ios::in);
        while(getline(produtos,nome,';')){
            if (produtos.eof())
                break;
            getline(produtos,preco,';');
            getline(produtos,estoque,';');
            getline(produtos,linha);
            std::istringstream iss(linha);
            for(; iss >> linha; )
                temp.push_back(linha);
            for(unsigned int j=0;j<temp.size();j++){
                if (temp[j] == categoriasRecentes[i]){
                    ordenacao.open("ordenacao.txt",ios::in);
                    while(getline(ordenacao,nomeOrd,';')){
                        if(ordenacao.eof())
                            break;
                        getline(ordenacao,linhaOrd);
                        if(nomeOrd == nome){
                            n = stoi(linhaOrd);
                            break;
                        }
                    }
                    ordenacao.close();
                    recomendacao[n-1] += 1;
                }
            }
            temp.clear();
            
        }
        produtos.close();
        
    }
    //
    //Ordenador
    //
    for (unsigned int i=0;i<recomendacao.size();i++){
        for(unsigned int j=0;j<i;j++){
            string nomeI, nomeJ;
            ordenacao.open("ordenacao.txt",ios::in);
                    while(getline(ordenacao,nomeOrd,';')){
                        if(ordenacao.eof())
                            break;
                        getline(ordenacao,linhaOrd);
                        n = stoi(linhaOrd);
                        if(n == numeracao[i]){
                            nomeI = nomeOrd;
                        }
                        else if(n == numeracao[j]){
                            nomeJ = nomeOrd;
                        }
                    }
                    ordenacao.close();
            if ((recomendacao[i] > recomendacao[j]) || (recomendacao[i] == recomendacao[j] && nomeI.compare(nomeJ) < 0)){
                int pos = recomendacao[i];
                recomendacao[i] = recomendacao[j];
                recomendacao[j] = pos;
                pos = numeracao[i];
                numeracao[i] = numeracao[j];
                numeracao[j] = pos; 
            }
        } 
    }
    //
    //Recomendações
    //
        cout << "Recomendações : " <<endl;
    for (unsigned int i=0;i<recomendacao.size();i++){
        ordenacao.open("ordenacao.txt",ios::in);
            while(getline(ordenacao,nomeOrd,';')){
                if(ordenacao.eof())
                    break;
                getline(ordenacao,linhaOrd);
                n = stoi(linhaOrd);
                if(n == numeracao[i] && recomendacao[i] > 0){
                    cout << " -" << i+1 << ")" << nomeOrd << endl;
                    break;
                }
            }
            ordenacao.close();
        if (i == 9)
            break;
    }
    remove("ordenacao.txt");
}

