/**============================================================================
Name        : Tests.cpp
Created on  : 15.09.2021
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : Tests C++ project
============================================================================**/

#include <cstdlib>
#include <string_view>
#include <iostream>

#include "Point.h"
#include "Line.h"

#define ASSERT(expr) \
if (false == (expr)) \
std::cout << "Error at " << __FUNCTION__ << "." << __LINE__ << std::endl;

#define ASSERT_NOT(expr) \
if (true == (expr)) \
std::cout << "Error at " << __FUNCTION__ << "." << __LINE__ << std::endl;

namespace Common
{
    template<size_t Size, typename Type>
    Type Dot(const Point<Size, Type>& pt1, const Point<Size, Type>& pt2)
    {
        Type val{};
        for (size_t i = 0; i < Size; ++i)
            val += pt1[i] * pt2[i];
        return val;
    }
}

namespace Common::Testing
{

	void CreateFromVector() {
		std::vector<float> v {1,2,3};
		Point<3, float> pt;

		pt.assign(v);

		ASSERT(pt[0] == 1);
		ASSERT(pt[1] == 2);
		ASSERT(pt[2] == 3);
	}

	void MultiplyTest () {
		Point<3, float> pt {1, 2, 3};
		pt = pt * 3;

		ASSERT(pt[0] == 3);
		ASSERT(pt[1] == 6);
		ASSERT(pt[2] == 9);
	}

	void DevideTest() {
		Point<3, float> pt{ 3,6,9 };
		pt = pt / 3;

		ASSERT(pt[0] == 1);
		ASSERT(pt[1] == 2);
		ASSERT(pt[2] == 3);
	}

	void EqualTest() {
		Point<3, float> pt1{ 3,6,9 };
		Point<3, float> pt2{ 3,6,9 };

		ASSERT(pt1 == pt2);
	}

	void NotEqualTest() {
		Point<3, float> pt1{ 3,3,9 };
		Point<3, float> pt2{ 3,6,9 };

		ASSERT(pt1 != pt2);
	}

	void AccesByIndex() {
		Point<3, float> pt1{ 3,3,9 };
		std::cout << pt1[0] << std::endl;
	}

	void AccesByIndexConst() {
		const Point<3, float> pt1{ 3,3,9 };
		std::cout << pt1[0] << std::endl;
	}

	void SumTest()
	{
		{
			Point<3, float> pt1{ 1,2,3 }, pt2{ 2,3,4 }, pt3{3,5,7};
			ASSERT((pt1 + pt2) == pt3);
		}
		{
			Point<3, float> pt1{ 1,2 }, pt2{ 2,3 }, pt3{ 3,5 };
			ASSERT((pt1 + pt2) == pt3);
		}
	}

	void MinusTest()
	{
		{
			Point<3, float> pt1{ 1,2,3 }, pt2{ 2,3,4 }, pt3{ 3,5,7 };
			ASSERT((pt3 - pt2) == pt1);
		}
		{
			Point<3, float> pt1{ 1,2 }, pt2{ 2,3 }, pt3{ 3,5 };
			ASSERT((pt3 - pt2) == pt1);
		}
	}

	void DistanceTest()
	{
		/*
		{
			Types::Point<3, float> pt1{ 1,1,1 };
			Types::Point<3, float> pt2{ 3,3,3 };

			auto x = pt1[0] - pt2[0];
			auto y = pt1[1] - pt2[1];
			auto z = pt1[2] - pt2[2];

			ASSERT(pt1.distanceTo(pt2) == std::hypot(x, y, z));
		}
		*/

		/*
		Types::Point<3, float> pt1{ 1,1,1 };
		Types::Point<3, float> pt2{ 3,3,3 };

		auto x = pt1[0] - pt2[0];
		auto y = pt1[1] - pt2[1];
		auto z = pt1[2] - pt2[2];

		std::cout << std::setprecision(12) <<  pt1.distanceTo(pt2) << std::endl;
		std::cout << std::setprecision(12) << std::hypot(x, y, z) << std::endl;
		*/
	}

