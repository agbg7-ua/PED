#include "tcomplejo.h"
#include <cmath>


TComplejo :: TComplejo(){
    this->re = 0;
    this->im = 0;
}
TComplejo :: TComplejo(double real){
    this->im = 0;
    this->re = real;
}
TComplejo :: TComplejo(double real, double imaginaria){
    this->re = real;
    this->im = imaginaria;
}
TComplejo :: TComplejo(const TComplejo& tComplejo){
    this->re = tComplejo.re;
    this->im = tComplejo.im;
}
TComplejo :: ~TComplejo(){
    this->re = 0;
    this->im = 0;
}
TComplejo& operator= (const TComplejo& tComplejo){
    if(this!= &tComplejo){
        (*this).~TComplejo();
        this->re = tComplejo.re;
        this->im = tComplejo.im;
    }
    return *this;
}
TComplejo operator==(const TComplejo& tComplejo){
    return (this->re = tComplejo.re && this->im = tComplejo.im);
}
TComplejo operator!=(const TComplejo& tComplejo){
    return (!this->operator==(tComplejo));
}
TComplejo operator+ (const TComplejo& tComplejo){
    TComplejo comp;
    comp.re = this.re + tComplejo.re;
    comp.im = im + tComplejo.im;
}
TComplejo operator- (const TComplejo& tComplejo){
    TComplejo comp;
    comp.re = re - tComplejo.re;
    comp.im = im - tComplejo.im;
}
TComplejo operator* (const TComplejo& tComplejo){
    TComplejo comp;
    comp.re = re * tComplejo.re;
    comp.im = im * tComplejo.im;
}
TComplejo operator+ (double doub){
    TCompleo comp;
    comp.re = this.re + doub;
    comp.im = this.im;
    return comp;

}
TComplejo operator- (double doub){
    TCompleo comp;
    comp.re = this.re - doub;
    comp.im = this.im;
    return comp;


}
TComplejo operator* (double doub){
    TCompleo comp;
    comp.re = this.re * doub;
    comp.im = this.im * n;
    return comp;
}

bool TComplejo :: operator== (const TComplejo& tComplejo){
    bool igual = true;
    if(re == tComplejo.re && im == tComplejo.im){
        igual = true;
    }else{
        igual = false;
    }
    return igual;
}
bool TComplejo :: operator!= (const TComplejo& tComplejo){
    bool igual = true;
    if(re != tComplejo.re || im != tComplejo.im){
        igual = true;
    }else{
        igual = false;
    }
} 
double TComplejo :: Re(){
    return re;
}
double TComplejo :: Im(){
    return im;
}
void TComplejo :: Re(double real){
    re = real;
}
void TComplejo :: Im(double imaginaria){
    im = imaginaria;
}
double TComplejo :: Arg(void){
    double ag ;
    ag = (atan2(im,re));
    return ag;
}
double TComplejo :: Mod(void); {
    double mod;
    mod = sqrt(pow(re,2)+ pow(im,2));
    return mod;
}
friend TComplejo operator+ (double d, const TComplejo &obj){
    TComplejo complejo(d,0);
    return (complejo.operator + obj);
}
friend TComplejo operator- (double d, const TComplejo &obj){
    TComplejo complejo(d,0);
    return (complejo.operator - obj);
}
friend TComplejo operator* (double , const TComplejo &obj){
    TComplejo complejo(d,0);
    return (complejo.operator *obj);
}
ostream& operator<<(ostream& o,const TComplejo& t){
    o<<"("<<t.re<<" "<<t.im<< ")";
    return o;
}