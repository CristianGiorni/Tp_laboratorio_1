#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int x = 0;
    int y = 0;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorial;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (%d=x)\n", x);
        printf("2- Ingresar 2do operando (%d=y)\n", y);
        printf("3- Calcular la suma (%d+%d)\n",x , y);
        printf("4- Calcular la resta (%d-%d)\n",x , y);
        printf("5- Calcular la division (%d/%d)\n", x, y);
        printf("6- Calcular la multiplicacion (%d*%d)\n",x , y);
        printf("7- Calcular el factorial (%d!)\n", x);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("ingrese un numero");
                scanf("%d",&x);
                break;
            case 2:
                 printf("ingrese otro numero");
                scanf("%d",&y);
                break;
            case 3:
                suma = Suma(x , y);
                printf("La suma de los numeros es:%d\n",suma);
                break;
            case 4:
                resta = Resta(x , y);
                printf("La resta de los numeros es:%d\n",resta);
                break;
            case 5:
                division =  Division(x , y);
                printf("La division de los numeros es:%.4f\n",division);
                break;
            case 6:
                multiplicacion = Multiplicacion(x , y);
                printf("La multimplicacion de los numeros es:%d\n",multiplicacion);
                break;
            case 7:
                factorial = Factorial(x);
                 printf("El factorial es:%d\n",factorial);
                break;
            case 8:
                printf("Todas las operaciones:\n");
                suma = Suma(x , y);
               printf("La suma de los numeros es:%d\n",suma);
               resta = Resta(x , y);
                printf("La resta:%d\n",resta);
                 division = Division(x , y);
                printf("La division:%.4f\n",division);
                 multiplicacion = Multiplicacion(x , y);
                printf("La multiplicacion:%d\n",multiplicacion);
                factorial = Factorial(x);
                printf("El factorial:%d\n",factorial);
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}


