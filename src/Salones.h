/*
1) ALTA DE SAL�N
	Se deber� dar de alta un sal�n con los siguientes datos: Nombre, direcci�n y tipo.
	Se generar� un ID �nico para gestionar los SALONES.
	Este sal�n se imprimir� por pantalla si el alta es correcta.
2) ELIMINAR SAL�N
	Se imprime la lista de salas listando ID, nombre y direcci�n.
	Se ingresa un ID y la misma generar� la baja del sal�n, junto con todos los arcades que lo componen.
3) IMPRIMIR SALONES
	Se imprime la lista completa de salas con todos sus datos. Nombre, direcci�n y tipo.

	TIPOS DE SAL�N:
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
 * Mostrar� el men� de opciones
 * @return Retornar� la opci�n elegida.
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
