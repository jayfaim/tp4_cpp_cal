#include "tp4.hpp"
#include <iostream>
using namespace std;
	template <typename T>
	SmartPointer<T>::SmartPointer(){
		*this->mNbRef = *this->mNbRef + 1;
	}

	template <typename T>
	SmartPointer<T>::SmartPointer(T* ptr){
		*this->mNbRef = *this->mNbRef + 1;
		this->mPtr = ptr;
	}

	template <typename T>
	SmartPointer<T>::SmartPointer(T* ptr,DeleteFunctionType* dft){
		*this->mNbRef = *this->mNbRef + 1;
		this->mPtr = ptr;
		this->mDeleteFunction = dft;
	}

	template <typename T>
	SmartPointer<T>::SmartPointer(SmartPointer<T> &smp){
		mNbRef = smp.mNbRef;
		*mNbRef = *mNbRef + 1;
		mPtr = smp.mPtr;
	}	

	template<typename T>
	int SmartPointer<T>::getCount(){
		cout << "test valeur *mPtr = " << *mPtr << endl;
		return *this->mNbRef;
	}

	template<typename T>	
	void SmartPointer<T>::deletePtr(T* ptr){
		delete ptr;
	}
    
    template<typename T>
	void  SmartPointer<T>::deleteTab(T* ptr){
		delete[] ptr;
	}

	template<typename T>
	SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T> &copie){
		mNbRef = copie.mNbRef;
		*mNbRef = *mNbRef + 1;
		mPtr = copie.mPtr;
		mDeleteFunction = copie.mDeleteFunction;
		return *this;
	}
	template<typename T>
	T* SmartPointer<T>::operator->(){
		return &*this->mPtr;	
	}

	template<typename T>
	T* SmartPointer<T>::operator*(){
		return this->mPtr;
	}

	/**
	template<typename T>
	SmartPointer<T>::~SmartPointer(){
		if(*this->mNbRef > 1){
			*this->mNbRef = *this->mNbRef - 1;
		}else{
			*this->mDeleteFunction();
		}
	}
	**/
	/*
	template<typename T>
	SmartPointer<T>& SmartPointer<T>::operator[](int idx) const{
		return SmartPointer<T>[idx];
	}
	*/
	int main ( )
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
	string *str_tmp = *test3;
	cout << "test operateur * test3 = " << *str_tmp << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "**********tests max**************" << endl;
	int foo [5] = { 16, 2, 77, 40, 12071 };
	SmartPointer<int []> testTab1;
	SmartPointer<int> test5(new int(4));
	int *patate = *test5;
	

	
	cout << "Fuck you!!" << *patate << endl;

	/**
	// TEST LE COMPTE DE REFERENCES
	SmartPointer < int > sm ( new int (4) ) ;
	SmartPointer < int > sm2 = sm ;
	assert ( sm2 . getCount () == 2 && sm . getCount () == 2) ;
	SmartPointer < int > sm3 ;
	SmartPointer < int > sm4 ;
	// TEST surcharge de =
	sm3 = sm2 ;
	assert ( sm3 . getCount () ==3 && sm2 . getCount () ==3) ;
	assert ( sm . getCount () ==3) ;
	sm4 = sm2 ;
	assert ( sm4 . getCount () ==4 && sm3 . getCount () ==4) ;
	assert ( sm2 . getCount () ==4 && sm . getCount () ==4) ;
	// TEST LE DESTRUCTEUR
	SmartPointer< std :: string > smartPS3 ;
	{
		SmartPointer < std :: string > smartPS ( new string ( " bonjour " ) ) ;
		SmartPointer < std :: string > smartPS2 = smartPS ;
		smartPS3 = smartPS2 ;
	}
	assert ( smartPS3 . getCount () == 1) ;
	// TEST surcharge de *
	assert (* smartPS3 == " bonjour " ) ;
	assert (* sm4 == 4) ;
	* sm4 = 3;
	assert (* sm3 == 3) ;
	// TEST surcharge de ->
	int length = smartPS3 - > size () ;
	assert ( length == 7) ;
	// TEST surcharge de []
	SmartPointer < int > tab ( new int [7] , SmartPointer < int >:: deleteTab ) ;
	tab [0] = 0;
	cout << tab [0] << endl ;
	assert ( tab . getCount () ==1) ;
	**/
	return 0;
}