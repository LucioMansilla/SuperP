//LIBRERIAS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

//CONSTANTES
#define BajadaBandera  54.24
#define ValorKm 22.50
#define AlquilerporKm 18.50
#define AlquilerporDia 1800

//ESTRUCTURAS
typedef struct TEmpleado{ 
    char nombre[100]; 
    int telefono; 
    char direccion[100]; 
    int edad; 
}TEmpleado; 


struct TPers{
    char nom[20];
    char ape[20];
    int antiguedad;
    int basico;
    int sueldofull;
    int baja;
};


typedef struct snodo{ 
    TEmpleado info; 
    struct snodo *Next; 

}TNodo;
typedef TNodo *PunteroaTnodo; //La razón de esta linea es para una mejor comprensión del código, al crear un tipo puntero a TNodo



//PROTOTIPADO DE ACCIONES/FUNCIONES
int Pregunta();
void MostrarTXT(char ENUNCIADO[]);

//ACTIVIDADES
void PrimerActividad();
void Actividad2();
void Actividad3();
void Actividad4();
void Actividad5();
void Actividad6();
void Actividad7();


//FUNCIONES /ACCIONES ACTIVIDAD 06
void CrearFicticio(PunteroaTnodo *listaC);
void Inicializar(PunteroaTnodo *listaC);
bool estavacia(PunteroaTnodo listaC);
void cargaremp(TEmpleado *registro);
void insertarC(PunteroaTnodo listaC, TEmpleado registro);
void vaciarL2(PunteroaTnodo *listaC);
void InsertarPos (PunteroaTnodo *listaC);
void EliminarPos(PunteroaTnodo listaC);
void MuestraReg (PunteroaTnodo listaC, int pos);
void Mostrar(PunteroaTnodo q);

//FUNCIONES/ACCIONES ACTIVIDAD 07
void Alta(FILE *FP, char nomArchivo[]);
void Baja(FILE *FP, char nomArch[], char nombreBajar[]);
void Modificar(FILE *FP, char nomArch[], char apellido[]);
void CalcularSueldo(FILE *FP, char nomArch[], int convenio);
void Listar(FILE *FP, char nomArch[]);


//FUNCION MAIN
int main(void){
//DECLARACION VARIABLES
int opcion, ok;

    //COMIENZO
printf("\nBienvenido -> ");
printf("Ingrese una opcion: \n");
printf("""----------PROGRAMAS NIVEL INICIADO----------""");
printf("""\n1) HolaProfe!\n2) Calculo de Cesped\n3) Punto fuera o dentro \n4) Taxi \n5) Importe del Club?\n""");
printf("\n----------PROGRAMAS NIVEL INTERMEDIO----------");
printf("\n6) Listas Enlazadas con punteros");
printf("\n7) Memoria persistente con BD local (archivos binarios) ");


printf("\n--------------------");
printf("\n Su respuesta--> ");
scanf("%i",&opcion);


switch (opcion){

    case 1:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO1.txt");
        ok = Pregunta();
        if(ok == 1){
            PrimerActividad();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad1.txt");
        }else{
            MostrarTXT("./CODIGOS/CODIGO1.txt");
            
        }
    break;

    case 2:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO2.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad2();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad2.txt");
        }else{
            MostrarTXT("./CODIGOS/CODIGO2.txt");
        }
        
    break;

    case 3:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO3.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad2();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad3.txt");
        }else{
            MostrarTXT("./CODIGOS/CODIGO3.txt");
        }
    break;
        
    case 4:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO4.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad3();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad4.txt");
        }else{
            MostrarTXT("./CODIGOS/CODIGO4.txt");
        }
    break;

    case 5:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO5.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad5();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad5.txt");
        }else{
            MostrarTXT("./CODIGOS/CODIGO5.txt");
        }
    break;

    case 6:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO6.txt");
        ok = Pregunta();
        if ( ok == 1){
            Actividad6();
        }else if ( ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad6.txt");

        }else{
            MostrarTXT("./CODIGOS/CODIGO6.txt");
        }

    case 7:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO7.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad7();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad7.txt"); //
        }else{
            MostrarTXT("./CODIGOS/CODIGO7.txt");
        }
        
default:
    break;
}


    system("PAUSE");
    return 0;
}

int Pregunta(){

    int Opcion;
    
    printf("\n1-Ejecutar\t2-Ver Pseudocodigo\t3-Ver Codigo");
    printf("\nSu respuesta: ");
    scanf("%i",&Opcion);
    return Opcion;

}


void PrimerActividad(){
    printf("\n\n Hola profe!, Complete mi primer actividad");
}


