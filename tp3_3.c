//Programa en el que se soliciten 5 nombres, los cargue un vector de punteros char y una
//vez cargados los liste por pantalla (con reserva dinamica de memoria)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int i=0,N;
	puts("Ingrese la cantidad de usuarios que desea ingresar\n");
	scanf("%d",&N);
	char **nombres=(char **)malloc(sizeof(char *)*N);
	char *buff=(char *)malloc(100);
	for(i=0;i<N;i++){
		printf("Ingrese el nombre %d:\n",i+1);
		gets(buff);
		nombres[i]=(char *)malloc(strlen(buff)+1);
		strcpy(nombres[i],buff);
	}
	for(i=0;i<N;i++){
		printf("La nombre numero %d es: ",i+1);
		puts(nombres[i]);
	}
	free(nombres);
	free(buff);
	return 0;
}
