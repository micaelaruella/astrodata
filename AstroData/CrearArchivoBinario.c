#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*Declaración de tipos de datos personalizados*/
typedef char tString20[20];
typedef char tString100[100];
typedef tString100 vPalabras[5];
typedef struct{
	tString20 nombre,piedra,elemento;
	int numerologia,diaComienzo,diaFinal,mesComienzo,mesFinal; /*Las fechas son los intervalos de cada signo*/
	vPalabras caracteristicas;
}tRegistroSigno;

/*Declaración de prototipo*/
void inicializacion();
void grabar();
void finalizacion();

void registrarDatos();

/*Declaración de variables globales*/
tRegistroSigno rSigno;
FILE * aSignos;

/*Función principal*/
int main(){
	inicializacion();
	grabar();
	finalizacion();
	return 0;
}

/*Implementacion de funciones*/

void inicializacion(){
	
	aSignos = fopen ("Signos.dat", "ab");
	if(aSignos==NULL){
		aSignos = fopen ("Signos.dat", "wb");
	}
}
void grabar(){
	char respuesta;

	do{
		registrarDatos();
		fwrite(&rSigno, sizeof(tRegistroSigno), 1, aSignos);
		printf("\nSigno almacenado!\n");
		Sleep(1999);
		system("cls");
		printf("\nDesea agregar un signo? S/N: ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta=tolower(respuesta);
	}while (respuesta != 'n' );
}


void registrarDatos(){
		int i;
		printf("*********************************\n");
		printf("\nIngrese los siguientes datos del signo: ");
		printf("\nNombre: ");
		fflush(stdin);
		gets(rSigno.nombre);
		printf("\nFecha de inicio:\nDia: ");
		scanf("%d",&rSigno.diaComienzo);		
		printf("Mes: ");
		scanf("%d",&rSigno.mesComienzo);
		printf("\nFecha del fin:\nDia: ");
		scanf("%d",&rSigno.diaFinal);		
		printf("Mes: ");
		scanf("%d",&rSigno.mesFinal);
		printf("\nPiedra: ");
		fflush(stdin);
		gets(rSigno.piedra);
		printf("\nElemento: ");
		fflush(stdin);
		gets(rSigno.elemento);
		printf("\nNumerologia: ");
		scanf("%d",&rSigno.numerologia);
		printf("\nCaracteristicas: ");
		for(i=0; i<5; i++){
		fflush(stdin);
		gets(rSigno.caracteristicas[i]);	
		}
		
}

void finalizacion(){
	fclose(aSignos);
}
