// Written by: Yair Ayalon
// Date: 27/5/23
// This project combines between OOP (using a header file and a source file where all the methods are defined) to Threads and program efficiency.
// The program compare between using 0 / 1 / 2 /5 threads to execute some orders and the performance of the program is changed according to the amount of
// for loops in the functions definition before the main() function.
// Extra components: circle area and permiter calculation + quadratic equation calculation

#include <iostream>
#include "Calculator.h"
#include "QuadraticEquation.h"
#include "CircleAreaPerimeter.h"
#include <chrono>
#include <thread>

using namespace std;

void executionWithoutThreads(double number1, double number2, int amountOfIterations) {
	// Basic instructions
	basic_instructions<double> myObj1(number1, number2);
	cout << number1 << " + " << number2 << " = " << myObj1.sum_calc() << endl;
	int a = 0;
	for (auto i = 0; i < amountOfIterations; ++i) {
		a += i;
		cout << a;
	}
	cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << a << endl;
	cout << number1 << " - " << number2 << " = " << myObj1.sub_calc() << endl;
	int b = 0;
	for (auto i = 0; i < amountOfIterations; ++i) {
		b += i;
		cout << b;
	}
	cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << b << endl;
	cout << number1 << " * " << number2 << " = " << myObj1.mul_calc() << endl;
	int c = 0;
	for (auto i = 0; i < amountOfIterations; ++i) {
		c += i;
		cout << c;
	}
	cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << c << endl;
	cout << number1 << " / " << number2 << " = " << myObj1.dev_calc() << endl;
	int d = 0;
	for (auto i = 0; i < amountOfIterations; ++i) {
		d += i;
		cout << d;
	}
	cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << d << endl;
	// Average calculation
	average_calc<double> myObj2(number1, number2);
	cout << "The average of the numbers " << number1 << " & " << number2 << " is: " << myObj2.avg_calc() << endl;
	int e = 0;
	for (auto i = 0; i < amountOfIterations; ++i) {
		e += i;
		cout << e;
	}
	cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << e << endl;
}

void executionWith5Threads(double number1, double number2, int amountOfIterations) {
	// Basic instructions
	thread sumThread([=]() {
		basic_instructions<double> myObj1(number1, number2);
		cout << number1 << " + " << number2 << " = " << myObj1.sum_calc() << endl;
		int a = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			a += i;
			cout << a;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << a << endl;
		});
	thread subThread([=]() {
		basic_instructions<double> myObj1(number1, number2);
		cout << number1 << " - " << number2 << " = " << myObj1.sub_calc() << endl;
		int b = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			b += i;
			cout << b;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << b << endl;
		});
	thread mulThread([=]() {
		basic_instructions<double> myObj1(number1, number2);
		cout << number1 << " * " << number2 << " = " << myObj1.mul_calc() << endl;
		int c = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			c += i;
			cout << c;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << c << endl;
		});
	thread devThread([=]() {
		basic_instructions<double> myObj1(number1, number2);
		cout << number1 << " / " << number2 << " = " << myObj1.dev_calc() << endl;
		int d = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			d += i;
			cout << d;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << d << endl;
		});
	// Average calculation
	thread avgThread([=]() {
		average_calc<double> myObj2(number1, number2);
		cout << "The average of the numbers " << number1 << " & " << number2 << " is: " << myObj2.avg_calc() << endl;
		int e = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			e += i;
			cout << e;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << e << endl;
		});
	// Wait for all threads to finish
	sumThread.join();
	subThread.join();
	mulThread.join();
	devThread.join();
	avgThread.join();
}

void executionWith2Threads(double number1, double number2, int amountOfIterations) {
	// Basic instructions
	thread Thread1([=]() {
		basic_instructions<double> myObj1(number1, number2);
		cout << number1 << " + " << number2 << " = " << myObj1.sum_calc() << endl;
		int a = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			a += i;
			cout << a;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << a << endl;
		cout << number1 << " - " << number2 << " = " << myObj1.sub_calc() << endl;
		int b = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			b += i;
			cout << b;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << b << endl;
		cout << number1 << " * " << number2 << " = " << myObj1.mul_calc() << endl;
		int c = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			c += i;
			cout << c;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << c << endl;
		cout << number1 << " / " << number2 << " = " << myObj1.dev_calc() << endl;
		int d = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			d += i;
			cout << d;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << d << endl;
		});
	// Average calculation
	thread avgThread([=]() {
		average_calc<double> myObj2(number1, number2);
		cout << "The average of the numbers " << number1 << " & " << number2 << " is: " << myObj2.avg_calc() << endl;
		int e = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			e += i;
			cout << e;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << e << endl;
		});
	// Wait for all threads to finish
	Thread1.join();
	avgThread.join();
}

