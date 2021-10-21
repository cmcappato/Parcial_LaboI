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
 * Mostrar� el men� de opciones
 * @return Retornar� la opci�n elegida.
 */
int menuDeOpciones();

/**
 * Inicializa la lista de salones
 * @param listaSalones Recibe la lista de salones
 * @param len Recibe el largo que tendr� la lista a inicializar
 * @return -1 si hubo error, 0 si inicializa la lista
 */
int inicializarSalones(eSalon* listaSalones, int len);

/**
 * Busca si en la lista de salones hay espacio libre
 * @param listaSalones La lista de salones que deber� recorrer
 * @param len El largo de la lista de salones
 * @return -1 si hubo error, o el �ndice del primer espacio libre que encuentre
 */
int buscarEspacioLibreSalones(eSalon* listaSalones, int len);

/**
 * Agregar� un salon con toda su informacion a la lista, incrementando su ID en 1 cada vez que esto ocurra
 * @param listaSalones Lista a la cual see deber� agregar el sal�n a cargar
 * @param len Largo de la lista de salonees
 * @return -1 si hubo error, 0 si se agreg� correctamente el salon
 */
int agregarSalon(eSalon* listaSalones, int len);

/**
 * Muestra un solo sal�n de la lista
 * @param listaSalones Lista en la cual se deber� buscar el sal�n
 * @param index Indice donde est� ubicado el sal�n que se mostrar�
 * @return -1 si hubo error, 0 si se mostr� correctamente el salon
 */
int mostrarUnSalon(eSalon* listaSalones, int index);

/**
 * Muestra todos los salones de la lista
 * @param listaSalones Lista de salones que se recorrer� para mostrar los salones
 * @param len Largo de la lista de salones
 * @return -1 si hubo error, 0 si la lista se mostr� correctamente
 */
int mostrarSalones(eSalon* listaSalones, int len);

/**
 * Buscar� un sal�n en la lista
 * @param listaSalones Lista de salones en la que se deber� buscar el salon deseado
 * @param len Largo de la lista de salones
 * @param id ID del sal�n que se desea encontrar
 * @return -1 si no se encontr� el sal�n, el id del sal�n si lo encontr�
 */
int buscarSalonPorID(eSalon* listaSalones, int len, int id);

#endif
