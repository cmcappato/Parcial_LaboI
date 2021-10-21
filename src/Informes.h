/*
	A) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.
	B) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y
	nombre del salón al que pertenece.
	C) Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección y cantidad
	de arcades que posee.
	D) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos
	los arcades con sus datos junto con el nombre del juego que lo compone.
	E) Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de arcades que
	posee.
	F) Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede
	recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos
	ingresado)
	G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.
*/


#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "SalonesConArcades.h"


int submenuDeInformes();

/**
 * Devolverá una lista con los salones que contengan más de 4 arcades
 * @param listaSalones
 * @param listaArcades
 * @param lenSalones
 * @param lenArcades
 * @return
 */
int salonesConMasDeCuatroArcades(eSalon* listaSalones, eArcade* listaArcades, int lenSalones, int lenArcades);

int arcadesParaMasDeDosJugadores();

int infoDeSalonPorID();

int arcadesDeUnSalon();

int salonConMasArcades();

int montoMaximoPosible();

int cantidadDeJuegos();



#endif
