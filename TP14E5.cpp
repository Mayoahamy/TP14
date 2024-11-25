#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class calculator{
	public:
		void suma(int n1, int n2){
			cout<<"El resultado es: "<<n1+n2<<endl;
		}
		void suma(float f1, float f2){
			cout<<"El resultado es: "<<f1+f2<<endl;
		}
		void resta(int n1, int n2){
			cout<<"El resultado es: "<<n1-n2<<endl;
		}
		void resta(float f1, float f2){
			cout<<"El resultado es: "<<f1-f2<<endl;
		}
		void mult(int n1, int n2){
			cout<<"El resultado es: "<<n1*n2<<endl;
		}
		void mult(float f1, float f2){
			cout<<"El resultado es: "<<f1*f2<<endl;
		}
		void div(int n1, int n2){
			if(n2 == 0){
				cout<<"No se puede dividr por cero"<<endl;
			}else{
				cout<<"El resultado es: "<<n1/n2<<endl;
			}
		}
		void div(float f1, float f2){
			if(f2 == 0){
				cout<<"No se puede dividr por cero"<<endl;
			}else{
				cout<<"El resultado es: "<<f1/f2<<endl;
			}
		}		
};
int main(){
	calculator calculator1;
	int n1 = 0,n2 = 0,op;
	float f1 = 0,f2 = 0,mode;
	while(true){
		system("cls");
		cout<<"Ingresar modo de operacion: \nEnteros: 1\nDecimales: 2\nSalir: cualquier otro numero"<<endl;
		cin>>mode;
		if(mode != 1 && mode != 2){
			return 0;
		}
		cout<<"Ingresar valores a operar\nValor 1: ";
		if(mode == 1){
			cin>>n1;
		}else{
			cin>>f1;
		}
		cout<<"Valor 2: ";
		if(mode == 1){
			cin>>n2;
		}else{
			cin>>f2;
		}
		cout<<"Ingresar operacion: \nSuma: 1\nResta: 2\nMultiplicacion: 3\nDivision: 4\n";
		cin>>op;
		switch(op){
			case 1:
				if(mode == 1){
					calculator1.suma(n1,n2);
				}else{
					calculator1.suma(f1,f2);
				}
				break;
			case 2:
				if(mode == 1){
					calculator1.resta(n1,n2);
				}else{
					calculator1.resta(f1,f2);
				}
				break;
			case 3:
				if(mode == 1){
					calculator1.mult(n1,n2);
				}else{
					calculator1.mult(f1,f2);
				}
				break;
			case 4:
				if(mode == 1){
					calculator1.div(n1,n2);
				}else{
					calculator1.div(f1,f2);
				}
				break;
			default:
				cout<<"ERROR";
				return 1;
				break;
		}
		system("pause");
	}
}
