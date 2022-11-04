/*
Algoritmo que permite ordenar datos leidos desde un archivo .txt, calcular el tiempo de ejecución y los ordena mediante:
*Ordenamiento burbuja
*Ordenamiento de selección
*Ordenamiento de inserción 
*/

//Librerias a usar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipo de funciones
void escribirP();
int leerP();
int menu();
int ordB();
int ordS();
int ordI();
int menu2();

//Funcio principal
int main(){
	
	int *m1,b;
	b = menu(m1);
	
	//Condicionales para terminar el programa
	if(b==2){
		return 0;
	}
	b=menu2(m1);
	if(b==5){
		return 0;
	}
	
	printf("El programa ha finalizado");
	return 0;
}

//Funcion para presentar el primer menu
int menu(int *m1){
	int n=0,b=0;
	//Menu basico
	do{
		printf("                  MENU\n");
		printf("1. Obtener las edades mediante la lectura de un archivo .txt \n");
		printf("2. Salir\n");
		scanf("%d",&b);
		fflush(stdin);
		system("cls");
	}while(b<1 || b>2);
	
	
	
	if(b==1){
		//Llamar a la funcion que leera un archivo de texto con las edades
		leerP(m1);		
	}	
	if(b==2){
		printf("El programa ha finalizado");
		return b;
	}	
}
//Menu secundario para elegir el metodo de ordenamiento deseado
int menu2(int *m1, int cont){
	int b=0;
	do{
		printf("                  MENU SECUNDARIO\n");
		printf("Selecciona el ordenamiento a desear\n");
		printf("1. Ordenamiento Burbuja\n");
		printf("2. Ordenamiento por Selección\n");
		printf("3. Ordenamiento por Inserción\n");
		printf("4. Imprimir edades sin ordenar\n");
		printf("5. Salir\n");
		scanf("%d",&b);
		fflush(stdin);
		system("cls");
	}while(b<1 || b>5);
	
	if(b==1){
		//Llamar al burbuja
		system("cls");
		ordB(m1,cont);		
	}	
	if(b==2){
		//Llamar al de selección
		system("cls");
		ordS(m1,cont);
	}	
	if(b==3){
		//Llamar al de inserción
		system("cls");
		ordI(m1,cont);
	}
	if(b==4){
		//Visualizar las edades sin ordenar
		system("cls");
		printf("\nLas edades sin ordenar son:\n ");
		for(int x=0; x<cont-1; x++){
			printf("\nEdad %d: %d\n",x+1,m1[x]);
		}
		menu2(m1,cont);
	}	
	if(b==5){
		//Cerrar el programa
		printf("El programa ha finalizado");
		return b;
	}
	
}

int leerP(int *m1){
	//Definir variables, arreglos y punteros a usar
	int cont=0,i=0,c=0;
	FILE *archivo;
	char dir[100],temp[100],caracter,car;
	//Preguntarle al usuario la ruta del archivo y asignarla a un arreglo de caracteres
	printf("Escribe la ruta del archivo que deseas leer o el nombre del archivo (si el ejecutable esta en la misma carpeta)\n");
	scanf("%[^\n]",dir);
	//Abrir el archivo en modo lectura
	archivo = fopen(dir,"rb");
	//Uso de condicional doble para evaluar si el puntero apunta a una direccion de memoria
	if (archivo == NULL){
		system("cls");
		printf("\nError de apertura del archivo. \n\n");
		return main();
	}
	else{
		//Leer el archivo
		printf("Las edades que contiene el archivo son: \n\n");
		//Uso de la funcion rewind para llevar el puntero al inicio del archivo
		rewind(archivo);
		
		while(!feof(archivo)){
			fgets(temp,100,archivo);
			cont++;
		}
		//Uso de la funcion malloc para determinar el tamaño del arreglo estructurado
		m1=(int*) malloc(cont*sizeof(int));
		rewind(archivo);
		;
		//Leer los datos del archivo y asignarlos a el arerglo estructurado
		printf("%c",'\n');
		while(fscanf(archivo,"%d", &m1[c])==1){
			c++;	
		}
	//Cerrar archivo	
	fclose(archivo);	
	}	
	//Llamar a las funciones
	escribirP(m1,cont);	
	
}

