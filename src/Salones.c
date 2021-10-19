#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "Salones.h"

static int generarIdSalon()
{
	static int nextID = 1;

	return nextID++;
}

int menuDeOpciones()
{
	int opcion;

	printf("********************************\n");
	printf("SALONES:\n");
	printf("1- Alta de salón \t 2- Eliminar salón \t 3- Listar salones\n");
	printf("ARCADES:\n");
	printf("4- Alta de arcade \t 5- Modificar arcade \t 6- Eliminar arcade \t 7- Listar arcades\n");
	printf("JUEGOS:\n");
	printf("8- Listar juegos\n");
	printf("INFORMES:\n");
	printf("9- Ingresar al menú de informes\n");
	printf("0- Salir\n");
	printf("--------------------------------\n");
	printf("Elija una opcion:\n");
	printf("********************************\n");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int inicializarSalones(eSalon* listaSalones, int len)
{
	int retorno = -1;

	if (listaSalones != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			listaSalones[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarEspacioLibreSalones(eSalon* listaSalones, int len)
{
    int retorno = -1;

    if(listaSalones != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(listaSalones[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
    return retorno;
}

int agregarSalon(eSalon* listaSalones, int len)
{
	eSalon auxSalon;
	int lugarLibre = buscarEspacioLibreSalones(listaSalones, len);
	int retorno = -1;

	if(listaSalones != NULL)
	{
		if(lugarLibre != -1)
		{
			auxSalon.isEmpty = -1;
			auxSalon.ID = generarIdSalon();
			getValidString("Nombre del salon: ", "Error, ingrese nombre del salon: ", auxSalon.nombre);
			getSuperAlfaNumerico("Direccion del salon: ", "Error, ingrese direccion del salon: ", auxSalon.direccion);
			auxSalon.tipoDeSalon = getValidInt("Tipo de salon (0 para local, 1 para shopping): ", "Error, ingrese tipo de salon (0 para local, 1 para shopping): ", 0, 1);
			auxSalon.isEmpty = 0;
			listaSalones[lugarLibre] = auxSalon;

			retorno = 0;
		}
	}

	return retorno;
}

int mostrarUnSalon(eSalon* listaSalones, int index)
{
	int retorno = -1;

	if(listaSalones != NULL)
	{
		if(listaSalones[index].isEmpty == 0)
		{
			if(listaSalones[index].tipoDeSalon == 0)
				printf("ID: %d\t    NOMBRE: %s\t    DIRECCION: %s\t	LOCAL\t \n\n", listaSalones[index].ID, listaSalones[index].nombre, listaSalones[index].direccion);
			else if(listaSalones[index].tipoDeSalon == 1)
				printf("ID: %d\t    NOMBRE: %s\t    DIRECCION: %s\t	SHOPPING\t \n\n", listaSalones[index].ID, listaSalones[index].nombre, listaSalones[index].direccion);

			retorno = 0;
		}
	}

	return retorno;
}

int mostrarSalones(eSalon* listaSalones, int len)
{
    int retorno = -1;

    if(listaSalones != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(listaSalones[i].isEmpty == 0)
            {
            	mostrarUnSalon(listaSalones, i);
            	retorno = 0;
            }

        }
    }
    return retorno;
}

int buscarSalonPorID(eSalon* listaSalones, int len, int id)
{
	int retorno = -1;

	if(listaSalones != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(listaSalones[i].ID == id && listaSalones[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("No se encontró ese ID");
			}
		}
	}

	return retorno;
}

int eliminarSalon(eSalon* listaSalones, int len, int id)
{
	int retorno = -1;
	int index;
	char pregunta;

	if(listaSalones != NULL)
	{
		mostrarSalones(listaSalones, len);
		printf("Ingrese el ID del salon que desea eliminar: \n");
		scanf("%d", &id);
		index = buscarSalonPorID(listaSalones, len, id);

		if(index == -1)
		{
			printf("Ese ID no existe \n");
		}
		else
		{
			mostrarUnSalon(listaSalones, index);
			printf("Está seguro que desea eliminar este juego? S/N: ");
			fflush(stdin);
			scanf("%c", &pregunta);
			if(pregunta == 's' || pregunta == 'S')
			{
				printf("Salon eliminado\n");
				listaSalones[index].isEmpty = 1;
			}
			else
			{
				printf("No se elimino el salon\n");
			}
		}

		retorno = 0;
	}

	return retorno;
}
