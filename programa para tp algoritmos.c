#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <locale.h>



void encabezado(){
	
	printf("\n====================================================\n\n");
	printf("EL KIOSKITO DE LA UNO\n\n");
	printf("CUIT 30-23456789-5\n\n");
	printf("TELEFONO: 0220 4965878\n\n");
	printf("EMAIL: el_kioskito@gmail.com\n\n");
	printf("DIRECCION: renan 1190\n\n");
	struct tm *outtime;
   time_t hora;
   time(&hora);
   outtime=localtime(&hora);
 
   printf("%.19s \n", asctime(outtime));
 
 
	printf("====================================================");
}

 main (){
	
	const char usuario [15]="admin";
	const char clave [15]="1234";
	char usuario_u[15];
	char clave_u [15];
	int intentos=0;
	int correcta=0;
	int n_opcion;
	setlocale (LC_ALL, "spanish");
	
	
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
			
		}
		
		}
		while (intentos<3 && correcta==0);
				
	
	
	if (correcta=1 && intentos<3){
		system ("cls");
		encabezado();
		system("color 6");
		printf("\n\n\t\t BIENVENIDO AL SISTEMA\n ");
		printf("\n\t\t MENU "); 
		printf("\n1-VENTAS\n2-COMPRAS\n3-STOCK\n4-PROVEEDORES\n\n0-SALIR");
	}
	else  {
		system("cls");
		printf("Ha superado cantidad maxima de intentos\n");
		system("pause");
		exit(0);
	}
	
	printf("\n\n Ingrese el numero que corresponda a la opcion deseada:\n ");
	scanf("%i", & n_opcion);
	
	switch(n_opcion){
		
		case 0:
				printf("SALIR");
		break;
		case 1: 
		system("cls");
		system("color 4");
		encabezado();
			printf("VENTAS");
		break;
		
		case 2:
				printf("COMPRAS");
		break;
		
		case 3:
				printf("STOCK");
		break;
		
		case 4:
				printf("PROVEEDORES");
				
		break;
		
		default:
				printf("INGRESE OPCION VALIDA");
		
			
			
		
	}
	
	getch();
	return 0;
	
	
	
	
}
