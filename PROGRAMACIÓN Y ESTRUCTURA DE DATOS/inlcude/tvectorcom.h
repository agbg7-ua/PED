#ifndef _TVECTORCOM_H_
#define _TVECTORCOM_H_
#include <iostream>
#include "tcomplejo.h"

using namespace std;
class TVectorCom{
    public:
        TVectorCom();
        TVectorCom(int);
        TVectorCom(const TVectorCom&);
        ~TVectorCom();
        TVectorCom& operator=(const TVectorCom&);
        TVectorCom& operator==(const TVectorCom&);
        TVectorCom operator!=(const TVectorCom&);
   
        const TComplejo& operator[] (int);
        int Tamano();
        int Ocupadas();
        bool ExisteCom(const TComplejo&);
        void MostrarComplejos(double);
        bool Redimensionar(int);

        friend ostream& operator<<(ostream&,TVectorCom&);

    private:
        TComplejo *c;
        int tamano;
};
#endif