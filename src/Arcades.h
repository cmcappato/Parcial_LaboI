/*
4) INCORPORAR ARCADE
	Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad m�xima de
	fichas, ID del sal�n al que pertenece (Validar que exista) y nombre del juego que contiene (hasta 63 caracteres).
	Se generar� un ID �nico para gestionar los ARCADE.
5) MODIFICAR ARCADE
	Se imprime la lista de arcades con los ID y datos que lo componen.
	Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
	Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
	cargados en el sistema y se permitir� ingresar un texto con el nombre del nuevo juego.
6) ELIMINAR ARCADE
	Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la informaci�n del sal�n y el
	juego que contiene.
	Se ingresa un ID y previo a dar de baja se deber� solicitar confirmaci�n, imprimiendo el arcade a dar de baja y
	confirmando si est� seguro dar de baja est� mismo.
7) IMPRIMIR ARCADES
	Se imprime la lista de arcades con ID, y sus datos.

	TIPOS DE SONIDO PARA ARCADE:
		MONO
		EST�REO

*/

#ifndef ARCADES_H_INCLUDED
#define ARCADES_H_INCLUDED
#define SONIDO_MONO 0
#define SONIDO_ESTEREO 1


typedef struct
{
	int ID;
	char nacionalidad[100];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadFichas;
	char juegoQueContiene[63];
	int isEmpty;
}eArcade;

/**
 *
 * @param listaArcades
 * @param lenArray
 * @return
 */
int inicializarArcades(eArcade* listaArcades, int len);

int buscarEspacioLibreArcades(eArcade* listaArcades, int len);

int agregarArcade(eArcade* listaArcades, int len);

int mostrarUnArcade(eArcade* listaArcades, int index);

int mostrarArcades(eArcade* listaArcades, int len);

int encontrarArcadePorID(int id, eArcade* listaArcades, int len);

int eliminarArcade(int id, eArcade* listaArcades, int len);

#endif
