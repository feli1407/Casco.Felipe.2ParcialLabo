#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "pais.h"
#include "Controller.h"
#include "LinkedList.h"

int main()
{
    int option = 0;
    int flag = 0;

    char nombreDelArchivo[30];
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesExitosos = ll_newLinkedList();
    LinkedList* listaPaisesEnElHorno = ll_newLinkedList();
    srand(time(NULL));

    ePais* auxPais;
    int indicePaisMenosVacunados;

    do
    {
        option=menu();
        switch(option)
        {
        case 1:
            do
            {
                printf("Ingrese el nombre del archivo de texto: ");
                myGets(nombreDelArchivo,sizeof(nombreDelArchivo));
            }
            while(controller_loadFromText(nombreDelArchivo,listaPaises)!= 1);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                controller_ListPaises(listaPaises);
            }
            else
            {
                printf("Primero debe cargar los paises con la opcion 1.\n");
            }
            break;
        case 3:
            if(flag == 1)
            {
                ll_map(listaPaises,asignarStats);
                printf("Se aplico asignaron las estadisticas a la lista.\n");
            }
            else
            {
                printf("Primero debe cargar los paises con la opcion 1.\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
               listaPaisesExitosos=ll_filter(listaPaises,filtrarPaisesExitosos);
               controller_saveAsText("paisesexitosos.csv",listaPaisesExitosos);
               printf("Se filtraron los paises exitosos y se guardaron en un archivo de texto.\n");
            }
            else
            {
                printf("Primero debe cargar los paises con la opcion 1.\n");
            }
            break;
        case 5:
            if(flag == 1)
            {
               listaPaisesEnElHorno=ll_filter(listaPaises,filtrarPaisesEnElHorno);
               controller_saveAsText("paisesenelhorno.csv",listaPaisesEnElHorno);
               printf("Se filtraron los paises en el horno y se guardaron en un archivo de texto.\n");
            }
            else
            {
                printf("Primero debe cargar los paises con la opcion 1.\n");
            }
            break;
        case 6:
            if(flag == 1)
            {
                 controller_sortPais(listaPaises);
                 controller_ListPaises(listaPaises);

            }
            else
            {
                printf("Primero debe cargar los paises con la opcion 1.\n");
            }
            break;
        case 7:
            if(flag == 1)
            {
                indicePaisMenosVacunados = controller_PaisMenosVacunados(listaPaises);
                auxPais = ll_get(listaPaises,indicePaisMenosVacunados);
                printf("Con %d por ciento de poblacion no vacunada.\n", auxPais->sinVacunar);
            }
            else
            {
                printf("Primero debe cargar los paises con la opcion 1.\n");
            }
            break;
        default:
            if (option!=8)
            {
                printf("Error, elija una opcion valida entre el 1 y el 8\n");
            }
            break;
        }
        system("pause");
        system("cls");
    }
    while(option != 8);
    return 0;
}
