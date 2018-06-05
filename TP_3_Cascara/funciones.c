#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
void inicializarestados(EMovie movie[])
{
    for(int i=0;i<3;i++)
    {
        movie[i].estados=0;
    }

}
int buscarlibre(EMovie movie[])
{
    int indice=-1;
    for(int i=0;i<3;i++)
    {
        if(movie[i].estados==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int agregarPelicula(EMovie movie[])
{
    EMovie unapelicula;
    int lugar;
    lugar=buscarlibre(movie);
    if(lugar==-1)
    {
        printf("no hay capacidad");
    }
    else
    {
        printf("ingrese titulo:");
        fflush(stdin);
        gets(movie[lugar].titulo);
        printf("ingrese genero:");
        fflush(stdin);
        gets(movie[lugar].genero);
        printf("ingrese duracion:");
        fflush(stdin);
        scanf("%d",&movie[lugar].duracion);
        printf("ingrese descripcion:");
        fflush(stdin);
        gets(movie[lugar].descripcion);
        printf("ingrese puntuacion:");
        scanf("%d",&movie[lugar].puntaje);
        printf("ingrese link de imagen:");
        fflush(stdin);
        gets(movie[lugar].linkImagen);
        movie[lugar].estados=1;

    }
}
void guardarpeliculas(EMovie movie[])
{
    FILE* f;
    f = fopen("peliculas.bin","wb");
    if(f==NULL)
    {
        printf("no se pudo crear el archivo");
    }
    for(int i=0;i<3;i++)
    {
        if(movie[i].estados==1)
        {

            fwrite((movie+i),sizeof(EMovie),1,f);
    }
    }
    fclose(f);
}
void cargarpeliculas(EMovie* movie)
{

    int cant;
    FILE* f;
    f=fopen("peliculas.bin","rb");
    if(f==NULL)
    {
        printf("no se pudo leer");
    }
    while(!feof(f))
    {

        for(int i=0;i<3;i++)
        {
       cant = fread((&movie+i),sizeof(EMovie),1,f);
        }
       /*if(cant!=1)
       {
           break;
       }*/


    }
    fclose(f);
}
void generarPagina(EMovie lista[])
{
    FILE* f;
    f = fopen("peliculas.html","w");
    if(f==NULL)
    {
        printf("no se pudo crear");
    }
    for(int i=0;i<3;i++)
    {
    fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d</li></ul><p>%s</p></article>",lista[i].linkImagen,lista[i].titulo,lista[i].genero,lista[i].puntaje,lista[i].duracion,lista[i].descripcion);
    }
    fclose(f);
}
int borrarPelicula(EMovie movie[])
{
    char auxPeli[20];
    int flagEncontro=0;
    char respuesta='n';
            fflush(stdin);
            printf("Ingrese pelicula a buscar: ");
            gets(auxPeli);


            for(int i=0; i<3; i++)
            {
                if(strcmp(movie[i].titulo,auxPeli)==0)
                {
                    if(movie[i].estados==1)
                    {
                    printf("%s\t%s\t%d\t%s\t%d\t%s\n",movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion,movie[i].puntaje,movie[i].linkImagen);

                    printf("Esta seguro de eliminar? : \n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        movie[i].estados = -1;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!\n");
                    }
                    flagEncontro=1;
                    break;
                }
                }

            }
            if(flagEncontro==0)
            {
                printf("pelicula inexistente\n");
            }
            flagEncontro=0;
}
int modificarPelicula(EMovie movie[])
{
    char auxPeli[20];
    int flagEncontro=0;
    char respuesta='n';
    int auxpuntaje;
            fflush(stdin);
            printf("Ingrese pelicula a buscar: ");
            gets(auxPeli);


            for(int i=0; i<3; i++)
            {
                if(strcmp(movie[i].titulo,auxPeli)==0)
                {
                    if(movie[i].estados==1)
                    {
                     printf("%s\t%s\t%d\t%s\t%d\t%s\n",movie[i].titulo, movie[i].genero, movie[i].duracion, movie[i].descripcion,movie[i].puntaje,movie[i].linkImagen);
                    printf("ingrese puntaje a modificar\n");
                    scanf("%d",&auxpuntaje);
                    printf("Esta seguro de modificar? : \n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        movie[i].puntaje = auxpuntaje;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!\n");
                    }
                    flagEncontro=1;
                    break;
                }
                }

            }
            if(flagEncontro==0)
            {
                printf("pelicula inexistente\n");
            }
            flagEncontro=0;
                }

