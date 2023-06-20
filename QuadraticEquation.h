#pragma once
#include <iostream>

using namespace std;

template <class T>

class Quadratic_Equation {

private:
	
	T num1, num2, num3;

public:

	T x1, x2;

	Quadratic_Equation(T a, T b, T c);
	T x1_calc();
	T x2_calc();
};