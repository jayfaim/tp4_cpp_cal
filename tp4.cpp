#include "tp4.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
SmartPointer<T>::SmartPointer()
{
	*this->mNbRef = *this->mNbRef + 1;
}

template <typename T>
SmartPointer<T>::SmartPointer(T *ptr)
{
	*this->mNbRef = *this->mNbRef + 1;
	this->mPtr = ptr;
}

template <typename T>
SmartPointer<T>::SmartPointer(T *ptr, DeleteFunctionType *dft)
{
	*this->mNbRef = *this->mNbRef + 1;
	this->mPtr = ptr;
	this->mDeleteFunction = dft;
}

// Constructeur par copie.
template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> &smp)
{
	mNbRef = smp.mNbRef;
	*mNbRef = *mNbRef + 1;
	mPtr = smp.mPtr;
}

template <typename T>
int SmartPointer<T>::getCount()
{
	cout << "test valeur *mPtr = " << *mPtr << endl;
	return *this->mNbRef;
}

template <typename T>
SmartPointer<T> &SmartPointer<T>::operator=(const SmartPointer<T> &copie)
{
	mNbRef = copie.mNbRef;
	*mNbRef = *mNbRef + 1;
	mPtr = copie.mPtr;
	mDeleteFunction = copie.mDeleteFunction;
	return *this;
}

template <typename T>
bool SmartPointer<T>::operator==(const T &val)
{
	return *this->mPtr == val;
}

template <typename T>
T *SmartPointer<T>::operator->()
{
	return this->mPtr;
}

template <typename T>
T &SmartPointer<T>::operator*()
{
	return *this->mPtr;
}

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

template <typename T>
T& SmartPointer<T>::operator[](int idx) {
	return this->mPtr[idx];
}

template <typename T>
int SmartPointer<T>::size(){
	size_t size = (sizeof this->mPtr / sizeof this->mPtr[0]);
	return size;
}

int main()
{
	cout << "Fuck you!!" << endl;
	cout << "***********tests jay*************" << endl;
	SmartPointer<int> test1(new int(4));
	SmartPointer<int> test2;
	test2 = test1;
	int tmp = test2.getCount();
	cout << "nbref = " << tmp << endl;
	tmp = test1.getCount();
	cout << "nbref = " << tmp << endl;
	SmartPointer<string> test3(new string("je suis une string test"));
	cout << "taille de test3 = " << test3->size() << endl;
	//string *str_tmp = *test3;
	//cout << "test operateur * test3 = " << *str_tmp << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "**********tests max**************" << endl;
	int foo[5] = {16, 2, 77, 40, 12071};
	SmartPointer<int> test5(new int(4));
	//int *patate = *test5;

	//SmartPointer < int > tab ( new int [7] , SmartPointer < int >::deleteTab ) ;

	//cout << "Fuck you!!" << *patate << endl;

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
	cout << "AVANT SON SMARTPS3" << *smartPS3 << endl;
	assert(*smartPS3 == "bonjour");
	assert(*sm4 == 4);
	*sm4 = 3;
	assert(*sm3 == 3);
	cout << "Ok!" << endl;

	
	// TEST surcharge de ->
	cout << "Début du test de surcharge de ->...";
	int length = smartPS3->size();
	cout << "BLABLA" << length << endl;
	assert ( length == 7) ;
	cout << "Ok!" << endl;
	// TEST surcharge de []
	
	
	cout << "Début de test de surcharge de []...";
	//int *tab = new int[7];
	//int size = (sizeof *tab / sizeof tab[0]); // size == 5
	//cout << "BLABLABLALBALB " << tab->size() << " AFKOSDKSAODKADOASK " << sizeof tab[0] << endl;
	//SmartPointer<int> tabTest (new int[7]);
	//cout << "Patate" << tabTest.size() << endl;
	//SmartPointer<int> tab(new int[7], SmartPointer<int>::deleteTab);
	//tab[0] = 0;
	//cout << tab[0] << endl ;
	//assert (tab.getCount()==1) ;
	//cout << "Ok!" << endl;
	return 0;
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