#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pais.h"

/** \brief Parsea los datos los datos de los paises desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_PaisFromText(FILE* pFile, LinkedList* pArrayListPais)
{

    int todoOk=0;
    ePais* auxPais;
    char auxId[20];
    char auxNombre[20];
    char auxvac1dosis[20];
    char auxvac2dosis[20];
    char auxsinVacunar[20];
    int validar;

    if(pFile!=NULL && pArrayListPais!=NULL)
    {

        fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxvac1dosis,auxvac2dosis,auxsinVacunar);

        do
        {
            validar=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxvac1dosis,auxvac2dosis,auxsinVacunar);
            auxPais=pais_newParametros(auxId, auxNombre, auxvac1dosis,auxvac2dosis, auxsinVacunar);
            if(auxPais!=NULL && validar==5)
            {
                ll_add(pArrayListPais,auxPais);
            }

        }
        while(!feof(pFile));

        printf("La carga de datos se realizo de manera exitosa!\n");
        todoOk=1;
    }
    else
    {
        printf("Error, el archivo no existe\n\n");
    }

    return todoOk;
}

