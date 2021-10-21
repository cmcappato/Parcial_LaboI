/*
	A) Listar los salones con m�s de 4 arcades. Indicando ID de sal�n, nombre, direcci�n y tipo de sal�n.
	B) Listar los arcades para m�s de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y
	nombre del sal�n al que pertenece.
	C) Listar toda la informaci�n de un sal�n en espec�fico ingresando su ID. Imprimir nombre, tipo y direcci�n y cantidad
	de arcades que posee.
	D) Listar todos los arcades de un sal�n determinado ingresando su ID. Informar nombre y tipo de sal�n, listar todos
	los arcades con sus datos junto con el nombre del juego que lo compone.
	E) Imprimir el sal�n con m�s cantidad de arcades, indicando todos los datos del sal�n y la cantidad de arcades que
	posee.
	F) Ingresar el ID de un sal�n, y el valor en pesos de una ficha, e imprimir el monto m�ximo en pesos que puede
	recaudar el sal�n (sumar cantidad de fichas m�ximo de cada arcade del sal�n y multiplicarla por el valor en pesos
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
 * Devolver� una lista con los salones que contengan m�s de 4 arcades
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
