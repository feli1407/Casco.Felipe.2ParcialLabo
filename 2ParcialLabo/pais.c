#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include <time.h>

ePais* pais_new()
{
    ePais* nuevoPais = (ePais*) malloc(sizeof(ePais));

    if(nuevoPais!=NULL)
    {
        nuevoPais->id=0;
        strcpy(nuevoPais->nombre, "");
        nuevoPais->vac1dosis=0;
        nuevoPais->vac2dosis=0;
        nuevoPais->sinVacunar=0;
    }

    return nuevoPais;
}

ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr)
{
    ePais* nuevoPais = pais_new();
    if(nuevoPais!=NULL)
    {
        if(!(pais_setId(nuevoPais,atoi(idStr)) &&
                pais_setNombre(nuevoPais,nombreStr) &&
                pais_setvac1dosis(nuevoPais,atoi(vac1dosisStr)) &&
                pais_setvac2dosis(nuevoPais,atoi(vac2dosisStr)) &&
                pais_setsinVacunar(nuevoPais, atoi(sinVacunarStr)))
          )
        {
            pais_delete(nuevoPais);
            nuevoPais = NULL;
        }
    }

    return nuevoPais;
}

void pais_delete(ePais* p)
{
    free(p);
}

int pais_setId(ePais* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id >= 0)
    {
        this->id=id;
        todoOk=1;
    }
    return todoOk;
}

int pais_getId(ePais* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        todoOk=1;
    }
    return todoOk;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre != NULL && strlen(nombre)<20 && strlen(nombre)>2)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int todoOk = 0;
    if(nombre != NULL && this != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int pais_setvac1dosis(ePais* this,int vac1dosis)
{
    int todoOk=0;
    if(this!=NULL && vac1dosis >= 0)
    {
        this->vac1dosis=vac1dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_getvac1dosis(ePais* this,int* vac1dosis)
{
    int todoOk=0;
    if(this!=NULL && vac1dosis !=NULL)
    {
        *vac1dosis = this->vac1dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_setvac2dosis(ePais* this,int vac2dosis)
{
    int todoOk=0;
    if(this!=NULL && vac2dosis >= 0)
    {
        this->vac2dosis=vac2dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_getvac2dosis(ePais* this,int* vac2dosis)
{
    int todoOk=0;
    if(this!=NULL && vac2dosis !=NULL)
    {
        *vac2dosis = this->vac2dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_setsinVacunar(ePais* this,int sinVacunar)
{
    int todoOk=0;
    if(this!=NULL && sinVacunar >= 0)
    {
        this->sinVacunar=sinVacunar;
        todoOk=1;
    }
    return todoOk;
}

int pais_getsinVacunar(ePais* this,int* sinVacunar)
{
    int todoOk=0;
    if(this!=NULL && sinVacunar !=NULL)
    {
        *sinVacunar = this->sinVacunar;
        todoOk=1;
    }
    return todoOk;
}

void asignarStats(ePais* this)
{
    int numero1;
    int numero2;
    int numero3;
    int max1 = 60;
    int min1 = 1;
    int max2 = 40;
    int min2 = 1;


    if(this != NULL )
    {
        numero1 = rand() % (max1 - min1 + 1) + min1;
        this->vac1dosis = numero1;

        numero2 = rand() % (max2 - min2 + 1) + min2;
        this->vac2dosis = numero2;

        numero3 = 100 - numero1 - numero2;
        this->sinVacunar = numero3;
    }
}

int filtrarPaisesExitosos(ePais* this)
{
    int retorno = 0;
    if(this != NULL )
    {
        if(this->vac2dosis > 30)
        {
           retorno =1;
        }
    }
    return retorno;
}

int filtrarPaisesEnElHorno(ePais* this)
{
    int retorno = 0;
    if(this != NULL )
    {
        if(this->sinVacunar > this->vac1dosis + this->vac2dosis )
        {
           retorno =1;
        }
    }
    return retorno;
}

