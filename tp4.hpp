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
      T *mPtr;
      
      // un pointeur sur un entier compteur du nombre de références à mPtr.
      int *mNbRef = new int(0);

      //J'ai bougé la redéfinition avant qu'on l'appelle sinon ca plante
      //Voici une définition qui pourra être utile pour la déclaration de vos pointeurs sur les fonctions statiques :
      //Cela définit le type DeleteFunctionType comme un pointeur sur une fonction void prenant
      //en argument un pointeur de T, exactement le type des fonctions deletePtr et deleteTab.
      
      typedef void (* DeleteFunctionType )(T *p);
      
      // un pointeur vers une fonction statique de destruction du pointeur.
      DeleteFunctionType* mDeleteFunction;
    
      public :
      //Constructeur vide
      SmartPointer<T>();

      SmartPointer<T>(T*);

      //Constructeur avec pointeur vers fonction de destruction et la donnée
      SmartPointer<T>(T*,DeleteFunctionType*);
      
      //Constructeur par copie(prend une référence vers un autre smartpointer)
      SmartPointer<T>(SmartPointer<T>&);
      
      static void deletePtr(T*);
      static void deleteTab(T*);
      
      void destructeur(SmartPointer);
      SmartPointer<T>& operator=(const SmartPointer<T> &copie);
      //SmartPointer operator->();
      //SmartPointer operator*(SmartPointer);
      //SmartPointer operator[](SmartPointer);
	    SmartPointer<T>& operator->();
	    SmartPointer<T>& operator*(const SmartPointer<T> &copie);
	    //SmartPointer<T>& operator[](const SmartPointer<T> &copie);
      SmartPointer<T>& operator[](int idx) const;
      SmartPointer<T>& operator=(const SmartPointer<T>&);
      SmartPointer<T>& operator->();
      SmartPointer<T>& operator*(const SmartPointer<T>&);
      SmartPointer<T>& operator[](const SmartPointer<T>&);
      // — La fonction getCount(), qui vous donnera accès au nombre de références à mPtr.
      //  Cette fonction pourra être utilisée durant le débogage avec “assert”. 
      int getCount();
  };

#endif