#include "carrinho.hpp"
#include "Cliente.hpp"
#include "produto.hpp"
#include "socio.hpp"
#include <stdlib.h>
using namespace std;

int main(){
    // Interface
    fstream produtos;
    Cliente cliente;
    system("clear");
    while(1){
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
                cout << "1-Adicionar produto ao carrinho" << endl;
                cout << "2-Remover produto do carrinho" << endl;
                cout << "3-Prosseguir para compra" << endl;
                cout << "4-Sair" << endl << endl;
                cout << "Input -> ";
                cin >> mode;
                cout << endl;

                //Adicionar produto

                if (mode == "1"){
                    string buscaNome;
                    cout << "Digite o nome do produto" << endl << endl;
                    cout << "Input -> ";
                    cin.ignore();
                    getline(cin,buscaNome);
                    cout << endl;
                    carrinho.addCarrinho(buscaNome);
                    cout << "Total : R$" << carrinho.getTotal() << endl;
                }

                //Remover produto

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

                //Remover produto com o carrinho vazio

                else if (mode == "2")
                    cout << "ERRO : Não há produtos no carrinho" << endl << endl;

                //Prosseguir para a compra

                else if (mode == "3" && (carrinho.getNomesProdutos()).size() > 0){
                    system("clear");
                    string opc;
                    cliente.login();

                    //Login efetuado com sucesso

                    if (cliente.getLogado() == true){

                        //Cliente não sócio

                        if(cliente.getSocio() == false){
                            cout << "Cliente não sócio. Deseja se tornar (R$500)?[S/N]" << endl << endl << "Input -> ";
                            cin >> opc;
                            cout << endl;

                            //Cliente não deseja tornar-se sócio

                            if (!(opc == "S" || opc == "s")){
                                carrinho.mostrarCarrinho();
                                cliente.setCategorias(carrinho.getCategorias());
                                cliente.pagar(carrinho.getTotal());
                            }

                            //Cliente deseja tornar-se sócio

                            else{
                                carrinho.mostrarCarrinho();
                                cliente.tornarSocio(cliente.getCPF());
                                cliente.setCategorias(carrinho.getCategorias());
                                Socio socio;
                                socio.calcTotal(carrinho.getTotal());
                                socio.pagar(true);
                                socio.reset();
                            }
                            
                        }

                        //Cliente sócio

                        else{
                            carrinho.mostrarCarrinho();
                            cliente.setCategorias(carrinho.getCategorias());
                            Socio socio;
                            socio.calcTotal(carrinho.getTotal());
                            socio.pagar(false);
                            socio.reset();
                        }

                    }

                    //Login não efetuado com sucesso

                    else 
                        cout << "ERRO : Não foi possível fazer o login" << endl << endl;
                    cliente.reset();
                    carrinho.reset();
                    break;
                }  

                //Prosseguir para a compra com o carrinho vazio

                else if (mode == "3")
                    cout << "ERRO : Não há produtos no carrinho" << endl << endl;

                //Sair do modo venda com itens no carrinho

                else if(mode == "4" && (carrinho.getNomesProdutos()).size() > 0){
                    string opc;
                    cout << "Deseja mesmo sair ? O carrinho sera resetado![S/N]" << endl << endl << "Input -> ";
                    cin >> opc;
                    cout << endl;

                    //Não sair

                    if (!(opc == "S" || opc == "s"))
                        continue;

                    //Sair mesmo assim

                    else{
                        carrinho.reset(carrinho.getNomesProdutos());
                        system("clear");
                        break;
                    }
                }

                //Sair do modo venda
                
                else if (mode == "4"){
                    carrinho.reset(carrinho.getNomesProdutos());
                    system("clear");
                    break;
                }

                //Entrada inválida

                else{
                    cout << endl << "ERRO : Entrada inválida" << endl << endl << endl;
                }
            }
        }

        //Modo Recomendação

        else if(mode == "2"){
            while(1){
                cout << "---RECOMENDAÇÃO---" << endl << endl;
                Cliente cliente;
                cliente.login();

                //Login efetuado com sucesso e cliente comprou alguma coisa

                if (cliente.getLogado() == true && cliente.getCategorias()[0] != "Nenhuma"){
                    cliente.recomendar();
                }

                //Login não efetuado com sucesso 

                else if (cliente.getLogado() == false)
                    cout << "ERRO : Não foi possível fazer o login" << endl << endl;

                //Cliente não comprou nada

                else
                    cout << "ERRO : Cliente não tem histórico de compras" << endl << endl;


                break;
            }
        }

        //Modo Estoque

        else if(mode == "3"){
            while(1){
                system("clear");
                cout << "---ESTOQUE---" << endl << endl;
                cout << "1-Adicionar produto" << endl;
                cout << "2-Sair" << endl << endl;
                cout << "Input -> ";
                cin >> mode;

                //Adicionar produto

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

                        //Não adicionar mais categorias

                        if (!(opc == "S" || opc == "s")){
                            break;    
                        }
                    }
                    novoProduto.addLista();
                
                //Sair do modo estoque

                }    
                else if(mode == "2"){
                    system("clear");
                    break;
                }

                //Entrada inválida

                else{
                    cout << endl << "ERRO : Entrada inválida" << endl << endl << endl;
                }
            }
        }

        //Fechar Programa

        else if(mode == "4")
            break;
        
        //Entrada Inválida

        else
            cout << "ERRO : Entrada inválida" << endl << endl;
    }
    return 0;
}
