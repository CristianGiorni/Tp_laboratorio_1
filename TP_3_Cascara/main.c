#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    EMovie pelicula[3];

    inicializarestados(pelicula);
    cargarpeliculas(*pelicula);
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(pelicula);
                break;
            case 2:

                break;
            case 3:
               break;
            case 4:
                generarPagina(pelicula);
                break;
            case 5:
                guardarpeliculas(pelicula);
                 seguir = 'n';
                break;
        }
    }

    return 0;
}
