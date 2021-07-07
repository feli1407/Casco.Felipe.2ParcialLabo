#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

/** \brief muestra el menu y pide una opcion al usuario
 *
 * \return int retorna la opcion ingresada y validada
 *
 */
int menu();

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 1 (EXITO) si se obtiene una cadena y 0 (ERROR) si no
*
*/
int myGets(char* cadena, int longitud);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero entero y 0 (ERROR) si no
*
*/
int getInt(int* pResultado);

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
int esNumerica(char* cadena);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos Es la cantidad de reintentos que tiene el usuario
 * \return Retorna 1 si se obtuvo el numero y 0 si no
 */
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);

/** \brief Recorre la cadena verificando que todo lo de la cadena sean letras o espacios
 *
 * \param cadena[] char cadena a validar
 * \return int Retorna 1 si son todas letras o espacios, y 0 si no
 *
 */
int tieneUnicamenteLetrasDelAlfabeto(char cadena[]);

/** \brief Obtiene un numero en formato char validando el tamaño
 *
 * \param cadena[] char cadena a validar
 * \param tam int tamaño de la cadena
 * \param mensaje char* mensaje a mostrar
 * \param mensajeError char* mensaje a mostrar en caso de error
 * \param reintentos int cantidad de reintentos
 * \return int Retorna 1 si son todos numeros, y 0 si no
 *
 */
int getNumerosEnChar(char cadena[], int tam, char* mensaje, char* mensajeError,  int reintentos);

/** \brief Obtiene un string validando el tamaño y que tenga solo letras o espacios
 *
 * \param cadena[] char Cadena a analizar
 * \param tam int Tamaño maximo de la cadena
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje en caso de error a ser mostrado
 * \param reintentos int Es la cantidad de reintentos que tiene el usuario
 * \return int Retorna 1 si no hubo problemas y 0 si no pudo obtener la cadena correctamente
 *
 */
int getString(char cadena[], int tam, char* mensaje, char* mensajeError,  int reintentos);

/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return int Retorna 1 si se obtiene un numero flotante y 0 si no
 *
 */
int getFloat(float* pResultado);

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos Es la cantidad de reintentos que tiene el usuario
 * \return Retorna 1 si se obtuvo el numero flotante y 0 si no
 */
int getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float
maximo, int reintentos);

/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \return int Retorna 1 si es flotante y 0 si no lo es
 *
 */
int esFlotante(char* cadena);

/** \brief verifica que la cadena ingresada sea un telefono(pide que tenga un guion)
 *
 * \param cadena[] char cadena a analizar
 * \return int retorna 1 si es un telefono y 0 si no lo es
 *
 */
int esTelefono(char cadena[]);

/** \brief valida que lo que ingresa el usuario sea un telefono
 *
 * \param pResultado int* puntero donde almacenara el telefono en caso de que lo sea
 * \return int retorna 1 si pudo conseguir el telefono y 0 si no
 *
 */
int getTelefono(char cadena[]);

/** \brief pide un telefono al usuario con el mensaje ingresado y lo valida
 *
 * \param pResultado int* espacio en memoria donde se guardaria el resultado si pasa las validaciones
 * \param mensaje char* mensaje para pedir el telefono
 * \param mensajeError char* mensaje en caso de que no sea valido el telefono
 * \param reintentos int cantidad de veces que puede intentar antes de que devuelva error
 * \return int retorna 1 si no hubo problemas con la obtencion del numero y 0 si no pudo obtenerlo
 *
 */
int pedirTelefono(char cadena[], char* mensaje, char* mensajeError, int reintentos);

/** \brief pide el sexo al usuario validando que sea m o f
 *
 * \param pResultado char* espacio en memoria donde se guardaria el resultado si pasa las validaciones
 * \param mensaje char* mensaje para pedir el sexo
 * \param mensajeError char* mensaje en caso de error
 * \param reintentos int cantidad de reintentos
 * \return int retorna 1 si pudo conseguir l sexo y 0 si no
 *
 */
int pedirSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
