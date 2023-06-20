#pragma once
#include <math.h>

template <class T>

class CircleAreaPerimeter {
private:

	T R;

public:

	T area, perimeter;

	CircleAreaPerimeter(T radius);
	T area_calc();
	T perimeter_calc();

};