#pragma once
#include <iostream>
#include <fstream>

struct Marks
{
    unsigned marks[5];

    void input()
    {
        for (unsigned i = 0; i < 5; i++)
        {
            std::cin >> marks[i];
        }
    }

    void input(std::ifstream& in)
    {
        for (unsigned i = 0; i < 5; i++)
        {
            in >> marks[i];
        }
    }

    void output()
    {
        for (unsigned i = 0; i < 5; i++)
        {
            std::cout << marks[i] << " ";
        }
    }
    
    float countAvg()
    {
        float res = 0;
        for (unsigned i = 0; i < 5; i++)
        {
            res += marks[i];
        }
        res /= 5.f;
        return res;
    }
};

struct Group
{
    char index[10];

    void input()
    {
        for (unsigned i = 0; i < 10; i++)
        {
            std::cin >> index[i];
        }
    }

    void input(std::ifstream& in)
    {
        for (unsigned i = 0; i < 10; i++)
        {
            in >> index[i];
        }
    }

    void output()
    {
        for (unsigned i = 0; i < 10; i++)
        {
            std::cout << index[i];
        }
    }
};

struct Student
{
    std::string zachotka;
    std::string full_name;
    Group group;
    Marks marks;

    void input()
    {
        std::cin >> zachotka;
        std::cin >> full_name;
        group.input();
        marks.input();
    }

    void input(std::ifstream& in)
    {
        in >> zachotka;
        in >> full_name;
        group.input(in);
        marks.input(in);
    }

    void output()
    {
        std::cout << zachotka << ' ';
        std::cout << full_name << ' ';
        group.output();
        std::cout << ' ';
        marks.output();
        std::cout << ' ';
        std::cout << marks.countAvg();
        std::cout << '\n';
    }

    bool isGood()
    {
        return marks.countAvg() > 4.f;
    }
};

struct Table
{
    Student students[100];
    unsigned tmp_st = 0;
    const unsigned max_st = 100;

    void input_one()
    {
        Student tmpStudent;
        tmpStudent.input();
        students[tmp_st] = tmpStudent;
        ++tmp_st;
    }

    void input()
    {
        std::cout << "Enter amount of students: ";
        int value_of_students;
        std::cin >> value_of_students;
        for (unsigned i = 0; i < value_of_students; i++)
        {
            Student tmpStudent;
            tmpStudent.input();
            students[tmp_st] = tmpStudent;
            ++tmp_st;
        }
    }

    void input(std::ifstream& in)
    {
        while (!in.eof())
        {
            Student tmpStudent;
            tmpStudent.input(in);
            students[tmp_st++] = tmpStudent;
        }
    }

    void output()
    {
        for (unsigned i = 0; i < tmp_st; i++)
        {
            Student student = students[i];
            student.output();
        }
    }

    void goodTable()
    {
        for (unsigned i = 0; i < tmp_st; i++)
        {
            if (students[i].isGood())
            {
                std::cout << students[i].zachotka << '\n';
            }
        }
    }

    void Remove(unsigned index)
    {
        for (unsigned i = index; i < tmp_st; i++)
        {
            students[i] = students[i + 1];
        }
        --tmp_st;
    }

    void RemoveByAvg(float avg)
    {
        for (unsigned i = 0; i < tmp_st;)
        {
            if (students[i].marks.countAvg() <= avg)
            {
                Remove(i);
            }
            else
            {
                i++;
            }
        }
    }
};

