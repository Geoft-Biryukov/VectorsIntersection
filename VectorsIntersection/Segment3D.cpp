#include "Segment3D.h"

Vector3D Segment3D::direction() const 
{
	return end - start;
}

double Segment3D::length() const 
{
    return direction().length();
}

// ‘ункци€ дл€ нахождени€ точки пересечени€ двух отрезков
Vector3D Segment3D::Intersect(const Segment3D& seg1, const Segment3D& seg2) 
{
	Vector3D delta_u = seg1.direction();
	Vector3D delta_v = seg2.direction();
	Vector3D w = seg1.start - seg2.start;

	double u2 = delta_u.dot(delta_u);
	double v2 = delta_v.dot(delta_v);

	double uv = delta_u.dot(delta_v);
	double uw = delta_u.dot(w);
	double vw = delta_v.dot(w);

	double D = u2 * v2 - uv * uv;

	double t1, t2;

	// ¬ычисл€ем параметры дл€ ближайших точек на пр€мых
	if (D < 1e-10) {          // отрезки почти параллельны
		t1 = 0;
		t2 = (uv > v2 ? uw / uv : vw / v2);
	}
	else {
		t1 = (u2 * vw - uv * uw) / D;
		t2 = (uv * vw - v2 * uw) / D;
	}

	// ќграничиваем параметры в пределах отрезков
	if (t1 < 0) t1 = 0;
	if (t1 > 1) t1 = 1;
	if (t2 < 0) t2 = 0;
	if (t2 > 1) t2 = 1;

	// ¬ычисл€ем точки на отрезках
	Vector3D point1 = seg1.start + delta_v * t1;
	Vector3D point2 = seg2.start + delta_u * t2;

	// ѕровер€ем, совпадают ли точки (пересекаютс€ ли отрезки)
	Vector3D diff = point1 - point2;
	if (diff.length() < 1e-10) {
		return point1;  // отрезки пересекаютс€
	}
	else {
		throw std::runtime_error("ќтрезки не пересекаютс€");
	}
}
