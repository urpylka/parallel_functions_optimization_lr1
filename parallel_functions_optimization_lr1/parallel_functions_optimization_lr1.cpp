#include "stdafx.h"
#include <intrin.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#pragma intrinsic(__rdtsc)

using namespace std;
int COUNT_OP = 100000000;
const double CPU_FR = 4000000000.0;
unsigned __int64 t1, t2;
double T;
const double x = 2.0;
const double y = 3.0;
const double a = 1.57;
double sa, ca;
double r1, r2;
double get_r1(double a, double x, double y) {return x*sin(a) + y*cos(a);}
double get_r2(double a, double x, double y) {return -x*cos(a) + y*sin(a);}
int main()
{
	printf("Count of iterations: %i\n", COUNT_OP);
	/////////////////////////////////////////////////////
	t1 = __rdtsc();
	printf("Time of test 1: ");
	for (int i = 0; i<COUNT_OP; i++)
	{
		r1 = x*sin(a) + y*cos(a);
		r2 = -x*cos(a) + y*cos(a);
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	printf("Time of test 2: ");
	t1 = __rdtsc();
	for (int i = 0; i<COUNT_OP; i++)
	{
		sa = sin(a);
		ca = cos(a);
		r1 = sa*x + ca*y;
		r2 = -ca*x + sa*y;
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	printf("Time of test 3: ");
	t1 = __rdtsc();
	for (int i = 0; i<COUNT_OP; i++)
	{
		r1 = get_r1(a, x, y);
		r2 = get_r2(a, x, y);
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	printf("Time of sin(a): ");
	t1 = __rdtsc();
	for (int i = 0; i<COUNT_OP; i++)
	{
		sa = sin(a);
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	printf("Time of cos(a): ");
	t1 = __rdtsc();
	for (int i = 0; i<COUNT_OP; i++)
	{
		ca = cos(a);
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	printf("Time of addition: ");
	t1 = __rdtsc();
	for (int i = 0; i<COUNT_OP; i++)
	{
		r1 = x+y;
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	printf("Time of multiply: ");
	t1 = __rdtsc();
	for (int i = 0; i<COUNT_OP; i++)
	{
		r1 = x*y;
	}
	t2 = __rdtsc();
	T = (t2 - t1) / CPU_FR;
	printf("%f\n", T);
	/////////////////////////////////////////////////////
	system("pause");
	return 0;
}