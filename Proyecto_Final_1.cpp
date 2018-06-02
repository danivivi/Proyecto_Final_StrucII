#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Nodo{
	char dato [20];
	int id;
	Nodo *derecha;
	Nodo *izquierda;
	Nodo *padre;
};

Nodo *Crear_Nodo(char n,Nodo *padre,int codigo);
void Insertar(Nodo *&arbol,char n[20],Nodo *padre,int codigo);
void Mostrar_Arbol(Nodo *arbol,int cont);
void InOrden(Nodo *arbol);
bool busqueda(Nodo *arbol,int n);
void Menu();
void PostOrden(Nodo *arbol);
void PreOrden(Nodo *arbol);
void Eliminar(Nodo *arbol,int n);
void EliminarNodo(Nodo *NodoEliminar);
Nodo *Minimo(Nodo *arbol);
void Reemplazar(Nodo *arbol,Nodo *nuevo_nodo);
void DestruirNodo(Nodo *nodo);

bool busquedaCarpeta(Nodo *arbol,char nombre[20]);


int main() {
	Menu();
	return 0;
}

void Menu(){
	Nodo *arbol=NULL;
	int x,opcion,id,entrada,p,a,z;
	int cont=0;
	char n[20],nombre[20];
	do{
		printf("\n<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<MENU ARBOLES DE CARPETAS>>>>>>>>>>>>\n");
		printf("<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("<                                              >\n");
		printf("<     1.Ingresar Carpetas                      >\n");
		printf("<     2.Mostrar Arbol Completo                 >\n");
		printf("<     3.InOrden                                >\n");
		printf("<     4.PostOrden                              >\n");
		printf("<     5.PreOrden                               >\n");
		printf("<     6.Buscar Carpeta                         >\n");
		printf("<     7.Eliminar una Carpeta                   >\n");
		printf("<     0.Salir                                  >\n");
		printf("<                                              >\n");
		printf("<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");		
		printf("Ingrese Opcion: ");
		scanf("%d",&opcion);
		printf("\n");
		switch(opcion){
		case 0:
			exit(0);
			break;
		case 1:
			printf("\nCuantas Carpetas desea Crear: ");
			scanf("%d",&x);			
			for(int i=0;i<x;i++){
				printf("\nIngrese Nombre de Carpeta-> ");
				fflush stdin;
				gets(n);
				printf("\nCodigo: ");
				scanf("%d",&id);
				Insertar(arbol,n,NULL,id);
				printf("\nCarpeta  y Codigo Ingresados con Exito!!\n");
			}			
			break;
		case 2:
			Mostrar_Arbol(arbol,cont);
			break;
		case 3:
			InOrden(arbol);
			break;
		case 4:
			PostOrden(arbol);
			break;
		case 5:
			PreOrden(arbol);
			break;
		case 6:
			printf("Desea Buscar por: \n");
			printf("1.Codigo\n");
			printf("2.Nombre de la Carpeta\n");
			printf("\nIngrese una Opcion: ");
			scanf("%d",&entrada);
			switch(entrada){
			case 1:
				printf("\nIngrese Codigo a Buscar: ");
				scanf("%d",&a);
				if(busqueda(arbol,a)==true){
					printf("\nLa Carpeta Existe en el Arbol.\n");
				}else{
					printf("\nLa Carpeta NO Existe en el Arbol.\n");
				}
				break;
			case 2:
				printf("\nIngrese Nombre la Carpeta a Buscar: ");
				fflush stdin;
				gets(nombre);
				if(busquedaCarpeta(arbol,nombre)==true){
					printf("\nLa Carpeta Existe en el Arbol.\n");
				}else{
					printf("\nLa Carpeta NO Existe en el Arbol.\n");
				}
				break;
			default:
				printf("\nOpcion Incorrecta.\n");
			}			
			break;
		case 7:
			printf("\nIngrese Codigo de la Carpeta a Eliminar: ");
			scanf("%d",&z);
			Eliminar(arbol,z);
			printf("\nCarpeta Eliminada con Exito!\n");
			break;
		default:
			printf("Opcion Incorrecta.\n");
			break;
		}     
	}while(opcion!=0);
}

Nodo *Crear_Nodo(char n[20],Nodo *padre,int codigo){
	Nodo *nuevo_nodo= new Nodo();
	strcpy(nuevo_nodo->dato,n);
	nuevo_nodo->derecha=NULL;
	nuevo_nodo->izquierda=NULL;
	nuevo_nodo->padre=padre;
	nuevo_nodo->id=codigo;
	return nuevo_nodo;
}

void Insertar(Nodo *&arbol,char n[20],Nodo *padre,int codigo){
	if(arbol==NULL){
		Nodo *nuevo_nodo=Crear_Nodo(n,padre,codigo);
		arbol=nuevo_nodo;
	}else{
		int valorRaiz=arbol->id;
		if(codigo<valorRaiz){
			Insertar(arbol->izquierda,n,arbol,codigo);
		}else{
			Insertar(arbol->derecha,n,arbol,codigo);
		}		
	}		
}

void Mostrar_Arbol(Nodo *arbol,int cont){
	if(arbol==NULL){
		return;
	}else{
		Mostrar_Arbol(arbol->derecha,cont+1);
		for(int i=0;i<cont;i++){
			printf("  ");
		}
		printf("%d. %s\n",arbol->id,arbol->dato);
		Mostrar_Arbol(arbol->izquierda,cont+1);
	}	
}

void InOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		InOrden(arbol->izquierda);
		printf("%d. %s - ",arbol->id,arbol->dato);
		InOrden(arbol->derecha);
	}	
}

