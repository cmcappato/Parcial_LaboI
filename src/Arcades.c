#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "Arcades.h"

static int generarIdArcade()
{
	static int nextID = 1;

	return nextID++;
}

int inicializarArcades(eArcade* listaArcades, int len)
{
	int retorno = -1;

	if (listaArcades != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			listaArcades[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarEspacioLibreArcades(eArcade* listaArcades, int len)
{
    int retorno = -1;

    if(listaArcades != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(listaArcades[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
    return retorno;
}

int agregarArcade(eArcade* listaArcades, int len)
{
	eArcade auxArcade;
	int lugarLibre = buscarEspacioLibreArcades(listaArcades, len);
	int retorno = -1;

	if(listaArcades != NULL)
	{
		if(lugarLibre != -1)
		{
			auxArcade.isEmpty = -1;
			auxArcade.ID = generarIdArcade();
			getValidString("Pais de origen del arcade: ", "Error, ingrese pais de origen del arcade: ", auxArcade.nacionalidad);
			auxArcade.cantidadDeJugadores = getValidInt("Cantidad de jugadores: ", "Error, ingrese cantidad de jugadores: ", 1, 2);
			auxArcade.capacidadFichas = getValidInt("Capacidad de fichas (máximo 200): ", "Error, ingrese capacidad de fichas (máximo 200): ", 1, 200);
			auxArcade.tipoDeSonido = getValidInt("Tipo de sonido (0 para mono, 1 para stereo): ", "Error, ingrese tipo de sonido (0 para mono, 1 para stereo): ", 0, 1);
			auxArcade.isEmpty = 0;
			listaArcades[lugarLibre] = auxArcade;

			retorno = 0;
		}
	}

	return retorno;
}
