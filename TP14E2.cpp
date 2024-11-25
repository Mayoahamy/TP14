#include<iostream>
#include<vector>
using namespace std;

class Mesas{
	private:
		int n_sillas;
		bool ocupada = false;
	public:
		void set_n_sillas(int n){
			n_sillas = n;
		}
		void set_ocupada(bool n){
			ocupada = n;
		}
		int get_n_sillas(){ return n_sillas;}
		bool get_ocupada(){ return ocupada;}
};

class Restaurante{
	private:
		Mesas mesa;
	public:
		Restaurante(Mesas mesa) : mesa(mesa) {};
		int get_n_sillas(){
			return mesa.get_n_sillas();
		}
		bool get_ocupada(){
			return mesa.get_ocupada();
		}
		void set_ocupada(bool n){
			mesa.set_ocupada(n);
		}
};
int main(){
	vector<Restaurante> Restaurante1;
	Mesas mesa;
	int n_sillas,choice,cant_mesas,mesa_elegir;
	bool ocupada;
	cout<<"Ingresar cantidad de mesas en el restaurante: ";
	cin>>cant_mesas;
	for(int i=0;i<cant_mesas;i++){
		cout<<"Cantidad de sillas en mesa "<<i+1<<":";
		cin>>n_sillas;
		mesa.set_n_sillas(n_sillas);
		Restaurante1.push_back(Restaurante(mesa));
	}
	while(true){
		cout<<"\n\n\nIngresar opcion"<<endl<<"1: Ver mesas"<<endl<<"2: Reservar mesa"<<endl<<"3: Liberar mesa"<<endl<<"Otro numero: Cerrar \n";
		cin>>choice;
		switch(choice){
			case 1:
				for(int i=0;i<Restaurante1.size();i++){
					cout<<endl<<"Mesa "<<i+1<<" "<<Restaurante1[i].get_n_sillas()<<" sillas -  ";
					if(Restaurante1[i].get_ocupada()){
						cout<<"Ocupada";
					}else{
						cout<<"Libre";
					}
				}
				break;		
			case 2:
				for(int i=0;i<Restaurante1.size();i++){
					if(!Restaurante1[i].get_ocupada()){
						Restaurante1[i].set_ocupada(true);
						i=Restaurante1.size();
						cout<<"Mesa reservada"<<endl;
					}
					else if(i==Restaurante1.size()-1){
						cout<<"No hay mesas libres"<<endl;
					}
				}
				break;
			case 3:
				cout<<"Elegir mesa a liberar: ";
				for(int i=0;i<Restaurante1.size();i++){
					cout<<endl<<"Mesa "<<i+1<<" "<<Restaurante1[i].get_n_sillas()<<" sillas -  ";
					if(Restaurante1[i].get_ocupada()){
						cout<<"Ocupada";
					}else{
						cout<<"Libre";
					}
				}
				cout<<endl;
				cin>>mesa_elegir;
				if(mesa_elegir >= Restaurante1.size() || mesa_elegir < 1){
					cout<<"Mesa inexistente"<<endl;
					break;
				}
				if(Restaurante1[mesa_elegir-1].get_ocupada()){
					Restaurante1[mesa_elegir-1].set_ocupada(false);
					cout<<"Mesa "<<mesa_elegir<<" liberada";
				}else{
					cout<<"Mesa "<<mesa_elegir<<" ya libre, no se puede liberar";
				}
				break;
			default:return 0;		
		}
	}
	return 0;
}
