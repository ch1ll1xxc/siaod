#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

void Act(Table_Vector studentTable)
{
    std::cout << "Enter the code of action that you want" << std::endl;
    std::cout << "1 - Fill table by keyboard" << std::endl;
    std::cout << "2 - Fill table by .txt file" << std::endl;
    std::cout << "3 - Add note to table" << std::endl;
    std::cout << "4 - Make list of students (their numbers) which average mark more than 4.0" << std::endl;
    std::cout << "5 - Remove notes about students which average mark lower than given" << std::endl;
    std::cout << "6 - Write a table" << std::endl;
    std::cout << "0 - Finish" << std::endl;

    std::ifstream in("input.txt");
    
    unsigned ans;
    std::cin >> ans;

    if (ans == 1)
    {
        studentTable.input();
        Act(studentTable);
    }
    if (ans == 2)
    {
        studentTable.input(in);
        Act(studentTable);
    }
    if (ans == 3)
    {
        studentTable.input_one();
        Act(studentTable);
    }
    if (ans == 4)
    {
        studentTable.goodTable();
        Act(studentTable);
    }
    if (ans == 5)
    {
        float avg;
        std::cout << "Enter average mark: ";
        std::cin >> avg;
        studentTable.RemoveByAvg(avg);
        Act(studentTable);
    }
    if (ans == 6)
    {
        studentTable.output();
        Act(studentTable);
    }
    if (ans == 0)
    {
        return;
    }
}

int main()
{
    Table_Vector studentTable;
    Act(studentTable);
    return 0;
}

