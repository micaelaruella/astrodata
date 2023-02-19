#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Declaracion de tipos de datos personalizados*/
typedef char tString20[20];
typedef char tString100[100];
typedef tString100 vPalabras[5];
typedef struct{
	tString20 nombre,piedra,elemento;
	int numerologia,diaComienzo,diaFinal,mesComienzo,mesFinal; /*Las fechas son los intervalos de cada signo*/
	vPalabras caracteristicas;
}tRegistroSigno;

/*Declaracion de prototipos*/
void iniciarProceso();
void procesarDatos();
void finalizarProceso();


/*Declaracion de variables globales*/
tRegistroSigno rSigno;
FILE * aSignos;

int main(){
	iniciarProceso();
	procesarDatos();
	finalizarProceso();

	return 0;
}

/*Implementacion de funciones*/
void iniciarProceso(){
	/*Abrir el archivo*/
	aSignos=fopen("Signos.dat","rb");
	if(aSignos==NULL){
		printf("\nEl archivo no existe");
		exit(EXIT_FAILURE);
	}
}
void procesarDatos(){
	int i;
	printf("***Signos en el archivo***");

	fread(&rSigno,sizeof(tRegistroSigno),1,aSignos);
	while(!feof(aSignos)){
		printf("\n\n");
		printf("\nNombre: %s \nFecha (Dia-Mes): Del %d-%d al %d-%d \nPiedra: %s \nElemento: %s \nNumero: %d\n",
		rSigno.nombre, rSigno.diaComienzo,rSigno.mesComienzo,rSigno.diaFinal,rSigno.mesFinal, rSigno.piedra, rSigno.elemento, rSigno.numerologia);	
		printf("Caracteristicas: ");
		for(i=0; i<5; i++){
			printf("\n\t *%s", rSigno.caracteristicas[i]);
		}
	
		fread(&rSigno,sizeof(tRegistroSigno),1,aSignos);
	}
	
}
void finalizarProceso(){
	fclose(aSignos);
}

