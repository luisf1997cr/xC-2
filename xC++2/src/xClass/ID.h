/*
 * ID.h
 *
 *  Created on: 11 de mar. de 2016
 *      Author: acacia
 */

#ifndef SRC_XCLASS_ID_H_
#define SRC_XCLASS_ID_H_

class ID {
public:
	char IDnumber[][15];
	volatile int number;
	volatile int contador;

		ID(int& number, int& contador);
		virtual ~ID();

		void newID(int& number, int& contador);
		void deleteID(char&ID,int number);
};

ID::ID(int &numero, int& conta){

	numero=number;
	conta=contador;

}
ID::~ID(){delete IDnumber;}

void ID::newID(int& numero,int& conta){
	char valor[12];
	numero++;
	conta++;
	sprintf(valor, "%d", numero);
	IDnumber[conta]= valor;
}

void ID::deleteID(char& id, int numero){
	int i=0;
	char valor[12];
	sprintf(valor, "%d", numero);
	for(i=0;i>=contador;i++){
		if(IDnumber[i]==valor){
			IDnumber[i]="vacio";
			break;
		}
	}
}

#endif /* SRC_XCLASS_ID_H_ */
