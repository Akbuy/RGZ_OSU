#include "InputOutput.h"
#include <sstream>
#include <iomanip>

void Output::OutputXY(std::vector<std::vector<float>> V)
{
    std::cout << std::fixed
              << " \n"
                 "|    X    |    Y    |\n";
    for (auto& item : V)
    {
        std::cout << std::left << "|  " << std::setw(6) << item[0] << " |  " << std::setw(6) << item[1] << " |\n" << std::setw(0);
    }
    std::cout << "\n";
}

void Output::OutputArray(std::vector<float> V)
{
    std::cout << std::fixed << "\n";
    for (auto& item : V)
    {
        std::cout << std::left << "| " << std::setw(6) << item << " |  \n";
    }
    std::cout << "\n";
}

void Output::OutputMatrix(std::vector<std::vector<float>> V)
{
    std::cout << std::fixed << "\n";
    for (auto& item : V)
    {
        for (size_t i = 0; i < item.size(); i++)
        {
            if (i == 0)
                std::cout << std::left << "| " << std::setw(6) << item[i] << " | ";
            else
                std::cout << std::left << std::setw(6) << item[i] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Output::OutputMatrix(std::vector<std::vector<std::string>> V)
{
    std::cout << std::fixed << "\n";
    for (auto item : V)
    {
        for (size_t i = 0; i < item.size(); i++)
        {
            if (i == 0)
                std::cout << std::left << "| " << std::setw(6) << item[i] << " | ";
            else
                std::cout << std::left << std::setw(6) << item[i] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

float Input::FloatCorrectInput()
{
    std::string Input;
    std::getline(std::cin, Input);
    while (std::cin.fail() || std::cin.eof() || Input.find_first_not_of("0123456789,.-") != std::string::npos)
    {

        std::cout << "Invalid value, please enter a number: " << std::endl;

        if (Input.find_first_not_of("0123456789") == std::string::npos)
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        std::getline(std::cin, Input);
    }

    return std::stof(Input);
}
