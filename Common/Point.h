/**============================================================================
Name        : Point.h
Created on  : 15.09.2021
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef CPP_ML_EXPERIMENTS_COMMON_H
#define CPP_ML_EXPERIMENTS_COMMON_H

#include <vector>
#include <ostream>
#include <cmath>


namespace Common
{
    template<size_t Size = 2, typename Ty = int>
    struct Point
    {
        using value_type = Ty;
        using value_type_reference = value_type&;
        using const_value_type [[maybe_unused]] = const value_type;

        static_assert(!std::is_same_v<value_type, void>,
                      "The type of the coordinates in the Point can not be void");
        static_assert(0 != Size, "Number of coordinates should not be equal zero");

    private:
        std::array<value_type, Size> coordinates{};

    public:
        Point() = default;

        Point(std::initializer_list<value_type> list)
        {
            static_assert(0 != Size, "Number of coordinates should not be equal zero");
            for (size_t pos{ 0 }; const auto & v : list)
            coordinates[pos++] = v;
        }

        explicit Point(const std::vector<value_type>& vec)
        {
            for (size_t pos{ 0 }; auto & v : coordinates)
            v = vec[pos++];
        }

        friend std::ostream& operator<<(std::ostream& stream, const Point<Size, value_type>& pt) {
            for (const value_type& v : pt.coordinates)
                stream << v << " ";
            return stream;
        }

        [[nodiscard]]
        friend Point<Size, value_type> operator+(const Point<Size, value_type>& pt1,
                                                 const Point<Size, value_type>& pt2)
        {
            Point<Size, value_type> pt;
            for (size_t n = 0; n < Size; ++n)
                pt.coordinates[n] += (pt1.coordinates[n] + pt2.coordinates[n]);
            return pt;
        }

        [[nodiscard]]
        friend Point<Size, value_type> operator-(const Point<Size, value_type>& pt1,
                                                 const Point<Size, value_type>& pt2)
        {
            Point<Size, value_type> pt;
            for (size_t n = 0; n < Size; ++n)
                pt.coordinates[n] += (pt1.coordinates[n] - pt2.coordinates[n]);
            return pt;
        }

        [[nodiscard]]
        friend Point<Size, value_type> operator*(const Point<Size, value_type>& pt, int v)
        {
            Point<Size, value_type> point;
            for (size_t n = 0; n < Size; ++n)
                point.coordinates[n] = (pt.coordinates[n] * v);
            return point;
        }

        [[nodiscard]]
        friend Point<Size, value_type> operator/(const Point<Size, value_type>& pt, int v)
        {
            Point<Size, value_type> point;
            for (size_t n = 0; n < Size; ++n)
                point.coordinates[n] = (pt.coordinates[n] / v);
            return point;
        }

        friend bool operator==(const Point<Size, value_type>& pt1,
                               const Point<Size, value_type>& pt2) {
            return pt1.coordinates == pt2.coordinates;
        }

        friend bool operator!=(const Point<Size, value_type>& pt1,
                               const Point<Size, value_type>& pt2) {
            return !(pt1 == pt2);
        }

        [[nodiscard]]
        double distanceTo(const Point<Size, value_type>& pt) const noexcept
        {
            double sqrDist{ 0 };
            for (size_t i{ 0 }; const auto & coord: coordinates)
            sqrDist += std::pow(coord - pt.coordinates[i++], 2);
            return std::sqrt(sqrDist);
        }

        [[nodiscard]]
        auto data() const noexcept -> decltype(auto)
        {
            return coordinates.data();
        }

        [[nodiscard]]
        auto data() noexcept -> decltype(auto) {
            return coordinates.data();
        }

        void assign(const std::vector<value_type>& vec)
        {
            for (size_t pos{ 0 }; auto & v : coordinates)
            v = vec[pos++];
        }

        value_type_reference operator[](size_t index) noexcept
        {
            // TODO: Assert size match
            return coordinates[index];
        }

        value_type operator[](size_t index) const noexcept
        {
            // TODO: Assert size match
            return coordinates[index];
        }

        // TODO: Remove from the Point class?????
        // Given two linearly independent vectors a and b, the cross product, a � b, is a vector
        // that is perpendicular to both a and b,[2] and thus normal to the plane containing them.
        [[nodiscard]]
        friend Point<Size, value_type> cross(const Point<Size, value_type>& pt1,
                                             const Point<Size, value_type>& pt2)
        {
            static_assert(3 == Size, "Points cross product availableWorkers only for points with Capacity == 3");
            Point<Size, value_type> pt{
                    pt1.coordinates[1] * pt2.coordinates[2] - pt1.coordinates[2] * pt2.coordinates[1],
                    pt1.coordinates[2] * pt2.coordinates[0] - pt1.coordinates[0] * pt2.coordinates[2],
                    pt1.coordinates[0] * pt2.coordinates[1] - pt1.coordinates[1] * pt2.coordinates[0]
            };
            return pt;
        }

        [[nodiscard]]
        value_type dot(const Point<Size, value_type>& pt) const noexcept
        {
            value_type dot { 0 };
            for (size_t i{ 0 }; const auto & coord: coordinates)
            dot += coord * pt.coordinates[i++];
            return dot;
        }

        [[nodiscard]]
        static value_type dot(const Point<Size, value_type>& pt1,
                              const Point<Size, value_type>& pt2) noexcept
        {
            value_type val{};
            for (size_t i = 0; i < Size; ++i)
                val += pt1[i] * pt2[i];
            return val;
        }

        [[nodiscard]]
        static Point<Size, value_type> midPoint(const Point<Size, value_type>& pt1,
                                                const Point<Size, value_type>& pt2) noexcept
        {
            Point<Size, value_type> ptMiddle;
            for (size_t i = 0; i < Size; ++i)
                ptMiddle[i] = (pt1[i] + pt2[i]) / 2;
            return ptMiddle;
        }

        // TODO: Add operator >
        // TODO: Add operator <
    };
}

#endif //CPP_ML_EXPERIMENTS_COMMON_H
