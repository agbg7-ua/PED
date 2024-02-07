#include <iostream>
using namespace std;

#include "tlistacom.h"

TListaNodo::TListaNodo(){
    this->e= 0;
    this->siguiente = NULL;
    this->anterior = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &nodo){
    this->e = nodo.e;
    this->siguiente = nodo.siguiente;
    this->anterior = nodo.anterior
}

TListaNodo::~TListaNodo(){
    delete[]anterior;
    delete[]siguiente;
    this-> anterior = NULL;
    this-> siguiente = NULL;
    this->e = 0;
}

TListaNodo & TListaNodo::operator=(const TListaNodo &nodo){
    if(this != &nodo){  
        (*this).~TListaNodo();
        this->e = nodo.e;
        this->siguiente = nodo.siguiente;
        this->anterior = nodo.anterior;
    }
    return (*this);
}






TListaPos::TListaPos(){
    this->pos = NULL;
}

TListaPos::TListaPos(const TListaPos &obj){
    this->pos = obj.pos;
}

TListaPos::~TListaPos(){
    delete[]pos;
    this->pos = NULL;
}

TListaPos &  TListaPos::operator=(const TListaPos &obj){
    if(this != &obj){
        this->pos = obj.pos;
    }
    return (*this);
}

bool TListaPos::operator==(const TListaPos &obj) const{
    if(this->pos == obj.pos){
      return true;  
    }
    return false;
}

bool TListaPos::operator!=(const TListaPos &obj) const{ 
    if(this->pos == obj.pos){
      return false;  
    }
    return true;
}
TListaPos TListaPos::Anterior() const{
    TListaPos lista;
    if(this->pos->anterior != NULL){
        lista.pos = this->pos->siguiente;
    }
    return lista;
}
TListaPos TListaPos::Siguiente() const{
    TListaPos lista;
    if(this->pos->siguiente != NULL){
        lista.pos = this->pos->siguiente;
    }
    return lista;
}


bool TListaPos::EsVacia()const {
    if(this->pos == NULL){
        return true;
    }
    return false;
}



TListaCom::TListaCom(){
    this->primero = NULL;
    this->ultimo = NULL;
}

TListaCom::TListaCom(const TListaCom &obj){
   this->primero = NULL;
    for(TListaPos i = obj.Primera(); !i.EsVacia(); i = i.Siguiente()){ 
            this->Insertar(i.pos->c);
    }
}

TListaCom::~TListaCom(){

    TListaNodo *aux;

    while (this->primero != NULL){
        aux = this->primero->siguiente;
        delete this->primero;
        this->primero = aux;
    }
}

TListaCom & TListaCom::operator=(const TListaCom &obj){
    if(this != &obj){
        this->~TListaCom();
        for(TListaPos i = obj.Primera(); !i.EsVacia(); i = i.Siguiente()){ 
            this->Insertar(i.pos->c);
        }   
    }
    return (*this);
}

bool TListaCom::operator==(const TListaCom& obj){
   TListaPos posI,posD;
   posI = obj.Segunda();
   posD = obj.Primera();
   bool comprobar = true;
   while(!posI.EsVacia() && !posD.EsVacia() && comprobar == true){
    if(obj.Obtener(posD) != this->Obtener(posI)){
        comprobar=  false;
    }
    posD=obj.Siguiente();
    posI=obj.Siguiente();
   }
   if(comprobar && posI.EsVacia() && posD.EsVacia()){
        return true;
   }
    return false;
}
bool TListaCom :: operator !=(const TListaCom& obj){
    return(this->operator == (1));
}

TListaCom TListaCom::operator+ (TListaCom &obj){
    TListaCom resultado ;
    TListaPos pos;
    pos = obj.Ultima();
    while(!pos.EsVacia()){
        resultado=InsCabeza(obj.Obtener(pos));
        pos = pos.Anterior();
    }
    pos= this->Ultima();
    while(!pos.EsVacia()){
        resultado = InsCabeza(this->Obtener(pos));
    }
    return resultado;
}

TListaCom TListaCom::operator- (TListaCom &obj){
    TListaCom resultado;
    TListaPos pos;
    pos= obj.Ultima();
    while(!pos.EsVacia()){
        if(obj.Obtener(pos) == this->Obtener(pos)){
            resultado = InsCabeza(obj.Obtener(pos));
        }
        pos = pos.Anterior();
    }
    return resultado;
}