//Funcion para escribir en un archivo de texto todos los puntos existentes
void escribirP(int *m1,int n){
	int x=0;
	FILE *fichero;
	//Abrir y escribir en un archivo de texto
	fichero=fopen("edades.txt","w");
	
	fprintf (fichero,"%s","          Edades añadidas\n");
	//Uso de un iterador para escribir todos los puntos del arreglo estructurado en el archivo
	while(x<n-1){
			fprintf (fichero,"%c",'\n');
			fprintf (fichero,"Edad %d: %d %c",x+1,m1[x],'\n');
			
			x++;
	}
	//Cerrar archivo
	fclose(fichero);
	system("cls");
  	printf ("Se creo un archivo de texto con todas las edades \n\n");	
	menu2(m1,n);
  	
}

//Funcion que permite el ordenamiento burbuja
int ordB(int *m1,int n){
	//Defino otro arreglo estructurado para no cambiar el principal 
	int i=0,j=0,aux=0,z=0,*m2,x=0,cont=0;
	cont = n-1;
	//Funcion para calcular el tiempo de ejecución
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	
	//Uso de la funcion malloc para determinar el tamaño del arreglo estructurado
	m2=(int*) malloc(cont*sizeof(int));
	
	//Copio los valores del arreglo desordenado a un nuevo arreglo dinamico
	for(z=0;z<cont;z++){
		m2[z]=m1[z];
	}
	
	
	tiempo_inicio = clock();
 
	//Algoritmo burbuja
	
	for(i=0;i<cont;i++){
		for(j=0;j<cont;j++){
			if(m2[j] > m2[j+1]){
				aux = m2[j];
				m2[j] = m2[j+1];
				m2[j+1] = aux;
			}
		}
	}
	
	tiempo_final = clock();
	
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC; 

	
	//Mostrar en terminal las edades ordenadas
	printf("\nLas edades ordenadas mediante el algoritmo burbuja son:\n\n ");
	for(int x=0; x<cont; x++){
		printf("\nEdad %d: %d",x+1,m2[x+1]);	
	}
	printf("\nEl tiempo en segundos del ordenamiento burbuja es de: %fs\n\n",segundos);
	//llamar de nuevo al menu secundario
	menu2(m1,cont+1);
}
//Funcion que permite el ordenamiento por selección
int ordS(int *m1,int num){
	//Defino otro arreglo estructurado para no cambiar el principal 
	int i=0,j=0,aux=0,cont=0,z=0,*m3,m=0;
	cont=num-1;
	
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	
	m3=(int*) malloc(cont*sizeof(int));
	
	for(z=0;z<cont;z++){
		m3[z]=m1[z];
	}
	
	tiempo_inicio = clock();
 
	//Algoritmo de selección
	for(i=0;i<cont;i++){
		m = i;
		for(j=i+1;j<cont;j++){
			if(m3[j] < m3[m]){
				m = j;
			}
		}
		aux = m3[i];
		m3[i] = m3[m];
		m3[m] = aux;
	}
	
	tiempo_final = clock();
	
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC; 

	
	printf("\nLas edades ordenadas mediante el algoritmo de selección son:\n ");
	for(int x=0; x<cont; x++){
		printf("\nEdad %d: %d\n",x+1,m3[x]);	
	}	
	printf("\nEl tiempo en segundos del ordenamiento por seleccion es de: %fs\n\n",segundos);
	menu2(m1,cont+1);
}
//Funcion para el ordenamieto por inserción
int ordI(int *m1,int num){
	//Defino otro arreglo estructurado para no cambiar el principal 
	int i=0,aux=0,cont=0,z=0,*m4,p=0;
	cont=num-1;
	
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	
	m4=(int*) malloc(cont*sizeof(int));
	
	for(z=0;z<cont;z++){
		m4[z]=m1[z];
	}
	
	tiempo_inicio = clock();
	
	//Algoritmo de inserción
	for(i=0;i<cont;i++){
		p = i;
		aux = m4[i];
		
		while((p>0) && (m4[p-1] > aux )){
			m4[p] = m4[p-1];
			p--;
		}
		m4[p] = aux;
	}
	
	tiempo_final = clock();
	
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC; 
	
	
	printf("\nLas edades ordenadas mediante el algoritmo de inserción son:\n ");
	for(int x=0; x<cont; x++){
		printf("\nEdad %d: %d\n",x+1,m4[x]);	
	}	
	printf("\nEl tiempo en segundos del ordenamiento por inserción es de: %fs\n\n",segundos);
	menu2(m1,cont+1);
}


