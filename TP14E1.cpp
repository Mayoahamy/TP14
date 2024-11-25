#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
class Libros{
	private:
		string nombre;
		int cant_pag;
	public:
		void nombre_set(string a){
			nombre = a;
		}
		void cant_pag_set(int a){
			cant_pag = a;
		}
		string nombre_get(){
			return nombre;
		}
		int cant_pag_get(){
			return cant_pag;
		}
};
class Biblioteca{
	private:
		Libros libro;
	public:
		Biblioteca(Libros libro) : libro(libro) {};
		int cant_pag_get(){
			return libro.cant_pag_get();
		}
		string nombre_get(){
			return libro.nombre_get();
		}
};
int main(){
	vector<Biblioteca> biblioteca1;
	int n_libros, cant_pag, choice,sumatoria;
	string buscar;
	Libros libro;
	string nombre;
	while(true){
		system("cls");
		fflush(stdin);
		cout<<"Buscar libro: 1 \nAgregar libro: 2 \nBorrar libro: 3 \nCalcular cantidad de paginas totales: 4 \nIngresar cualquier otro numero para salir \n";
		cin>>choice;
		if(!scanf("%d", &n_libros)){
			cout<<"ERROR";
			return 0;
		}
		switch(choice){
			case 1:
				cout<<"Ingresar nombre a buscar: ";
				cin>>buscar;
				for(int i=0;i<biblioteca1.size();i++){
					if(buscar==biblioteca1[i].nombre_get()){
						string hola;
						i=biblioteca1.size();
						cout<<"Encontrado"<<endl;
						system("pause");
					}
					else if(i==biblioteca1.size()-1){
						cout<<"No se encontro"<<endl;
						system("pause");
					}
				}
				break;
			case 2:
				cout<<"Ingrese el numero de libros a agregar: ";
				cin>>n_libros;
				if(scanf("%d", &n_libros)){	
				}else{
					cout<<"ERROR";
					return 0;
				}
													
				for(int i=0;i<n_libros;i++){
					cout<<"Ingresar nombre: ";
					cin>>nombre;
					cout<<"Ingresar cantidad de paginas: ";
					cin>>cant_pag;
					libro.nombre_set(nombre);
					libro.cant_pag_set(cant_pag);
					biblioteca1.push_back(Biblioteca(libro));
				}
				break;
			case 3:
				cout<<"Ingresar nombre a buscar: ";
				cin>>buscar;
				for(int i=0;i<biblioteca1.size();i++){
					if(buscar==biblioteca1[i].nombre_get()){
						biblioteca1.erase(biblioteca1.begin() + i);
						cout<<"Borrado";
						system("pause");
					}
					else if(i==biblioteca1.size()-1){
						cout<<"No se encontro"<<endl;
						system("pause");
					}
				}
				break;
			case 4:
				for(int i=0;i<biblioteca1.size();i++){
					sumatoria+=biblioteca1[i].cant_pag_get();
				}
				cout<<"Los libros suman un total de "<<sumatoria<<" paginas."<<endl;
				break;		
			default:return 0;
		}
	}
}
