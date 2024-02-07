#include "tavlcom.h"

TNodoAVL :: TNodoAVL ():item(),iz(),de(){
    this->fe=0;
}

TNodoAVL :: TNodoAVL (const TNodoAVL &avl){
    this->iz = avl.iz;
    this->de = avl.de;
    this->fe = avl.fe;
    this->item = avl.item;
}

TNodoAVL :: ~TNodoAVL (){
    this-> fe = 0;
    this->iz.~TAVLCom();
    this->de.~TAVLCom();
    this->item.~TComplejo();
}

TNodoAVL & TNodoAVL :: operator=(const TNodoAVL &avl){

    if(this!=&avl){
        (*this).~TNodoAVL();
        this->iz=avl.iz;
        this->de=avl.de;
        this->fe=avl.fe;
        this->item=avl.item;
    }
    return *this;
}

void TAVLCom :: PreordenAux( TVectorCom &vect, int &pos){
    if(this->EsVacio() != true){
        if(raiz->iz.EsVacio() == false && raiz->de.EsVacio() == false){
            vect[pos] = this->raiz->item;
            pos++;
            raiz->iz.PreordenAux(vect,pos);
            pos++;
            raiz->de.PreordenAux(vect,pos);
        }else if(raiz->de.EsVacio() == false){
            vect[pos] = this->raiz->item;
            pos++;
            raiz->de.PreordenAux(vect,pos);
        }else if(raiz->iz.EsVacio() == false){
            vect[pos] = this->raiz->item;
            pos++;
            raiz->iz.PreordenAux(vect,pos);
        }else{
            vect[pos] = this->raiz->item;
        }

    }
}

void TAVLCom :: PostordenAux( TVectorCom &vect, int &pos){
    if(this->EsVacio() != true){
        if(raiz->iz.EsVacio() == false && raiz->de.EsVacio() == false){
            raiz->iz.PostordenAux(vect,pos);
            pos++;
            raiz->de.PostordenAux(vect,pos);
            pos++;
            vect[pos] = this->raiz->item;
        }else if(raiz->de.EsVacio() == false){
            raiz->de.PostordenAux(vect,pos);
            pos++;
            vect[pos] = this->raiz->item;
        }else if(raiz->iz.EsVacio() == false){
            raiz->iz.PostordenAux(vect,pos);
            pos++;
            vect[pos] = this->raiz->item;
        }else{
            vect[pos] = this->raiz->item;
        }

    }
}

void TAVLCom :: InordenAux( TVectorCom &vect, int &pos){
    if(this->EsVacio() != true && pos <= vect.Tamano()){
        if(raiz->iz.EsVacio() == false && raiz->de.EsVacio() == false){
            raiz->iz.InordenAux(vect,pos);
            pos++;
            vect[pos] = this->raiz->item;
            pos++;
            raiz->de.InordenAux(vect,pos);
        }else if(raiz->de.EsVacio() == false){
            vect[pos] = this->raiz->item;
            pos++;
            raiz->de.InordenAux(vect,pos);
        }else if(raiz->iz.EsVacio() == false){
            raiz->iz.InordenAux(vect,pos);
            pos++;
            vect[pos] = this->raiz->item;
            
        }else{
            vect[pos] = this->raiz->item;
        }

    }
}

