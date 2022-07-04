#ifndef _COMPLEX_H
#define _COMPLEX_H 1

class Complex{
	float real;
	float imag;
public:
	//constructors
	Complex();
	Complex(float real,float imag=0);
	Complex (const Complex& object);

	//overloaders
	Complex operator +(Complex c);
	Complex operator -(Complex c);
	Complex operator *(Complex c);
	Complex operator /(Complex c);
	void operator =(Complex c);
	bool operator ==(Complex c);

	//setters
	void assign(float real, float imag);

	//getters
	float getRealPart() const;
	float getImagPart() const;
	friend void print(Complex c);


	~Complex();
};

#endif