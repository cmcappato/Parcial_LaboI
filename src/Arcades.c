#include "Arcades.h"

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

int mostrarUnArcade(eArcade* listaArcades, int index)
{
	int retorno = -1;

	if(listaArcades != NULL)
	{
		if(listaArcades[index].isEmpty == 0)
		{
			if(listaArcades[index].tipoDeSonido == 0)
				printf("ID: %d\t    NACIONALIDAD: %s\t    SONIDO: MONO\t	CANT. JUGADORES: %d\t CAPACIDAD DE FICHAS: %d\t		JUEGO: %s\t		SALON: %d\n",
						listaArcades[index].ID,
						listaArcades[index].nacionalidad,
						listaArcades[index].cantidadDeJugadores,
						listaArcades[index].capacidadFichas,
						listaArcades[index].juegoQueContiene,
						listaArcades[index].salonAlQuePertenece);
			else if(listaArcades[index].tipoDeSonido == 1)
				printf("ID: %d\t    NACIONALIDAD: %s\t    SONIDO: ESTEREO\t	CANT. JUGADORES: %d\t CAPACIDAD DE FICHAS: %d\t		JUEGO: %s\t		SALON: %d\n",
						listaArcades[index].ID,
						listaArcades[index].nacionalidad,
						listaArcades[index].cantidadDeJugadores,
						listaArcades[index].capacidadFichas,
						listaArcades[index].juegoQueContiene,
						listaArcades[index].salonAlQuePertenece);

			retorno = 0;
		}
	}

	return retorno;
}

int mostrarArcades(eArcade* listaArcades, int len)
{
	int retorno = -1;

	if(listaArcades != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(listaArcades[i].isEmpty == 0)
			{
				mostrarUnArcade(listaArcades, i);
				retorno = 0;
			}

		}
	}
	return retorno;
}

int mostrarJuegos(eArcade* listaArcades, int len)
{
	int retorno = -1;
	int auxNombreJuego[63];

	if(listaArcades != NULL)
	{
		for(int i = 0; i < listaArcades; i++)
		{

		}
		retorno = 0;
	}

	return retorno;
}

int modificarArcade(eArcade* listaArcades, int len, int id)
{
	int retorno = -1;
	int opcion;
	int index;
	int auxCantidadJugadores;
	char auxJuegoQueContiene[63];
	char continuar = 'n';

	if(listaArcades != NULL)
	{
		mostrarArcades(listaArcades, len);
		printf("Ingrese el ID del arcade que desea modificar: \n");
		scanf("%d", &id);
		index = buscarArcadePorID(listaArcades, len, id);

		if(index != -1)
		{
			do
			{
				printf("¿Que desea modificar? \n");
				printf("1- Juego que contiene \t 2- Cantidad de jugadores");
				scanf("%d", &opcion);

				switch(opcion)
				{
					case 1:
						getValidString("Nuevo juego que tendra el arcade: ", "Error, ingrese el nuevo juego que tendra el arcade: ", auxJuegoQueContiene);
						strcpy(listaArcades[index].juegoQueContiene, auxJuegoQueContiene);
						break;
					case 2:
						auxCantidadJugadores = getValidInt("Nueva cantidad de jugadores: ", "Error, ingrese nueva cantidad de jugadores: ", 1, 4);
						listaArcades[index].cantidadDeJugadores = auxCantidadJugadores;
						break;
					default:
						printf("Opcion incorrecta \n");
						break;
				}

				printf("¿Desea continuar modificando este arcade? S/N \n :");
				fflush(stdin);
				scanf("%c",&continuar);
			}while(continuar == 's' || continuar == 'S');
		}

		retorno = 0;
	}

	return retorno;
}

int buscarArcadePorID(eArcade* listaArcades, int len, int id)
{
	int retorno = -1;

		if(listaArcades != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				if(listaArcades[i].ID == id && listaArcades[i].isEmpty == 0)
				{
					retorno = i;
					break;
				}
				else
				{
					printf("No se encontró ese ID \n");
					break;
				}
			}
		}

		return retorno;
}

int eliminarArcade(eArcade* listaArcades, int len, int id)
{
	int retorno = -1;
	int index;
	char pregunta;

	if(listaArcades != NULL)
	{
		mostrarArcades(listaArcades, len);
		printf("Ingrese el ID del arcade que desea eliminar: \n");
		scanf("%d", &id);
		index = buscarArcadePorID(listaArcades, len, id);

		if(index != -1)
		{
			mostrarUnArcade(listaArcades, index);
			printf("Está seguro que desea eliminar este arcade? S/N: ");
			fflush(stdin);
			scanf("%c", &pregunta);
			if(pregunta == 's' || pregunta == 'S')
			{
				printf("Arcade eliminado\n");
				listaArcades[index].isEmpty = 1;
			}
			else
			{
				printf("No se elimino el arcade\n");
			}
		}

		retorno = 0;
	}

	return retorno;
}