void TAVLCom :: EqDerecha(){
    TNodoAVL* r = raiz;
    TNodoAVL* j;
    TNodoAVL* k;
    int E2 = 0;
    if(raiz->de.raiz->fe != 1){
        j=r->de.raiz;
        r->de.raiz = NULL;

        k=j->iz.raiz;
        j->iz.raiz = NULL;
        
        E2 = k->fe;
        r->de.raiz = k->iz.raiz;
        k->iz.raiz = NULL;

        j->iz.raiz = k->de.raiz;
        k->de.raiz = NULL;

        k->de.raiz=j;
        j = NULL;

        k->iz.raiz = r;
        r = NULL;
        
        k->fe = 0;

        if(E2 == -1){
            k->iz.raiz->fe = 0;
            k->de.raiz->fe = 1;
        }
        else if(E2 == 0){
            k->iz.raiz->fe = 0;
            k->de.raiz->fe = 0;
        }
        else if(E2 == 1){
            k->iz.raiz->fe = -1;
            k->de.raiz->fe = 0;
        }
        this->raiz = k;
    }else{
        j=r->de.raiz;
        r->de.raiz = NULL;

        r->de.raiz = j->iz.raiz;
        j->iz.raiz = NULL;

        j->iz.raiz = r;
        r = NULL;

        j->fe = 0;
        j->iz.raiz->fe = 0;

        this->raiz = j;
    }
}
void TAVLCom :: EqIzquierda(){
    TNodoAVL* r = raiz;
    TNodoAVL* j;
    TNodoAVL* k;
    int E2 = 0;
    if(raiz->iz.raiz->fe != 1){
        j=r->iz.raiz;
        r->iz.raiz = NULL;

        k=j->iz.raiz;
        j->iz.raiz = NULL;
        
        E2 = k->fe;
        r->iz.raiz = k->de.raiz;
        k->de.raiz = NULL;

        j->de.raiz = k->iz.raiz;
        k->iz.raiz = NULL;

        k->iz.raiz=j;
        j = NULL;

        k->de.raiz = r;
        r = NULL;
        
        k->fe = 0;

        if(E2 == -1){
            k->iz.raiz->fe = 0;
            k->de.raiz->fe = 1;
        }
        else if(E2 == 0){
            k->iz.raiz->fe = 0;
            k->de.raiz->fe = 0;
        }
        else if(E2 == 1){
            k->iz.raiz->fe = -1;
            k->de.raiz->fe = 0;
        }
        this->raiz = k;
    }else{
        j=r->iz.raiz;
        r->iz.raiz = NULL;

        r->iz.raiz = j->de.raiz;
        j->de.raiz = NULL;

        j->de.raiz = i;
        r = NULL;

        j->fe = 0;
        j->de.raiz->fe = 0;

        this->raiz = j;
    }
}

