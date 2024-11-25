/* Crea una clase Empresa que tenga una colección de objetos Empleado. 
 Cada Empleado tiene un nombre, salario y departamento. Implementa métodos 
 para calcular la nómina total, encontrar al empleado con mayor salario y 
 listar a los empleados de un departamento específico.*/
#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
#include<windows.h>
using namespace std;
class Empleados{
	private:
		string name;
		string departamento;
		int salario;
	public:
		void setName(string a){
			name = a;
		}
		void setDepartamento(string a){
			departamento = a;
		}
		void setSalario(int a){
			salario = a;
		}	
		string getName(){
			return name;
		}
		string getDepartamento(){
			return departamento;
		}
		int getSalario(){
			return salario;
		}
};
class Empresa{
	private:
		Empleados empleado;
	public:
		Empresa(Empleados empleado) : empleado(empleado) {};
		string getDepartamento() {
			return empleado.getDepartamento();
		}
		int getSalario(){
			return empleado.getSalario();
		}
		string getNombre(){
			return empleado.getName();
		}
};
int main(){
	vector<Empresa> Empresa1;
	Empleados empleado1;
	int cant,salario,opc,top_salary_employee=0;
	string nombre,departamento,depart_comparate;
	cout<<"Ingresar cantidad de empleados: ";
	cin>>cant;
	for(int i=0;i<cant;i++){
		cout<<"Nombre: ";
		cin>>nombre;
		cout<<"Salario: ";
		cin>>salario;
		cout<<"Departamento: ";
		cin>>departamento;
		empleado1.setName(nombre);
		empleado1.setDepartamento(departamento);
		empleado1.setSalario(salario);
		Empresa1.push_back(Empresa(empleado1));
	}
	while(true){
		system("cls");
		cout<<"\nIngresar opcion:\n1: Nomina de empleados total\n2: Empleado con mayor salario\n3: Ver empleados de un departamento\nOtro numero: Cerrar\n";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"La empresa tiene una nomina de "<<Empresa1.size()<<" empleados\n";
				system("pause");
				break;
			case 2:
				for(int i=0;i<Empresa1.size();i++){
					if(Empresa1[i].getSalario() > Empresa1[top_salary_employee].getSalario()){
						top_salary_employee=i;
					}
				}
				cout<<"El empleado con mayor salario es: \n"<<Empresa1[top_salary_employee].getNombre()<<"\nSalario: "<<Empresa1[top_salary_employee].getSalario()<<"\nDepartamento: "<<Empresa1[top_salary_employee].getDepartamento()<<endl;
				system("pause");
				break;
			case 3:
				departamento = "";
				depart_comparate = "";
				cout<<"Ingresar departamento a filtrar: ";
				cin>>departamento;
				transform(departamento.begin(), departamento.end(), departamento.begin(), [](unsigned char c){ return tolower(c);});
				for(int i=0;i<Empresa1.size();i++){
					depart_comparate = Empresa1[i].getDepartamento();
					transform(depart_comparate.begin(), depart_comparate.end(), depart_comparate.begin(), [](unsigned char c){ return tolower(c);});
					if(depart_comparate == departamento){
						cout<<endl<<Empresa1[i].getNombre()<<"\nSalario: "<<Empresa1[i].getSalario()<<"\nDepartamento: "<<Empresa1[i].getDepartamento()<<endl<<endl;
					}else if(i == Empresa1.size()-1){
						cout<<"No hay empleados en este departamento, o el departamento no existe"<<endl;
					}
				}
				system("pause");
				break;
			default:return 0;
		}
	}
	return 0;
}

