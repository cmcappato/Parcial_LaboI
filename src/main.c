/*
 ============================================================================
 Name        : Cappato_PrimerParcial.c
 Author      : Cappato Carolina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Salones.h"
#include "Arcades.h"
#include "SalonesConArcades.h"
#include "Informes.h"
#define CANTIDAD_SALONES 100
#define CANTIDAD_ARCADES 1000

int main(void) {
	setbuf(stdout, NULL);

	eSalon salones[CANTIDAD_SALONES];
	eArcade arcades[CANTIDAD_ARCADES];

	int salonVacio, arcadeVacio;
	int flagSalon = 0, flagArcade = 0;
	char continuar = 's';

	inicializarSalones(salones, CANTIDAD_SALONES);
	inicializarArcades(arcades, CANTIDAD_ARCADES);

	do
	{
		switch(menuDeOpciones())
		{
			case 1:
				flagSalon = 1;
				salonVacio = buscarEspacioLibreSalones(salones, CANTIDAD_SALONES);
				if(salonVacio != -1)
					agregarSalon(salones, CANTIDAD_SALONES);
				else
					printf("No hay espacio para agregar un salón");
				break;
			case 2:
				if(flagSalon == 1)
					eliminarSalonConArcades(salones, arcades, CANTIDAD_SALONES, CANTIDAD_ARCADES, salonVacio);
				else
					printf("No hay salones para eliminar\n");
				break;
			case 3:
				if(flagSalon == 1)
					mostrarSalones(salones, CANTIDAD_SALONES);
				else
					printf("No hay salones para mostrar\n");
				break;
			case 4:
				flagArcade = 1;
				arcadeVacio = buscarEspacioLibreArcades(arcades, CANTIDAD_ARCADES);

				if(arcadeVacio != -1)
					agregarArcadeConSalon(arcades, salones, CANTIDAD_ARCADES, CANTIDAD_SALONES);
				else
					printf("No hay espacio para agregar un arcade");
				break;
			case 5:
				if(flagArcade == 1)
					modificarArcade(arcades, CANTIDAD_ARCADES, arcadeVacio);
				else
					printf("No hay arcades para modificar\n");
				break;
			case 6:
				if(flagArcade == 1)
					eliminarArcade(arcades, CANTIDAD_ARCADES, arcadeVacio);
				else
					printf("No hay arcades para eliminar\n");
				break;
			case 7:
				if(flagArcade == 1)
					mostrarArcades(arcades, CANTIDAD_ARCADES);
				else
					printf("No hay arcades para mostrar\n");
				break;
			case 8:
				printf("Acá iría la lista de juegos si hubiera una funcion que lo hiciera!!\n");
				break;
			case 9:
				switch(submenuDeInformes())
				{
					case 2:
						arcadesParaMasDeDosJugadores(salones, arcades, CANTIDAD_SALONES, CANTIDAD_ARCADES);
						break;
					case 9:
						promedioDeArcades(salones, arcades, CANTIDAD_SALONES, CANTIDAD_ARCADES);
						break;
					default:
						printf("Opcion incorrecta \n");
						break;
				}
				break;
			case 10:
				harcodearSalones(salones, CANTIDAD_SALONES);
				harcodearArcades(arcades, CANTIDAD_ARCADES);
				flagArcade = 1;
				flagSalon = 1;
				printf("Se cargaron los datos de prueba \n");
				break;
			case 11:
				printf("Gracias por utilizar el programa \n");
				continuar = 'n';
				break;
			default:
				break;
		}
	} while(continuar == 's');

	return 0;
}
