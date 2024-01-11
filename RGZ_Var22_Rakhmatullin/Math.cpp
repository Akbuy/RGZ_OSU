#include "Math.h"

// y =3cos5x+2sinx, [-π, π], h =π/10.
void Math::Tabulate(std::vector<std::vector<float>>& Original, std::vector<float>& Q, std::vector<float>& U, const float& C)
{
    // Clear containers
    Q.clear();
    U.clear();

    std::vector<float> Temp;

    for (float i = -M_PI; i < M_PI; i += M_PI / 10)
    {
        Temp.push_back(FunctionY(i));
        Original.push_back(std::vector<float>() = {i, FunctionY(i)});
    }

    for (size_t i = 0; i < 21; i++)
    {
        if (Temp[i] < C)
        {
            Q.push_back(Temp[i]);
        }
        else if (Temp[i] < 0)
        {
            U.push_back(Temp[i]);
        }
    }
}

void Math::TransformationArray(std::vector<float>& Q, std::vector<float>& U)
{
    for (size_t i = 0; i < Q.size(); i++)
    {
        if (Q[i] > 0)
        {
            Q[i] = -1;
        }
    }

    for (size_t i = 0; i < U.size(); i++)
    {
        if (i % 2 == 0)
        {
            U[i] = powf(U[i], 2.0f);
        }
    }
}

void Math::GenerateMatrix(const std::vector<float>& Q, const std::vector<float>& U, std::vector<std::vector<float>>& S)
{
    const size_t Length = Q.size() < U.size() ? Q.size() : U.size();
    if (Length == 0) throw "The length of the array is zero";

    S = std::vector<std::vector<float>>(Length, std::vector<float>(Length, 0));

    for (size_t i = 0; i < Length; i++)
    {
        for (size_t j = 0; j < Length; j++)
        {
            if (Q[i] >= U[i])
            {
                S[i][j] = Q[i] - U[i];
            }
            if (Q[i] < U[i])
            {
                S[i][j] = Q[i] * U[i];
            }
        }
    }
}

std::vector<std::vector<float>> Math::TransformationMatrix(const std::vector<std::vector<float>>& S)
{
    std::vector<std::vector<float>> Temp = S;
    size_t i_min = -1;
    size_t j_min = -1;
    float Min = MinValueMatrix(S, i_min, j_min);

    size_t i_max = -1;
    size_t j_max = -1;
    float Max = MaxValueMatrix(S, i_max, j_max);

    Temp[i_min][j_min] = Max;
    Temp[i_max][j_max] = Min;

    return Temp;
}

std::vector<std::vector<std::string>>& Math::FloatMatrixToString(const std::vector<std::vector<float>>& Matrix)
{
    std::vector<std::vector<std::string>> Temp =
        std::vector<std::vector<std::string>>(Matrix.size(), std::vector<std::string>(Matrix[0].size()));

    for (size_t i = 0; i < Matrix.size(); i++)
    {
        for (size_t j = 0; j < Matrix[i].size(); j++)
        {
            Temp[i][j] = std::to_string(Matrix[i][j]);
        }
    }
    return Temp;
}

float Math::FunctionY(const float& X)
{
    return 3 * cosf(5 * X) + 2 * sinf(X);
}
