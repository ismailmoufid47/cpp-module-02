#include "Point.hpp"

float ft_fabs(float f)
{
	if (f < 0)
		return (-f);
	return (f);
}

float area(Point const &p1, Point const &p2, Point const &p3)
{
	return
		(
			ft_fabs
			(
				(
					  (p1.getX() * (p2.getY() - p3.getY()))
					+ (p2.getX() * (p3.getY() - p1.getY()))
					+ (p3.getX() * (p1.getY() - p2.getY()))
				).toFloat() * 0.5f
			)
		);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float total;
	float a1;
	float a2;
	float a3;

	total = area(a, b, c);

	a1 = area(point, b, c);
	a2 = area(a, point, c);
	a3 = area(a, b, point);

	if (a1 == 0 || a2 == 0 || a3 == 0 || a1 + a2 + a3 != total)
		return (false);

	return (true);
}