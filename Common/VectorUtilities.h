/**============================================================================
Name        : VectorUtilities.h
Created on  : 15.09.2021
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef CPP_ML_EXPERIMENTS_VECTORUTILITIES_H
#define CPP_ML_EXPERIMENTS_VECTORUTILITIES_H

#include <vector>
#include <numbers>
#include <numeric>

namespace VectorUtilities
{
    template<typename Ty>
    double mean(const std::vector<Ty>& data) noexcept {
        return std::accumulate(data.cbegin(), data.cend(), 0.0f) / data.size();
    }

    template<typename Ty>
    Ty MultAndSum(const std::vector<Ty>& data1,
                  const std::vector<Ty>& data2) noexcept
    {
        return std::inner_product(data1.begin(), data1.end(), data2.begin(), 0.0f);
    }

    // TODO: Rename to MultAndSum ?? or keep  'dot'
    template<typename Ty>
    Ty dot(const std::vector<Ty>& data1,
           const std::vector<Ty>& data2) noexcept
    {
        return std::inner_product(data1.begin(), data1.end(), data2.begin(), 0.0f);
    }

    template<typename Ty>
    std::vector<Ty> operator*(const std::vector<Ty>& vect, Ty value)
    {
        const typename std::vector<Ty>::size_type size { vect.size() };
        std::vector<Ty> result;
        result.reserve(size);
        for (size_t i = 0; i < size; ++i)
            result[i] *= value;
        return result;
    }

    template<typename Ty>
    std::vector<Ty> operator/(const std::vector<Ty>& vect, Ty value)
    {
        const typename std::vector<Ty>::size_type size { vect.size() };
        std::vector<Ty> result;
        result.reserve(size);
        for (size_t i = 0; i < size; ++i)
            result[i] /= value;
        return result;
    }


    //-------------------------------------------- Refactor ---------------------------------


    template<typename Ty>
    void Multiply(const std::vector<Ty>& in,
                  Ty val,
                  std::vector<Ty>& out) noexcept {
        out.clear();
        for (const auto& v: in)
            out.push_back(val * v);
    }

    template<typename Ty>
    void Multiply(const std::vector<Ty>& a,
                  const std::vector<Ty>& b,
                  std::vector<Ty>& out) noexcept
    {
        out.clear();
        for (size_t i = 0; i < a.size(); ++i)
            out.push_back(a[i] * b[i]);
    }

    template<typename Ty>
    void Devide(std::vector<Ty>& data,
                const Ty val) noexcept
    {
        for (Ty& v: data)
            v = v / val;
    }

    template<typename Ty>
    Ty SquareSum(const std::vector<Ty>& data) noexcept
    {
        Ty result = 0;
        for (auto& v: data)
            result += v * v;
        return result;
    }

    template<typename Ty>
    Ty SquareDifferences(const std::vector<Ty>& data1,
                         const std::vector<Ty>& data2) noexcept
    {
        const size_t size { data1.size() };
        Ty result = 0;
        for (size_t i = 0; i < size; ++i)
            result += (data1[i] - data2[i]) * (data1[i] - data2[i]);
        return result;
    }
}


#endif //CPP_ML_EXPERIMENTS_VECTORUTILITIES_H
