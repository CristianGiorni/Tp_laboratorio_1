#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define  TAM 2

int main()
{
    EPersona lista[100];
    char seguir='s';
    int opcion=0;

    validarEstado(lista, TAM);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                AgregarPersona(lista , TAM);
                buscarespacio(lista, TAM);

                break;
            case 2:
                bajaPersona(lista, TAM);
                break;
            case 3:
                OrdenarPersonas(lista, TAM);
                mostrarpersonas(lista, TAM);
                break;
            case 4:
                /*for(int i=0;i<TAM,i++)
                {
                    grafico(lista[i].edad,lista[i].edad,lista[i].edad);
                }*/
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
