//declaracion de librerias que utilizamos

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <locale.h>

//declaracion de funciones, para opciones de menu y validar codigo entre 1 y 5(cantidad de productos ingresados)
int funcion_opcion();
int validar_codigo();
main()
{ 
//Declaracion de variables...
	int i,j,opcion,cant_vendida,cantidad_producto[6],cod_de_producto,cantidad_de_ventas=0,cant_comprada=0,cantidad_de_compras=0;
	float precio_producto[6],p_prod_proveedor[6],venta,total_ventas=0,compra,total_compras=0,promedio_compras,promedio_ventas;
	char n_de_producto[6][15],n_de_proveedor[6][15],n_prod_proveedor[6][15];
	const char usuario [15]="admin";
	const char clave [15]="1234";
	char usuario_u[15];
	char clave_u [15];
	int intentos=0;
	int correcta=0;
	int n_opcion;
	//habilita el uso del lenguaje español, ñ etc
	setlocale (LC_ALL, "spanish");
	//ingreso de productos y provedores 
	for(i=1;i<=5;i++){
		printf("Ingrese productos\n\n");
		printf("Nombre de producto: ");
		fflush(stdin);
		gets(n_de_producto[i]);
		printf("Precio de producto: ");
		scanf("%f",&precio_producto[i]);
		printf("Cantidad: ");
		scanf("%i",&cantidad_producto[i]);
		system("cls");
	}
	for(i=1;i<=5;i++){
		printf("Ingrese Proveedores\n\n");
		printf("Nombre de proveedor: ");
		fflush(stdin);
		gets(n_de_proveedor[i]);
		printf("Nombre de producto: ");
		fflush(stdin);
		gets(n_prod_proveedor[i]);
		printf("Precio de producto: ");
		scanf("%f",&p_prod_proveedor[i]);
		system("cls");
	}	
	//Login, ingreso por usurio y contraseña, con tres intentos	
	do{
        system("cls");
        printf("\t\t \n INICIO DE SESION\n\n\n");	
		printf("usuario: ");
		fflush(stdin);
		scanf("%s", &usuario_u);
		printf("clave: ");
		fflush(stdin);
		scanf("%s", &clave_u);
		
		if (strcmp(usuario, usuario_u)==0 && strcmp (clave, clave_u)==0){
			correcta=1;
		}
		else {
			intentos++;
		}}
		while (intentos<3 && correcta==0);
		
	if (correcta=1 && intentos<3){
		system ("cls");
		system("color 6");
		printf("\n\n\t\t BIENVENIDO AL SISTEMA\n ");
		printf("\n\t\t MENU \n"); 
	
	}
	else  {
		system("cls");
		printf("Ha superado cantidad maxima de intentos\n");
		system("pause");
		exit(0);
	}
	//llamado a funcion del menu
	opcion=funcion_opcion();
	//menu con ventas, proovedores, articulos, facturacion y gastos compras.
	while(opcion!=0){
		switch(opcion){
			case 1: //ventas
				system("cls");
				printf("\t\t\tVentas");
				printf("\n------------------------------------------------------------------");
				cod_de_producto=validar_codigo();
				cant_vendida=0;
				do{
					if(cant_vendida!=0){
						printf("\nERROR!!! ingrese un valor mayor igual a 1 o 0 para salir");
					}
					printf("\nIngrese cantidad: ");
					scanf("%i",&cant_vendida);
				}while(cant_vendida<0);
				if(cantidad_producto[cod_de_producto]>cant_vendida){
					cantidad_producto[cod_de_producto]=cantidad_producto[cod_de_producto]-cant_vendida;
					venta=cant_vendida*precio_producto[cod_de_producto];
					cantidad_de_ventas++;
					if(cantidad_producto[cod_de_producto]==0){
						printf("\nComprar mas %s",n_de_producto);
					}
				}
				else{
					printf("Error!!! quedan %i de %s",cantidad_producto[cod_de_producto],n_de_producto[cod_de_producto]);
				}
				getch();
				system("cls");
				break;
			case 2: //proveedores
				system("cls");
				printf("\t\t\tProveedores");
				printf("\n------------------------------------------------------------------");
				printf("\nNombre\t\tProducto\t\tPrecio\n");
				for(i=1;i<=5;i++){								
					printf("%s\t %s \t\t $ %.2f\n",n_de_proveedor[i],n_prod_proveedor[i],p_prod_proveedor[i]);						
				}
				getch();
				system("cls");
				break;
			case 3: //Articulos
				system("cls");
				printf("\t\t\tArticulos");
				printf("\n-------------------------------------------------------------------");				
				printf("\nCodigo\t\tNombre\t\tCantidad\tprecio\n");
				for(i=1;i<=5;i++)
				{								
					printf("%i\t\t%s\t%i\t\t $ %.2f\n",i,n_de_producto[i],cantidad_producto[i],precio_producto[i]);	
				}				
				getch();
				system("cls");
				break;
			case 4: //facturacion y gastos
				system("cls");
				printf("\t\tFacturacion y Gastos");
				printf("\n--------------------------------------------------------------------");
				if(cantidad_de_ventas>0){				
					printf("\n\nLo total facturado hasta el momento es:\t\t $ %.2f",total_ventas);
					printf("\n\nLa cantidad de ventas han sido hasta el momento: %i",cantidad_de_ventas);
					promedio_ventas=total_ventas/cantidad_de_ventas;
					printf("\n\nPromedio por venta es: %.2f",promedio_ventas);
				}
				else{
					printf("\n\nNo se ha realizado ninguna venta");
				}
				if(cantidad_de_compras>0){				
					printf("\n\nLo total gastado hasta el momento es:\t\t $ %.2f",total_compras);
					printf("\n\nLa cantidad de compras han sido hasta el momento: %i",cantidad_de_compras);
					promedio_compras=total_compras/cantidad_de_compras;
					printf("\n\nPromedio por compra:\t\t\t\t $ %.2f",promedio_compras);
				}
				else{
					printf("\n\nNo se ha realizado ninguna compra");
				}
				getch();
				system("cls");
				break;
			case 5: //compras
				system("cls");
				printf("\t\t\tCompras");
				printf("\n----------------------------------------------------------------------");				
				cod_de_producto=validar_codigo();
				for(i=1;i<=5;i++){
					if(strcmp(n_de_producto[cod_de_producto],n_prod_proveedor[i])==0){
						printf("\nEl producto es: %s el costo por unidad es $ %.2f",n_prod_proveedor[i],p_prod_proveedor[i]);						
						cant_comprada=0;
						do{
							if(cant_comprada!=0){
								printf("\nERROR!!! Ingrese un valor mayor a 0 o 0 si quiere salir de compras");
							}
							printf("\nCuantas unidades desea comprar?: ");
							scanf("%i",&cant_comprada);
						}while(cant_comprada<0);
						cantidad_producto[cod_de_producto]=cantidad_producto[cod_de_producto]+cant_comprada;
						compra=cant_comprada*p_prod_proveedor[i];
						cantidad_de_compras++;
						
					}					
				}
				getch();
				system("cls");
				break;
				
		}//cierra switch
		total_ventas=total_ventas+venta;
		total_compras=total_compras+compra;
		opcion=funcion_opcion();
	}//cierra while opcion
}//cierra main
// INICIO DE FUNCIONES
int funcion_opcion(){
	int opcion,i=0;
	do{
			system("cls");
			if(i==0){
				i=1;
			}
			else{
				printf("ERROR!!! Ingrese una opcion valida");
				getch();
				system("cls");
			}			
			printf("Ingrese la opcion deseada\n");
			printf("--------------------------------------\n");
			printf("1-Ventas\n");
			printf("2-Proveedores\n");
			printf("3-Articulos\n");
			printf("4-Mostrar facturacion y gastos\n");
			printf("5-Compras\n");
			printf("0-Salir\n");
			printf("Opcion: ");
			scanf("%i",&opcion);
		}while((opcion<0)||(opcion>5));
	return opcion;
}//fin funcion opcion

int validar_codigo(){
	int cod_de_producto;	
	printf("\nIngrese codigo de producto: ");
	scanf("%i",&cod_de_producto);
	while((cod_de_producto<1)||(cod_de_producto>5)){
		system("cls");
		printf("ERROR!!! Ingrese un codigo de articulo valido");
		printf("\nIngrese codigo de producto: ");
		scanf("%i",&cod_de_producto);	
	}
	return cod_de_producto;
}//fin funcion validar
