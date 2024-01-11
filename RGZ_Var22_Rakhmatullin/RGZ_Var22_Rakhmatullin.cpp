// RGZ_Var22_Rakhmatullin.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Math.h"
#include "InputOutput.h"

struct SResult
{
    std::vector<std::vector<float>> S;
    std::vector<std::vector<float>> S_transform;
    std::vector<std::vector<std::string>> S_string;
    std::vector<std::vector<float>> Original;
    std::vector<float> Q;
    std::vector<float> U;
    std::vector<float> Q_transform;
    std::vector<float> U_transform;
    std::string Input;
    float C;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SResult Result;
    std::cout << "Введите значение C: ";
    Result.C = Input::FloatCorrectInput();

    Math::Tabulate(Result.Original, Result.Q, Result.U, Result.C);

    Result.Q_transform = Result.Q;
    Result.U_transform = Result.U;

    Math::TransformationArray(Result.Q_transform, Result.U_transform);

    Math::GenerateMatrix(Result.Q_transform, Result.U_transform, Result.S);

    Result.S_transform = Math::TransformationMatrix(Result.S);

    Result.S_string = Math::FloatMatrixToString(Result.S_transform);

    std::cout.precision(3);

    Output::OutputXY(Result.Original);

    std::cout << "Массив Q без изменений: \n";

    Output::OutputArray(Result.Q);

    std::cout << "Массив U без изменений: \n";

    Output::OutputArray(Result.U);

    std::cout << "Массив Q c изменениями: \n";

    Output::OutputArray(Result.Q_transform);

    std::cout << "Массив U c изменениями: \n";

    Output::OutputArray(Result.U_transform);

    std::cout << "Матрица S без изменений: \n";

    Output::OutputMatrix(Result.S);

    std::cout << "Матрица S с изменениями: \n";

    Output::OutputMatrix(Result.S_transform);
}