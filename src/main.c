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
#include "Juegos.h"
#include "Informes.h"
#define CANTIDAD_SALONES 100
#define CANTIDAD_ARCADES 1000


int main(void) {
	setbuf(stdout, NULL);

	eSalon salones[CANTIDAD_SALONES];
	eArcade arcades[CANTIDAD_ARCADES];

	int salonVacio;
	int flagSalon = 0, flagArcade = 0;
	char continuar = 's';

	inicializarSalones(salones, CANTIDAD_SALONES);

	do
	{
		switch(menuDeOpciones())
		{
			case 1:
				flagSalon = 1;
				salonVacio = buscarEspacioLibreSalones(salones, CANTIDAD_SALONES);
				if(salonVacio != -1)
				{
					agregarSalon(salones, CANTIDAD_SALONES);
				}
				else
				{
					printf("No hay espacio para agregar un salón");
				}
				break;
			case 2:
				if(flagSalon == 1)
				{
					eliminarSalon(salones, CANTIDAD_SALONES, salonVacio);
				}
				else
				{
					printf("No hay salones para eliminar\n");
				}
				break;
			case 3:
				if(flagSalon == 1)
				{
					mostrarSalones(salones, CANTIDAD_SALONES);
				}
				else
				{
					printf("No hay salones para mostrar\n");
				}
				break;
			default:
				break;
		}

	}while(continuar == 's');


















	return EXIT_SUCCESS;
}
