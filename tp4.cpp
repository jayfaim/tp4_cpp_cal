#include "tp4.hpp"
#include <iostream>
using namespace std;
int main ( )
{
	cout << "bonjour!" << endl;
	//SmartPointer<int> test;
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
	SmartPointer < std :: string > smartPS3 ;
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
}