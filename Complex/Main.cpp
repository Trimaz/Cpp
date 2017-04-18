#include "Complex.h"

#include <cstdio>

void main()
{
	Complex z(3.14, 5.7);
	Complex w(2.72, 9.3);
	Complex c = z + w;

	double d = (z / w);
	int i = z + w;
	printf("i = %d\n", i);

	auto y = z.Pow(2);

	printf("(%.15f, %.15f)", c.Real, c.Imaginary);
	printf("d = %f\n", d);
	printf("Exp((double)w(3, 4)) = %f %f\n", y.Real, y.Imaginary);
	printf("sqrt = %f %f", y.Sqrt().Real, y.Sqrt().Imaginary);

	getchar();
}
