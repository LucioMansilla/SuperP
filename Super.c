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

/* ACTIVIDAD 8 */
#define CARGAR_ARCHIVO 1
#define MOSTRAR_PRODUCTOS 2
#define VENDER_C 3
#define INFORME_CLIENTE 4
#define INFORME_TOTAL 5
#define INFORME_STOCK 6
#define EXIT 9 

//ESTRUCTURAS
typedef struct TEmpleado{ 
    char nombre[100]; 
    char apellido[100]; 
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

/* ACTIVIDAD 8 */
struct TProductos{
    int precio;
    char Descripcion[80];
    int stock;
    int NumeroArticulo;
    int contador;
};

struct TClientes{
    int NumeroCliente;
    int cantGastada;
    int cantCompras;
};

struct TStock{
    int NumeroCliente;
    int NumeroArticulo;
    int unidadesFaltante;
};


// RECURSIÓN ESTRUCTURAL : creación de objetos ( DOBLETES ) que responden a una misma definición
typedef struct snodo{ 
    TEmpleado info; 
    struct snodo *Next; 

}TNodo;

typedef TNodo *PunteroaTnodo; //La razón de esta linea es para una mejor comprensión del código, al crear un tipo puntero a TNodo

//PROTOTIPADO DE ACCIONES/FUNCIONES GENERICAS
int Pregunta();
int Pregunta2();
void MostrarTXT(char ENUNCIADO[]);

//ACTIVIDADES
void PrimerActividad();
void Actividad2();
void Actividad3();
void Actividad4();
void Actividad5();
void Actividad6();
void Actividad7();
void Actividad8();

//FUNCIONES /ACCIONES ACTIVIDAD 06
void CrearFicticio(PunteroaTnodo *listaC);
void Inicializar(PunteroaTnodo *listaC);
bool estaVacia(PunteroaTnodo listaC);
void cargaremp(TEmpleado *registro);
void InsertarC(PunteroaTnodo listaC, TEmpleado registro);
void VaciarL(PunteroaTnodo *listaC);
void InsertarPos (PunteroaTnodo *listaC);
void EliminarPos(PunteroaTnodo listaC);
int Buscar(PunteroaTnodo lista, char nom[30]);
void MuestraReg (PunteroaTnodo listaC, int pos);
void Mostrar(PunteroaTnodo q);

//ACCIONES ACTIVIDAD 07
void Alta(FILE *FP, char nomArchivo[]);
void Baja(FILE *FP, char nomArch[], char nombreBajar[]);
void Modificar(FILE *FP, char nomArch[], char apellido[]);
void CalcularSueldo(FILE *FP, char nomArch[], int convenio);
void Listar(FILE *FP, char nomArch[]);

//ACCIONES ACTIVIDAD 08
void CargarProductos(char PRODUCTOS[]);
bool ExistenciaCliente(char CLIENTES[],int auxCliente);
void MostrarProductos(char PRODUCTOS[]);
int LEE_CONTROL(char PRODUCTOS[], char CLIENTES[]);
void GenerarFaltaStock(int auxCliente, int nroArticulo);
void MostrarStockFaltante(char FALTASTOCK[]);
void InformarCC(char CLIENTES[]);
void InfoClienteParticular(char CLIENTES[]);
void InicializarClientes(char CLIENTES[], int auxCliente);


//FUNCION MAIN
int main(void){
//DECLARACION VARIABLES
int opcion, ok;

    //COMIENZO
printf("\nBienvenido -> ");
printf("Ingrese una opcion: \n");
printf("""----------PROGRAMAS NIVEL INICIACION----------""");
printf("""\n1) HolaProfe!\n2) Calculo de Cesped\n3) Punto fuera o dentro \n4) Taxi \n5) Importe del Club?\n""");
printf("\n----------PROGRAMAS NIVEL INTEGRADOR----------");
printf("\n6) Listas Enlazadas con punteros");
printf("\n7) Memoria persistente con BD local (archivos binarios) ");
printf("\n8) Fichero almacenamiento en dispositivo secundario (archivos binarios) ");


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
            Actividad3();
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
            Actividad4();
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
    break;

    case 7:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO7.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad7();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad7.txt"); 
        }else{
            MostrarTXT("./CODIGOS/CODIGO7.txt");
        }
      break; 

    case 8:
        MostrarTXT("./ENUNCIADOS/ENUNCIADO8.txt");
        ok = Pregunta();
        if(ok == 1){
            Actividad8();
        }else if(ok == 2){
            MostrarTXT("./PSEUDOCODIGOS/Actividad8.txt");
        }else{
            MostrarTXT("./CODIGOS/CODIGO8.txt");
        }
    break; 

    default:
    break;


    system("PAUSE");
    return 0;
}

}

