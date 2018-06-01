#include <stdio.h>
#include <stdlib.h>
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
void cargarpeliculas(EMovie movie)
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


       cant = fread(&movie,sizeof(EMovie),1,f);

       if(cant!=1)
       {
           break;
       }


    }
    fclose(f);
}
void generarPagina(EMovie lista[])
{
    FILE* f;
    f = fopen("peliculas.html","r");
    if(f == NULL){
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
}
