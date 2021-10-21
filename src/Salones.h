#ifndef SALONES_H_INCLUDED
#define SALONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#define LOCAL 0
#define SHOPPING 1

typedef struct
{
	int ID;
	char nombre[100];
	char direccion[100];
	int tipoDeSalon;
	int isEmpty;
}eSalon;

/**
 * Mostrará el menú de opciones
 * @return Retornará la opción elegida.
 */
int menuDeOpciones();

/**
 * Inicializa la lista de salones
 * @param listaSalones Recibe la lista de salones
 * @param len Recibe el largo que tendrá la lista a inicializar
 * @return -1 si hubo error, 0 si inicializa la lista
 */
int inicializarSalones(eSalon* listaSalones, int len);

/**
 * Busca si en la lista de salones hay espacio libre
 * @param listaSalones La lista de salones que deberá recorrer
 * @param len El largo de la lista de salones
 * @return -1 si hubo error, o el índice del primer espacio libre que encuentre
 */
int buscarEspacioLibreSalones(eSalon* listaSalones, int len);

/**
 * Agregará un salon con toda su informacion a la lista, incrementando su ID en 1 cada vez que esto ocurra
 * @param listaSalones Lista a la cual see deberá agregar el salón a cargar
 * @param len Largo de la lista de salonees
 * @return -1 si hubo error, 0 si se agregó correctamente el salon
 */
int agregarSalon(eSalon* listaSalones, int len);

/**
 * Muestra un solo salón de la lista
 * @param listaSalones Lista en la cual se deberá buscar el salón
 * @param index Indice donde está ubicado el salón que se mostrará
 * @return -1 si hubo error, 0 si se mostró correctamente el salon
 */
int mostrarUnSalon(eSalon* listaSalones, int index);

/**
 * Muestra todos los salones de la lista
 * @param listaSalones Lista de salones que se recorrerá para mostrar los salones
 * @param len Largo de la lista de salones
 * @return -1 si hubo error, 0 si la lista se mostró correctamente
 */
int mostrarSalones(eSalon* listaSalones, int len);

/**
 * Buscará un salón en la lista
 * @param listaSalones Lista de salones en la que se deberá buscar el salon deseado
 * @param len Largo de la lista de salones
 * @param id ID del salón que se desea encontrar
 * @return -1 si no se encontró el salón, el id del salón si lo encontró
 */
int buscarSalonPorID(eSalon* listaSalones, int len, int id);

#endif
