#ifndef _TABBCom_ 
#define _TABBCom_

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#include "tcomplejo.h"
#include "tvectorcom.h"
class TABBCom;
class TNodoABB{
    friend class TABBCom;

    private:
        TComplejo item;
        TABBCom iz;
        TABBCom de;
    public:
        TNodoABB();
        TNodoABB(TNodoABB &nodo);
        ~TNodoABB();
        TNodoABB & operator=(const TNodoABB &nodo);
};


class TABBCom{
    friend class TNodoABB;

    private:
        TNodoABB *nodo;
        void Copiar(TABBCom &arbol);
        void InordenAux(TVectorCom &vector,int &i);
        void PreordenAux(TVectorCom &vector,int &i);
        void PostordenAux(TVectorCom &vector,int &i);
    public:
        TABBCom();
        TABBCom(TABBCom &arbol);
        ~TABBCom();
        TABBCom & operator=(const TABBCom &nodo);
        bool operator==(TABBCom &arbol);
        bool EsVacio();
        bool Insertar(TComplejo &complejo);
        bool Borrar(TComplejo &complejo); 
        bool Buscar(TComplejo &complejo);  
        TComplejo Raiz();
        int Altura();
        int Nodos();
        int NodosHoja();
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();
        TVectorCom Niveles();
        friend ostream & operator<< (ostream &os, TABBCom &arbol);
};
#endif