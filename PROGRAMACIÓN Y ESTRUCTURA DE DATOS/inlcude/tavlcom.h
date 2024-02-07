#ifndef _TAVLCOM_H_
#define _TAVLCOM_H_

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;

class TNodoAVL;
class TAVLCom{
    friend class TNodoAVL;
    private:
        TNodoAVL *raiz;
        void PreordenAux( TVectorCom &, int &);
        void PostordenAux( TVectorCom &, int &);
        void InordenAux( TVectorCom &, int &);
        bool InsertarAux(const TComplejo &,bool &);
        bool BorrarAux(const TComplejo &,bool &);
        TNodoAVL CamMax(TAVLCom &);
        void EqIzquierda();
        void EqDerecha();
    public:
        TAVLCom ();
        TAVLCom (const TAVLCom &);
        ~TAVLCom ();
        TAVLCom & operator=(const  TAVLCom &);
        bool operator==(TAVLCom &) ;
        bool operator!=(TAVLCom &) ;
        bool EsVacio() const ;
        bool Insertar(const TComplejo &) ;
        bool Buscar(const TComplejo &);
        bool Borrar(TComplejo &) ;
        int Altura() const ;
        TComplejo Raiz() const ;
        int Nodos() const ;
        int NodosHoja() const ;
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();
        friend ostream & operator<<(ostream &,TAVLCom &);
};

class TNodoAVL{
    friend class TAVLCom;
    private:
        TComplejo item;
        TAVLCom iz, de;
        int fe;
    public:
        TNodoAVL ();
        TNodoAVL (const TNodoAVL &);
        ~TNodoAVL ();
        TNodoAVL & operator=(const TNodoAVL &);
};

#endif