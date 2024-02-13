#include<iostream>
#include<string>

using namespace std;

class Usuario{
	protected:
		string password;
		string mail;
		string username;
	public:
		Usuario(string, string, string);
		virtual void logIn();
		void logOut();
		string getPassword();
		string getMail();
};

class Trabajador : public Usuario{
	private:
		int numWorker;
	public:
		Trabajador(string, string, string, int);
		void logIn();
		void vender();
		void actualizarInv();
};

class Cliente : public Usuario{
	private:
		int numCustomer;
	public:
		Cliente(string, string, string, int);
		void logIn();
		void comprar();
		void devolver();
};

Usuario::Usuario(string _password, string _mail, string _username){
	password = _password;
	mail = _mail;
	username = _username;
}

void Usuario::logIn(){
	cout<<"\t"<<username<<" ha entrado correctamente."<<endl;
}

void Usuario::logOut(){
	cout<<"\t"<<username<<" ha salido correctamente."<<endl;
}

string Usuario::getPassword(){
	return password;
}

string Usuario::getMail(){
	return mail;
}

Trabajador::Trabajador(string _password, string _mail, string _username, int _numWorker) : Usuario(_password, _mail, _username){
	numWorker = _numWorker;
}

void Trabajador::logIn(){
	cout<<"\t"<<username<<" ha entrado correctamente como trabajador."<<endl;	
}

void Trabajador::vender(){
	cout<<"\t\t"<<username<<" ha vendido un producto."<<endl;
}

void Trabajador::actualizarInv(){
	cout<<"\t\t"<<username<< " ha actualizado el inventario."<<endl;
}

Cliente::Cliente(string _password, string _mail, string _username, int _numCustomer) : Usuario(_password, _mail, _username){
	numCustomer = _numCustomer;
}

void Cliente::logIn(){
	cout<<"\t"<<username<<" ha entrado correctamente como cliente."<<endl;	
}

void Cliente::comprar(){
	cout<<"\t\t"<<username<<" ha comprado un producto correctamente."<<endl;
}

void Cliente::devolver(){
	cout<<"\t\t"<<username<<" ha devuelto un producto correctamente."<<endl;
}

int main(){
	int opc1;
	string pass, correo;
	bool acceder = false;
	
	/*
		Primer dato - Contraseña
		Segundo dato - Mail
		Tercer dato - Nombre
	*/
	
	Usuario usuario1("abc", "abc@gmail.com", "Alexis");
	Trabajador trabajador1("opq", "opq@gmail.com", "Alex", 1);
	Cliente cliente1("xyz", "xyz@gmail.com", "Alexa", 1);
	
	cout<<"\n\tDigite como desea entrar: "<<endl;
	cout<<"\t1. Usuario."<<endl;
	cout<<"\t2. Trabajador."<<endl;
	cout<<"\t3. Cliente."<<endl;
	cout<<"\tOpcion: "; cin>>opc1;
	
	cout<<"\n";
	
	switch(opc1){
		case 1:
			{
				while(!acceder){
					cout<<"\tDigite su contrasenia: "; cin>>pass;
					cout<<"\tDigite su correo: "; cin>>correo;
					
					if(pass == usuario1.getPassword() && correo == usuario1.getMail()) acceder = true;
					else{
						
						cout<<"\n\tINCORRECTO."<<endl<<endl;
						
					}
				}
				
				cout<<"\n\n";
				
				usuario1.logIn();
				
				cout<<"\n\t\tEl usuario no puede realizar acciones. Saliendo..."<<endl;
				cout<<"\n";
				
				usuario1.logOut();
			}
			
			break;
			
			case 2:
			{
				while(!acceder){
					cout<<"\tDigite su contrasenia: "; cin>>pass;
					cout<<"\tDigite su correo: "; cin>>correo;
					
					if(pass == trabajador1.getPassword() && correo == trabajador1.getMail()) acceder = true;
					else{
						
						cout<<"\n\tINCORRECTO."<<endl<<endl;
						
					}
				}
				
				cout<<"\n\n";
				
				trabajador1.logIn();
				
				cout<<"\n\t\tEl usuario esta trabajando"<<endl<<endl;
				
				trabajador1.vender();
				cout<<"\n";
				
				trabajador1.actualizarInv();
				cout<<"\n";
				
				cout<<"\t\tEl usuario termina de trabajar"<<endl<<endl;
				
				trabajador1.logOut();
			}
			
			break;
			
			case 3:
			{
				while(!acceder){
					cout<<"\tDigite su contrasenia: "; cin>>pass;
					cout<<"\tDigite su correo: "; cin>>correo;
					
					if(pass == cliente1.getPassword() && correo == cliente1.getMail()) acceder = true;
					else{
						
						cout<<"\n\tINCORRECTO."<<endl<<endl;
						
					}
				}
				
				cout<<"\n\n";
				
				cliente1.logIn();
				
				cout<<"\n\t\tEl usuario esta yendo de compras"<<endl<<endl;
				
				cliente1.comprar();
				cout<<"\n";
				
				cliente1.devolver();
				cout<<"\n";
				
				cout<<"\t\tEl usuario ha terminado de comprar"<<endl<<endl;
				
				cliente1.logOut();
			}
	}
	
	return 0;
}
