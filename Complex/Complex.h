/**
	Complex.h
	
	The Complex class is part of a larger framework. Though the standard library has
	ways of executing operations involving complex numbers, this class does it in a fashion
	that puts all the necessary functionality in one place, making it easier to use and maintain.

	Last updated: Sunday, April 16th 2007

	Copyright (c) Thomas Juhl Kappel, 2017
*/

#pragma once

class Complex
{
public:

	// The two parts that make up the complex number
	double Real;
	double Imaginary;

	const static Complex I;

	// Constructors
	Complex();
	Complex(const Complex&);
	Complex(double);
	Complex(double, double);

	// Arithmetical operations
	double Abs();
	double Arg();

	static Complex Exp(Complex);
	static Complex Log(Complex);
	Complex Pow(Complex);
	Complex Sqrt();

	// Operators
	Complex operator +(const Complex&);
	Complex operator -(const Complex&);
	Complex operator *(const Complex&);
	Complex operator /(const Complex&);

	operator double();

};
