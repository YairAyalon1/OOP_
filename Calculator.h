#pragma once
#include <iostream>

using namespace std;

template <class T>
class basic_instructions {

private:
	
	T num1, num2;

public:
	
	T sum, substruct, multiply, deviation;

	basic_instructions(T x, T y); // Constructor
	T sum_calc(); // Sum calculation
	T sub_calc(); // Substruction
	T mul_calc(); // Mutiplying
	T dev_calc(); // Deviation calculation
};

template <class T>
class average_calc : public basic_instructions<T> {

public:
	
	T avg;

	average_calc(T x, T y) : basic_instructions<T>(x, y) {} // Constructor
	T avg_calc(); // Average calculation
};