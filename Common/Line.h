/**============================================================================
Name        : Line.h
Created on  : 15.09.2021
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef CPP_ML_EXPERIMENTS_COMMON_LINE_H
#define CPP_ML_EXPERIMENTS_COMMON_LINE_H

#include "Point.h"


namespace Common
{
    template<size_t _Dimensions>
    struct Line
    {
        using point_type = Point<_Dimensions, double>;
        using point_type_reference = point_type&;
        using const_type_reference = const point_type&;
        using const_point_type [[maybe_unused]] = const point_type;

        static_assert(0 != _Dimensions, "Number of dimensions should not be equal zero");
        // TODO: Add concepts ??

    private:
        point_type pt1;
        point_type pt2;

    public:
        Line(const Point<_Dimensions, double>& p1,
             const Point<_Dimensions, double>& p2) : pt1{ p1 }, pt2{ p2 } {
        }

    public:
        const_type_reference getFirstPoint() const noexcept {
            return pt1;
        }

        const_type_reference getSecondPoint() const noexcept {
            return pt2;
        }

        double getLength() const noexcept {
            return pt1.distanceTo(pt2);
        }

        double getDistanceFromPoint(const Point<_Dimensions, double>& pt) {
            std::cout << pt1 << std::endl;
            std::cout << pt2 << std::endl;
            std::cout << pt << std::endl;
            const double double_area = std::abs((pt2[1] - pt1[1]) * pt[0] -
                                                (pt2[0] - pt1[0]) * pt[1] +
                                                pt2[0] * pt1[1] -
                                                pt2[1] * pt1[0]);
            std::cout << double_area << std::endl;
            // const double line_segment_length = sqrt((x2*x2 - x1*x1) + (y2*y2 - y1*y1));
            return 0;
        }

        // TODO: Dot product
        // TODO: add calc equation of the line
        // TODO: Inersection of lines
        // TODO: Is intersection?
        // TODO: The algorithm to find the point of intersection of two 3D line segment
        // TODO: Distance from a point to a line - 3-Dimensional
        // TODO: Angle between two lines https://onlinemschool.com/math/assistance/cartesian_coordinate/line_angle/
        // TODO: Perf src
    };
}

#endif //CPP_ML_EXPERIMENTS_COMMON_LINE_H
