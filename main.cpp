#include <iostream>
#include "Intersect.h"

void testFunction(const Segment3D &s1, const Segment3D &s2, const std::string &caseName)
{
    Vector3D point;
    std::cout << caseName << ":\n";
    if (Intersect(s1, s2, point))
    {
        std::cout << "  Пересечение в точке: " << "X(" << point.x() << "), " << "Y(" << point.y() << "), " << "Z(" << point.z() << ")\n";
    }
    else
    {
        std::cout << "  Пересечения нет\n";
    }
    std::cout << std::endl;
}


int main()
{
	Segment3D s1(Vector3D(0,0,0), Vector3D(1,1,1));
	Segment3D s2(Vector3D(1,0,0), Vector3D(0,1,1));
	testFunction(s1, s2, "Случай 1: пересечение в одной точке");

	Segment3D s3(Vector3D(0,0,0), Vector3D(1,0,0));
	Segment3D s4(Vector3D(0,1,1), Vector3D(1,1,1));
	testFunction(s3, s4, "Случай 2: скрещивающиеся отрезки");

	Segment3D s5(Vector3D(0,0,0), Vector3D(2,2,2));
	Segment3D s6(Vector3D(1,1,1), Vector3D(3,3,3));
	testFunction(s5, s6, "Случай 3: коллинеарные с перекрытием");

	Segment3D s7(Vector3D(0,0,0), Vector3D(1,1,1));
	Segment3D s8(Vector3D(2,2,2), Vector3D(3,3,3));
	testFunction(s7, s8, "Случай 4: коллинеарные без перекрытия");

	Segment3D s9(Vector3D(0,0,0), Vector3D(1,0,0));
	Segment3D s10(Vector3D(0,1,0), Vector3D(1,1,0));
	testFunction(s9, s10, "Случай 5: параллельные, не коллинеарные");
	
	return 0;
}
