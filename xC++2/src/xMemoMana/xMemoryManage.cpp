#include "xMemoryManager.h"

xMemoryManager* xMemoryManager::m_pInstance = 0;

xMemoryManager* xMemoryManager::Instance(){
	if(!m_pInstance)
		m_pInstance = new xMemoryManager;
	return m_pInstance;
}

xMemoryManager::xMemoryManager() {
	_Memoria = new HashTable<xPointer>(13);
	void* memory = malloc(5000000);    //5000000
	xPointer localMemory;
	localMemory.setTopPointer(memory);
	localMemory.setLimitPointer(memory + 5000000);
	localMemory.setReference(-1);
	std::string s;
	std::stringstream out;
	out << localMemory->getId();
	s = out.str();
	NodoSimple<xPointer> *n = new NodoSimple<xPointer>{s,&localMemory,NULL};
	_Memoria->insertItem(n);
}

//xPointer xMemoryManager::xCalloc(int pNum, int pSize){
//	for (int index = 1; index < _Memoria->getLength(); index++ ){
//		NodoSimple<xPointer<xObject> >* nodoSpace = _Memoria->getItemByNumElem(index);
//		if((*nodoSpace->val).getReference() == -1){    //status libre
//			xPointer<xObject> newSpace;
//			(*nodoSpace->val).setReference(1);
//			newSpace.setLimitPointer((*nodoSpace->val).getLimitPointer());
//			(*nodoSpace->val).setLimitPointer((*nodoSpace->val).getTopPointer() + pNum * pSize);
//			newSpace.setTopPointer((*nodoSpace->val).getLimitPointer() + 1);
//			std::string s;
//			std::stringstream out;
//			out << newSpace.getId();
//			s = out.str();
//			NodoSimple<xPointer<xObject> > *newNodoSpace = new NodoSimple<xPointer<xObject> >{s,&newSpace,NULL};
//			_Memoria->insertItem(newNodoSpace);
//			return newSpace;
//		}
//	}
//}

xPointer xMemoryManager::xMalloc(int pSize){
	for (int index = 1; index < _Memoria->getLength(); index++ ){
		NodoSimple<xPointer>* nodoSpace = _Memoria->getItemByNumElem(index);
		if((*nodoSpace->val).getReference() == -1){    //status libre
			xPointer newSpace;
			(*nodoSpace->val).setReference(1);
			newSpace.setLimitPointer((*nodoSpace->val).getLimitPointer());
			(*nodoSpace->val).setLimitPointer((*nodoSpace->val).getTopPointer() + pSize);
			newSpace.setTopPointer((*nodoSpace->val).getLimitPointer() + 1);
			std::string s;
			std::stringstream out;
			out << newSpace->getId();
			s = out.str();
			NodoSimple<xPointer> *newNodoSpace = new NodoSimple<xPointer>{s,&newSpace,NULL};
			_Memoria->insertItem(newNodoSpace);
			return *nodoSpace->val;
		}
	}
}

bool xMemoryManager::xFree(xPointer pXPointer){
	std::string s;
	std::stringstream out;
	out << pXPointer->getId();
	s = out.str();
	NodoSimple<xPointer> nodo = *_Memoria->getItemByKey(s);
	if(nodo.val->getReference() == 1){
		if(nodo.next->val->getReference() == -1){
			nodo.val->setLimitPointer(nodo.next->val->getLimitPointer());
			nodo.val->setReference(0);
			_Memoria->removeItem(nodo.next->key);
		}else{
			_Memoria->removeItem(s);
		}
	}else{
		nodo.val->setReference(nodo.val->getReference()-1);
	}
}

void xMemoryManager::xSet(bool type,xPointer pXPointer){

}

xMemoryManager::~xMemoryManager() {
}
