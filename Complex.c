#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

// Signum / sign function
#define sgn(x) (x > 0 ? 1 : (x == 0 ? 0 : -1))

#define WriteLine(s) printf(s); printf("\n")

// Lav en datatype, der har en reel og en imaginær del
// Datatypen 'double' kan holde decimaltal og er meget præcis, deraf navnet
struct Complex
{
	double re;
	double im;

};

double C_abs(struct Complex z)
{
	return sqrt(z.re * z.re + z.im * z.im);
}

double C_arg(struct Complex z)
{
	return atan2(z.im, z.re);
}

struct Complex C_mul(struct Complex a, struct Complex b)
{
	// (a+b*i)(c+d*i) = ac - bd + i(bc + ad)
	struct Complex z;
	z.re = a.re * b.re - a.im * b.im;
	z.im = a.im * b.re + a.re * b.im;
	return z;
}

struct Complex C_div(struct Complex a, struct Complex b)
{
	// (a+b*i)/(c+d*i) = (ac + bd)/(c^2 + d^2) + i(bc - ad) / (c^2 + d^2)
	struct Complex z;
	z.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	z.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
	return z;
}

struct Complex C_sqrt(struct Complex z)
{
	// sqrt(a+b*i):
	//   a = sqrt((re + sqrt(re^2 + im^2)) / 2)
	//   b = sgn(im)sqrt((-re + sqrt(re^2 + im^2)) / 2)
	struct Complex w;
	w.re = sqrt((z.re + sqrt(z.re * z.re + z.im * z.im)) / 2.0);
	w.im = sgn(z.im) * sqrt((-z.re + sqrt(z.re * z.re + z.im * z.im)) / 2.0);
	return w;
}

struct Complex C_log(struct Complex z)
{
	// ln(z) = ln(|z|) + i*arg(z)
	struct Complex w;
	w.re = log(z.re * z.re + z.im * z.im) / 2.0;
	w.im = atan2(z.im, z.re);
	return w;
}

struct Complex C_exp(struct Complex z)
{
	// e^z = e^x(e^(iy)) = e^x * (cos(y) + i sin(y))
	struct Complex w;
	w.re = exp(z.re) * cos(z.im);
	w.im = exp(z.re) * sin(z.im);
	return w;
}

struct Complex C_pow(struct Complex a, struct Complex b)
{
	// (a+b*i)^(c+d*i) = (a^2+b^2)^((c+d*i)/2) * e^(-c*arg(a+i*b)) * ...
	// ... cos[c arg(a+ib) + 0.5 d ln(a^2 + b^2)] + i sin[c arg(a + i*b) + 0.5 d ln(a^2 + b^2)]
	struct Complex w;
	w.re = pow(a.re * a.re + a.im * a.im, b.re / 2.0) * exp(-b.im*C_arg(a)) * cos(b.re * C_arg(a) + 0.5 * b.im * log(a.re * a.re + a.im * a.im));
	w.im = pow(a.re * a.re + a.im * a.im, b.re / 2.0) * exp(-b.im*C_arg(a)) * sin(b.re * C_arg(a) + 0.5 * b.im * log(a.re * a.re + a.im * a.im));
	return w;
}

const char * C_str(struct Complex z)
{
	char *b = (char *)malloc(32 * sizeof(char));
	sprintf_s(b, 32, "(%.5f, %.5f)", z.re, z.im);
	return (const char *)b;
}

int main()
{
	struct Complex i, a, b, z;
	char buffer[64];
	int index, cont = 0;
	int d, e, f, g;

	printf("Enter 2 complex numbers as (a;b)(c;d): ");
	scanf_s("(%d;%d)(%d;%d)", &d, &e, &f, &g);
	puts("\n");
	getchar();
	a.re = d;
	a.im = e;
	b.re = f;
	b.im = g;

	// sqrt(-1)
	i.re = 0;
	i.im = 1;

	// 2 + 3i
	/*a.re = 2;
	a.im = 0;

	// 4 + 5i
	b.re = 4;
	b.im = 0;*/

	z = C_div(a, b);
	z = C_sqrt(b);

	WriteLine(C_str(C_exp(a)));
	WriteLine(C_str(C_exp(b)));
	WriteLine(C_str(C_pow(a, b)));
	getchar();
}