int Pregunta(){

    int Opcion;
    printf("\n");
    printf("\n1-Ejecutar\t2-Ver Pseudocodigo\t3-Ver Codigo");
    printf("\n\nSu respuesta: ");
    scanf("%i",&Opcion);

    return Opcion;
}


int Pregunta2(){

    int Opcion;

    printf("\t1-Volver al Menu Principal\t2-Salir");
    printf("\nSu respuesta: ");
    scanf("%i",&Opcion);

}


void PrimerActividad(){
    printf("\nHola profe!, Complete mi primer actividad");
}


void Actividad2(){

    float ladoPlaza,areaChampas,areaCemento,areaCuadrado,areaTriangulo;

    printf("\nIngrese el lado de la plaza: ");
    scanf("%f",&ladoPlaza);

    areaTriangulo = ( (ladoPlaza / 2 ) * (ladoPlaza/2) ) / 2;
    areaChampas = areaTriangulo * 4;

    areaCuadrado = ladoPlaza * ladoPlaza;

    areaCemento = areaCuadrado - areaChampas;

    printf("\nEl area de champas es %f",areaChampas);
    printf("\nEl area de cemento es %f",areaCemento);

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

    printf("\nIngrese la coordenada x del punto: ");
    scanf("%f",&xCirculo);

    printf("\nIngrese la coordenada y del punto: ");
    scanf("%f",&yPunto);

    printf("\nIngrese la coordenada x del circulo: ");
    scanf("%f",&xCirculo);

    printf("\nIngrese la coordenada y del circulo: ");
    scanf("%f",&yCirculo);

    printf("\nIngrese el radio: ");
    scanf("%f",&radio);

    distancia = sqrt(pow((xPunto - xCirculo),2) - pow((yPunto - yCirculo),2));

    if(distancia <= radio){

        printf("\nEl punto esta dentro del circulo");

    }else{

        printf("\nEl punto esta afuera del circulo");

    }


}

void Actividad4(){

float montoPagar,cantKm;

printf("\nIngrese la cantidad de kilometros registrados: ");
scanf("%f",&cantKm);

montoPagar = (cantKm * ValorKm) + BajadaBandera ;

printf("\nEl monto a pagar es %f",montoPagar);

}


void Actividad5(){
  
    float kmInicio,kmFinal,importePagar,kmNeto;
    int cantDias;

    printf("\nPorfavor ingrese los km al inicio: ");
    scanf("%f",&kmInicio);

    printf("\nPorfavor ingrese los km a su llegada: ");
    scanf("%f",&kmFinal);

    printf("\nPorfavor ingrese la cantidad de dias que utilizo el servicio: ");
    scanf("%i",&cantDias);

    kmNeto = kmFinal-kmInicio;
    importePagar = kmNeto*AlquilerporKm + cantDias*AlquilerporDia;

    printf("\nEl importe a pagar por el club es %.2f",importePagar);


}


