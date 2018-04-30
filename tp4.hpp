/* Ceci est une première version du tp04. C'est un brouillon. (Je sais pas trop où m'en allez.)
*
*
*/
#ifndef SMARTPOINTER_HPP
  #define SMARTPOINTER_HPP
  #include <string>
  using namespace std;
  
  template <typename T>
  class SmartPointer
  {
    private :
      // un pointeur vers l’emplacement mémoire qui est “gardé” par l’instance SmartPointer.
      // Je suis pas sur du type des variables.
      T **mPtr;
      
      // un pointeur sur un entier compteur du nombre de références à mPtr.
      int *mNbRef;

              typedef void (* DeleteFunctionType )(T *p);


      // un pointeur vers une fonction statique de destruction du pointeur.
      DeleteFunctionType* mDeleteFonction;
    
    public :

      void deletePtr(T* ptr);
      void deleteTab(T* ptr);
      void constructeur();
      //Un constructeur prenant les arguments suivants :
      //  1. un pointeur vers la donnée à englober par votre SmartPointer
      //  2. un pointeur vers une fonction de destruction
      //void constructeur(*pointer, &destructeur());
      SmartPointer constructeur(SmartPointer p);
      void destructeur(SmartPointer p);
      SmartPointer operator=(SmartPointer p);
      SmartPointer operator->();
      SmartPointer operator*(SmartPointer p);
      SmartPointer operator[](SmartPointer p);
      // — La fonction getCount(), qui vous donnera accès au nombre de références à mPtr.
      //  Cette fonction pourra être utilisée durant le débogage avec “assert”. 
      int getCount() const;
    

        // Doc ? -> http://tipsandtricks.runicsoft.com/Cpp/MemberFunctionPointers.html
        //Voici une définition qui pourra être utile pour la déclaration de vos pointeurs sur les fonctions statiques :
        //typedef void (* DeleteFunctionType )(T *p);
        //Cela définit le type DeleteFunctionType comme un pointeur sur une fonction void prenant
        //en argument un pointeur de T, exactement le type des fonctions deletePtr et deleteTab.
      
  };

#endif