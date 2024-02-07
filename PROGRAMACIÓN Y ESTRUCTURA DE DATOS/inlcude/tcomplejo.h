#ifndef _TCOMPLEJO_H_
#define _TCOMPLEJO_H_
#include <iostream>

using namespace std;
class TComplejo{
    friend class TListaCom;
    friend class TVectorCom;
    public:
        TComplejo();
        TComplejo(double);
        TComplejo(double, double);
        TComplejo(const TComplejo&);
        ~TComplejo();
        TComplejo& operator= (const TComplejo&);

        TComplejo operator+ (const TComplejo&);
        TComplejo operator- (const TComplejo&);
        TComplejo operator* (const TComplejo&);
        TComplejo operator+ (double);
        TComplejo operator- (double);
        TComplejo operator* (double);

        bool operator== (const TComplejo&); 
        bool operator!= (const TComplejo&); 
        double Re(); 
        double Im(); 
        void Re(double); 
        void Im(double); 
        double Arg(void); 
        double Mod(void); 

        friend TComplejo operator+ (double , const TComplejo&);
        friend TComplejo operator- (double , const TComplejo&);
        friend TComplejo operator* (double , const TComplejo&);

    private:
        double re;
        double im;
};
#endif