#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;
void validarEstado(EPersona [], int);
void AgregarPersona(EPersona[], int);
void bajaPersona(EPersona [], int);
void OrdenarPersonas(EPersona [], int);
void mostrarPersona(EPersona);
void mostrarpersonas(EPersona [], int );
void buscarespacio(EPersona [], int);
//int graficos(int rango1, int rango2, int rango3);
//int calcularmayor(int x, int y, int z);
/*int obtenerEspacioLibre(EPersona lista[]);
int buscarPorDni(EPersona lista[], int dni);*/