	void DotTests()
	{
		{
			Point<3, float> pt1{ 1,1,1 }, pt2{ 3,3,3 };
			ASSERT(pt1.dot(pt2) == Dot(pt1, pt2));
		}
		{
			Point<3, float> pt1{ 1,6 }, pt2{ 3,6 };
			ASSERT(pt1.dot(pt2) == Dot(pt1, pt2));
		}
		{
			Point<3, float> pt1{ 1,6 }, pt2{ 3,6 }, pt3{ 4, 6 };
			ASSERT_NOT(pt1.dot(pt2) == Dot(pt1, pt3));
		}
	}

	void DotTestsStatic()
	{
		{
			Point<3, float> pt1{ 1,1,1 }, pt2{ 3,3,3 };
			ASSERT((Point<3, float>::dot(pt1, pt2) == Dot(pt1, pt2)));
		}
		{
			Point<3, float> pt1{ 1,6 }, pt2{ 3,6 };
			ASSERT((Point<3, float>::dot(pt1, pt2) == Dot(pt1, pt2)));
		}
		{
			Point<3, float> pt1{ 1,6 }, pt2{ 3,6 }, pt3{ 5,6 };
			ASSERT_NOT((Point<3, float>::dot(pt1, pt2) == Dot(pt1, pt3)));
		}
	}

	void MidpointTestsStatic()
	{
		struct TestData2d {
			Point<2, float> pt1;
			Point<2, float> pt2;
			Point<2, float> mipoint;
		};

		struct TestData3d {
			Point<3, float> pt1;
			Point<3, float> pt2;
			Point<3, float> mipoint;
		};

		{
			const std::vector<TestData2d> data{
				{{0.0, 2.0}, {8.0, 8.0}, {4.0, 5.0}},
				{{3.0, 2.0}, {5.0, 9.0}, {4.0, 5.5}},
				{{-33.0, 23.0}, {54.0,94.0}, {10.5, 58.5}},
				{{-2.0, 233.0}, {-54.0, 123.0}, {-28, 178}},
			};

			for (const auto& pts : data) {
				ASSERT((Point<2, float>::midPoint(pts.pt1, pts.pt2) == pts.mipoint));
			}
		}

		{
			const std::vector<TestData3d> data{
				{{0.0, 2.0, 0}, {8.0, 8.0, 0}, {4.0, 5.0, 0}},
				{{3.0, 2.0}, {5.0, 9.0}, {4.0, 5.5}},
				{{-33.0, 23.0}, {54.0,94.0}, {10.5, 58.5}},
				{{-2.0, 233.0}, {-54.0, 123.0}, {-28, 178}},
			};

			for (const auto& pts : data) {
				ASSERT((Point<3, float>::midPoint(pts.pt1, pts.pt2) == pts.mipoint));
			}
		}
	}
}


namespace Common::LineTesting
{
	double getDistance2D(const Line<2>& line, const Point<2, double>& pt)
	{
		const auto& pt1 = line.getFirstPoint();
		const auto& pt2 = line.getSecondPoint();
		const double doubleArea = std::abs((pt2[1] - pt1[1]) * pt[0] -
			(pt2[0] - pt1[0]) * pt[1] +
			pt2[0] * pt1[1] - pt2[1] * pt1[0]);
		return  doubleArea / line.getLength();
	}

	// https://www.mathportal.org/calculators/analytic-geometry/line-point-distance.php
	double getDistance2D_2(const Line<2>& line, const Point<2, double>& pt)
	{
		const auto& pt1 = line.getFirstPoint();
		const auto& pt2 = line.getSecondPoint();
		const auto a = pt2[1] - pt1[1];
		const auto b = pt2[0] - pt1[0];
		const auto c = pt2[0] * pt1[1] - pt1[0] * pt2[1];
		return std::abs(a * pt[0] - b * pt[1] + c) / std::sqrt(a * a + b * b);
	}

	void Calc2DLineEquation(const Line<2>& line)
	{
		const auto& pt1 = line.getFirstPoint();
		const auto& pt2 = line.getSecondPoint();
		const auto a = pt2[1] - pt1[1];
		const auto b = pt2[0] - pt1[0];
		const auto c = pt2[0] * pt1[1] - pt1[0] * pt2[1];
		std::cout << a << " * X  + (" << c << ") = " << b << " * y" << std::endl;
	}

