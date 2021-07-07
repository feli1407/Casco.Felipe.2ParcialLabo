#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "funciones.h"
#include "parser.h"
#include "pais.h"
#include "Controller.h"


/** \brief Carga los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPaises LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPaises)
{
    int todoOk=0;
    FILE* f = NULL;
    if(path!=NULL && pArrayListPaises!=NULL)
    {
        if((f = fopen(path, "r")) != NULL)
        {
            if(parser_PaisFromText(f, pArrayListPaises))
            {
                printf("\nSe cargaron los paises con exito!\n");
                todoOk=1;
            }
        }
        else
        {
            printf("\nEl archivo %s no se pudo encontrar.\n", path);
        }
    }
    return todoOk;
}

/** \brief Listar Paises
 *
 * \param path char*
 * \param pArrayListPaises LinkedList*
 * \return int
 *
 */
int controller_ListPaises(LinkedList* pArrayListPaises)
{
    int todoOk=0;
    ePais* auxPais;
    int auxId;
    char auxNombre[20];
    int auxvac1dosis;
    int auxvac2dosis;
    int auxsinVacunar;


    printf("***LISTA DE PAISES***");
    printf("\n  ID               Nombre     vac1dosis  vac2dosis  sinVacunar\n");
    printf("-------------------------------------------------------------------\n");
    if(pArrayListPaises!=NULL)
    {

        for(int i=0; i<ll_len(pArrayListPaises); i++)
        {
            auxPais = ll_get(pArrayListPaises,i);
            pais_getId(auxPais,&auxId);
            pais_getNombre(auxPais,auxNombre);
            pais_getvac1dosis(auxPais,&auxvac1dosis);
            pais_getvac2dosis(auxPais,&auxvac2dosis);
            pais_getsinVacunar(auxPais, &auxsinVacunar);

            printf("%4d  %20s %6d %13d %13d\n",auxId,auxNombre,auxvac1dosis,auxvac2dosis,auxsinVacunar);

        }
        todoOk=1;
    }
    return todoOk;
}


/** \brief Ordena los paises de manera descendente segun los vacunados con 1 dosis
 *
 * \param paisUno void*
 * \param paisDos void*
 * \return int
 *
 */
int ordenarPaisVac1Dosis(void* paisUno, void* paisDos)
{
    int retorno=-2;
    ePais* auxUno;
    ePais* auxDos;

    if(paisUno!=NULL && paisDos!=NULL)
    {
        auxUno=(ePais*)paisUno;
        auxDos=(ePais*)paisDos;
        if((auxUno->vac1dosis) < (auxDos->vac1dosis))
        {
            retorno=1 ;
        }
        else if((auxUno->vac1dosis) == (auxDos->vac1dosis))
        {
            retorno=0;
        }
        else if((auxUno->vac1dosis) > (auxDos->vac1dosis))
        {
            retorno=-1 ;
        }
    }

    return retorno;
}

/** \brief Recorre el linked list en busca de los paises con menos porcentaje de vacunados
 *
 * \param pArrayListPais LinkedList*
 * \return int retorna un indice del pais con menos vacunados despues de haber impreso en pantalla los nombres de estos paises
 *
 */
int controller_PaisMenosVacunados(LinkedList* pArrayListPais)
{
    ePais* auxPais;
    int indice=-1;
    int menosVacunados=0;
    if(pArrayListPais!=NULL)
    {
         for(int i=0; i<ll_len(pArrayListPais); i++)
         {
             auxPais = ll_get(pArrayListPais,i);
             if(auxPais->sinVacunar > menosVacunados)
             {
                 menosVacunados=auxPais->sinVacunar;
                 indice=i;
             }

         }
         printf("Pais con menos vacunados: \n");
         for(int i=0; i<ll_len(pArrayListPais); i++)
         {
             auxPais = ll_get(pArrayListPais,i);
             if(auxPais->sinVacunar == menosVacunados)
             {
                 printf("-%s\n",auxPais->nombre);
                 indice=i;
             }

         }
    }
    return indice;
}

/** \brief Ordenamiento por nivel de vacunacion 1 dosis descendiente
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_sortPais(LinkedList* pArrayListPais)
{
    int retorno=-1;

    if(pArrayListPais!=NULL)
    {
        printf("Ordenamiento por nivel de vacunacion 1 dosis descendiente\n");

        ll_sort(pArrayListPais,ordenarPaisVac1Dosis, 1);
        retorno = 0;

    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPais)
{
    FILE* f;
    ePais* auxPais;
    int auxId;
    char auxNombre[20];
    int auxvac1dosis;
    int auxvac2dosis;
    int auxsinVacunar;
    int todoOk=0;
    int len;

    if(pArrayListPais!=NULL && path!=NULL)
    {

        len=ll_len(pArrayListPais);
        f=fopen(path,"w");
        fprintf(f,"id,nombre,vac1dosis,vac2dosis,sinVacunar\n");

        for(int i=0; i<len; i++)
        {
            auxPais=(ePais*)ll_get(pArrayListPais,i);

            pais_getId(auxPais,&auxId);
            pais_getNombre(auxPais,auxNombre);
            pais_getvac1dosis(auxPais,&auxvac1dosis);
            pais_getvac2dosis(auxPais,&auxvac2dosis);
            pais_getsinVacunar(auxPais, &auxsinVacunar);

            fprintf(f,"%d,%s,%d,%d,%d\n",auxId,auxNombre,auxvac1dosis,auxvac2dosis,auxsinVacunar);
        }
        printf("Se guardaron los paises con exito!\n");
        todoOk=1;
        fclose(f);
    }

    return todoOk;
}
