#ifndef INTERSECT_H
#define INTERSECT_H

#include "Segment3D.h"

bool Intersect(const Segment3D &seg1, const Segment3D &seg2, Vector3D &intersection, double eps = 1e-9);

#endif
