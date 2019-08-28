#include <iostream> 
#include <string>
using namespace std;

class Cliente{
    private:
        string nome;
        string senha;
        int socio;
    public:
        Cliente();
        ~Cliente();
        int getSocio();
        void setSocio();
        int login();
}