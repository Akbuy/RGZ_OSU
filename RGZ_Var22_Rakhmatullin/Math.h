#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Math
{
public:
    static void Tabulate(std::vector<std::vector<float>>& Original, std::vector<float>& Q, std::vector<float>& U, const float& C);

    static void TransformationArray(std::vector<float>& Q, std::vector<float>& U);

    static void GenerateMatrix(const std::vector<float>& Q, const std::vector<float>& U, std::vector<std::vector<float>>& S);

    static std::vector<std::vector<float>> TransformationMatrix(const std::vector<std::vector<float>>& S);

    static std::vector<std::vector<std::string>>& FloatMatrixToString(const std::vector<std::vector<float>>& A);

private:
    static float FunctionY(const float& X);

    static float MaxValueMatrix(const std::vector<std::vector<float>>& Matrix, size_t& I, size_t& J)
    {
        auto max = INT_MIN;

        for (size_t i = 0; i < Matrix.size(); i++)
        {
            for (size_t j = 0; j < Matrix[i].size(); j++)
            {
                if (Matrix[i][j] > max)
                {
                    max = Matrix[i][j];
                    I = i;
                    J = j;
                }
            }
        }
        return max;
    }

    static float MinValueMatrix(const std::vector<std::vector<float>>& Matrix, size_t& I, size_t& J)
    {
        auto min = INT_MAX;

        for (size_t i = 0; i < Matrix.size(); i++)
        {
            for (size_t j = 0; j < Matrix[i].size(); j++)
            {
                if (Matrix[i][j] < min)
                {
                    min = Matrix[i][j];
                    I = i;
                    J = j;
                }
            }
        }
        return min;
    }
};
