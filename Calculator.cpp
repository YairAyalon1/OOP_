#include "Calculator.h"

template <class T>
basic_instructions<T>::basic_instructions(T x, T y) {
    num1 = x;
    num2 = y;
    sum = 0;
    substruct = 0;
    multiply = 0;
    deviation = 0;
}

template <class T>
T basic_instructions<T>::sum_calc() {
    sum = num1 + num2;
    return sum;
}

template <class T>
T basic_instructions<T>::sub_calc() {
    substruct = num1 - num2;
    return substruct;
}

template <class T>
T basic_instructions<T>::mul_calc() {
    multiply = num1 * num2;
    return multiply;
}

template <class T>
T basic_instructions<T>::dev_calc() {
    deviation = num1 / num2;
    return deviation;
}

template <class T>
T average_calc<T>::avg_calc() {
    avg = this->sum_calc() / 2;
    return avg;
}

// Explicit instantiation
template class basic_instructions<double>;
template class average_calc<double>;
