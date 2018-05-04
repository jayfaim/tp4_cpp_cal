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
      T *mPtr;
      
      // un pointeur sur un entier compteur du nombre de références à mPtr.
      int *mNbRef = new int(0);

      //Définit le type DeleteFunctionType comme un pointeur sur une fonction void prenant
      //en argument un pointeur de T, exactement le type des fonctions deletePtr et deleteTab.
      typedef void (* DeleteFunctionType )(T *p);
      
      
      // un pointeur vers une fonction statique de destruction du pointeur.
      DeleteFunctionType mDeleteFunction;
    
      public :
      //Constructeur vide.
      SmartPointer<T>();

      //Constructeur avec valeur.
      SmartPointer<T>(T*);

      //Constructeur avec pointeur vers fonction de destruction et la donnée.
      SmartPointer<T>(T*, DeleteFunctionType);
      
      //Constructeur par copie(prend une référence vers un autre smartpointer)
      SmartPointer<T>(SmartPointer<T>&);
      
      //Fonctions de destruction passées au constructeur
      static void deletePtr(T*);
      static void deleteTab(T*);
      
      //Opérateurs
      ~SmartPointer<T>();
      SmartPointer<T>& operator=(const SmartPointer<T>&);
      bool operator==(const T&);
	    T* operator->();
	    T& operator*();
      T& operator[](int idx);

      //Fonctions d'accès
      int getCount();
      int size();
  };

#endif