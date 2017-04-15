#include "Complex.h"

#include <cmath>

const Complex Complex::I(0.0, 1.0);

Complex::Complex() { Real = Imaginary = 0.0; }

Complex::Complex(const Complex& z) {
	Real = z.Real;
	Imaginary = z.Imaginary;
}

Complex::Complex(double real) {
	Real = real;
	Imaginary = 0.0;
}

Complex::Complex(double real, double imaginary) {
	Real = real;
	Imaginary = imaginary;
}

