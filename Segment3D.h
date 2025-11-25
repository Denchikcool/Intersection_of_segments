#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include "Vector3D.h"

class Segment3D
{
	private:
		Vector3D start_;
		Vector3D end_;

	public:
		Segment3D() {}
		Segment3D(const Vector3D &start, const Vector3D &end) : start_(start), end_(end) {}

		Vector3D start() const { return start_; }
		Vector3D end() const { return end_; }

		void setStart(const Vector3D &start) { start_ = start; }
		void setEnd(const Vector3D &end) { end_ = end; }

		Vector3D direction() const 
		{
			return end_ - start_;
		}

		Vector3D pointAt(double t) const 
		{
			return start_ + direction() * t;
		}

		double length() const 
		{
			return direction().length();
		}
};

#endif

