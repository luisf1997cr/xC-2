/*
 * xMemoryManage.h
 *
 *  Created on: 2 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_XMEMOMANA_XMEMORYMANAGE_H_
#define SRC_XMEMOMANA_XMEMORYMANAGE_H_

/*
 *
 */

class xMemoryManage {
protected:

	int memprogra = 200; //Entero de cantidad de memoria que se pasa desde archivo de configuracion
	int memprograusada =0; //Entero de cantidad de memoria que se ha usado
	char* PROGRAMMEMORY = malloc(memprogra); // Puntero de inicializacion de toda la memoria a utilizar


public:


	xMemoryManage();
	virtual ~xMemoryManage();
};

#endif /* SRC_XMEMOMANA_XMEMORYMANAGE_H_ */
