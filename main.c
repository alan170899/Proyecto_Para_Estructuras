#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contacto{
	char Nombre[20];
	char Telefono[20];
	struct contacto *Sig;
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
		
	if (Agenda != NULL){//Agregando contacto al final
		Aux1 = Agenda;
		while (Aux1 != NULL){//ciclo para buscar el final de la agenda
			Aux2 = Aux1;
			Aux1 = Aux1->Sig;
		}
		Aux2->Sig = NuevoContacto;
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

struct contacto* Eliminar_Contacto(struct contacto *Agenda, char Nombre[20], char Numero[20]){
	//Puntero de ayuda
	struct contacto *Aux1 = NULL;
	struct contacto *Aux2 = NULL;
	struct contacto *Aux3 = NULL;

	if (Agenda != NULL){
		Aux1 = Agenda;
		
		while ( (Aux1 != NULL) && (Aux1->Nombre !=  Nombre) && (Aux1->Telefono != Numero) ){
			Aux2 = Aux1;
			Aux1 = Aux1->Sig;
		}//Busca el elemmento a borrar

		if (Aux2 == NULL){
			Aux2 = Aux1;
			Aux2 = Aux2->Sig;
			Agenda = Aux2;
			free(Aux1);
		}//Borra el primer elemento
		else{
			Aux3 = Aux1->Sig;
			Aux2->Sig = Aux3;
			free (Aux1);
		}//Borra cualquiera elemento si lo encontro 
	}
	else {
		printf ("La agenda esta vacia \n\n");
	}
	return Agenda;
}

int main(){
	struct contacto *Agenda = NULL;
	char Nombre[20];
	char Numero[15];
	Agenda = Agregar_Contacto(Agenda, "Alan", "111111111");
	Agenda = Agregar_Contacto(Agenda, "Fany", "222222222");
	Agenda = Agregar_Contacto(Agenda, "Elias", "33333333");
	Agenda = Agregar_Contacto(Agenda, "Fernanda", "44444444");
	Mostrar_Contacto(Agenda);
	Agenda = Eliminar_Contacto(Agenda, "Fany", "222222222");
	Mostrar_Contacto(Agenda);







  
return 0;
}
