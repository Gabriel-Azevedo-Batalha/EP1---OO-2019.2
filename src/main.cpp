#include "carrinho.hpp"
#include "Cliente.hpp"
#include "produto.hpp"
#include <stdlib.h>
using namespace std;

int main(){
    // Interface
    cout << endl << endl;

    fstream produtos;
    Cliente cliente;
    while(1){
        system("clear");
        cout << endl << "Modo de operação :" << endl;
        cout << "1-Modo Venda" << endl;
        cout << "2-Modo Recomendação" << endl;
        cout << "3-Modo Estoque" << endl;
        cout << "4-Encerrar Programa" << endl << endl;
        cout << "Input -> ";

        string mode;    
        cin >> mode;
        cout << endl;

        //Modo Venda
       
        if(mode == "1"){
            Carrinho carrinho;
            while(1){
                cout << endl << "---VENDA---" << endl << endl;
                //Implementar
                cout << "1-Adicionar produto ao carrinho" << endl;
                cout << "2-Remover produto do carrinho" << endl;
                cout << "3-Prosseguir para compra" << endl;
                cout << "4-Sair" << endl << endl;
                cout << "Input -> ";
                cin >> mode;
                cout << endl;
                if (mode == "1"){
                    string buscaNome;
                    cout << "Digite o nome do produto" << endl << endl;
                    cout << "Input -> ";
                    cin.ignore();
                    getline(cin,buscaNome);
                    cout << endl;
                    carrinho.addCarrinho(buscaNome);
                    cout << "Total : " << carrinho.getTotal() << endl;
                }
                else if (mode == "2" && (carrinho.getNomesProdutos()).size() > 0){
                    string buscaNome;
                    system("clear");
                    carrinho.mostrarCarrinho();
                    cout << endl << "Digite o nome do produto" << endl << endl;
                    cout << "Input -> ";
                    cin.ignore();
                    getline(cin,buscaNome);
                    cout << endl;
                    carrinho.remCarrinho(buscaNome);
                }
                else if (mode == "2")
                    cout << "ERRO : Não há produtos no carrinho" << endl << endl;
                else if (mode == "3"){
                    system("clear");
                    cliente.login();
                    if (cliente.getLogado() == true){
                        carrinho.mostrarCarrinho();
                    }
                    else 
                        cout << "ERRO : Não foi possível fazer o login" << endl << endl;
                }
                else if(mode == "4"){
                    break;
                }
                else{
                    cout << endl << "Entrada inválida" << endl << endl << endl;
                }
            }
        }

        //Modo Recomendação
        else if(mode == "2"){
            while(1){
                cout << "---RECOMENDAÇÃO---" << endl << endl;
                //Implementar
                break;
            }
        }

        //Modo Estoque
        else if(mode == "3"){
            while(1){
                cout << "---ESTOQUE---" << endl << endl;
                cout << "1-Adicionar produto" << endl;
                cout << "2-Alterar produto" << endl;
                cout << "3-Sair" << endl << endl;
                cout << "Input -> ";
                cin >> mode;
                if(mode == "1"){
                    Produto novoProduto;
                    while(1){
                        string categoria;
                        string opc;
                        cout << "Adicione uma categoria" << endl << "Input -> ";
                        cin.ignore();
                        getline(cin,categoria);
                        cout << endl;
                        novoProduto.addCategoria(categoria);
                        cout << "Deseja adicionar mais categorias ?[S/N]" << endl << "Input -> ";
                        cin >> opc;
                        if (!(opc == "S" || opc == "s")){
                            break;    
                        }
                    }
                    novoProduto.addLista();
                }    
                else if(mode == "2"){
                    //Implementar
                }
                else if(mode == "3"){
                    break;
                }
                else{
                    cout << endl << "Entrada inválida" << endl << endl << endl;
                }
            }
        }

        //Fechar Programa
        else if(mode == "4")
            break;
        
        //Entrada Inválida
        else
            cout << "Entrada inválida" << endl << endl;
    }
    return 0;
}
