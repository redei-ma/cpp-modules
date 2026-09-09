#include "Point.hpp"

/*
** AREA APPROACH - Point-in-triangle test
**
** Idea: If P is inside triangle ABC, then:
** Area(ABC) = Area(PAB) + Area(PBC) + Area(PCA)
**
** If P is outside, the sum of areas will be greater than the original area
**
** Triangle area formula with coordinates:
** Area = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
*/

// Calculates the absolute value of a Fixed number
Fixed	absoluteValue(Fixed const value)
{
	if (value < Fixed(0))
		return (Fixed(0) - value);
	return (value);
}

// Calculates the area of a triangle using three points
// Formula: Area = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
Fixed	triangleArea(Point const p1, Point const p2, Point const p3)
{
	Fixed	area = ((p1.getX() * (p2.getY() - p3.getY())) +
					(p2.getX() * (p3.getY() - p1.getY())) +
					(p3.getX() * (p1.getY() - p2.getY())));

	area = absoluteValue(area);
	return (area / Fixed(2));
}

// Checks if the triangle is degenerate (area = 0, collinear points)
bool	isTriangleDegenerate(Fixed const area)
{
	if (area.getRawBits() == 0)
		return (true);
	else
		return (false);
}

// Checks if the point lies on any edge of the triangle
bool	isPointOnEdge(Fixed const area1, Fixed const area2, Fixed const area3)
{
	if ((area1.getRawBits() == 0) || (area2.getRawBits() == 0) || (area3.getRawBits() == 0))
		return (true);
	else
		return (false);
}

// Checks if two areas are equal (with tolerance for numerical errors)
bool	areAreasEqual(Fixed const totalSubAreas, Fixed const originalArea)
{
	Fixed	difference = absoluteValue(totalSubAreas - originalArea);

	if (difference.getRawBits() <= 4)
		return (true);
	else
		return (false);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	originalArea = triangleArea(a, b, c);

	if (isTriangleDegenerate(originalArea))
		return (false);

	Fixed	area1 = triangleArea(point, a, b);
	Fixed	area2 = triangleArea(point, b, c);
	Fixed	area3 = triangleArea(point, c, a);

	if (isPointOnEdge(area1, area2, area3))
		return (false);

	Fixed	totalSubAreas = area1 + area2 + area3;

	return (areAreasEqual(totalSubAreas, originalArea));
}