void Actividad6(){

    //DECLARACION DE VARIABLES/TIPOS LOCALES
    int opt,pos;
    PunteroaTnodo lista;
    char nombre[30];
    TEmpleado registro;
    Inicializar(&lista);
    CrearFicticio(&lista);
    
    //MENU
    system("color B0");
    printf("===========================================================================\n");
    printf("\n");
	printf("==============================================================================================\n");
	printf("Bienvenido, ya le hemos creado su lista, (aunque esta vacia, disfrute del software!)).\n");
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
        printf("6- Insertar en una posicion determinada\n");
        printf("6- Eliminar un elemento en un posicion determinada\n");
        printf("7- Buscar un empleado en la lista\n");
        printf("8- Mostrar la lista\n");
        printf("9- Mostrar una posicion determinada\n");
        printf("10- Salir\n");
        printf("==============================================================================================\n");
        printf("SU RESPUESTA: ");
        scanf("%i",&opt);
        system("cls");

        switch(opt){
            case 1: VaciarL(&lista);
            break;
            case 2:
                    cargaremp(&registro);
                    InsertarC(lista,registro);
            break;

            case 3: estaVacia(lista);
            break;

            case 4: VaciarL(&lista);
            break;

            case 5: InsertarPos(&lista);
            break;  

            case 6: EliminarPos(lista);
            break;

            case 7: 
                    printf("Ingrese el nombre del empleado a buscar: ");
                    scanf(" %s",nombre);

                    if(Buscar(lista,nombre) != -1){
                        printf("\nEl empleado se encuentra en la posicion %i",Buscar(lista,nombre));
                    }else{
                        printf("\nEl empleado no se encuentra en la lista");
                    }
                    system ("pause");
            break;

            case 8: Mostrar(lista);
            break;

            case 9:  printf("Que posicion desea visualizar?: ");
                     scanf("%i",&pos);
                     MuestraReg(lista,pos);
            break;

            default:
            break;
        }

    }while(opt != 10);


}

/* Funcion para analizar el estado de la lista */
bool estaVacia(PunteroaTnodo listaC){
    if(listaC->Next == NULL){
         printf("Si");
        return true;
       
    }else{
        printf("No");
        return false;
        
    }
}

/*Accion encargada de inicializar la lista en NULL, (vacia)*/
void Inicializar(PunteroaTnodo *listaC){ 
    *listaC = NULL; 

}

/* Accion encargada de crear un elemento ficticio */
void CrearFicticio(PunteroaTnodo *listaC){
	
	PunteroaTnodo aux; 

	aux = malloc(sizeof(TNodo)); 
	aux->Next = *listaC; 
	*listaC = aux; 
    aux=NULL;
    free(aux);
}

void cargaremp(TEmpleado *registro){

    fflush(stdin);
    printf("Ingrese el nombre del empleado: ");
    gets(registro->nombre);

    fflush(stdin);
    printf("\nIngrese el apellido del empleado: ");
    gets(registro->apellido);
    
    printf("\nIngrese la edad del empleado: ");
    scanf("%i",&registro->edad);

    printf("\nIngrese el telefono del empleado: ");
    scanf("%i",&registro->telefono);

    fflush(stdin);
    printf("\nIngrese la direccion del empleado: ");
    gets(registro->direccion);


}

void InsertarC(PunteroaTnodo listaC, TEmpleado registro){

	PunteroaTnodo aux;

	aux = malloc(sizeof(TNodo));
	aux->info = registro;
	aux->Next = listaC->Next;
	listaC->Next = aux; 
    aux = NULL;
    free(aux);
}

void VaciarL(PunteroaTnodo *listaC){

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

	PunteroaTnodo aux, nuevo;
	int i,n;
	
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
 
	PunteroaTnodo aux, aux2;
	int i,n;

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

int Buscar(PunteroaTnodo lista, char nom[30]){

    PunteroaTnodo aux;
    int pos;
    int i;

    pos = -1;
    i = 1;

    aux = lista->Next;

    fflush(stdin);

    while (aux != NULL){
        
        if(strcmp(aux->info.nombre,nom) == 0){
            pos = i;
        }
        i ++;
        aux = aux->Next;
    }

    return pos;
    
}

void MuestraReg (PunteroaTnodo listaC, int pos){
	
	PunteroaTnodo aux,aux2;
	int i = 1;

    aux = listaC->Next;
    while(i<pos && aux->Next != NULL){
		i++;
		aux = aux->Next;
	}

    if(i == pos){
	 printf(" [%s] -> ",aux->info.nombre);
     printf(" [%s] -> ",aux->info.apellido);
     printf(" [%i] -> ",aux->info.edad);
     printf(" [%i] -> ",aux->info.telefono);
     printf(" [%s] -> ",aux->info.direccion);

    }else{
        printf("La posición no existe");
    }
    aux=NULL;
    free(aux);
}


void Mostrar(PunteroaTnodo q){ 
    
    PunteroaTnodo aux = q;
    int i = 1;

    if (q != NULL){

        while(aux->Next != NULL){
            
            MuestraReg(q,i);
            i++;
            aux = aux->Next;
        
        }
    }

    aux = NULL;
    free(aux);
} 

/* ACTIVIDAD 07 - LOGICA DE FUNCIONES/ACCIONES */

void Alta(FILE *FP, char nomArchivo[]){
    int cant;
    int i = 0;
    struct TPers reg;
    puts("Ingrese la cantidad que desee dar de alta: ");
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
    printf("\nSU RESPUESTA: ");
    scanf("%i",&opt);

    switch (opt){

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
    case 4: printf("Ingrese el monto del convenio establecido: ");
            scanf("%i",&convenio);
            CalcularSueldo(FP,"PERSONAL",convenio);
        break;
    case 5: Listar(FP,"PERSONAL");
        break;    
    default:
        break;
    }

printf("\n\n");

}while(opt != 6);
   

}

