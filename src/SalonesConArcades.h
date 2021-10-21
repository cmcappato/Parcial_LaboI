#ifndef SALONESCONARCADES_H_INCLUDED
#define SALONESCONARCADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "SalonesConArcades.h"

/**
 *
 * @param listaArcades
 * @param listaSalones
 * @param lenArcade
 * @param lenSalon
 * @return
 */
int agregarArcadeConSalon(eArcade* listaArcades, eSalon* listaSalones, int lenArcade, int lenSalon);

/**
 *
 * @param listaSalones
 * @param listaArcades
 * @param lenSalon
 * @param lenArcade
 * @param id
 * @return
 */
int eliminarSalonConArcades(eSalon* listaSalones, eArcade* listaArcades, int lenSalon, int lenArcade, int id);

/**
 *
 * @param salones
 * @param nombre
 * @param direccion
 * @param tipoSalon
 * @param len
 * @return
 */
int salonesConParametros(eSalon* salones, char *nombre, char *direccion, int tipoSalon, int len);

/**
 *
 * @param arcades
 * @param nacionalidad
 * @param sonido
 * @param jugadores
 * @param fichas
 * @param juego
 * @param salon
 * @param len
 * @return
 */
int arcadesConParametros(eArcade* arcades, char *nacionalidad,int sonido, int jugadores, int fichas, char *juego, int salon ,int len);

/**
 *
 * @param salones
 * @param len
 */
void harcodearSalones(eSalon* salones, int len);

/**
 *
 * @param arcades
 * @param len
 */
void harcodearArcades(eArcade* arcades, int len);

#endif
