#include "SalonesConArcades.h"

static int generarID()
{
	static int nextID = 1;

	return nextID++;
}

int agregarArcadeConSalon(eArcade* listaArcades, eSalon* listaSalones, int lenArcade, int lenSalon)
{
	eArcade auxArcade;
	int lugarLibre = buscarEspacioLibreArcades(listaArcades, lenArcade);
	int retorno = -1;

	if(listaArcades != NULL && listaSalones != NULL)
	{
		if(lugarLibre != -1)
		{
			auxArcade.isEmpty = -1;
			auxArcade.ID = generarID();
			getValidString("Pais de origen del arcade: ", "Error, ingrese pais de origen del arcade: ", auxArcade.nacionalidad);
			auxArcade.cantidadDeJugadores = getValidInt("Cantidad de jugadores: ", "Error, ingrese cantidad de jugadores: ", 1, 4);
			auxArcade.capacidadFichas = getValidInt("Capacidad de fichas (máximo 200): ", "Error, ingrese capacidad de fichas (máximo 200): ", 1, 200);
			auxArcade.tipoDeSonido = getValidInt("Tipo de sonido (0 para mono, 1 para stereo): ", "Error, ingrese tipo de sonido (0 para mono, 1 para stereo): ", 0, 1);
			getValidString("Juego que tendra el arcade: ", "Error, ingrese el juego que tendra el arcade: ", auxArcade.juegoQueContiene);
			auxArcade.salonAlQuePertenece = getInt("ID de salon al que pertenece: \n");
			while(buscarSalonPorID(listaSalones, lenSalon, auxArcade.salonAlQuePertenece) == -1)
			{
				auxArcade.salonAlQuePertenece = getInt("No se encontró ese ID de salon, intente con otro: ");
			}
			auxArcade.isEmpty = 0;
			listaArcades[lugarLibre] = auxArcade;

			retorno = 0;
		}
	}

	return retorno;
}

int eliminarSalonConArcades(eSalon* listaSalones, eArcade* listaArcades, int lenSalon, int lenArcade, int id)
{
	int retorno = -1;
	int index;
	char pregunta;

	if(listaSalones != NULL)
	{
		mostrarSalones(listaSalones, lenSalon);
		printf("Ingrese el ID del salon que desea eliminar: \n");
		scanf("%d", &id);
		index = buscarSalonPorID(listaSalones, lenSalon, id);

		if(index != -1)
		{
			mostrarUnSalon(listaSalones, index);
			printf("Está seguro que desea eliminar este salon? S/N: \n");
			fflush(stdin);
			scanf("%c", &pregunta);
			if(pregunta == 's' || pregunta == 'S')
			{
				printf("Salon eliminado\n");
				for(int i = 0; i < lenArcade; i++)
				{
					if(listaArcades[i].salonAlQuePertenece == id)
					{
						listaArcades[i].isEmpty = 1;
					}
				}
				listaSalones[index].isEmpty = 1;
			}
			else
			{
				printf("No se elimino el salon\n");
			}
		}
		else
		{
			printf("Hubo un error \n");

		}

		retorno = 0;
	}

	return retorno;
}

int salonesConParametros(eSalon* salones, char *nombre, char *direccion, int tipoSalon, int len)
{
	int retorno = -1;
	int lugarLibre = buscarEspacioLibreSalones(salones, len);
	eSalon auxSalon;

	if(salones != NULL)
	{
		if (lugarLibre != -1)
		{
			auxSalon.ID = generarID();
			strcpy(auxSalon.nombre, nombre);
			strcpy(auxSalon.direccion, direccion);
			auxSalon.tipoDeSalon = tipoSalon;

			auxSalon.isEmpty = 0;
			salones[lugarLibre] = auxSalon;
			retorno = 0;
		}
	}

	return retorno;
}

int arcadesConParametros(eArcade* arcades, char *nacionalidad,int sonido, int jugadores, int fichas, char *juego, int salon ,int len)
{
	int retorno = -1;
	int lugarLibre = buscarEspacioLibreArcades(arcades, len);
	eArcade auxArcade;

	if(arcades != NULL)
	{
		if(lugarLibre != -1)
		{
			auxArcade.ID = generarID();
			strcpy(auxArcade.nacionalidad, nacionalidad);
			auxArcade.tipoDeSonido = sonido;
			auxArcade.cantidadDeJugadores = jugadores;
			auxArcade.capacidadFichas = fichas;
			strcpy(auxArcade.juegoQueContiene, juego);
			auxArcade.salonAlQuePertenece = salon;

			auxArcade.isEmpty = 0;
			arcades[lugarLibre] = auxArcade;
			retorno = 0;
		}
	}

	return retorno;
}

void harcodearSalones(eSalon* salones, int len)
{
	salonesConParametros(salones, "Elderflame", "Balcarce 1000", 1, len);
	salonesConParametros(salones, "Winterwunderland", "Acha 652", 0, len);
	salonesConParametros(salones, "Sovereign", "Lugones 3965", 0, len);
	salonesConParametros(salones, "Wasteland", "Miller 4821", 0, len);
	salonesConParametros(salones, "Glitchpop", "Los Incas 230", 1, len);
	salonesConParametros(salones, "Origin", "La Haya 935", 0, len);
	salonesConParametros(salones, "Forsaken", "Berlin 763", 0, len);
	salonesConParametros(salones, "Sentinels of light", "Rivadavia 1620", 1, len);
	salonesConParametros(salones, "Singularity", "Mitre 750", 0, len);
	salonesConParametros(salones, "Ruination", "Triunvirato 4141", 1, len);
	salonesConParametros(salones, "Spectrum", "Suncho 634", 0, len);
}

void harcodearArcades(eArcade* arcades, int len)
{
	arcadesConParametros(arcades, "Argentina" , 1, 2, 150, "Metal Slug 4", 1 ,len);
	arcadesConParametros(arcades, "Portugal" , 0, 2, 100, "Sims", 3 ,len);
	arcadesConParametros(arcades, "Portugal" , 0, 1, 150, "Splitgate", 1 ,len);
	arcadesConParametros(arcades, "Argentina" , 1, 3, 60, "CS GO", 4 ,len);
	arcadesConParametros(arcades, "Argentina" , 0, 1, 35, "Valorant", 2 ,len);
	arcadesConParametros(arcades, "Mexico" , 1, 2, 200, "Apex", 5 ,len);
	arcadesConParametros(arcades, "Jordania" , 1, 1, 50, "Overwatch", 5 ,len);
	arcadesConParametros(arcades, "Rusia" , 1, 2, 170, "Cyberpunk", 5 ,len);
	arcadesConParametros(arcades, "Chile" , 1, 2, 150, "Life is strange", 8 ,len);
	arcadesConParametros(arcades, "Portugal" , 1, 3, 100, "Mario Tenis", 1 ,len);
	arcadesConParametros(arcades, "Brasil" , 0, 2, 150, "Kirby", 3 ,len);
	arcadesConParametros(arcades, "Colombia" , 0, 4, 70, "Sonic", 8 ,len);
	arcadesConParametros(arcades, "Irlanda" , 0, 2, 150, "Tetris", 3 ,len);
	arcadesConParametros(arcades, "España" , 1, 4, 55, "Lineage", 10 ,len);
	arcadesConParametros(arcades, "Suecia" , 1, 1, 40, "DOTA", 11 ,len);
	arcadesConParametros(arcades, "Jordania" , 0, 3, 60, "Fall Guys", 9 ,len);
	arcadesConParametros(arcades, "Portugal" , 1, 4, 200, "Daytona", 7 ,len);
}
