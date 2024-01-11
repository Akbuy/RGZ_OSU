#pragma once

#include <iostream>
#include <string>
#include <vector>

class Output
{
public:
    static void OutputXY(std::vector<std::vector<float>> V);
    static void OutputArray(std::vector<float> V);
    static void OutputMatrix(std::vector<std::vector<float>> V);
    static void OutputMatrix(std::vector<std::vector<std::string>> V);
};

class Input
{
public:
    static float FloatCorrectInput();
};