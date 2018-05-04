#include "tp4.hpp"
#include <iostream>
#include <assert.h>
using namespace std;
/**
********************************************************************************************
Constructeurs et destructeur
**/

//Constructeur vide
template <typename T>
SmartPointer<T>::SmartPointer()
{
	*this->mNbRef = *this->mNbRef + 1;
}

//Constructeur avec valeur
template <typename T>
SmartPointer<T>::SmartPointer(T *ptr)
{
	*this->mNbRef = *this->mNbRef + 1;
	this->mPtr = ptr;
}

//Constructeur avec valeur et fonction de destruction
template <typename T>
SmartPointer<T>::SmartPointer(T *ptr, DeleteFunctionType dft)
{
	*this->mNbRef = *this->mNbRef + 1;
	this->mPtr = ptr;
	this->mDeleteFunction = dft;
}

//Constructeur par copie
template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &smp)
{
	mNbRef = smp.mNbRef;
	*mNbRef = *mNbRef + 1;
	mPtr = smp.mPtr;
}

//Destructeur
template <typename T>
SmartPointer<T>::~SmartPointer()
{
	if (*this->mNbRef > 1)
	{
		*this->mNbRef = *this->mNbRef - 1;
	}
	else
	{
		mDeleteFunction;
	}
}
/**
********************************************************************************************
Opérateurs
**/

//Opérateur =
template <typename T>
SmartPointer<T> &SmartPointer<T>::operator=(const SmartPointer<T> &copie)
{
	mNbRef = copie.mNbRef;
	*mNbRef = *mNbRef + 1;
	mPtr = copie.mPtr;
	mDeleteFunction = copie.mDeleteFunction;
	return *this;
}

//Opérateur ==
template <typename T>
bool SmartPointer<T>::operator==(const T &val)
{
	return *this->mPtr == val;
}

//Opérateur ->
template <typename T>
T *SmartPointer<T>::operator->()
{
	return this->mPtr;
}

//Opérateur *
template <typename T>
T &SmartPointer<T>::operator*()
{
	return *this->mPtr;
}

//Opérateur[]
template <typename T>
T& SmartPointer<T>::operator[](int idx) {
	return this->mPtr[idx];
}

/**
********************************************************************************************
Fonctions d'accès aux données du pointeur et fonctions de destruction
**/

template <typename T>
int SmartPointer<T>::getCount()
{
	return *this->mNbRef;
}

template <typename T>
int SmartPointer<T>::size(){
	size_t size = (sizeof this->mPtr / sizeof this->mPtr[0]);
	return size;
}

template <typename T>
void SmartPointer<T>::deletePtr(T *ptr)
{
	delete ptr;
}

template <typename T>
void SmartPointer<T>::deleteTab(T *ptr)
{
	delete[] ptr;
}

/**
********************************************************************************************
Boucle principale
**/

int main()
{
	// TEST LE COMPTE DE REFERENCES
	cout << "Début test références...";
	SmartPointer<int> sm(new int(4));
	SmartPointer<int> sm2 = sm;
	assert(sm2.getCount() == 2 && sm.getCount() == 2);
	SmartPointer<int> sm3;
	SmartPointer<int> sm4;
	cout << "Ok!" << endl;
	
	// TEST surcharge de =
	cout << "Début test surcharge de =...";
	sm3 = sm2;
	assert(sm3.getCount() == 3 && sm2.getCount() == 3);
	assert(sm.getCount() == 3);
	sm4 = sm2;
	assert(sm4.getCount() == 4 && sm3.getCount() == 4);
	assert(sm2.getCount() == 4 && sm.getCount() == 4);
	cout << "Ok!" << endl;
	
	// TEST LE DESTRUCTEUR
	cout << "Début test destructeur...";
	SmartPointer<std ::string> smartPS3;
	{
		SmartPointer<std ::string> smartPS(new string("bonjour"));
		SmartPointer<std ::string> smartPS2 = smartPS;
		smartPS3 = smartPS2;
	}
	assert(smartPS3.getCount() == 1);
	cout << "Ok!" << endl;

	// TEST surcharge de *
	cout << "Début du test de surcharge de *...";
	assert(*smartPS3 == "bonjour");
	assert(*sm4 == 4);
	*sm4 = 3;
	assert(*sm3 == 3);
	cout << "Ok!" << endl;

	
	// TEST surcharge de ->
	cout << "Début du test de surcharge de ->...";
	int length = smartPS3->size();
	assert ( length == 7) ;
	cout << "Ok!" << endl;
	
	// TEST surcharge de []
	cout << "Début de test de surcharge de []...";
	SmartPointer<int> tabTest (new int[7]);
	SmartPointer<int> tab(new int[7], SmartPointer<int>::deleteTab);
	tab[0] = 0;
	assert (tab.getCount()==1) ;
	cout << "Ok!" << endl;
	return 0;
}

