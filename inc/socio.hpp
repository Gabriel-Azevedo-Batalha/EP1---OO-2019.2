#ifndef SOCIO_HPP_
#define SOCIO_HPP_
#include "Cliente.hpp"
class Socio : public Cliente{
    private:
        float totalReal;
        float desconto;
    public:
        Socio();
        ~Socio();
        void reset();
        float calcTotal(float total);
        float getDesconto();
        void pagar(bool taxa);
};
#endif