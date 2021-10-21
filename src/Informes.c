#include "Informes.h"

int submenuDeInformes()
{
	int opcion;

	printf("\t-------------------------------------------------------------------------------------------------------------\n");
	printf("\t1) Salones con más de 4 arcades\n");
	printf("\t2) Arcades para más de 2 jugadores\n");
	printf("\t3) Buscar la informacion de un salon\n");
	printf("\t4) Buscar los arcades de un salon\n");
	printf("\t5) Buscar el salon con más cantidad de arcades\n");
	printf("\t6) Calcular monto máximo de un salon\n");
	printf("\t7) Cantidad de arcades que contienen un juego determinado\n");
	printf("\t8) Salones completos (8 arcades con más de 2 jugadores)\n");
	printf("\t9) Promedio de arcades por salon\n");
	printf("\t10) Salir del menu de informes\n");
	printf("\t------------------------------------------------------------------------------------------------\n");
	printf("\tElija una opcion:\n");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int salonesConMasDeCuatroArcades(eSalon* listaSalones, eArcade* listaArcades, int lenSalones, int lenArcades)
{
	int retorno = -1;


	return retorno;
}

int arcadesParaMasDeDosJugadores(eSalon* listaSalones, eArcade* listaArcades, int lenSalones, int lenArcades)
{
	int retorno = -1;
	int index;

	if(listaSalones != NULL && listaArcades != NULL)
	{
		for(int i = 0; i < lenArcades; i++)
		{
			if(listaArcades[i].cantidadDeJugadores > 2 && listaArcades[i].isEmpty == 0)
			{
				index = buscarSalonPorID(listaSalones, lenSalones, i);
				mostrarUnArcade(listaArcades, i);
			}
		}


		retorno = 0;
	}

	return retorno;
}

int infoDeSalonPorID()
{
	int retorno = -1;

	return retorno;
}

int arcadesDeUnSalon()
{
	int retorno = -1;

	return retorno;
}

int salonConMasArcades()
{
	int retorno = -1;

	return retorno;
}

int montoMaximoPosible()
{
	int retorno = -1;

	return retorno;
}

int cantidadDeJuegos()
{
	int retorno = -1;

	return retorno;
}

int promedioDeArcades(eSalon* listaSalones, eArcade* listaArcades, int lenSalones, int lenArcades)
{
	int retorno = -1;
	int cantidadSalones = 0, cantidadArcades = 0;
	float promedio;

	if(listaSalones != NULL && listaArcades != NULL)
	{
		for(int i = 0; i < lenSalones; i++)
		{
			if(listaSalones[i].isEmpty == 0)
				cantidadSalones++;
		}

		for(int i = 0; i < lenArcades; i++)
		{
			if(listaArcades[i].isEmpty == 0)
				cantidadArcades++;
		}

		promedio = (float)cantidadArcades / cantidadSalones;

		printf("El promedio de arcades es %.2f\n", promedio);

		retorno = 0;
	}


	return retorno;
}
