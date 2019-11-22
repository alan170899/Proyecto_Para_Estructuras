#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contacto{
	char Nombre[20];
	char Telefono[20];
	struct contacto *Sig;
	struct contacto *Ant;
};

//Prototipos
struct contacto* Agregar_Contacto(struct contacto *Agenda, char Nombre[20], char Numero[20]){
	//Apuntadores de ayuda
	struct contacto *Aux1 = NULL;
	struct contacto *Aux2 = NULL;
	//Asignacion de memoria al contacto y sus datos
	struct contacto *NuevoContacto = NULL;
	NuevoContacto = (struct contacto *) malloc (sizeof (struct contacto));
	//Asignacion de valores 
	strcpy(NuevoContacto->Nombre,Nombre);
	strcpy(NuevoContacto->Telefono,Numero);
	//punteros de direcion a null
	NuevoContacto->Sig = NULL;
	NuevoContacto->Ant = NULL;
	
	if (Agenda != NULL){//Agregando contacto al final
		Aux1 = Agenda;
		while (Aux1 != NULL){//ciclo para buscar el final de la agenda
			Aux2 = Aux1;
			Aux1 = Aux1->Sig;
		}
		Aux2->Sig = NuevoContacto;
		NuevoContacto->Ant = Aux2;
		return Agenda;
	}
	else {	//solo funciona si la agenda esta vacia 
		Agenda = NuevoContacto;
		return Agenda;
	}
}

void Mostrar_Contacto(struct contacto *Agenda){
	//Punter de ayuda 
	struct contacto *Aux = NULL;
	
	Aux = Agenda;
	printf("--------------------------------------- \n");
	while (Aux != NULL){
		printf ("%s \n", Aux->Nombre);
		printf ("%s \n\n", Aux->Telefono);
		Aux = Aux->Sig;
	}
	printf("--------------------------------------- \n");
}
struct contacto* Eliminar_Contacto_ultimo(struct contacto *Agenda, char *Nombre, char *Numero){
	//Punteros de ayuda
	struct contacto *Aux1 = NULL;
	struct contacto *Aux2 = NULL;
	
	if (Agenda != NULL){
		Aux1 = Agenda;
		while ((Aux1 != NULL) && (Aux1->Nombre != Nombre) && (Aux1->Telefono != Numero)){
			Aux2 = Aux1;
			Aux1 = Aux1->Sig;
		}
		Aux2->Sig = NULL;
		free(Aux1);
		printf ("Contacto Eliminado \n\n");
	}
	else {
		printf ("Contacto No Encontrado \n");
	}
	return Agenda;
}
struct contacto* Eliminar_Contacto_primero(struct contacto *Agenda, char *Nombre, char *Numero){
	//Punteros de ayuda
	struct contacto *Aux1 = NULL;
	struct contacto *Aux2 = NULL;
	
	if (Agenda != NULL){
		Aux1 = Agenda;
		if ((Aux1 != NULL) || (Aux1->Nombre != Nombre) || (Aux1->Telefono != Numero)){
			Aux2 = Aux1;
			Aux1 = Aux1->Sig;
			Aux1->Ant = NULL;
			Agenda = Aux1;
			free (Aux2);
			printf ("Contacto Eliminado \n\n");
		}
	}
	else {
		printf ("Contacto No Encontrado \n");
	}
	return Agenda;
}
struct contacto* Eliminar_Contacto_medio(struct contacto *Agenda, char *Nombre, char *Numero){
	//Punteros de ayuda
	struct contacto *Aux1 = NULL;
	struct contacto *Aux2 = NULL;
	struct contacto *Aux3 = NULL;
	
	if (Agenda != NULL){
		Aux1 = Agenda;
		while ((Aux1 != NULL) && (Aux1->Nombre != Nombre) && (Aux1->Telefono != Numero)){
			Aux2 = Aux1;
			Aux1 = Aux1->Sig;
		}
		Aux3 = Aux1;
		Aux1 = Aux1->Sig;
		Aux2->Sig = Aux1;
		Aux1->Ant = Aux2;
		free(Aux3);
		printf ("Contacto Eliminado \n\n");
	}
	else {
		printf ("Contacto No Encontrado \n");
	}
	return Agenda;
}
void Buscar_Contacto(struct contacto *Agenda, char *Nombre, char *Numero){
	//Punteros de Ayuda
	struct contacto *Aux1 = NULL;
	
	if (Agenda != NULL){
		Aux1 = Agenda;
		while ((Aux1 != NULL) && (Aux1->Nombre != Nombre) && (Aux1->Telefono != Numero)){
			Aux1 = Aux1->Sig;
		}
	printf ("El contacto que busca es: \n");
	printf ("%s \n", Aux1->Nombre);
	printf ("%s \n\n", Aux1->Telefono);
	}
	else {
		printf("Contacto No existe \n\n");
	}
}


int main(){
	struct contacto *Agenda = NULL;
	char Nombre[20];
	char Numero[15];
	Agenda = Agregar_Contacto(Agenda, "Alan", "121212121");
	Agenda = Agregar_Contacto(Agenda, "Fany", "212121212");
	Agenda = Agregar_Contacto(Agenda, "Elias", "232323232");
	Agenda = Agregar_Contacto(Agenda, "Fernanda", "3232323232");
	Mostrar_Contacto(Agenda);
	Agenda = Eliminar_Contacto_ultimo(Agenda, "Fernanda", "3232323232");
	Mostrar_Contacto(Agenda);
	Agenda = Eliminar_Contacto_primero(Agenda, "Alan", "121212121");
	Mostrar_Contacto(Agenda);
	Agenda = Agregar_Contacto(Agenda, "Alan", "121212121");
	Agenda = Agregar_Contacto(Agenda, "Fernanda", "3232323232");	
	Mostrar_Contacto(Agenda);
	Agenda = Eliminar_Contacto_medio(Agenda, "Elias", "232323232" );
	Mostrar_Contacto(Agenda);
	Agenda = Agregar_Contacto(Agenda, "Elias", "232323232");
	Mostrar_Contacto(Agenda);
	Buscar_Contacto(Agenda, "Fany", "212121212");

  
return 0;
}