bool TListaCom::InsCabeza(const TComplejo &obj){
    TListaNodo nuevoNodo;
    nuevoNodo->c = obj;

    if(this->EsVacia()){  
        nuevoNodo->siguiente = NULL;    
        this->primero = nuevoNodo;
        return true;
    }
    else if(!this->Buscar(obj)){

        TListaNodo *nodo = new TListaNodo();
        nodo = this->primero;

        do{
            nuevoNodo->siguiente = nodo;
            this->primero = nuevoNodo;
            return true;
            nodo = nodo->siguiente;
        }while(nodo != NULL)

        return false; 
    }
    else return false;
}

bool TListaCom :: InsertarI(const TComplejo& obj){
    TListaNodo nuevoNodo;
    nuevoNodo->c = obj;
    TListaNodo *nodo = new TListaNodo();
    nodo = this->primero;
    do{
        nuevoNodo->anterior = nodo->anterior;
        nodo->anterior = nuevoNodo;
        return true;
        nodo = nodo->siguiente;
    }while(nodo != null);

}
bool TListaCom :: InsertarD(const TComplejo &){
    TListaNodo nuevoNodo;
    nuevoNodo->c = obj;
    TListaNodo *nodo = new TListaNodo();
    nodo = this->primero;
    do{
        nuevoNodo->siguiente = nodo->siguiente;
        nodo->siguiente = nuevoNodo;
        return true;
        nodo = nodo->siguiente;
    }while(nodo != null);

}
bool TListaCom::Borrar(const TComplejo &obj){
    TListaNodo *aux = this->primero;
    TListaNodo *aEliminar;

    while(aux != NULL){  
        if(this->primero->c == obj){
            aEliminar = this->primero;
            this->primero = this->primero->siguiente; 
            delete aEliminar;
            return true;  
        }

        else{
            if(aux->siguiente != NULL && aux->siguiente->c == obj){
                aEliminar = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente; 
                delete aEliminar;
                return true;
            }

            else aux = aux->siguiente;
        }  
    }
    return false;
}


bool TListaCom::BorrarTodos(const TComplejo& obj){
    TListaPos posic,aux;
    bool comprobar = false;
    while(posic.EsVacia()){
        aux = posic.Siguiente();
        if(posic.pos -> e== obj){
            comprobar = true;
            if(!posic.Siguiente().EsVacia()){
                posic.Siguiente().pos -> anterior = posic.Anterior().pos;
            }else{
                ultimo = posic.Anterior().pos;
                delete posic.pos;
            }
            
        }
        posic = aux;
    } 
    return comprobar; 
}


bool TListaCom::Borrar(const TListaPos& po){
    if(!po.EsVacia() && po.lista == this){
        if(!po.Anterior().EsVacia()){
            po.Anterior().pos -> siguiente = po.Siguiente().pos;
        }else{
            primero=po.Siguiente().pos;
        }
        if(!po.Siguiente().EsVacia()){
            po.Siguiente().pos->anterior = po.Anterior().pos;
        }else{
            ultimo = po.Anterior().pos;
        }
        delete po.pos;
        po.~TListaCom();
        return true;
    }
    return false;
}

bool TListaCom::EsVacia() const{
    if(this->primero == NULL)
        return true;
    return false;
}

TCalendario TListaCom::Obtener(const TListaPos &obj) const{
    for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente())
        if(i == obj)
            return i.pos->c;

    return TCalendario();
}

bool TListaCom::Buscar(const TComplejo &obj) const{
    for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente())
        if(i.pos->c == obj) 
            return true;
    return false;
}

int TListaCom::Longitud() const{
    int longitud = 0;
    for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente() )
        longitud++;
    return longitud;
}

TListaPos TListaCom::Primera() const{
    TListaPos tpos;
    if(this->EsVacia())
        return tpos;
    else{
        tpos.pos = this->primero;
        return tpos; 
    }
}
TListaPos TListaCom::Segunda() const{
    TListaPos tpos;
    if(this->EsVacia())
        return tpos;
    else{
        tpos.pos = this-> pos.Siguiente();
        return tpos; 
    }
}

TListaPos TListaCom::Ultima() const{
    TListaPos ultima = this->Primera();
    for(int i = 1; i < this->Longitud(); i++) 
        ultima = ultima.Siguiente();
    return ultima;
}




