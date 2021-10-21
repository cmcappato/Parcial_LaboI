#ifndef ARCADES_H_INCLUDED
#define ARCADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#define SONIDO_MONO 0
#define SONIDO_ESTEREO 1

typedef struct
{
	int ID;
	char nacionalidad[100];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadFichas;
	char juegoQueContiene[63];
	int salonAlQuePertenece;
	int isEmpty;
}eArcade;

/**
 *
 * @param listaArcades
 * @param lenArray
 * @return
 */
int inicializarArcades(eArcade* listaArcades, int len);

/**
 *
 * @param listaArcades
 * @param len
 * @return
 */
int buscarEspacioLibreArcades(eArcade* listaArcades, int len);

/**
 *
 * @param listaArcades
 * @param index
 * @return
 */
int mostrarUnArcade(eArcade* listaArcades, int index);

/**
 *
 * @param listaArcades
 * @param len
 * @return
 */
int mostrarArcades(eArcade* listaArcades, int len);

/**
 *
 * @param listaArcades
 * @param len
 * @return
 */
int mostrarJuegos(eArcade* listaArcades, int len);

/**
 *
 * @param listaArcades
 * @param len
 * @param id
 * @return
 */
int modificarArcade(eArcade* listaArcades, int len, int id);

/**
 *
 * @param listaArcades
 * @param len
 * @param id
 * @return
 */
int buscarArcadePorID(eArcade* listaArcades, int len, int id);

/**
 *
 * @param listaArcades
 * @param len
 * @param id
 * @return
 */
int eliminarArcade(eArcade* listaArcades, int len, int id);

#endif
