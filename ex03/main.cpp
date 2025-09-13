#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	std::cout << "Is ( 2,  2) inside triangle A(0,0), B(10,0), C(0,10)? ";
	std::cout << (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;

	Point outside(10, 10);
	std::cout << "Is (10, 10) inside triangle A(0,0), B(10,0), C(0,10)? ";
	std::cout << (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;

	Point vertexA(0, 0);
	std::cout << "Is ( 0,  0) inside triangle A(0,0), B(10,0), C(0,10)? ";
	std::cout << (bsp(a, b, c, vertexA) ? "Yes" : "No") << std::endl;

	Point onEdge(5, 0);
	std::cout << "Is ( 5,  0) inside triangle A(0,0), B(10,0), C(0,10)? ";
	std::cout << (bsp(a, b, c, onEdge) ? "Yes" : "No") << std::endl;

}