TComplejo TAVLCom :: CamMax(TAVLCom &avl){
    if(avl.raiz->de.EsVacio() == true && avl.raiz->iz.EsVacio()== true){
        return *avl.raiz;
    }
    if(avl.raiz->iz.EsVacio()== true){
        return *avl.raiz;
    }else{
        return CamMax(avl.raiz->iz);
    }
}
bool TAVLCom :: InsertarAux( TComplejo &comp, bool &aumenta){
    bool aumHijoIz = false;
    bool aumHijoDe = false;
    bool ok = false;

    if(this->EsVacio() == true){
        raiz=new TNodoAVL();
        raiz->item=comp;
        aumenta=true;
    }
    if(this->Buscar(comp) == true){
        return false;
    }
    if(raiz->item.Mod() == comp.Mod() && raiz->item.Re() == comp.Re() && raiz->item.Im() == comp.Im()){
        ok = raiz->iz.InsertarAux(comp,aumHijoIz);
    }else{
        if(raiz->item.Mod()== comp.Mod() && raiz->item.Re() > comp.Re()){
            ok = raiz->iz.InsertarAux(comp,aumHijoIz);
        }else{
            if(raiz->item.Mod() < comp.Mod()){
                ok = raiz->de.insertarAux(comp,aumHijoDe);
            }else{
                ok = raiz->iz.insertarAux(comp,aumHijoIz);
            }
            if(ok == false){
                ok = raiz->de.insertarAux(comp,aumHijoDe);
            } 
        }
        if(ok == false){
            ok = raiz->de.insertarAux(comp,aumHijoDe);
        }
    }
    if(aumHijoIz == true || aumHijoDe == true){
        if ((aumHijoDe == true && raiz->fe ==-1) || (aumHijoIz == true && raiz->fe ==1)) {
            aumenta=false;
            raiz->fe=0;
        }
        else if (aumHijoIz == true && raiz->fe == 0){
            aumenta = true;
            raiz->fe = -1;
        }
        else if (aumHijoDe == true && raiz->fe == 0){
            aumenta = true;
            raiz->fe = 1;
        }
        else if (aumHijoIz == true && raiz->fe == -1){
            aumenta = false;
            this->EqIzquierda();
        }
        else if (aumHijoDe == true && raiz->fe == 1){
            aumenta = false;
            this->EqDerecha();
        }
        else if(creceHijoDe == true && raiz->fe == 0){
            aumenta = true;
            raiz->fe = 1;
        }
        else if(aumHijoIz == true && raiz->fe == 0){
            aumenta = true;
            raiz->fe = -1;
        }
    }else{
        aumenta = false;
    }
    return ok;
}
bool TAVLCom :: BorrarAux(TComplejo &comp,bool &disminuye){
    bool disHijoIz =false;
    bool disHijoDe=false;
    bool ok=false;

    if(this->Nodos() == 1 && raiz->item == comp){
        disminuye = true;
        raiz->~TNodoAVL();
        raiz = NULL;
        return true;
    }
    if(this->Buscar(comp) == false){
        return false;
    }

    if(raiz->item == comp){
        disminuye = false;
        if(raiz->de.EsVacio() == false && raiz->iz.EsVacio() == true){
            raiz = raiz->de.raiz;
            return true;
        }else{
            TNodoAVL avl(CamMax(raiz->iz));
            if(avl.iz.EsVacio() == true){
                raiz->item = avl.item;

                raiz->iz.BorrarAux(avl.item,disHijoIz); 

                raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();
                if(raiz->fe == 2){
                    int E2;
                    TNodoAVL* r = raiz;
                    TNodoAVL* j;
                    TNodoAVL* k;
                    if(raiz->de.raiz->fe == 1){
                        j=r->de.raiz;
                        r->de.raiz = NULL;

                        r->de.raiz = j->iz.raiz;
                        j->iz.raiz = NULL;

                        j->iz.raiz = r;
                        r = NULL;

                        j->fe = 0;
                        j->iz.raiz->fe = 0;

                        raiz = j;
                    }else{
                        j=r->de.raiz;
                        r->de.raiz = NULL;

                        k=j->iz.raiz;
                        j->iz.raiz = NULL;
                        
                        r->de.raiz = k;
                        k = NULL;

                        j->iz.raiz = r;
                        r = NULL;

                        raiz = j;
                        raiz->fe = this->raiz->de.Altura() - this->raiz->iz.Altura();
                    }
                }

                return true;
            }else{
                raiz->item = avl.item;
                raiz->iz.Insertar(avl.iz.raiz->item);
                raiz->iz.BorrarAux(avl.item,disHijoIz); 
                return true;
            }
        }
    }
    if(ok == false){
        if(raiz->item.Mod() == comp.Mod() && raiz->item.Re() == comp.Re() && raiz->item.Im() > comp.Im()){
            ok = raiz->iz.BorrarAux(comp,disHijoIz);
        }else{
            if(raiz->item.Mod() == comp.Mod() && raiz->item.Re() > comp.Re()){
                ok = raiz->iz.BorrarAux(comp,disHijoIz);
            }else{
                if(raiz->item.Mod() < comp.Mod()){
                    ok = raiz->de.BorrarAux(comp,disHijoDe);
                }else{
                    ok = raiz->iz.BorrarAux(comp,disHijoIz);
                }
                if(borradoOK == false){
                    ok = raiz->de.BorrarAux(comp,disHijoDe);
                }
            }
            if(ok == false){
                ok = raiz->de.BorrarAux(comp,disHijoDe);
            }
        }
   }

    if (disHijoIz == true || disHijoDe == true){
        if ( (disHijoIz == true && raiz->fe ==-1) || (disHijoDe == true && raiz->fe ==1) ) {
            disminuye=false;
            raiz->fe=0;
        }else if (disHijoDe == true && raiz->fe == 0){
            disminuye = false;
            raiz->fe = -1;
        }else if (disHijoIz == true && raiz->fe == 0){
            disminuye = false;
            raiz->fe = 1;
        }else if (disHijoIz == true && raiz->fe ==1){
            if (this->raiz->de.raiz->fe == 0){
                disminuye = false;
            }else{
                disminuye = true;
            }
            EqDerecha();
        }else if (disHijoDe == true && raiz->fe ==-1){
            if (this->raiz->iz.raiz->fe == 0) {
                disminuye = false;
            }else{
                disminuye = true;
            }
            EqIzquierda();
        }else if(disHijoIz == true && raiz->fe == 0){
            disminuye = false;
            raiz->fe = 1;
        }else if(disHijoDe == true && raiz->fe == 0){
            disminuye = false;
            raiz->fe = -1;
        }
    }
    return ok;
}

