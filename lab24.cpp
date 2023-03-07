#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c)
{
	return ComplexNumber(real*c.real - imag*c.imag, imag*c.real + real*c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c)
{
    ComplexNumber temp;
        temp.real = ((real * c.real) + (imag * c.imag))/(c.real*c.real + c.imag*c.imag);
        temp.imag = ((imag * c.real) - (real * c.imag))/(c.real*c.real + c.imag*c.imag);
        return temp;
}

bool ComplexNumber::operator==(const ComplexNumber &c)
{
    return real == c.real && imag == c.imag;
}

double ComplexNumber::abs()
{
    return sqrt((real*real) + (imag*imag));
}


double ComplexNumber::angle()
{
    return atan2(imag, real) *180/M_PI;
}

ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-1*c.imag);
}

ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
  ComplexNumber temp;
        temp.real = ((s * c.real) + (0 * c.imag))/(c.real*c.real + c.imag*c.imag);
        temp.imag = ((0 * c.real) - (s * c.imag))/(c.real*c.real + c.imag*c.imag);
        return temp;

}

bool operator==(double b,const ComplexNumber &c)
{
    return b == c.real && c.imag == 0;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
	if(c.real != 0){
		if (c.imag < 0) return os << c.real << c.imag<< "i";
		else if(c.imag > 0) return os << c.real << "+" << c.imag<< "i";
		else return os << c.real;
	} else if(c.imag != 0) return os << c.imag << "i";
	else return os << 0;

}