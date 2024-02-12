#include<iostream>
#include<string>

using namespace std;

class Usuario{
    private:
        string password;
        string mail;
        string username;
    public:
        Usuario(string, string, string);
        void LogIn();
        void LogOut();
};

class Vendedor : public Usuario{
    private: 
        int numWorker;
    public:
        Vendedor(string, string, string, int);
        void vender();
        void actualizarInv();
};

class Comprador : public Usuario{
    private: 
        int numCliente;
    public:
        Comprador(string, string, string, int);
        void comprar();
        void reclamar();
        void devolver();
};

Usuario::Usuario(string _password, string _mail, string _username){
    password = _password;
    mail = _mail;
    username = _username;
}

void Usuario::LogIn(){
    cout<<"Usted ha entrado correctamente."<<endl;
}

void Usuario::LogOut(){
    cout<<"Usted ha salido correctamente."<<endl;
}

Vendedor::Vendedor(string _password, string _mail, string _username, int _numWorker) : Usuario(_password, _mail, _username){
    numWorker = _numWorker;
}

void Vendedor::vender(){
    cout<<"Usted ha vendido correctamente."<<endl;
}

void Vendedor::actualizarInv(){
    cout<<"Usted ha actualizado el inventario correctamente."<<endl;
}

Comprador::Comprador(string _password, string _mail, string _username, int _numCliente) : Usuario(_password, _mail, _username){
    numCliente = _numCliente;
}

int main(){
    
    Vendedor vendedor1("abc", "abc@gmail.com", "Alexis");
    Comprador comprador1("abc", "abc@gmail.com", "Alexis");
}