TAVLCom :: TAVLCom (){

    this->raiz=NULL;
}

TAVLCom :: TAVLCom (const TAVLCom &avl){
    if(avl.EsVacio() == true){
        raiz=NULL;
    }
    else{
        raiz=new TNodoAVL(*(avl.raiz));
    }
}

TAVLCom :: ~TAVLCom (){
    this->raiz = NULL;
}

TAVLCom & TAVLCom :: operator=( TAVLCom &avl){
    if(this != &avl){
        (*this).~TAVLCom();
        if(avl.EsVacio() == true){
            this->raiz=NULL;
        }
        else{
            this->raiz = new TNodoAVL(*avl.raiz);
        }
    }
    return *this;
}

bool TAVLCom :: operator==( TAVLCom &avl){
    TVectorCom compO = avl.Preorden();
    TVectorCom compT = this->Preorden();
    if(compT.Tamano() == compO.Tamano()){
        for(int i = 1; i < compT.Tamano(); i++){
            if(avl.Buscar(compT[i]) == false){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

bool TAVLCom :: operator!=( TAVLCom &avl){
    return !(*this == avl);
}

bool TAVLCom :: EsVacio()const{
    if(this->raiz == NULL){
        return true;
    }else{
        return false;
    }
}

bool TAVLCom :: Insertar(const TComplejo &comp){
    bool aumenta=false;

    return InsertarAux(comp,aumenta);
}

bool TAVLCom :: Buscar( TComplejo &comp){
    bool encontrado = false;
    TVectorCom vect = this->Preorden();
    for(int i = 1;i<= vect.Tamano();i++){
        if(comp == vect[i]){
            encontrado = true;
        }
    }
    return encontrado;
}

bool TAVLCom :: Borrar(TComplejo &comp){
    bool disminuye =false;

    return BorrarAux(comp,disminuye);
}

int TAVLCom :: Altura()const{
    int altura=0;
    if(this->EsVacio() != true){
        altura= 1 + max(raiz->iz.Altura(), raiz->de.Altura());
    }else{
        altura = 0;
    }
    return altura;
}

TComplejo TAVLCom :: Raiz(){
    if(this->raiz == NULL){
        TComplejo comp;
        return comp;
    }else{
        return this->raiz->item;
    }

}

int TAVLCom :: Nodos()const{
    int nodos = 0;
    if(this->EsVacio() == true){
        nodos= 0; 
    }else{
        nodos = 1 + raiz->iz.Nodos() + raiz->de.Nodos(); 
    }
    return nodos;
}

int TAVLCom :: NodosHoja()const{
    int nodos=0;
    if(this->EsVacio() == true){
        nodos= 0; 
    }
    if(raiz->iz.EsVacio() == false && raiz->de.EsVacio()==false){
        nodos = raiz->iz.NosdosHoja() + raiz->de.NodosHoja();
    }
    else if(raiz->de.EsVacio() == false){
        nodos = raiz->de.NodosHoja();
    }else if(raiz->iz.EsVacio() == false){
        nodos = raiz->iz.NodosHoja();
    }else{
        nodos =1;
    }
    return nodos;
}

TVectorCom TAVLCom :: Inorden(){
    int pos=1;
    TVectorCom vect(Nodos());
    InordenAux(vect,pos);
    return vect;
}

TVectorCom TAVLCom :: Preorden(){
    int pos=1;
    TVectorCom vect(Nodos());
    PreordenAux(vect,pos);
    return vect;
}

TVectorCom TAVLCom :: Postorden(){
    int pos=1;
    TVectorCom vect(Nodos());
    PostordenAux(vect,pos);
    return vect;
}

ostream & operator<<(ostream &os, TAVLCom &avl){
    os << avl.Inorden();
    return os;
}