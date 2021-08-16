#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<cstdlib>

using namespace std;

typedef struct nodo{
	int dato;
	char nombre[20];
	struct nodo* siguiente;
	struct nodo* atras;
}nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarInicio();
//void insertarFinal();
void buscarNodo();
void desplegarListaInicio();
void desplegarListaFinal();
void eliminarBusqueda();
//void eliminarPrimero();
//void eliminarUltimo();

char menu(){
	char op;
	system("cls");
	printf("\n ** MENU * *");
	printf("\n 1. INSETAR AL INICIO ");
	printf("\n 2. MOSTRAR PRIMERO AL ULTIMO ");
	printf("\n 3. MOSTRAR ULTIMO AL PRIMERO ");
	printf("\n 4. ELIMINAR POR BUSQUEDA ");
	printf("\n 5. SALIR");
	printf("\n OPCION-->"); fflush(stdin);
	op=getch();
	return op;	
	system("pause");
}

int main(void){
	char op;
	do{
		op=menu();
		switch(op){
			
			case'1':
			system("cls");
			insertarInicio();
			break;
				
			case'2':
			system("cls");
			cout<<"\tNOMBRE\t\t\tSEMESTRE\n";
			desplegarListaInicio();
			system("\npause>n");
			break;
					
			case'3':
			system("cls");
			cout<<"\tNOMBRE\t\t\tSEMESTRE\n";
			desplegarListaFinal();
			system("\npause>n");
			break;
					
			case'4':
			system("cls");
			eliminarBusqueda();
			system("pause");
			break;				
		}
	}while(op!='5');
	return 0;
}


void insertarInicio(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	cout << "Ingrese nombre: ";
	cin >> nuevo->nombre; 
	cout << "Ingrese semestre: ";
	cin >> nuevo->dato; 
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}

	printf("\n *Nodo ingresado*\n\n");
}

void buscarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void eliminarBusqueda(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el semestre del nodo a Buscar para Eliminar: " );
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n Nodo eliminado con exito\n\n");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
			
		}else{
			delete(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void desplegarListaInicio(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			cout << "\n\n\t " << actual->nombre;
			cout << "\t\t\t " << actual->dato;
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void desplegarListaFinal(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = ultimo;
	if(primero!=NULL){
		while(actual != NULL){
			cout << "\n\n\t " << actual->nombre;
			cout << "\t\t\t " << actual->dato;	
			actual = actual->atras;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}	
}
