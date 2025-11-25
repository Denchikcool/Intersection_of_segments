#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

class Vector3D
{
	private:
		double x_;
		double y_;
		double z_;

	public:
		Vector3D() : x_(0.0), y_(0.0), z_(0.0) {}
		Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

		double x() const { return x_; }
		double y() const { return y_; }
		double z() const { return z_; }

		void setX(double x) { x_ = x; }
		void setY(double y) { y_ = y; }
		void setZ(double z) { z_ = z; }

		Vector3D operator+(const Vector3D &v) const 
		{
			return Vector3D(x_ + v.x_, y_ + v.y_, z_ + v.z_);
		}

		Vector3D operator-(const Vector3D &v) const 
		{
			return Vector3D(x_ - v.x_, y_ - v.y_, z_ - v.z_);
		}

		Vector3D operator*(double k) const 
		{
			return Vector3D(x_ * k, y_ * k, z_ * k);
		}


		double dot(const Vector3D &v) const 
		{
			return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
		}

		Vector3D cross(const Vector3D &v) const 
		{
			return Vector3D(y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_ * v.z_, x_ * v.y_ - y_ * v.x_);
		}

		double length() const 
		{
			return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
		}

};

#endif

