#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

char *TiposProductos[]= {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto{
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef(prod);

struct Cliente{
int ClienteID; // Numerado en el ciclo iterativo
char NombreCliente[MAX]; // Ingresado por usuario
int CantidadProductos; // (aleatorio entre 1 y 5)
prod *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef(clien);

//-------------------Cargar Informacion-------------------

void generar(prod *Productos,int m){ //Genera los valores de los productos
	int i=0;
	for(i=0;i<m;i++){
		Productos->ProductoID=i+1; //Asigna ID al producto
		Productos->Cantidad=1+rand()%10; //Asigna cantidad de productos que compro
		Productos->TipoProducto=TiposProductos[1+rand()%5]; //Asigna que tipo de producto fue adquirido
		Productos->PrecioUnitario=10+rand()%100; //Asigna el precio unitario de cada producto
		Productos++;
	}
}

void cargarClientes(clien *Clientes,int n){ //Carga los clientes
	int i,m;
	for(i=0;i<n;i++){
		printf("-------CLIENTE NUMERO %d-------",i+1);
		Clientes->ClienteID=i+1; //Ingresa ID que tendra el cliente
		puts("\nNombre:");
		gets(Clientes->NombreCliente); //Ingresa nombre del cliente
		Clientes->CantidadProductos=1+rand()%5; //Asigna cuantos productos compro el cliente
		Clientes->Productos=(prod *)malloc(sizeof(prod)*Clientes->CantidadProductos); //Asigna memoria
		m=Clientes->CantidadProductos;
		generar(Clientes->Productos,m); //Genera los productos del cliente
		Clientes++;
		fflush(stdin);
	}
}

float PrecioTotal(prod *Productos,int m){
	int i;
	float tp=0;
	for(i=0;i<m;i++){
		tp+=Productos->PrecioUnitario;
		Productos++;
	}
	return tp;
}

//-------------------Mostrar Clientes-------------------

void mostrarProductos(prod *Productos,int m){
	int i;
	for(i=0;i<m;i++){
		printf("\n\n///////PRODUCTO NUMERO %d///////\n\n",i+1);
		printf("ID del producto: %d",Productos->ProductoID);
		printf("\nCantidad en stock del producto: %d",Productos->Cantidad);
		printf("\nTipo de producto: %s",Productos->TipoProducto);
		printf("\nPrecio unitario de cada producto: %d",Productos->PrecioUnitario);
		Productos++;
	}
}

void mostrarClientes(clien *Clientes,int n){
	int i,m;
	for(i=0;i<n;i++){
		printf("\n\n-------CLIENTE NUMERO %d-------\n\n",i+1);
		printf("ID del cliente: %d",Clientes->ClienteID);
		printf("\nNombre del cliente: %s",Clientes->NombreCliente);
		printf("\nCantidad de productos del cliente: %d",Clientes->CantidadProductos);
		m=Clientes->CantidadProductos;
		mostrarProductos(Clientes->Productos,m);
		printf("\nTotal a pagar: %.1f",PrecioTotal(Clientes->Productos,m));
		Clientes++;
	}
}

//-------------------Funcion Principal-------------------

int main(){
	clien *Clientes;
	int n,i;
	srand(time(NULL));
	puts("Ingrese la cantidad de clientes:");
	scanf("%d",&n);
	while(n>5 || n<1){
		puts("Ingrese un numero valido de clientes:");
		scanf("%d",&n);
	}
	fflush(stdin);
	Clientes=(clien*)malloc(sizeof(clien)*n);
	cargarClientes(Clientes,n);
	puts("=======DATOS DE LOS CLIENTES=======");
	mostrarClientes(Clientes,n);
	for(i=0;i<n;i++){
		free(Clientes->Productos);
	}
	free(Clientes);
	return 0;
}
