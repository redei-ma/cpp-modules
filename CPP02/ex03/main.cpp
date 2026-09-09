#include "Point.hpp"
#include <iostream>

int main()
{
	// Triangle with vertices A(0,0), B(5,0), C(2.5,5)
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);

	std::cout << "=== TEST BSP FUNCTION ===" << std::endl;
	std::cout << "Triangle: A(0,0) B(5,0) C(2.5,5)" << std::endl;
	std::cout << std::endl;

	// Test 1: point inside
	Point p1(2.5f, 2.0f);
	std::cout << "Test 1 - Point P1(2.5, 2.0): ";
	if (bsp(a, b, c, p1))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	// Test 2: point outside
	Point p2(0.0f, 6.0f);
	std::cout << "Test 2 - Point P2(0.0, 6.0): ";
	if (bsp(a, b, c, p2))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	// Test 3: point on a vertex
	Point p3(0.0f, 0.0f);
	std::cout << "Test 3 - Point P3(0.0, 0.0) [vertex]: ";
	if (bsp(a, b, c, p3))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	// Test 4: point on an edge
	Point p4(2.5f, 0.0f);
	std::cout << "Test 4 - Point P4(2.5, 0.0) [edge]: ";
	if (bsp(a, b, c, p4))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	// Test 5: another point inside
	Point p5(2.0f, 1.5f);
	std::cout << "Test 5 - Point P5(2.0, 1.5): ";
	if (bsp(a, b, c, p5))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	return 0;
}
