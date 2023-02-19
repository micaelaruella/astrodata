#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Declaracion de tipos de datos personalizados*/
typedef char tString[20];
typedef int vInt12[12];
typedef struct{
	tString signo;
	int codigoSigno;
	vInt12 compatibilidad;
}tRegistroCompatibilidad;

/*Declaracion de prototipos*/
void iniciarProceso();
void procesarDatos();
void finalizarProceso();


/*Declaracion de variables globales*/
tRegistroCompatibilidad rCompatibilidad;
FILE * aCompatibilidades;

int main(){
	iniciarProceso();
	procesarDatos();
	finalizarProceso();

	return 0;
}

/*Implementacion de funciones*/
void iniciarProceso(){
	/*Abrir el archivo*/
	aCompatibilidades=fopen("Compatibilidades.dat","rb");
	if(aCompatibilidades==NULL){
		printf("\nEl archivo no existe");
		exit(EXIT_FAILURE);
	}
}
void procesarDatos(){
	int i;
	printf("### Compatibilidades en el archivo ###");

	fread(&rCompatibilidad,sizeof(tRegistroCompatibilidad),1,aCompatibilidades);
	while(!feof(aCompatibilidades)){
		printf("\nNombre: %s", rCompatibilidad.signo);
		printf("\nCodigo: %d", rCompatibilidad.codigoSigno);
		printf("\nCompatibilidad: ");
		for(i=0; i<12; i++){
			printf("\n%d", rCompatibilidad.compatibilidad[i]);
		}
		fread(&rCompatibilidad,sizeof(tRegistroCompatibilidad),1,aCompatibilidades);
	}
	
}
void finalizarProceso(){
	fclose(aCompatibilidades);
}

