#include "CircleAreaPerimeter.h"
#include <math.h>

#define pi 3.1415986

template <class T>
CircleAreaPerimeter<T>::CircleAreaPerimeter(T radius) {
	R = radius;
	area = 0;
	perimeter = 0;
}


template <class T>
T CircleAreaPerimeter<T>::area_calc() {
	area = pi * (pow(R, 2));
	return area;
}

template <class T>
T CircleAreaPerimeter<T>::perimeter_calc() {
	perimeter = 2 * pi * R;
	return perimeter;
}

// Explicit instantiation
template class CircleAreaPerimeter<double>;