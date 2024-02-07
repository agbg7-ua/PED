#ifndef _tlistacalendario_ 
#define _tlistacalendario_

#include <iostream>
#include <cstring>
using namespace std;

#include "tcomplejo.h"
#include "tvectorcom.h"

class TListaNodo{
    friend class TListaPos;
    friend class TListaCom;

    private:
        TComplejo e;
        TListaNodo *siguiente;
        TListaNodo *anterior;

    public:
        TListaNodo();
        TListaNodo(const TlistaNodo &);
        ~TListaNodo();

        TListaNodo & operator=(const TListaNodo &);
};

class TListaPos{
    friend class TListaNodo;
    friend class TListaCom;

    private:
        //Para implementar la posicion a nodo de la lista de TCalendario
        TListaNodo *pos;

    public:
        TListaPos();
        TListaPos(const TListaPos &);
        ~TListaPos();
        
        TListaPos & operator=(const TListaPos &);
        bool operator==(const TListaPos &);
        bool operator!=(const TListaPos &);

        TListaPos Anterior()const;
        TListaPos Siguiente()const;
        bool EsVacia()const;
};

class TListaCom{
    friend class TListaNodo;
    friend class TListaPos;
    friend ostream & operator<< (ostream &, const TListaCom &);

    private:
        TListaNodo *primero;
        TListaNodo *ultimo;

    public:
        TListaCom();
        TListaCom(const TListaCom &);
        ~TListaCom();

        TListaCalendario & operator=(const TListaCalendario &);

        bool operator== (TListaCom &);
        bool operator!= (TListaCom &);
        TListaCom operator+ (TListaCom &);
        TListaCom operator- (TListaCom &);
        
        bool EsVacia() const;
        bool InsCabeza(const TComplejo &);
        bool InsertarI(const TComplejo &);
        bool InsertarD(const TComplejo &);
        bool Borrar(const TComplejo &);
        bool BorrarTodos(const TComplejo &);
        bool Borrar(const TListaPos &);
        

        TComplejo Obtener(const TListaPos &)const;
        bool Buscar(const TComplejo &) const;
        
        int Longitud() const;

        TListaPos Primera() const;
        TListaPos Ultima() const;

};
#endif