/* ACTIVIDAD 08 - LOGICA DE FUNCIONES/ACCIONES */

void CargarProductos(char PRODUCTOS[]){
remove("CLIENTES");
remove("FALTASTOCK");
FILE *FP;
    struct TProductos Pinturas;
    int I; //Para iterar 

    int cantidad;
    char nombre[20];
    printf("\n");
    printf(".:MENU DE CARGA:\n");

    printf("IDENTIFIQUESE (Nombre): ");
    scanf(" %s",nombre);
   
    printf("\nBienvenido, %s , Cuantas pinturas desea agregar?: ",nombre);
    scanf("%i",&cantidad);
    printf("\n");   
 

if((FP = fopen(PRODUCTOS,"wb"))== NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO");
    }else{

    
        for(I = 0 ; I < cantidad ; I++){
           
            fflush(stdin);
            printf("\n\n\t  NUMERO DEL ARTICULO %i: ",I);
            scanf("%i",&Pinturas.NumeroArticulo); 
            fflush(stdin);

            printf("\n\n\t  DESCRIPCION: ");
            gets(Pinturas.Descripcion);
            fflush(stdin);

            printf("\n\n\t  STOCK: ");
            scanf("%i",&Pinturas.stock);
            fflush(stdin);

            printf("\n\n\t  PRECIO: "); 
            scanf("%i",&Pinturas.precio);
            fflush(stdin);

            fwrite(&Pinturas,sizeof(Pinturas),1,FP);
    }

    }

    fclose(FP);
}



void MostrarProductos(char PRODUCTOS[]){

FILE *FP;
struct TProductos Pinturas;

if((FP = fopen(PRODUCTOS,"rb")) == NULL){

        printf("\n\n ERROR APERTURA DE ARCHIVO");
}else{

    printf("==== LISTADO DE PINTURAS ====\n\n");
    printf("\n\n\t %-20s %15s %15s\n\n","DESCRIPCION","ARTICULO","CANT UNIDADES");
    fread(&Pinturas,sizeof(Pinturas),1,FP);

    while(! feof(FP)){
   
        printf("\n\n\t %-20s %12i \t\t%i",
        Pinturas.Descripcion,
        Pinturas.NumeroArticulo,
        Pinturas.stock);
        fread(&Pinturas,sizeof(Pinturas),1,FP);
       
    }

    fclose(FP);
}
}


