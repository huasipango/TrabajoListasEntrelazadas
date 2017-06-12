#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct COLUMNA
{
    int dato;
    COLUMNA *sig_col;
};

struct FILA
{
    FILA *sig_fila;
  	COLUMNA *col;
};

struct MATRIZ
{
    int n_fila;
    int n_columna;
    FILA *fila;
};
//************************************************************************************************

int menu()
{
	int opc;
 	printf("\n\n\nSeleccione una opción: \n");
    printf("1. Crear matriz: \n");
    printf("2. Imprimir matriz: \n");
    printf("3. Buscar Posicion: \n");
    printf("4. Multiplicar por escalar: \n");
    printf("5. Transpuesta: \n");
    printf("6. Obtener submatriz: \n");
    printf("7. Salir: \n");
    scanf("%d", &opc);
    return opc;
}


COLUMNA *CrearColumna(MATRIZ *matriz)
{
	COLUMNA *nuevo=NULL, *anterior=NULL, *cab=NULL;
	int num=matriz->n_columna;
	for(int i=1; i<=num; i++)
    {
    	anterior=nuevo;
    	nuevo=(COLUMNA *)malloc(sizeof(COLUMNA));
	    printf("\nIngrese el valor %d :", i);
        scanf("%d", &nuevo->dato);
        nuevo->sig_col=NULL;
        fflush(stdin);
    	if(cab==NULL){
            cab=nuevo;
       	}
        else
            anterior->sig_col=nuevo;
	}
	return cab;
}

MATRIZ *CrearFila(MATRIZ *matriz)
{
	FILA *nuevo=NULL, *anterior=NULL, *cab=NULL;
	int num=matriz->n_fila;
	for(int i=1; i<=num; i++)
    {
    	anterior=nuevo;
    	nuevo=(FILA *)malloc(sizeof(FILA));
	    nuevo->col=CrearColumna(matriz);
        nuevo->sig_fila=NULL;
        fflush(stdin);
    	if(cab==NULL){
            cab=nuevo;
            matriz->fila=cab;
    	}
        else
            anterior->sig_fila=nuevo;
	}
	return (matriz);
}

MATRIZ *Crear()
{
	int fila,columna;
	MATRIZ *matriz;
	matriz=(MATRIZ *)malloc(sizeof(MATRIZ));
	do{
		printf("\n Ingrese el numero de filas");
		scanf("%d",&matriz->n_fila);
		printf("\n Ingrese el numero de columnas");
		scanf("%d",&matriz->n_columna);
		if((matriz->n_fila<1)||(matriz->n_columna<1)){
			printf("\n*** Los valores no deben ser menores de uno***");
		}
	}while((matriz->n_fila<1)||(matriz->n_columna<1));
	matriz=CrearFila(matriz);
	return (matriz);
}


//************************************************************************************************
void Listar(MATRIZ *aux)
{
    FILA *aux_fila=NULL;
    COLUMNA *aux_columna=NULL;
    aux_fila=aux->fila;
    do{
        aux_columna=aux_fila->col;
        do{
            printf ("%d \t",aux_columna->dato);
            aux_columna=aux_columna->sig_col;
        }while(aux_columna!=NULL);
        printf ("\n");
        aux_fila=aux_fila->sig_fila;
    }while(aux_fila!=NULL);
    return;    
}


//************************************************************************************************
void BuscarPosicion(MATRIZ *aux)
{
    int fila,columna,auxiliar;
    
    do{
        printf("\n Ingrese el numero de fila");
        scanf("%d",&fila);
        if((fila<1)||(aux->n_fila<fila)){
            printf("\n*** valor fuera de rangos existentes***");
        }
    }while((fila<1)||(aux->n_fila<fila));
   
     do{
        printf("\n Ingrese el numero de columna");
        scanf("%d",&columna);
        if((columna<1)||(aux->n_columna<columna)){
            printf("\n*** valor fuera de rangos existentes***");
        }
    }while((columna<1)||(aux->n_columna<columna));

    FILA *aux_fila=NULL;
    COLUMNA *aux_columna=NULL;
    aux_fila=aux->fila;
    for(int cont_f=0;cont_f<fila;cont_f++){
        aux_columna=aux_fila->col;
        for(int cont_c=0;cont_c<columna;cont_c++){
            auxiliar=aux_columna->dato;
            aux_columna=aux_columna->sig_col;
        }
        
        aux_fila=aux_fila->sig_fila;
    }
    printf ("\n*** El dato en la posicion %d , %d es: %d *****",fila,columna,auxiliar);
    return;    
}

//************************************************************************************************
void Submatriz(MATRIZ *aux)
{
    int fila,columna;
    
    do{
        printf("\n Ingrese el numero de fila");
        scanf("%d",&fila);
        if((fila<1)||(aux->n_fila<fila)){
            printf("\n*** valor fuera de rangos existentes***");
        }
    }while((fila<1)||(aux->n_fila<fila));
   
     do{
        printf("\n Ingrese el numero de columna");
        scanf("%d",&columna);
        if((columna<1)||(aux->n_columna<columna)){
            printf("\n*** valor fuera de rangos existentes***");
        }
    }while((columna<1)||(aux->n_columna<columna));

    FILA *aux_fila=NULL;
    COLUMNA *aux_columna=NULL;
    aux_fila=aux->fila;
    for(int cont_f=0;cont_f<fila;cont_f++){
        aux_columna=aux_fila->col;
        for(int cont_c=0;cont_c<columna;cont_c++){
            printf ("%d \t",aux_columna->dato);
            aux_columna=aux_columna->sig_col;
        }
        printf ("\n");
        aux_fila=aux_fila->sig_fila;
    }
    return;    
}
//************************************************************************************************
int main() 
{
	MATRIZ *matriz=NULL; 
    int opc;
 	system("clear");
    do
    {
	    do
	    {
	        opc=menu();
	        if(opc!=7){
	        	if((matriz==NULL)&&(opc!=1)){
	        	printf("No existen listas creadas\nAgregue una...\n");
				opc=9;
				}
				if((matriz!=NULL)&&(opc==1)){
		        	printf("Ya existe una lista creada..\n");
					opc=9;
				}
	        }
	        
	                
		}while((opc<1)||(opc>7));
		switch(opc)
        {
            case 1:
            	matriz=Crear();
            break;
	// opcion 2+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   
            case 2:
                system("clear");
            	Listar(matriz);
            break;
    // opcion 3+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++         
            case 3:
                system("clear");
            	BuscarPosicion(matriz);
            break;
            case 4:
            	
            break;
            case 5:
            break;
            case 6:
                system("clear");
                Submatriz(matriz);
            break;
            case 7:
                system("clear");            
            break;
    // opcion 3+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++         
        }
    }while(opc!=7);
}