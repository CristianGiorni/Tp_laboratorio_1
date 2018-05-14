#include "funciones.h"
void validarEstado(EPersona lista[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        lista[i].estado = 0;
    }
}
void AgregarPersona(EPersona lista[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("ingrese un nombre:");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("ingrese edad:");
        scanf("%d",&lista[i].edad);
        printf("ingrese DNI:");
        scanf("%d",&lista[i].dni);
        lista[i].estado=1;
    }
}
void bajaPersona(EPersona lista[], int tam)
{
    int auxDni;
    int flagEncontro=0;
    char respuesta;
    printf("Ingrese DNI a buscar: \n");
            scanf("%d", &auxDni);


            for(int i=0; i<tam; i++)
            {
                if(lista[i].dni == auxDni)
                {
                    printf("%s\t%d\t%d\n",lista[i].nombre, lista[i].edad, lista[i].dni);

                    printf("Esta seguro de eliminar? : \n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        lista[i].estado = -1;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!\n");
                    }
                    flagEncontro=1;
                    break;
                }


            }
            if(flagEncontro==0)
            {
                printf("DNI inexistente\n");
            }
}
void OrdenarPersonas(EPersona lista[], int tam)
{
    EPersona aux;

    for(int i=0;i<tam-1;i++)
    {
         if(lista[i].estado==1)
    {
        for(int j=i+1;i<tam;i++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)<0);
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    }
}
void mostrarPersona(EPersona lista)
{
  printf("nombre:%s--edad:%d--dni:%d--\n", lista.nombre, lista.edad, lista.dni);
}
void mostrarpersonas(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        mostrarPersona(lista[i]);
    }

}
void buscarespacio(EPersona lista[], int tam)
{
    int flag = 0;
    for(int i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
            flag = 1;
        }
        if(flag == 1)
            {
            printf("no hay espacio\n");
            }
    }
}
/*int graficos(int rango1, int rango2, int rango3)
{

    int mayor,min,neu = calcularmayor(rango1,rango2,rango3);
    int i,j;
    char matriz[mayor][3];
    for (int j=0; j<mayor;j++)
    {
        for(int i=0;i<3;j++)
        {
            switch(i)
            {
            case 0:
                if(rango1>j)
                {
                    matriz[j][i]='*';
                }
                else
                {
                    matriz[j][i]='';
                }
                break;
                case 1:
                if(rango2>j)
                {
                    matriz[j][i]='*';
                }
                else
                {
                    matriz[j][i]='';
                }
                break;
                case 2:
                if(rango3>j)
                {
                    matriz[j][i]='*';
                }
                else
                {
                    matriz[j][i]='';
                }
                break;
            }
        }
    }
    for(j=mayor-1;j>=0;j--)
    {
        printf("%c  %c  %c  \n",matriz[j][0],matriz[j][1],matriz[j][2]);
    }
}
int calcularmayor(int x,int y, int z)
{
    int mayor;
    int min;
    int neu;
    if(x<18)
    {
        min=x;
    }
    else if(y>19 && y<35)
    {
        neu =y;
    }
    else
    {
        mayor = z;
    }
}*/
