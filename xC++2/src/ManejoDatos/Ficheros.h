/**
 * @file Ficheros.h
 * @date 4/3/16
 * @title Ficheros
 * @brief Manejo de ficheros para el proyecto xC++2
 */

#ifndef SRC_MANEJODATOS_FICHEROS_H_
#define SRC_MANEJODATOS_FICHEROS_H_

#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "../Structures/LinkedList.h"

#include <sys/types.h>
#include <dirent.h>

using namespace std;

class Ficheros {
public:

	/**
	 * @brief Metodo constructor de Ficheros
	 */
	Ficheros();
	/**
	 * @brief Metodo devuelve el valor de verdad, si encuentra pBuscar dentro de pLine
	 * @param char[] pLine Linea en donde buscar
	 * @param char[] pBuscar Cadena a buscar
	 * @return bool
	 */
	bool cadenaDentroDeOtra(char pLine[], char pBuscar[]);
	/**
	 * @brief Metodo lee dentro del fichero asignado como pNameArchive
	 * @param char[] pNameArchive
	 */
	void leerEnFichero(char pNameArchive[]);
	/**
	 * @brief Metodo escribe dentro del fichero existente la cadena de caracteres
	 * @param char[] pNameArchive
	 * @param char[] pEscribir
	 */
	void escribirEnFicheroExistente(char nameArchive[], char pEscribir[]);

	/**
	 * @brief Metodo escribe dentro del fichero que se crea la cadena de caracters
	 * @param char[] pnameArchive
	 * @param char[] pEscribir
	 */
	void escribirEnFicheroNuevo(char nameArchive[], char pEscribir[]);void escribirEnFichero(char pNameArchive[], char pEscribir[]);
	/**
	 * @brief Metodo extrae los parametros que estan definidos con Include
	 * @param char[] pLine
	 * @param int pLarge
	 * @return char*
	 */
	char* extraerParametrosInclude(char pLine[], int pLarge);
	/**
	 * @brief Metodo lee el fichero y realiza la busqueda del include
	 * @param char[] pNameArchive
	 * @param char pBuscar
	 */
	void leerEnFicheroPrepro(char pNameArchive[],char pBuscar[]);
	/**
	 * @brief Metodo procesa los tokens para el proceso de serializar de xC++2
	 * @param char pLine
	 */
	void LogicaDeIncludeSerializar(char pLine[]);

	/**
	 * @brief Metodo  procesa los tokens para el proceso de desserializar de xC++2
	 * @param char pLine
	 */
	void LogicaDeIncludeDesserializar(char pline[]);
	/**
	 * @brief Metodo busca los archivos entre el folder de la ubicacion especificada
	 * @param pSourceDir
	 * @return int
	 */
	int BuscarArchivosEnFolder(char pSourceDir[], char pBuscar[]);
	/**
	 * @brief Metodo destructor de ficheros
	 */
	virtual ~Ficheros();
};

#endif /* SRC_MANEJODATOS_FICHEROS_H_ */