	void DistanceFromPoint_Test_2D()
	{
		const Point<2, double> pt0{ 4.0, 8.0 };
		const Point<2, double> pt1{ 1.0, 2.0 }, pt2{ 2.0, 6.0 };


		const double dist1 = getDistance2D({ pt1, pt2 }, { pt0 });
		const double dist2 = getDistance2D_2({ pt1, pt2 }, { pt0 });

		std::cout << "Distance actual   = " << dist1 << std::endl;
		std::cout << "Distance actual   = " << dist2 << std::endl;
		std::cout << "Distance expected = " << (double)6 / 17 * std::sqrt(17) << std::endl;

		Calc2DLineEquation({ pt1, pt2 });
	}

	//=================================================================================


	void Calc3DLineEquation(const Line<3>& line) {
		const auto& pt1 = line.getFirstPoint();
		const auto& pt2 = line.getSecondPoint();
		const auto a = pt2[1] - pt1[1];
		const auto b = pt2[0] - pt1[0];
		const auto c = pt2[0] * pt1[1] - pt1[0] * pt2[1];
		std::cout << a << " * X  + (" << c << ") = " << b << " * y" << std::endl;
	}

	// Add src with current pre-calculated values
	void DistanceFromPoint_Test_3D()
	{
		const Point<3, double> A{ 0.0, 4.0, 6 };
		const Point<3, double> B{ -6.0, 0, -2 }, C{ 2.0, 0, -2 };

		// Calc3DLineEquation({pt1, pt2});

		const Point<3, double> d = (C - B) / C.distanceTo(B);
		const Point<3, double> v = A - B;
		double t = Dot(v, d);
		const Point<3, double> P = B + d * t;

		std::cout << P << std::endl;
		std::cout << "Distance = " << P.distanceTo(A) << std::endl;
	}
}

#if 0
namespace Types::MatricesTests
{
	void CreateTest() {
		Matrix<2, 2> M {
			1, 2,
			3, 4
		};
		std::cout << M << std::endl;
	}

	void CreateTest1() {
		Matrix<4, 2> M {
			1, 2, 3, 4,
			5, 6, 7, 8
		};
		std::cout << M << std::endl;
	}

	void Multipy_3x3_Test()
	{
		Matrix<3, 3> a{
			1,  4,  3,
			2,  1,  5,
			3,  2,  1
		};

		Matrix<3, 3> b{
			5,  2,  1,
			4,  3,  2,
			2,  1,  5
		};

		/*
		a.data[0][0] = 1;
		a.data[1][0] = 4;
		a.data[2][0] = 3;

		a.data[0][1] = 2;
		a.data[1][1] = 1;
		a.data[2][1] = 5;

		a.data[0][2] = 3;
		a.data[1][2] = 2;
		a.data[2][2] = 1;

		b.data[0][0] = 5;
		b.data[1][0] = 2;
		b.data[2][0] = 1;

		b.data[0][1] = 4;
		b.data[1][1] = 3;
		b.data[2][1] = 2;

		b.data[0][2] = 2;
		b.data[1][2] = 1;
		b.data[2][2] = 5;
		*/


		std::cout << a << std::endl;
		std::cout << b << std::endl;

		auto c = a * b;
		std::cout << c << std::endl;
	}
}
#endif





int main([[maybe_unused]] const int argc,
         [[maybe_unused]] char** argv)
{
    const std::vector<std::string_view> args(argv + 1, argv + argc);

	namespace Testing = Common::Testing;
	namespace LineTesting = Common::LineTesting;

	Testing::CreateFromVector();
	Testing::DevideTest();
	Testing::MultiplyTest();
	Testing::EqualTest();
	Testing::NotEqualTest();
	Testing::DistanceTest();
	Testing::SumTest();
	Testing::MinusTest();
	Testing::DotTests();
	Testing::DotTestsStatic();
	Testing::MidpointTestsStatic();

	LineTesting::DistanceFromPoint_Test_2D();
	LineTesting::DistanceFromPoint_Test_3D();


    return EXIT_SUCCESS;
}