void Actividad2(){

    float ladoPlaza,areaChampas,areaCemento,areaCuadrado,areaTriangulo;

    printf("Ingrese el lado de la plaza: ");
    scanf("%f",&ladoPlaza);

    areaTriangulo = ( (ladoPlaza / 2 ) * (ladoPlaza/2) ) / 2;
    areaChampas = areaTriangulo * 4;

    areaCuadrado = ladoPlaza * ladoPlaza;

    areaCemento = areaCuadrado - areaChampas;

    printf("El area de champas es %f",areaChampas);
    printf("El area de cemento es %f",areaCemento);

}

void MostrarTXT(char ENUNCIADO[]){
    
    FILE *fp;
    char caracter;
    printf("\n\n");
    if((fp= fopen(ENUNCIADO,"r")) == NULL ){

        perror("ERROR DE APERTURA");
        exit(1);

    }else{

        while(!feof(fp)){ 

            fflush(stdin);
            
            caracter = fgetc(fp);
            putchar(caracter);

        }

}

fclose(fp);

}

void Actividad3(){

    float xCirculo,yCirculo,xPunto,yPunto,radio,distancia;

    printf("Ingrese la coordenada x del punto: ");
    scanf("%f",&xCirculo);

    printf("Ingrese la coordenada y del punto: ");
    scanf("%f",&yPunto);

    printf("Ingrese la coordenada x del circulo: ");
    scanf("%f",&xCirculo);

    printf("Ingrese la coordenada y del circulo: ");
    scanf("%f",&yCirculo);

    printf("Ingrese el radio: ");
    scanf("%f",&radio);

    distancia = sqrt(pow((xPunto - xCirculo),2) - pow((yPunto - yCirculo),2));

    if(distancia <= radio){

        printf("El punto esta dento del circulo");

    }else{

        printf("El punto esta afuera del circulo");

    }


}

void Actividad4(){

float montoPagar,cantKm;

printf("Ingrese la cantidad de kilometros registrados: ");
scanf("%f",&cantKm);

montoPagar = (cantKm * ValorKm) + BajadaBandera ;

printf("El monto a pagar es %f",montoPagar);

}


void Actividad5(){
    printf("\n AUTHOR: ByL");
    float kmInicio,kmFinal,importePagar,kmNeto;
    int cantDias;

    printf("\n\n Porfavor Ingrese  los km al inicio: ");
    scanf("%f",&kmInicio);

    printf("\n Porfavor Ingrese los km a su llegada: ");
    scanf("%f",&kmFinal);

    printf("\n Porfavor Ingrese la cantidad de Dias que utilizo el servicio: ");
    scanf("%i",&cantDias);

    kmNeto = kmFinal-kmInicio;
    importePagar = kmNeto*AlquilerporKm + cantDias*AlquilerporDia;

    printf("%.2f",importePagar);


}


void Actividad6(){
     //DECLARACION DE VARIABLES
    int opt,pos;
    PunteroaTnodo lista; 
    TEmpleado registro;
    Inicializar(&lista);
    CrearFicticio(&lista);
    
    //MENU
    system("color B0");
    printf("===========================================================================\n");
    printf("\n");
	printf("==============================================================================================\n");
	printf("Bienvenido, ya le hemos creado su lista, (aunque esta vacia :( , disfrute del software!)).\n");
	printf("==============================================================================================\n");
	printf("\n");
    system("PAUSE");

    do{
        
        system("color 0F");
        printf("\n==============================================================================================\n");
        printf("\n\t.:MENU:.");
        printf("\nSeleccione la opcion deseada: \n");
        printf("1- Crear Lista vacia NUEVA(la otra se perdera)\n");
        printf("2- Insertar un elemento a la cabeza\n");
        printf("3- Corroborar si la lista esta vacia o no\n");
        printf("4- Vaciar la lista\n");
        printf("5- Mostrar la lista\n");
        printf("6- Insertar en una posición determinada\n");
        printf("7- Eliminar un elemento en un posición determinada\n");
        printf("8- Mostrar una posición determinada\n");
        printf("9- Salir\n");
        printf("==============================================================================================\n");
        printf("SU RESPUESTA: ");
        scanf("%i",&opt);
        system("cls");
        switch(opt){
            case 1: vaciarL2(&lista);
            break;
            case 2:
                    cargaremp(&registro);
                    insertarC(lista,registro);
            break;

            case 3: estavacia(lista);
            break;

            case 4: vaciarL2(&lista);
            break;

            case 5: Mostrar(lista);
            break;  

            case 6: InsertarPos(&lista);
            break;

            case 7: EliminarPos(lista);
            break;

            case 8:  printf("Que posición desea visualizar?: ");
                     scanf("%i",&pos);
                     MuestraReg(lista,pos);
            break;
        }

    }while(opt !=9);


}


/* funcion para comprobacion del estado de la lista */
bool estavacia(PunteroaTnodo listaC){
    if(listaC->Next == NULL){
         printf("Si");
        return true;
       
    }else{
        printf("No");
        return false;
        
    }
}


