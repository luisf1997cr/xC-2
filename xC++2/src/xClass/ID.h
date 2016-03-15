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
	int* number;
	int* contador;

		ID(int numero, int contador);
		virtual ~ID();

		void newID(int& number, int& contador);
		void deleteID(char&ID,int number);
};

void ID::ID(int &numero, int& conta){

	numero=number;
	conta=contador;

}
ID::~ID(){delete IDnumber;}

void ID::newID(int& numero,int& conta){
	char valor[12];
	numero++;
	conta++;
	IDnumber[conta]=sprintf(valor, "%d", numero); ;
}

void ID::deleteID(char& id, int numero){
	int i=0;
	char valor[12];
	for(i=0;i>=contador;i++){
		if(IDnumber[i]==sprintf(valor, "%d", numero)){
			IDnumber[i]=0;
			break;
		}
	}
}

#endif /* SRC_XCLASS_ID_H_ */
