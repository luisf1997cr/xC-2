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
	localMemory.setPointerSize(5000000);
	localMemory.setReference(-1);
	std::string s;
	std::stringstream out;
	out << localMemory->getId();
	s = out.str();
	NodoSimple<xPointer> *n = new NodoSimple<xPointer>{s,new xPointer(localMemory),NULL};
	_Memoria->insertItem(n);
}

xPointer xMemoryManager::xMalloc(int pSize){
	for (int index = 1; index <= _Memoria->getNumberOfItems(); index++ ){
		NodoSimple<xPointer>* nodoSpace = _Memoria->getItemByNumElem(index);
		if(nodoSpace->val->getReference() == -1){    //status libre
			long int size = nodoSpace->val->getPointerSize();
			if (size >= pSize){
				xPointer newSpace;
				cout << newSpace->getId() << endl;
				newSpace.setReference(-1);
				nodoSpace->val->setReference(1);
				newSpace.setPointerSize(size - pSize);
				nodoSpace->val->setPointerSize(pSize);
				newSpace.setTopPointer(nodoSpace->val->getTopPointer() + pSize);
				std::string key;
				std::stringstream out;
				char* buff = new char[225];
				strcpy(buff,out.str().c_str());
				out << newSpace->getId();
				cout <<"mallocid" << newSpace->getId() << endl;
				cout <<"malloc" << out.str() << endl;
				_Memoria->insertItem(new NodoSimple<xPointer>{out.str(),new xPointer(newSpace),NULL});
				return *nodoSpace->val;
			}
		}
	}
	cout << "Memory Insufficient" << endl;
	exit(1);
}

bool xMemoryManager::xFree(xPointer pXPointer){
	cout << "free" << endl;
	std::string key;
	std::stringstream out;
	char* buff = new char[225];
	strcpy(buff,out.str().c_str());
	out << pXPointer->getId();
	NodoSimple<xPointer> nodo = *_Memoria->getItemByKey(out.str());
	cout << nodo.val->getTopPointer() << endl;
//	if(nodo.val->getReference() == 1){
//		if(nodo.next->val->getReference() == -1){
//			nodo.val->setPointerSize(nodo.next->val->getPointerSize());
//			nodo.val->setReference(0);
//			_Memoria->removeItem(nodo.next->key);
//		}else{
//			_Memoria->removeItem(out.str());
//		}
//	}else{
//		nodo.val->setReference(nodo.val->getReference()-1);
//	}
}

void xMemoryManager::xSet(bool type,xPointer pXPointer){

}

xMemoryManager::~xMemoryManager() {
}