void executionWith1Threads(double number1, double number2, int amountOfIterations) {
	// All instructions
	thread Thread1([=]() {
		basic_instructions<double> myObj1(number1, number2);
		cout << number1 << " + " << number2 << " = " << myObj1.sum_calc() << endl;
		int a = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			a += i;
			cout << a;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << a << endl;
		cout << number1 << " - " << number2 << " = " << myObj1.sub_calc() << endl;
		int b = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			b += i;
			cout << b;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << b << endl;
		cout << number1 << " * " << number2 << " = " << myObj1.mul_calc() << endl;
		int c = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			c += i;
			cout << c;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << c << endl;
		cout << number1 << " / " << number2 << " = " << myObj1.dev_calc() << endl;
		int d = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			d += i;
			cout << d;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << d << endl;
		average_calc<double> myObj2(number1, number2);
		cout << "The average of the numbers " << number1 << " & " << number2 << " is: " << myObj2.avg_calc() << endl;
		int e = 0;
		for (auto i = 0; i < amountOfIterations; ++i) {
			e += i;
			cout << e;
		}
		cout << "The sum of all the numbers between 0 and " << amountOfIterations - 1 << " is: " << e << endl;
		});
	// Wait for all threads to finish
	Thread1.join();
}

void quadraticEquationCalculator(double x, double y, double z) {
	Quadratic_Equation<double> myObj1(x, y, z);
	cout << "The solutions for the quadratic eauation are: \n";
	cout << "x1 = " << myObj1.x1_calc() << endl;
	cout << "x2 = " << myObj1.x2_calc() << endl;
}

void circleAreaPerimeterCalc(double r) {
	CircleAreaPerimeter<double> myObj1(r);
	cout << "The circle area: " << myObj1.area_calc() << endl;
	cout << "The circle permiteter: " << myObj1.perimeter_calc() << endl;
}

int main() {

	double number1, number2;
	double R;
	int amountOfIterations;
	double a, b, c;
	cout << "Please enter the required amount of iterations to check the thread performance: ";
	cin >> amountOfIterations;
	cout << "Please enter the first number x: ";
	cin >> number1;
	cout << "Please enter the second number y: ";
	cin >> number2;

	// Execution without threads
	chrono::steady_clock::time_point start = chrono::steady_clock::now(); // Start execution
	for (auto i = 0; i < 1; ++i) {
		executionWithoutThreads(number1, number2, amountOfIterations);
	}
	chrono::steady_clock::time_point end = chrono::steady_clock::now(); // End execution
	chrono::duration<double> elapsed_seconds = end - start; // Calculate the elapsed time

	// Execution with 5 threads
	chrono::steady_clock::time_point start1 = chrono::steady_clock::now(); // Start execution
	for (auto i = 0; i < 1; ++i) {
		executionWith5Threads(number1, number2, amountOfIterations);
	}
	chrono::steady_clock::time_point end1 = chrono::steady_clock::now(); // End execution
	chrono::duration<double> elapsed_seconds1 = end1 - start1; // Calculate the elapsed time

	// Execution with 2 threads
	chrono::steady_clock::time_point start2 = chrono::steady_clock::now(); // Start execution
	for (auto i = 0; i < 1; ++i) {
		executionWith2Threads(number1, number2, amountOfIterations);
	}
	chrono::steady_clock::time_point end2 = chrono::steady_clock::now(); // End execution
	chrono::duration<double> elapsed_seconds2 = end2 - start2; // Calculate the elapsed time

	// Execution with 1 thread
	chrono::steady_clock::time_point start3 = chrono::steady_clock::now(); // Start execution
	for (auto i = 0; i < 1; ++i) {
		executionWith1Threads(number1, number2, amountOfIterations);
	}
	chrono::steady_clock::time_point end3 = chrono::steady_clock::now(); // End execution
	chrono::duration<double> elapsed_seconds3 = end3 - start3; // Calculate the elapsed time

	//Output the execution times
	cout << "Execution time without threads: " << elapsed_seconds.count() << " seconds." << std::endl; // Output the elapsed time
	cout << "Execution time with 5 threads: " << elapsed_seconds1.count() << " seconds." << std::endl; // Output the elapsed time
	cout << "Execution time with 2 threads: " << elapsed_seconds2.count() << " seconds." << std::endl; // Output the elapsed time
	cout << "Execution time with 1 threads: " << elapsed_seconds3.count() << " seconds." << std::endl; // Output the elapsed time

	// Quadratic_Equation testing
	cout << "--------------------------------------------\n";
	cout << "This program calculated the results of a quadratic equation.\n";
	cout << "Please enter the required values of the variables a, b, and c.\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	quadraticEquationCalculator(a, b, c);

	// Circle area and perimeter calculation
	cout << "--------------------------------------------\n";
	cout << "This program calculated the area and perimeter of a circle according a given radius.\n";
	cout << "Please enter the radius of the circle (m): ";
	cin >> R;
	circleAreaPerimeterCalc(R);

	return 0;
}