/*Accion encargada de inicializar la lista en NULL, (vacia), SI ES LA ACCION QUE HACE UNA LISTA VACIA SI*/
void Inicializar(PunteroaTnodo *listaC){ //Recibe la direccion de un puntero, que cosas (esto en pseudocodigo no se puede hacer)
    *listaC = NULL; //accedo a esa direccion y asigno NULL
}



/* Accion encargada de crear un elemento ficticio, esto me sirve para insertar en la posicion que quiera, eliminar.. etc*/
void CrearFicticio(PunteroaTnodo *listaC){
	/*lexico local*/
	PunteroaTnodo aux; //declaracion de otra variable puntera a TNodo
	/*inicio*/
	aux = malloc(sizeof(TNodo)); //declaracion del doblete
	aux->Next = *listaC; // asignamos al campo next de aux la lista
	*listaC = aux; // y a lista aux donde el campo info no tiene nada
    aux=NULL;
    free(aux);
}

void cargaremp(TEmpleado *registro){
    printf("Ingrese el nombre del empleado: ");
    scanf(" %s",registro->nombre);
    printf("Ingrese el telefono del empleado(No se mostrara): ");
    scanf("%i",&registro->telefono);
}

void insertarC(PunteroaTnodo listaC, TEmpleado registro){
	PunteroaTnodo aux;
	aux = malloc(sizeof(TNodo));
	aux->info = registro;
	aux->Next = listaC->Next;
	listaC->Next = aux; 
    aux = NULL;
    free(aux);
}

void vaciarL2(PunteroaTnodo *listaC){
    if(*listaC !=NULL){

     while(*listaC != NULL){
        PunteroaTnodo aux;
        aux = *listaC;
        *listaC =  aux->Next;
        free(aux);
    }
    
    CrearFicticio(listaC);
    
    }
}


void InsertarPos (PunteroaTnodo *listaC){
	/*lexico local*/
	PunteroaTnodo aux, nuevo;
	int i,n;
	/*inicio*/
	do{
		printf("\n\tIngrese la posicion donde ingresar el nuevo elemento   ");
		scanf("%i",&n);	
	}while(n<0);
	aux = *listaC;
	i=1;
	while(i<n && aux->Next != NULL){
		i++;
		aux= aux->Next;
	}
	if(i==n){
		nuevo = malloc(sizeof(TNodo));
		TEmpleado empTemporal;
        cargaremp(&empTemporal);
        nuevo->info = empTemporal;
		nuevo->Next = aux->Next;	
		aux->Next = nuevo;	
		printf("\n\tEmpleado insertado con exito!");	
	}else{
		printf("\n\tLa posicion no existe");
	}
    aux=NULL;
    nuevo=NULL;
    free(aux);
    free(nuevo);
}



void EliminarPos(PunteroaTnodo listaC){
    /*lexico local*/
	PunteroaTnodo aux, aux2;
	int i,n;
	/*inicio*/
	do{
		printf("\n\tIngrese la posicion que desea eliminar  ");
		scanf("%i",&n);	
	}while(n<0);
	aux = listaC;
	i=1;
	while(i<n && aux->Next != NULL){
		i++;
		aux= aux->Next;
	}
	if(i==n){
		aux2 = aux->Next;	
		aux->Next = aux2->Next;	
        
        free(aux2);
		printf("\n\tEmpleado insertado con exito!");	
	}else{
		printf("\n\tLa posicion no existe");
	}
    aux=NULL;
    free(aux);
}


void MuestraReg (PunteroaTnodo listaC, int pos){
	/*lexico local*/
	PunteroaTnodo aux,aux2;
	int i = 1;
	/*inicio*/
    aux = listaC->Next;
    while(i<pos && aux->Next != NULL){
		i++;
		aux = aux->Next;
	}
    if(i == pos){
	 printf(" [%s] -> ",aux->info.nombre);
    }else{
        printf("La posición no existe");
    }
    aux=NULL;
    free(aux);
}


void Mostrar(PunteroaTnodo q){ 
    PunteroaTnodo aux = q;
    if (q != NULL){
   
    int i = 1;
    while(aux->Next != NULL){
        
          MuestraReg(q,i);
           i++;
           aux= aux->Next;
      
    }
    }
    aux = NULL;
    free(aux);
} 



