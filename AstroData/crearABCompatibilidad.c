#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*Declaración de tipos de datos personalizados*/
typedef char tString[20];
typedef int vInt12[12];
typedef struct{
	tString signo;
	int codigoSigno;
	vInt12 compatibilidad;
}tRegistroCompatibilidad;

/*Declaración de prototipo*/
void inicializacion();
void grabar();
void finalizacion();

void registrarDatos();

/*Declaración de variables globales*/
tRegistroCompatibilidad rCompatibilidad;
FILE * aCompatibilidades;

/*Función principal*/
int main(){
	inicializacion();
	grabar();
	finalizacion();
	return 0;
}

/*Implementacion de funciones*/

void inicializacion(){
	
	aCompatibilidades = fopen ("Compatibilidades.dat", "ab");
	if(aCompatibilidades==NULL){
		aCompatibilidades = fopen ("Compatibilidades.dat", "wb");
	}
}
void grabar(){
	char respuesta;

	do{
		registrarDatos();
		fwrite(&rCompatibilidad, sizeof(tRegistroCompatibilidad), 1, aCompatibilidades);
		printf("\nCompatibilidad almacenada!");
		Sleep(1999);
		system("cls");
		printf("\nDesea agregar otra compatibilidad? S/N: ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta=tolower(respuesta);
	}while (respuesta != 'n' );
}


void registrarDatos(){
	int i;
	printf("Ingrese los datos del signo \n");
	printf("Nombre: ");
	fflush(stdin);
	gets(rCompatibilidad.signo);
	printf("Codigo: ");
	scanf("%d", &rCompatibilidad.codigoSigno);
	printf("Compatibilidad: \n");
		for(i=0; i<12; i++){
		scanf("%d ", &rCompatibilidad.compatibilidad[i]);
	}
}


void finalizacion(){
	fclose(aCompatibilidades);
}
