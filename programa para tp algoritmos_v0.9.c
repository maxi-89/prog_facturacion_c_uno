#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <locale.h>

void stock (&cantidad_stock, int i){
		int cod_de_producto, cantidad_vendida, cantidad_comprada, opcion;
	do{
		printf("Ingrese la opcion deseada:\n");
		printf("--------------------------------------\n");
		printf("1-Venta\n");
		printf("2-Compra\n");
		printf("3-Imprimir\n");
		printf("0-Salir\n");
		printf("Opcion: ");
		scanf("%i",&opcion);
	}while((opcion<0)||(opcion>3));
	
	system("cls");		
	
	switch(opcion){
		case 0:
			printf("HASTA LUEGO");
		case 1:
			printf("VENTAS\n");
			printf("--------------------------------------\n");
			printf("ingrese codigo de producto: ");
			scanf("%i",&cod_de_producto);
			printf("ingrese cantidad vendida: ");
			scanf("%i",&cantidad_vendida);
			cantidad_stock=-cantidad_vendida;
			break;
		case 2:
			printf("COMPRAS\n");
			printf("--------------------------------------\n");
			printf("ingrese codigo de producto: ");
			scanf("%i",&cod_de_producto);
			printf("ingrese cantidad comprada: ");
			scanf("%i",&cantidad_comprada);
			cantidad_stock=+cantidad_comprada;
			break;
		case 3:
			printf("IMPRIMIR\n");
			printf("--------------------------------------\n");
			printf("Codigo del producto\t Cantidad \n");
			printf("%i\t\t%i",cod_de_producto,cantidad_stock);
			break;
	}
	
}

void provedores(){
	   int opcion_prov;
       long int cuit;
       long int telefono;
       char categoria [50];
       char  correo_electronico[50];
       char razon_social[20];
       
       printf("1- ingresar nuevo provedor\n 2 salida");
       scanf("%i", &opcion_prov);
       
       switch(opcion_prov ){
                 case 1:   
       printf("ingrese razon social\n");    
	   fflush(stdin);  
       scanf("%s", &razon_social);
       printf("ingrese cuit");
       fflush(stdin);
       scanf("%li" , &cuit);
       printf("ingrese correo electronico");
       fflush(stdin);
       scanf("%s" , &correo_electronico);
       
       printf("ingrese telefeono");
       scanf("%li" , &telefono);
       printf("ingrese categoria");       
       scanf("%s" , &categoria);                   
       break;
       case 2: 
            printf("");
            break;
       default:
               printf("opcion incorrecta");
         }
          }

void compras (){
	int opcion;
	char cat_prod [20];
	char fecha_prod [20];
	long int cant_prod;
	double precio_unidad;
	int opcion_2;
	
	printf("BIENVENIDO\n\n");
	printf("COMPRAS\n\n\n");
	
	printf("1-INGRESAR MERCADERIA\n2- SALIR\n");
	
	scanf("%d", &opcion);
	
	
	
	
	if (opcion==1){
		do {
		system("cls");
		printf("Ingrese Categoria de Producto\n");
		fflush(stdin);
		scanf("%d", &cat_prod);
		printf("Ingrese cantidad de productos\n");
		fflush(stdin);
		scanf("%d", &cant_prod);
		printf("Ingrese precio de Producto /x unidad\n");
		fflush(stdin);
		scanf("%d", &precio_unidad);
		printf("Ingrese fecha de vencimiento de Producto\n");
		fflush(stdin);
		scanf("%d", &fecha_prod);
		printf("Desea realizar la carga de otro pruducto si=1, no=2\n");
		fflush(stdin);
		scanf("%d", &opcion_2);
		
	} while (opcion_2==1);
		
	}
	
	
	else if (opcion==2){
		
		
		
	}
	
	else{
		
		printf("INGRESE UNA OPCION VALIDA");
		
	}
	
	
	
}

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
				compras();
		break;
		
		case 3:
				printf("STOCK");
				stock();
		break;
		
		case 4:
				printf("PROVEEDORES");
				provedores();
		break;
		
		default:
				printf("INGRESE OPCION VALIDA");
		
			
			
		
	}
	
	getch();
	return 0;
	
	
	
	
}
