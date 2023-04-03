#include<stdio.h>
#include<math.h>

#define n 5
#define m 12

int main (){
	int i=0,j=0,aux=0,aux2=0,aux3=0,aux4=0,aux5=0,aux6=0,aux7=0;
	int matriz[n][m];
	int ganancia[n];
	srand(time(NULL));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matriz[i][j]=10000+rand()%50000;
			printf("[$%d]",matriz[i][j]);
			aux=aux+matriz[i][j];
			if(aux2==0 && aux3==0){
				aux2=matriz[i][j];
			    aux3=matriz[i][j];
			    aux4=i; aux5=j; //para el valor mayor
				aux6=i; aux7=j;
			}
			if(aux2<matriz[i][j]){
				aux3=aux2; //aux3 es para valor mas bajo
				aux2=matriz[i][j]; //aux2 es para el valor mas alto
				aux6=aux4; aux7=aux5; //para el valor menor
				aux4=i; aux5=j; //para el valor mayor
			}else{
				if(aux2>matriz[i][j]){
					if(aux3>matriz[i][j]){
						aux3=matriz[i][j];
				        aux6=i; aux7=j;
					}
				}
			}
			
		}
		ganancia[i]=aux/m;
		printf("\n");
		aux=0;
	}
	for(i=0;i<n;i++){
		printf("\nEl promedio de ganancia del anio %d es: $%d",i+1,ganancia[i]);
	}
	printf("\n\nEl maximo valor obtenido fue en el anio %d en el mes %d: $%d",aux4+1,aux5+1,aux2);
	printf("\nEl minimo valor obtenido fue en el anio %d en el mes %d: $%d",aux6+1,aux7+1,aux3);
	return 0;
}
