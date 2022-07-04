#include <iostream>
#include "complex.h"

using namespace std;

Complex :: Complex(){

	real = 0.0;
	imag = 0.0;
}

Complex :: Complex(float real ,float imag ){

	assign(real,imag);
}

Complex :: Complex(const Complex& object)
{
	real = object.real;
	imag = object.imag;
}

void Complex :: assign(float real,float imag){

	this->real = real;
	this->imag = imag;
}


void print(Complex c)
{
	std::cout<<c.getRealPart()<<" +"<<c.getImagPart()<<"j"<<std::endl;

}


Complex Complex :: operator +(Complex c){

	Complex temp;
	temp = Complex(real+c.getRealPart(),imag+c.getImagPart());

	return temp;
}


Complex Complex :: operator -(Complex c){

	return Complex((real-c.getRealPart()),(imag-c.getImagPart()) );
}

Complex Complex :: operator *(Complex c){

	return Complex((real*c.getRealPart()-imag*c.getImagPart()),(real*c.getImagPart()+imag*c.getRealPart()) );
}

Complex Complex :: operator /(Complex c){

	float denom =  c.getRealPart()*c.getRealPart()+c.getImagPart()*c.getImagPart();

	float numReal = real*c.getRealPart()+imag*c.getImagPart();

	float numImag = c.getRealPart()*imag - c.getImagPart()*real;

	return Complex(numReal/denom,numImag/denom);
}

void Complex :: operator =(Complex c){

 real = c.getRealPart();
 imag = c.getImagPart();

}

bool Complex :: operator ==(Complex c){

	if(this->real == c.getRealPart() && this->imag == c.getImagPart()) return true;

	return false;
}

float Complex :: getRealPart() const{

	return real;
}

float Complex :: getImagPart() const{

	return imag;
}

Complex :: ~Complex(){}
