#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
}ePais;

#endif // PAIS_H_INCLUDED

/** \brief Crea una nueva estructura de ePais con todos sus datos inicializados en 0
 *
 * \return ePais*
 *
 */
ePais* pais_new();

/** \brief Crea una nueva estructura de ePais con los parametros que le pasamos
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param vac1dosisStr char*
 * \param vac2dosisStr char*
 * \param sinVacunarStr char*
 * \return ePais*
 *
 */
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarStr);

/** \brief elimina la estructura ePais que le pasamos
 *
 * \param p ePais*
 * \return void
 *
 */
void pais_delete(ePais* p);

/** \brief Setea el id que le pasamos por parametro al id de la estructura
 *
 * \param this ePais*
 * \param id int
 * \return int
 *
 */
int pais_setId(ePais* this,int id);
/** \brief Obtiene el id de la estructura y nos lo guarda en el puntero a id
 *
 * \param this ePais*
 * \param id int*
 * \return int
 *
 */
int pais_getId(ePais* this,int* id);

/** \brief Setea el nombre que le pasamos por parametro al nombre de la estructura
 *
 * \param this ePais*
 * \param nombre char*
 * \return int
 *
 */
int pais_setNombre(ePais* this,char* nombre);
/** \brief Obtiene el nombre de la estructura y nos lo guarda en el puntero a nombre
 *
 * \param this ePais*
 * \param nombre char*
 * \return int
 *
 */
int pais_getNombre(ePais* this,char* nombre);

/** \brief Setea la cantidad de vac1dosis que le pasamos por parametro al vac1dosis de la estructura
 *
 * \param this ePais*
 * \param vac1dosis int
 * \return int
 *
 */
int pais_setvac1dosis(ePais* this,int vac1dosis);
/** \brief Obtiene la cantidad de vac1dosis de la estructura y nos lo guarda en el puntero a vac1dosis
 *
 * \param this ePais*
 * \param vac1dosis int*
 * \return int
 *
 */
int pais_getvac1dosis(ePais* this,int* vac1dosis);

/** \brief Setea la cantidad de vac2dosis que le pasamos por parametro al vac2dosis de la estructura
 *
 * \param this ePais*
 * \param vac2dosis int
 * \return int
 *
 */
int pais_setvac2dosis(ePais* this,int vac2dosis);
/** \brief Obtiene la cantidad de vac2dosis de la estructura y nos lo guarda en el puntero a vac2dosis
 *
 * \param this ePais*
 * \param vac2dosis int*
 * \return int
 *
 */
int pais_getvac2dosis(ePais* this,int* vac2dosis);

/** \brief Setea la cantidad de sinVacunar que le pasamos por parametro al sinVacunar de la estructura
 *
 * \param this ePais*
 * \param sinVacunar int
 * \return int
 *
 */
int pais_setsinVacunar(ePais* this,int sinVacunar);
/** \brief Obtiene la cantidad de sinVacunar de la estructura y nos lo guarda en el puntero a sinVacunar
 *
 * \param this ePais*
 * \param sinVacunar int*
 * \return int
 *
 */
int pais_getsinVacunar(ePais* this,int* sinVacunar);

/** \brief Genera los porcentajes aleatorios para los parametros vac1dosis, vac2dosis, sinVacunar
 *
 * \param this ePais*
 * \return void
 *
 */
void asignarStats(ePais* this);
/** \brief filtra los paises donde el 30 o mas por ciento de su poblacion esta vacunada con 2 dosis
 *
 * \param this ePais*
 * \return int
 *
 */
int filtrarPaisesExitosos(ePais* this);
/** \brief filtra paises donde la cantidad total de vacunados sea menor que la de no vacunados
 *
 * \param this ePais*
 * \return int
 *
 */
int filtrarPaisesEnElHorno(ePais* this);
