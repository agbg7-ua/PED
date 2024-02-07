#include "tvectorcom.h"
#include <cmath>

TVectorCom :: TVectorCom(){
    this->tamano = 0;
    this->c = new TComplejo[0];
}
TVectorCom :: TVectorCom(int tam){
    if(tam < 0){
        TVectorCom();
    }else{
        TComplejo com;
        this->tamano = tam;
        this->c = new TComplejo[tamano]; 
        for(int i = 0;i<tamano;i++){
            this->c[i] = com;
        }
    }
}
TVectorCom :: TVectorCom(const TVectorCom &tVector){
    this->tamano = tVector.tamano;
    this->c = new TComplejo[tamano];
    for(int i = 0; i < tamano; i++){
        this->c[i] = tVector.c[i];
    }
}
TVectorCom :: ~TVectorCom(){
    delete[] c;
    this->tamano = 0;
    this->c = NULL;
}
TVectorCom& operator=(const TVectorCom &vect){
    if(this != vect){
        (*this).~TVectorCom();
        this->tamano = vect.tamano;
        this-> c = new TComplejo[vect.tamano];
        for(int i = 0;i<this->tamano;i++){
            this->c[i] = vect.c[i];
        }
 
    }
    return (*this);
}
TVectorCom&  operator== (const TVectorCom &tVector){
    if(tamano != tVector.tamano){
        return false;
    }
    for(int i = 0;i<tamano;i++){
        if(c[i]== tVector.c[i]){
            return false;
        }
    }
    return true;
}

TVectorCom operator != (const TVectorCom &){
    if(tamano != tVector.tamano){
        return true;
    }
    for(int i = 0;i<tamano;i++){
        if(c[i]== tVector.c[i]){
            return true;
        }
    }   
    return false;
}

TComplejo &TVectorCom :: operator[] (int i){
    if(i > 0 && i <= this->tamano){
        return c[i-1];
    }
    return error;
}
TComplejo &TVectorCom :: operator[] (int i) const{
    TComplejo comp;
    if(i < 0 && i <= this->tamano){
        return c[i-1];
    }
    return tc;
}
int TVectorCom :: Tamano(){
    return tamano;
}
int TVectorCom :: Ocupadas(){
    int ocupadas = 0;
    TComplejo vacio;
    for(int i = 0;i<tamano;i++){
        if(c[i]==vacio){
            ocupadas++;
        }
    }
    return ocupadas;
}
bool TVectorCom :: ExisteCom(const TComplejo &tComplejo){
    bool existe = false;
    for(int i = 0; i < tamano; i++){
        if(c[i]== tComplejo){
            existe = true;
        }
    }
    return existe;
}
void TVectorCom :: MostrarComplejos(double argumento){
    cout << '[';
    for (int i = 0;i< tamano;i++){
        if(c[i].Re()>=argumento){
            cout << c[i];
            cout << "; "
        }
    }
    cout << ']';
    
}
bool TVectorCom :: Redimensionar(int entero){
    if(entero < 0){
        return false;
    }
    if(entero == this.tamano){
        return false;
    }
    if(entero > 0 && entero > this->tamano){
        TVectorCom tThis(*this);
        TComplejo comp;
        c->~TComplejo();
        c = new Complejo[tam];
        tamano = entero;
        for(int i = 0;i < tThis.tamano ;i++){
            c[i] = tThis.c[i];
        }
        for(int i = tThis.tamano;i < tam ;i++){
            c[i] = comp;
        }
        tThis.~TVectorCom();
        return true;
    }
    if(entero < this->tamano){
        TVectorCom vect(*this);
        this->c->~TComplejo();
        this->tamano = entero;
        for(int i = 0;i < entero;i++){
            c[i]=vect.c[i];
        }
        vect->~TVectorCom();
        return true;
    }
    return false;
}
ostream& operator<<(ostream &o,TVectorCom& obj){

}