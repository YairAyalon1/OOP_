#include "QuadraticEquation.h"
#include <math.h>


template <class T>
Quadratic_Equation<T>::Quadratic_Equation(T a, T b, T c) {
	num1 = a;
	num2 = b;
	num3 = c;
	x1 = 0;
	x2 = 0;
}

template <class T>
T Quadratic_Equation<T>::x1_calc() {
	x1 = (- num2 + (sqrt(pow(num2, 2) - (4 * num1 * num3)))) / (2 * num1);
	return x1;
}

template <class T>
T Quadratic_Equation<T>::x2_calc() {
	x2 = (-num2 - (sqrt(pow(num2, 2) - (4 * num1 * num3)))) / (2 * num1);
	return x2;
}

// Explicit instantiation
template class Quadratic_Equation<double>;