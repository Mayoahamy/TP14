/*Crea una clase base Figura con atributos como color y posición. Deriva clases como Circulo, 
Rectangulo y Triangulo, cada una con sus propios atributos y métodos para calcular el área y el 
perímetro. Sobrecarga el método calcularArea() para que pueda calcular el área de diferentes tipos de figuras.*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include<time.h>
using namespace std;
class Figura{
	protected:
		string color;
	public:
		
		void getColor(){
			cout<<"El color de la figura es: "<<color;
		}
};
class Circ : public Figura{
	private:
		const double PI = M_PI;
		double r;
	public:
		Circ(double radio, string col){
			r = radio;
			color = col;
		}
		double calcPerim(){
			return 2*r*PI;
		}
		double calcArea(){
			return PI*pow(r,2);
		}
		void getData(){
			cout<<"\nRadio: "<<r<<endl;
		}
};
class Rect : public Figura{
	private:
		double h,b;
	public:
		Rect(double H, double B, string COLOR){
			h = H;
			b = B;
			color = COLOR;
		}
		double calcPerim(){
			return 2*(h+b);
		}
		double calcArea(){
			return h*b;
		}
		void getData(){
			cout<<endl<<"Altura: "<<h;
			cout<<endl<<"Ancho: "<<b;
		}
};
class Tri : public Figura{
	private:
		double h,b,l1,l2,l3;
	public:
		Tri(double H, double B, double L1, double L2, double L3, string COLOR){
			h = H;
			b = B;
			l1 = L1;
			l2 = L2;
			l3 = L3;
			color = COLOR;
		}
		double calcPerim(){
			return l1+l2+l3;
		}
		double calcArea(){
			return (h*b)/2;
		}
		void getData(){
			cout<<endl<<"Altura: "<<h<<endl;
			cout<<"Ancho: "<<b<<endl;
			cout<<"Lado 1: "<<l1<<endl<<"Lado 2: "<<l2<<endl<<"Lado 3: "<<l3<<endl;
		}
};
int main(){
	int opcion;
	string color;
	double h,b,r,l1,l2,l3,area,perim;
	cout<<"Figura a calcular: \nCirculo: 1\nRectangulo: 2\nTriangulo: 3\n";
	cin>>opcion;
	switch(opcion){
		case 1:{
			cout<<"Ingresar radio: ";
			cin>>r;
			cout<<"Ingresar color: ";
			cin>>color;
			Circ circ1(r,color);
			cout<<"Que deseas hacer?\nCalcular Area: 1\nCalcular Perimetro: 2\nMostrar datos: 3\n";
			cin>>opcion;
			switch(opcion){
				case 1:
					area = circ1.calcArea();
					cout<<"El area del circulo es: "<<area<<endl;
					break;
				case 2:
					perim = circ1.calcPerim();
					cout<<"El perimetro del circulo es: "<<perim<<endl;
					break;
				case 3:
					circ1.getColor();
					circ1.getData();
					break;
				default:
					cout<<"ERROR";
					return 1;
			}
			break;
		}
		case 2:{
			cout<<"Ingresar altura: ";
			cin>>h;
			cout<<"Ingresar ancho: ";
			cin>>b;
			cout<<"Ingresar color: ";
			cin>>color;
			Rect rect1(h,b,color);
			cout<<"Que deseas hacer?\nCalcular Area: 1\nCalcular Perimetro: 2\nMostrar datos: 3\n";
			cin>>opcion;
			switch(opcion){
				case 1:
					area = rect1.calcArea();
					cout<<"El area del rectangulo es: "<<area<<endl;
					break;
				case 2:
					perim = rect1.calcPerim();
					cout<<"El perimetro del rectangulo es: "<<perim<<endl;
					break;
				case 3:
					rect1.getColor();
					rect1.getData();
					break;
				default:
					cout<<"ERROR";
					break;
			}
			break;
		}
		case 3:{
			cout<<"Ingresar altura: ";
			cin>>h;
			cout<<"Ingresar ancho: ";
			cin>>b;
			cout<<"Ingresar longitud lado 1: ";
			cin>>l1;
			cout<<"Ingresar longitud lado 2: ";
			cin>>l2;
			cout<<"Ingresar longitud lado 3: ";
			cin>>l3;
			cout<<"Ingresar color: ";
			cin>>color;
			Tri tri1(h,b,l1,l2,l3,color);
			cout<<"Que deseas hacer?\nCalcular Area: 1\nCalcular Perimetro: 2\nMostrar datos: 3\n";
			cin>>opcion;
			switch(opcion){
				case 1:
					area = tri1.calcArea();
					cout<<"El area del triangulo es: "<<area<<endl;
					break;
				case 2:
					perim = tri1.calcPerim();
					cout<<"El perimetro del trianuglo es: "<<perim<<endl;
					break;
				case 3:
					tri1.getColor();
					tri1.getData();
					break;
				default:
					cout<<"ERROR";
					return 1;
			}
			break;
		}
	}
}


