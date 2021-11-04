#include <iostream>

using namespace::std;

struct nodo{
	int id;
	string dueño;
	string raza;
	float peso;
	int edad;
	nodo* siguiente;
} *primero, *ultimo;


void insertarNodo();
void buscarNodo();
void eliminarNodo();



int main(){
	int id;
	string dueño;
	string raza;
	float peso;
	int edad;
	nodo* siguiente;

	int opcion_menu=0;
	do
	{
		cout <<endl<<"Veterinaria PED"<<endl<<endl;
		cout << "1-Agregar datos"<<endl;
		cout << "2-Mostrar datos"<<endl;
		cout << "3-Eliminar datos"<<endl;
		cout << "4-Salir"<<endl;
		cout << "Digite su opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout <<endl<<"Ingresar datos"<<endl<<endl;
			insertarNodo();
			break;
		case 2:
			cout <<endl<<"Mostrar datos"<<endl;
			buscarNodo();
			break;

		case 3:
			cout <<endl<<"Eliminar datos"<<endl;
			eliminarNodo();
			break;
	
		case 4:
			cout <<endl<<"Programa ha finalizado"<<endl;
			break;
		
		default:
			cout <<endl<<"Opcion No Valida"<<endl;
		}
	} while (opcion_menu != 4);
	
	return 0;
}
				
 
void insertarNodo(){
	nodo* nuevo = new nodo();
cout<<"Ingresar ID: ";
cin >> nuevo->id; 
cout<<"Nombre del dueño: ";
cin >> nuevo->dueño;
cout<<"Raza: ";
cin >> nuevo->raza;
cout<<"Peso: ";
cin >> nuevo->peso;
cout<<"Edad: ";
cin >> nuevo->edad;
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "Ingrese su ID para encontrar su datos"<<endl;
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->id == nodoBuscado){
				cout << "El ID es valido"<<endl;
			cout << endl <<"ID :"<< actual->id;
			cout << endl <<"Nombre del dueño: "<<actual->dueño;
			cout << endl <<"Raza: "<<actual->raza;
			cout << endl <<"Peso: "<<actual->peso;
			cout << endl <<"Edad: "<< actual->edad;
				encontrado = true;
			}
			
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "El ID no es valido"<<endl;
		}
	}else{
		cout << "La lista se encuentra vacia"<<endl;
	}
}


void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "Ingresar ID de los datos que se desean eliminar "<<endl;
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->id == nodoBuscado){
				cout << "ID encontrado"<<endl;
				
				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					anterior->siguiente = primero;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				cout << "Los datos han sido eliminados"<<endl<<endl;
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "ID no se encuentra"<<endl<<endl;
		}
	}else{
		cout << "La lista se encuentra vacia"<<endl<<endl;
	}
}