void Alta(FILE *FP, char nomArchivo[]){
    int cant;
    int i = 0;
    struct TPers reg;
    puts("Ingrese la cantidad que desee  dar de alta: ");
    scanf("%i",&cant);
    if((FP = fopen(nomArchivo,"ab"))==NULL){
        perror("Error");
        exit(1);
    }else{
        while(i < cant){
            fflush(stdin);
            printf("Ingrese el nombre: ");
            scanf("%s",reg.nom);
            fflush(stdin);
            
            printf("Ingrese el ape: ");
            scanf("%s",reg.ape);
            fflush(stdin);

            printf("Ingrese la antiguedad: ");
            scanf("%i",&reg.antiguedad);

            printf("Ingrese el basico: ");
            scanf("%i",&reg.basico);
            fwrite(&reg,sizeof(reg),1,FP);
            i  = i+1;        
        }
    }
    fclose(FP);
}

void Baja(FILE *FP, char nomArch[], char nombreBajar[]){
    
    struct TPers reg;

    if((FP = fopen(nomArch,"r+b"))==NULL){
        perror("Error: " );

    }else{
        fread(&reg,sizeof(reg),1,FP);
        while(!feof(FP)){
            if((strcmp(reg.nom,nombreBajar))==0){
                printf("sdasd");
                reg.baja = 1;
                fseek(FP,(-1*sizeof(reg)),1);
                fwrite(&reg,sizeof(reg),1,FP);
                fseek(FP,0L,1);
            }
        fread(&reg,sizeof(reg),1,FP);
        }
    }
    fclose(FP);
}

void Modificar(FILE *FP, char nomArch[], char apellido[]){

    struct TPers reg;

    if ( (FP = fopen(nomArch,"r+b"))==NULL){
        perror("Error: ");
    }else{
        fread(&reg,sizeof(reg),1,FP);
        while(!feof(FP)){
            fflush(stdin);
            if ((strcmp(reg.ape, apellido))== 0){
                printf("\n Modifica el nombre: ");
                scanf("%s",reg.nom);
                fflush(stdin);

                printf("\n Modifica la antiguedad: ");
                scanf("%i",&reg.antiguedad);
                fflush(stdin);

                printf("\n Modifica el basico");
                scanf("%i",&reg.basico);
                fflush(stdin);
                fseek(FP,(-1*sizeof(reg)),1);
                fwrite(&reg,sizeof(reg),1,FP);
                fseek(FP,0L,1);
        }
        fread(&reg,sizeof(reg),1,FP);
    }


}
fclose(FP);
}

void CalcularSueldo(FILE *FP, char nomArch[], int convenio){
    struct TPers reg;

    if ( (FP = fopen(nomArch,"r+b"))==NULL){
        perror("Error: ");
    }else{
        fread(&reg,sizeof(reg),1,FP);
        while(!feof(FP)){
                fflush(stdin);
                reg.sueldofull = reg.basico + (convenio*reg.antiguedad);
                fseek(FP,(-1*sizeof(reg)),1);
                fwrite(&reg,sizeof(reg),1,FP);
                fseek(FP,0L,1);
                fread(&reg,sizeof(reg),1,FP);
             }
        }
        
    fclose(FP);
}

void Listar(FILE *FP, char nomArch[]){
    struct TPers reg;

    if ( (FP = fopen(nomArch,"r+b"))==NULL){
        perror("Error: ");
    }else{
        fread(&reg,sizeof(reg),1,FP);
        printf("\n\n");
        while(!feof(FP)){
              if(reg.baja != 1){
                  printf("\n-------------------------------------------------------\n");
                  printf("\nNombre: %s \nApellido: %s \nSueldo:  %i \nAntiguedad: %i",
                  reg.nom,
                  reg.ape,
                  reg.sueldofull,
                  reg.antiguedad);
              }
                fread(&reg,sizeof(reg),1,FP);
        }
      
    }
    printf("\n\n");
    fclose(FP);
}

void Actividad7(){
        FILE *FP;
    int convenio,opt;
    char apellido[20] = "Juan";
    char nombreAbuscar[20] = "Pablo";

do{
    printf("\n\nSELECCIONE UNA OPCION\n\n");
    printf("\n1- Dar de Alta");
    printf("\n2- Dar de Baja");
    printf("\n3- Modificar");
    printf("\n4- Calcular Sueldo");
    printf("\n5- Listar");
    printf("\n6- Salir");
    scanf("%i",&opt);

    switch (opt)
    {
    case 1: Alta(FP,"PERSONAL");
        break;

    case 2: printf("Ingrese el nombre a buscar: ");
            scanf("%s",nombreAbuscar);
            fflush(stdin);
            Baja(FP,"PERSONAL",nombreAbuscar);
        break;
    case 3:  printf("Ingrese el apellido de la persona a modificar: ");
             scanf("%s",apellido);
             fflush(stdin);
             Modificar(FP,"PERSONAL",apellido);
        break;
    case 4: CalcularSueldo(FP,"PERSONAL",convenio);
        break;
    case 5: Listar(FP,"PERSONAL");
        break;    
    default:
        break;
    }
printf("\n\n");

}while(opt != 6);
   

}