int LEE_CONTROL(char PRODUCTOS[], char CLIENTES[]){
    struct TClientes Cliente;
    struct TProductos Pinturas;
    FILE *FP;
    int cant,auxCliente,nroArticulo,cont=0;
    int ok = 0;
   MostrarProductos(PRODUCTOS);
   do{
    printf("\n==== SECCION VENTAS ====\n");
    printf("\n\t COMPRA %i",cont+1);
    printf("\n\n\tIngrese el numero de cliente: ");
    scanf("%i",&auxCliente);
    if(auxCliente > 0  && auxCliente < 100){
        
        if(ExistenciaCliente(CLIENTES,auxCliente) == false){
            printf("\nEl cliente no se ha encontrado en la base de Datos, se creará uno nuevo\n");
            InicializarClientes(CLIENTES,auxCliente);
        } 
    
    printf("Ingrese el articulo a vender: ");
    scanf("%i",&nroArticulo);
    printf("Ingrese la cantidad de unidades a vender: ");
    scanf("%i",&cant);

    int auxPrecio;
    if((FP = fopen("PINTURAS","r+b"))== NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO");
    };

    fread(&Pinturas, sizeof(Pinturas),1,FP);
    
    while(!feof(FP) && ok == 0){

        if(Pinturas.NumeroArticulo == nroArticulo){
            if(Pinturas.stock >= cant){
        Pinturas.stock = (Pinturas.stock - cant);
        auxPrecio = Pinturas.precio;
        fseek(FP, (-1*sizeof(Pinturas)),1);
        fwrite(&Pinturas,sizeof(Pinturas),1,FP);
        fseek(FP, 0L,1);
        
        ok = 1;
            }else{
                 printf("--> Falta Stock<-- ");
                 printf("\n\n");
                 GenerarFaltaStock(auxCliente,nroArticulo);
                  
            }
        }
        
        fread(&Pinturas,sizeof(Pinturas),1,FP);
    }
    fclose(FP);


    if(ok == 1){
       ok = 0;    
    
    if((FP = fopen("CLIENTES","r+b"))== NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO");
    };
    
    fread(&Cliente, sizeof(Cliente),1,FP);
    
    while(!feof(FP) && ok == 0){

        if(Cliente.NumeroCliente == auxCliente){
        Cliente.cantCompras = Cliente.cantCompras + 1;
        Cliente.cantGastada = Cliente.cantGastada + auxPrecio*cant;
        fseek(FP, (-1*sizeof(Cliente)),1);
        fwrite(&Cliente,sizeof(Cliente),1,FP);
        fseek(FP, 0L,1);
        ok = 1;
        }
        
        fread(&Cliente,sizeof(Cliente),1,FP);
    }
    cont = cont +1;
    fclose(FP);
    }  
     };
 printf("\n\n\n");
}while(auxCliente != -1);
   
}


void GenerarFaltaStock(int auxCliente, int nroArticulo){
    struct TStock Stock;
                FILE *QP;
                if((QP = fopen("FALTASTOCK","ab"))== NULL){
                    printf("\n\n ERROR APERTURA DE ARCHIVO");
                };
                        Stock.NumeroCliente = auxCliente;
                        Stock.NumeroArticulo = nroArticulo;
                        fwrite(&Stock,sizeof(Stock),1,QP);
                fclose(QP);
}


void MostrarStockFaltante(char FALTASTOCK[]){

FILE *FP;
struct TStock Stock;

  if((FP = fopen(FALTASTOCK,"rb")) == NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO");
    }else{

    printf("\n\n\t %-20s %15s\n\n","CLIENTE","ARTICULO");
    fread(&Stock,sizeof(Stock),1,FP);

    while(! feof(FP)){
   
        printf("\n\n\t %-20i %12i",
        Stock.NumeroCliente,
        Stock.NumeroArticulo);
        fread(&Stock,sizeof(Stock),1,FP);
    }
    }
    fclose(FP);

}


void InformarCC(char CLIENTES[]){
    struct TClientes Cliente;
    FILE *FP;
    int auxC = 0;
    int auxNumArt,verificarMaximo=0;
  if((FP = fopen("CLIENTES","rb"))== NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO");
    }else{

    printf("\n\n\t %-20s %15s %15s\n\n","CLIENTE","MONTO","CANT COMPRAS");
    fread(&Cliente,sizeof(Cliente),1,FP);

    while(! feof(FP)){
        
        if(Cliente.cantCompras != 0){
        printf("\n\n\t %-20i %12i \t\t%i",
        Cliente.NumeroCliente,
        Cliente.cantGastada,
        Cliente.cantCompras);
        if(Cliente.cantCompras > auxC){
             if(Cliente.cantCompras != auxC){
              
                verificarMaximo = 1;
            }
            auxC = Cliente.cantCompras;
            auxNumArt = Cliente.NumeroCliente;
           
        }
       
        }
         fread(&Cliente,sizeof(Cliente),1,FP);
    }
    }
    printf("\n-------------------------------------------------------------------------------------");
    if(verificarMaximo ==1){
    printf("\n\n\tCliente con mayor cantidad de compras %i con %i compras",auxNumArt,auxC);
    }else{
        printf("\n\n\tPor algun motivo no hemos encontrado un cliente con maximo de compras");
    }
        printf("\n-------------------------------------------------------------------------------------");

    fclose(FP);
    
}


