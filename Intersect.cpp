#include "Segment3D.h"
#include <cmath>
#include <algorithm>

bool Intersect(const Segment3D &seg1, const Segment3D &seg2, Vector3D &intersection, double eps = 1e-9)
{
	Vector3D start1 = seg1.start();
	Vector3D start2 = seg2.start();
	Vector3D dir1 = seg1.direction();
	Vector3D dir2 = seg2.direction();
	Vector3D delta = start1 - start2;

	double a = dir1.dot(dir1);
	double e = dir2.dot(dir2);
	double f = dir2.dot(delta);
	double dirDot = dir1.dot(dir2);
	double denom = a * e - dirDot * dirDot;

	double s = 0.0, t = 0.0;

	if (std::fabs(denom) < eps)
	{
		if (delta.cross(dir1).length() > eps)
		{
			return false;
		}

		double absX = std::fabs(dir1.x());
		double absY = std::fabs(dir1.y());
		double absZ = std::fabs(dir1.z());
		int axis = 0;
		if (absY > absX && absY > absZ)
		{
			axis = 1;
		}
		else if (absZ > absX && absZ > absY)
		{ 
			axis = 2;
		}

		auto getCoord = [&](const Vector3D &v) -> double 
		{
			switch(axis) 
			{
			    case 0: return v.x();
			    case 1: return v.y();
			    case 2: return v.z();
			    default: return 0.0;
			}
		};

		double seg1Start = getCoord(seg1.start());
		double seg1End   = getCoord(seg1.end());
		double seg2Start = getCoord(seg2.start());
		double seg2End   = getCoord(seg2.end());

		if (seg1Start > seg1End)
		{ 
			std::swap(seg1Start, seg1End);
		}
		if (seg2Start > seg2End)
		{
			std::swap(seg2Start, seg2End);
		}

		double left  = std::max(seg1Start, seg2Start);
		double right = std::min(seg1End, seg2End);

		if (left > right + eps)
		{
			return false;
		}

		intersection = seg1.start();
		switch(axis) 
		{
			case 0: intersection.setX(left); break;
			case 1: intersection.setY(left); break;
			case 2: intersection.setZ(left); break;
		}

		return true;
	}

	s = (dirDot * f - e * dir1.dot(delta)) / denom;
	t = (dirDot * s + f) / e;

	if (s < -eps || s > 1.0 + eps)
	{
		return false;
	}
	if (t < -eps || t > 1.0 + eps)
	{
		return false;
	}

	Vector3D point1 = seg1.pointAt(s);
	Vector3D point2 = seg2.pointAt(t);

	if ((point1 - point2).length() > eps)
	{
		return false;
	}

	intersection = point1;
	return true;
}

