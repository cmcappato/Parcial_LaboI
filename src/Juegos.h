/*
8) IMPRIMIR JUEGOS
	Se imprime la lista de juegos que contienen todos los arcades sin repetir.
*/

#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

struct
{
	int ID;
	char nombre[51];
	int isEmpty;
}typedef eJuego;


/**
 *
 * @param listaJuegos
 * @param lenArray
 * @return
 */
int inicializarJuegos(eJuego* listaJuegos, int lenArray);




#endif