bool ExistenciaCliente(char CLIENTES[],int auxCliente){
    FILE *FP;
    struct TClientes Cliente;
    int I;
    if((FP = fopen(CLIENTES,"rb"))== NULL){
        printf("\n\n ERROR ARCHIVO VACIO");
        I = 0;
        return false; 
    };
          
           fread(&Cliente, sizeof(Cliente),1,FP);
    
            while(!feof(FP)){
            if(Cliente.NumeroCliente == auxCliente){
                fclose(FP);
                printf("\n\nEntre\n\n");
                return true;
                
            }
            fread(&Cliente, sizeof(Cliente),1,FP);
    }

    fclose(FP);
    return false;
}


void InicializarClientes(char CLIENTES[], int auxCliente){

FILE *FP;
struct TClientes Cliente;

    if((FP = fopen(CLIENTES,"ab"))== NULL){
        printf("\n\n ERROR APERTURA DE ARCHIVO");
    };
    
            Cliente.NumeroCliente = auxCliente;
            Cliente.cantGastada = 0;
            Cliente.cantCompras = 0;
            fwrite(&Cliente,sizeof(Cliente),1,FP);
    
    fclose(FP);

}


void InfoClienteParticular(char CLIENTES[]){
    
    struct TClientes Cliente;
    FILE *FP;
    int numeroCliente;
    printf("Ingrese el numero del cliente: ");
    scanf(" %i",&numeroCliente);
    
if((FP = fopen("CLIENTES","rb"))== NULL){

    printf("\n\n ERROR APERTURA DE ARCHIVO");

}else{

    printf("\n\n\t %-20s %15s %15s\n\n","CLIENTE","FACTURA TOTAL","CANT COMPRAS");
    fread(&Cliente,sizeof(Cliente),1,FP);

    while(!feof(FP)){

        if(numeroCliente == Cliente.NumeroCliente){

        printf("\n\n\t %-20i %12i \t\t%i",
        Cliente.NumeroCliente,
        Cliente.cantGastada,
        Cliente.cantCompras);
        }

    fread(&Cliente,sizeof(Cliente),1,FP);
    
    }

}


fclose(FP);

}


void Actividad8(){

FILE *FP;
int ficticio;
if((FP = fopen("PINTURAS","rb"))== NULL){
        printf("\n\n DEBE CARGAR SUS PRODUCTOS..\n");
        CargarProductos("PINTURAS");
    }

   do{
        
        printf("\n==============================================================================================\n");
        printf("\n\t.:MENU:.");
        printf("\nSeleccione la opcion deseada: \n");
        printf("1- Cargar TIPOS DE PINTURA (Eliminara la Base de datos actual)\n");
        printf("2- Mostrar lista de productos\n");
        printf("3- Vender productos (BD se actualiza sola)\n");
        printf("4- Mostrar Cliente Particular\n");
        printf("5- Informar y Listar , CLIENTES/CANTIDAD COMPRA\n");
        printf("6- Informar los productos sin stock");
        printf("\n9- Salir\n");
        printf("==============================================================================================\n");
        printf("\nSU RESPUESTA: ");
        scanf("%i",&ficticio);
        system("cls");
        
    switch (ficticio){
       
    case CARGAR_ARCHIVO: CargarProductos("PINTURAS");
        break;
    case MOSTRAR_PRODUCTOS: MostrarProductos("PINTURAS");
        break;
    case VENDER_C: LEE_CONTROL("PINTURAS","CLIENTES");
        break;
    case INFORME_CLIENTE: InfoClienteParticular("CLIENTES");
        break;
    case INFORME_TOTAL: InformarCC("CLIENTES");
        break;
    case INFORME_STOCK: MostrarStockFaltante("FALTASTOCK");
        break;
    default:
        break;
    }

    }while(ficticio != 9);

}