bool busqueda(Nodo *arbol,int n){
	if(arbol==NULL){
		return false;
	}else if(arbol->id==n){
		return true;
	}else if(n < arbol->id){
		return busqueda(arbol->izquierda,n);
	}else{
		return busqueda(arbol->derecha,n);
	}
}
bool busquedaCarpeta(Nodo *arbol,char nombre[20]){
	//printf("%d",strcmp(arbol->dato,nombre));
	if(arbol==NULL){
		return false;
	}else if(strcmp(arbol->dato,nombre)==0){
		return true;
	}else{//if (strcmp(arbol->dato,nombre)>0){
		printf("%d",strcmp(arbol->dato,nombre));
		printf("%s",arbol->dato);
		return busquedaCarpeta(arbol->izquierda,nombre);
		return busquedaCarpeta(arbol->derecha,nombre);	
		
		
	}//else if (strcmp(arbol->dato,nombre)<0){
		//return busquedaCarpeta(arbol->izquierda,nombre);
	//}
}
void PostOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		PostOrden(arbol->izquierda);
		PostOrden(arbol->derecha);
		printf("%d. %s - ",arbol->id,arbol->dato);
	}
}
void PreOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		printf("%d. %s - ",arbol->id,arbol->dato);
		PreOrden(arbol->izquierda);
		PreOrden(arbol->derecha);
	}
}
void Eliminar(Nodo *arbol,int n){
	if(arbol==NULL){
		return;
	}else if(n<arbol->id){
		Eliminar(arbol->izquierda,n);
	}else if(n>arbol->id){
		Eliminar(arbol->derecha,n);
	}else{
		EliminarNodo(arbol);
	}
}

void EliminarNodo(Nodo *NodoEliminar){
	if(NodoEliminar->izquierda && NodoEliminar->derecha){
		Nodo *menor=Minimo(NodoEliminar->derecha);
		NodoEliminar->id=menor->id;
		EliminarNodo(menor);
	}else if(NodoEliminar->izquierda){
		Reemplazar(NodoEliminar,NodoEliminar->izquierda);
		DestruirNodo(NodoEliminar);
	}else if(NodoEliminar->derecha){
		Reemplazar(NodoEliminar,NodoEliminar->derecha);
		DestruirNodo(NodoEliminar);
	}else{
		Reemplazar(NodoEliminar,NULL);
		DestruirNodo(NodoEliminar);
	}
}

Nodo *Minimo(Nodo *arbol){
	if(arbol==NULL){
		return NULL;
	}if(arbol->izquierda){
		return Minimo(arbol->izquierda);
	}else{
		return arbol;
	}
}

void Reemplazar(Nodo *arbol,Nodo *nuevo_nodo){
	if(arbol->padre){
		if(arbol->padre->izquierda!=NULL){
			if(arbol->dato==arbol->padre->izquierda->dato){
				arbol->padre->izquierda=nuevo_nodo;
			}
		}
		if(arbol->padre->derecha!=NULL){
			if(arbol->dato==arbol->padre->derecha->dato){
				arbol->padre->derecha=nuevo_nodo;
			}
		}
	}
	if(nuevo_nodo){
		nuevo_nodo->padre=arbol->padre;
	}
}

void DestruirNodo(Nodo *nodo){
	nodo->izquierda=NULL;
	nodo->derecha=NULL;
	delete nodo;
}


