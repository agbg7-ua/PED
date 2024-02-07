#include <iostream>
using namespace std;

#include "tabbcom.h"

TNodoABB :: TNodoABB(){
    this->item = new TComplejo();
    this->iz = new TABBCom();
    this->de = new TABBCom();
}
TNodoABB :: TNodoABB(TNodoABB &nodo){
    this->item = nodo.item;
    this->iz = nodo.iz;
    this->de = nodo.de;
}
TNodoABB :: ~TNodoABB(){

}
TNodoABB :: TNodoABB & operator=(const TNodoABB &nodo){
    if(this != &nodo){  
        (*this).~TNodoABB();
        this->item = nodo.item;
        this->iz = nodo.iz;
        this->de = nodo.de;
    }
    return (*this);

}
void TABBCom :: Copiar(TABBCom &arbol){
    if(arbol.nodo != NULL){
        TNodoABB *aux = new TNodoABB();
        aux->item = arbol.nodo -> item;
        nodo = aux;
        Copiar(arbol.nodo->iz);
        Copiar(arbol.nodo->de);
    }else{
        nodo =  NULL;
    }


}
TABBCom :: TABBCom(){
   (*this).nodo = NULL;
}
TABBCom :: TABBCom(TABBCom &arbol){
    Copiar(arbol);
}
TABBCom :: ~TABBCom(){
    if((*this).nodo != NULL){
        [delete nodo];
        (*this).nodo = NULL;
    }
}
TABBCom :: TABBCom & operator=(const TABBCom &arbol){
    this-> TABBCom();
    Copiar(arbol);
    return *this;
}
bool TABBCom :: operator==(TABBCom &arbol){

}
void TABBCom :: InordenAux(TVectorCom &vector,int &i){
    if(nodo != NULL){
        (nodo->iz).InordenAux(vector,i);
        vector[i] = nodo->item;
        i++;
        (nodo->de),InordenAux(vector,i);
    }
}
void TABBCom :: PreordenAux(TVectorCom &vector,int &i){
    if(nodo != NULL){
        vector[i] = nodo->item;
        i++;  
        (nodo->iz).PreordenAux(vector,i);
        (nodo->de).PretordenAux(vector,i); 
    }   

}
void TABBCom :: PostordenAux(TVectorCom &vector,int &i){
    if(nodo != NULL){
        (nodo->iz).PostordenAux(vector,i);
        (nodo->de).PostordenAux(vector,i);
        vector[i] = nodo->item;
        i++;   
    }   
}
bool TABBCom :: EsVacio(){
    return ((*this).nodo == NULL);
}
bool TABBCom :: Insertar(TComplejo &complejo){
    if(EsVacio()){
        nodo = new TNodoABB(complejo);
        return true;
    }else if(complejo == nodo->item){
        return false;
    }else if(complejo < nodo->item){
        if(nodo->iz != NULL){
            return nodo->iz.Insertar(complejo);
        }else{
            nodo->iz = new TNodoABB(complejo);
            return true;
        }
    }else{
        if(nodo->de != NULL){
            return nodo->de.Insertar(complejo);
        }else{
            nodo->de = new TNodoABB(complejo);
            return true;
        }
    }
}
bool TABBCom :: Borrar(TComplejo &complejo){
    if (EsVacio()) { // Si el árbol está vacío
        return false;
    }
    else if (complejo < nodo->item) { // Si el complejo es menor que el nodo actual
        if (nodo->iz == NULL) { // Si no hay un subárbol izquierdo
            return false;
        }
        else { // Si hay un subárbol izquierdo
            bool resultado = nodo->iz->abb.Borrar(complejo); // Busca el complejo en el subárbol izquierdo
            if (nodo->iz->abb.EsVacio()) { // Si el subárbol izquierdo quedó vacío
                delete nodo->iz; // Borra el nodo del subárbol izquierdo
                nodo->iz = NULL;
            }
            return resultado;
        }
    }
    else if (complejo > nodo->item) { // Si el complejo es mayor que el nodo actual
        if (nodo->de == NULL) { // Si no hay un subárbol derecho
            return false;
        }
        else { // Si hay un subárbol derecho
            bool resultado = nodo->de->abb.Borrar(complejo); // Busca el complejo en el subárbol derecho
            if (nodo->de->abb.EsVacio()) { // Si el subárbol derecho quedó vacío
                delete nodo->de; // Borra el nodo del subárbol derecho
                nodo->de = NULL;
            }
            return resultado;
        }
    }
    else { // Si se encontró el complejo en el nodo actual
        if (nodo->iz == NULL) { // Si no hay subárbol izquierdo
            TNodoABB *temp = nodo->de; // Guarda el subárbol derecho en una variable temporal
            delete nodo; // Borra el nodo actual
            nodo = temp; // Asigna el subárbol derecho al nodo actual
            return true;
        }
        else if (nodo->de == NULL) { // Si no hay subárbol derecho
            TNodoABB *temp = nodo->iz; // Guarda el subárbol izquierdo en una variable temporal
            delete nodo; // Borra el nodo actual
            nodo = temp; // Asigna el subárbol izquierdo al nodo actual
            return true;
        }
        else { // Si hay subárbol izquierdo y derecho
            TNodoABB *temp = nodo->iz->Maximo(); // Busca el máximo del subárbol izquierdo
            nodo->item = temp->item; // Copia el complejo del máximo al nodo actual
            nodo->iz->abb.Borrar(temp->item); // Borra el nodo del subárbol izquierdo
            if (nodo->iz->abb.EsVacio()) { // Si el subárbol izquierdo quedó vacío
                delete nodo->iz; // Borra el nodo del subárbol izquierdo
                nodo->iz = NULL;
            }
            return true;
        }
    }
}
bool TABBCom :: Buscar(TComplejo &complejo){
    TNodoABB *nodoActual = nodo;
    while (nodoActual != NULL) {
        if (complejo == nodoActual->item) {
            return true;
        } else if (complejo < nodoActual->item) {
            nodoActual = nodoActual->iz;
        } else {
            nodoActual = nodoActual->de;
        }
    }
    return false;
}  
TABBCom :: TComplejo Raiz(){
    if(EsVacio()){
        return (*this).nodo -> item;
    }else{
        return item_error;
    }
}
int TABBCom :: Altura(){
    int a1,a2;
    if(EsVacio()){
        a1 = (nodo->iz).Altura();
        a2 =(nodo->de).Altura();
        return (1+(a1 ? a2 : a1));
    }else{
        return 0;
    }
}
int TABBCom :: Nodos(){
    if(EsVacio()){
        return 0;
    }
    queue<TNodoABB*> cola;
    int contadorNodos = 0;
    cola.push(nodo);
    while(!cola.empty()){
        TNodoABB *n = cola.front();
        cola.pop();
        contadorNodos++;
        if(n->iz != NULL){
            cola.push(n->iz);
        }if(n->de != NULL){
            cola.push(n->de);
        }
    }
    return contadorNodos;
}
int TABBCom :: NodosHoja(){
    if (EsVacio()) { // si el árbol está vacío, no hay nodos hoja
        return 0;
    }

    int nodosHoja = 0; // contador de nodos hoja
    queue<TNodoABB*> cola; // cola de nodos

    cola.push(nodo); // se encola la raíz del árbol

    while (!cola.empty()) { // mientras la cola no esté vacía
        TNodoABB* nodoActual = cola.front(); // se obtiene el primer nodo de la cola
        cola.pop(); // se desencola el nodo actual

        if (nodoActual->de== NULL && nodoActual->iz == NULL) { // si el nodo actual es hoja
            nodosHoja++; // se incrementa el contador de nodos hoja
        } else { // si el nodo actual no es hoja
            if (nodoActual->iz != NULL) { // si tiene subárbol izquierdo, se encola
                colaNodos.push(nodoActual->iz);
            }
            if (nodoActual->de != NULL) { // si tiene subárbol derecho, se encola
                colaNodos.push(nodoActual->de);
            }
        }
    }

    return nodosHoja;
}
TVectorCom TABBCom :: Inorden(){
    int posicion = 1;
    TVectorCom v(Nodos());
    InordenAux(v,posicion);
    return v;
}
TVectorCom TABBCom :: Preorden(){
    int posicion = 1;
    TVectorCom v(Nodos());
    PreordenAux(v,posicion);
    return v;
}
TVectorCom TABBCom :: Postorden(){
    int posicion = 1;
    TVectorCom v(Nodos());
    PostordenAux(v,posicion);
    return v;
}
TVectorCom TABBCom :: Niveles(){
    queue<TNodoABB*> cola;
    TVectorCom vector(Nodos());
    int i = 1;
    cola.push(nodo);
    while(!cola.empty()){
        TNodoABB *n = cola.front();
        cola.pop();
        vector[i] = n->item;
        i++;
        if(n->i< !=NULL){
            cola.push(n->iz);
        }if(n->de != NULL){
            cola.push(n->de);
        }
    }
    return vector;
}
friend ostream & operator<< (ostream &os, TABBCom &arbol){

}