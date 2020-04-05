#include <iostream>

using namespace std;


class MyComplex {

    friend MyComplex operator+(MyComplex v1, MyComplex v2);
    friend MyComplex operator+(MyComplex v1, double v2);
    friend MyComplex operator+(double v1, MyComplex v2);
    friend MyComplex operator+(MyComplex v1, int v2);
    friend MyComplex operator+(int v1, MyComplex v2);
    friend MyComplex operator-(MyComplex v1, MyComplex v2);
    friend MyComplex operator-(MyComplex v1, double v2);
    friend MyComplex operator-(double v1, MyComplex v2);
    friend MyComplex operator-(MyComplex v1, int v2);
    friend MyComplex operator-(int v1, MyComplex v2);
    friend MyComplex operator*(MyComplex v1, MyComplex v2);
    friend MyComplex operator*(MyComplex v1, double v2);
    friend MyComplex operator*(double v1, MyComplex v2);
    friend MyComplex operator*(MyComplex v1, int v2);
    friend MyComplex operator*(int v1, MyComplex v2);
    friend ostream& operator<<(ostream &o, MyComplex B);
    friend istream& operator>>(istream &i, MyComplex &B);

private:
    double Im, Re;

public:

    double getRe(){
        return Re;
    }
    double getIm(){
        return Im;
    }
    int setRe(double newRe){
        Re = newRe;
        return 1;
    }
    int setIm(double newIm){
        Im = newIm;
        return 1;
    }
    MyComplex (double pRe=0, double pIm=0){
        Re=pRe;
        Im=pIm;
    }

    MyComplex operator= ( MyComplex A){
        Re = A.Re;
        Im = A.Im;
        return *this;
    }
};

MyComplex operator+(MyComplex v1, MyComplex v2){
    MyComplex C;
    C.setRe(v1.getRe()+v2.getRe());
    C.setIm(v1.getIm()+v2.getIm());
    return C;
}

MyComplex operator+(MyComplex v1, double v2){
    MyComplex C;
    C.setRe(v1.getRe()+v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator+(int v1, MyComplex v2){
    return (v2+v1);
}

MyComplex operator+(MyComplex v1, int v2){
    MyComplex C;
    C.setRe(v1.getRe()+v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator+(double v1, MyComplex v2){
    return (v2+v1);
}

MyComplex operator-(MyComplex v1, MyComplex v2){
    MyComplex C;
    C.setRe(v1.getRe()-v2.getRe());
    C.setIm(v1.getIm()-v2.getIm());
    return C;
}

MyComplex operator-(MyComplex v1, double v2){
    MyComplex C;
    C.setRe(v1.getRe()-v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator-(double v1, MyComplex v2){
    return (v2-v1);
}

MyComplex operator-(MyComplex v1, int v2){
    MyComplex C;
    C.setRe(v1.getRe()-v2);
    C.setIm(v1.getIm());
    return C;
}

MyComplex operator-(int v1, MyComplex v2){
    return (v2-v1);
}

MyComplex operator*(MyComplex v1, MyComplex v2){
    MyComplex C;
    C.setRe(v1.getRe()*v2.getRe()-v1.getIm()*v2.getIm());
    C.setIm(v1.getRe()*v2.getIm()+v1.getIm()*v2.getRe());
    return C;
}

MyComplex operator*(MyComplex v1, double v2){
    MyComplex C;
    C.setRe(v1.getRe()*v2);
    C.setIm(v1.getIm()*v2);
    return C;
}

MyComplex operator*(double v1, MyComplex v2){
    return (v2*v1);
}

MyComplex operator*(int v1, MyComplex v2){
    return (v2*v1);
}

MyComplex operator*(MyComplex v1, int v2){
    MyComplex C;
    C.setRe(v1.getRe()*v2);
    C.setIm(v1.getIm()*v2);
    return C;
}



ostream& operator<<(ostream  &o, MyComplex B){
    if(B.getIm()<0)
        o<<B.getRe()<<B.getIm()<<"i";
    if(B.getIm()>0)
        o<<B.getRe()<<"+"<<B.getIm()<<"i";
    if(B.getIm()==0)
        o<<B.getRe();
}

istream& operator>>(istream &i, MyComplex &B){
    i>>B.Re;
    i>>B.Im;
    return i;
}


int main()
{
    MyComplex A;
    MyComplex B;
    MyComplex C;
    cout<<"A = ";
    cin>>A;
    cout<<"B = ";
    cin>>B;
    cout<<"A + B = (";
    C=A+B;
    cout<<C.getRe()<< ", " << C.getIm() << ")" <<endl;;
    return 0;
}