/*
1) ALTA DE SALÓN
	Se deberá dar de alta un salón con los siguientes datos: Nombre, dirección y tipo.
	Se generará un ID único para gestionar los SALONES.
	Este salón se imprimirá por pantalla si el alta es correcta.
2) ELIMINAR SALÓN
	Se imprime la lista de salas listando ID, nombre y dirección.
	Se ingresa un ID y la misma generará la baja del salón, junto con todos los arcades que lo componen.
3) IMPRIMIR SALONES
	Se imprime la lista completa de salas con todos sus datos. Nombre, dirección y tipo.

	TIPOS DE SALÓN:
		SHOPPING
		LOCAL

*/

#ifndef SALONES_H_INCLUDED
#define SALONES_H_INCLUDED
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
 *
 * @param listaSalones
 * @param lenArray
 * @return
 */
int inicializarSalones(eSalon* listaSalones, int len);

/**
 *
 * @param listaSalones
 * @param lenArray
 * @return
 */
int buscarEspacioLibreSalones(eSalon* listaSalones, int len);

/**
 *
 * @param listaSalones
 * @param lenArray
 * @return
 */
int agregarSalon(eSalon* listaSalones, int len);

/**
 *
 * @param listaSalones
 * @param index
 * @return
 */
int mostrarUnSalon(eSalon* listaSalones, int index);

/**
 *
 * @param listaSalones
 * @param lenArray
 * @return
 */
int mostrarSalones(eSalon* listaSalones, int len);

/**
 *
 * @param listaSalones
 * @param len
 * @param id
 * @return
 */
int buscarSalonPorID(eSalon* listaSalones, int len, int id);

/**
 *
 * @param listaSalones
 * @param len
 * @param id
 * @return
 */
int eliminarSalon(eSalon* listaSalones, int len, int id);





#endif
