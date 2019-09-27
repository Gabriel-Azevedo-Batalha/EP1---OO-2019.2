#include "socio.hpp"

Socio::Socio(){
    this->totalReal = 0.0;
    this->desconto = 0.0;
}
Socio::~Socio(){
}
void Socio::reset(){
    this->totalReal = 0.0;
    this->desconto = 0.0;
}
float Socio::calcTotal(float total){
    this->desconto = total*1.15 - total;
    this->totalReal = total - this->desconto;
    return this->totalReal;
}
float Socio::getDesconto(){
    return this->desconto;
}
void Socio::pagar(bool taxa){
    if (taxa == true){
        cout << "Taxa de adesão : R$500" << endl;
        this->totalReal += 500.00;
    }
    cout << "Total Real : R$" << this->totalReal << endl;
    cout << "Desconto : R$" << this->desconto << endl;
    cout << "Compra efetuada" << endl;
}