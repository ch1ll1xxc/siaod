#pragma once
#include <iostream>
#include <fstream>
#include <vector>

struct Marks_Stat
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

struct Group_Stat
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

struct Student_Stat
{
    std::string zachotka;
    std::string full_name;
    Group_Stat group;
    Marks_Stat marks;

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

struct Table_Stat
{
    Student_Stat students[100];
    unsigned tmp_st = 0;
    const unsigned max_st = 100;

    void input_one()
    {
        Student_Stat tmpStudent;
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
            Student_Stat tmpStudent;
            tmpStudent.input();
            students[tmp_st] = tmpStudent;
            ++tmp_st;
        }
    }

    void input(std::ifstream& in)
    {
        while (!in.eof())
        {
            Student_Stat tmpStudent;
            tmpStudent.input(in);
            students[tmp_st++] = tmpStudent;
        }
    }

    void output()
    {
        for (unsigned i = 0; i < tmp_st; i++)
        {
            Student_Stat student = students[i];
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

struct Marks_Vector
{
    std::vector<unsigned> marks;

    void input()
    {
        for (unsigned i = 0; i < 5; i++)
        {
            int tmp_mark;
            std::cin >> tmp_mark;
            marks.push_back(tmp_mark);
        }
    }

    void input(std::ifstream& in)
    {
        for (unsigned i = 0; i < 5; i++)
        {
            int tmp_mark;
            in >> tmp_mark;
            marks.push_back(tmp_mark);
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

struct Group_Vector
{
    std::vector<char> group;

    void input()
    {
        for (unsigned i = 0; i < 5; i++)
        {
            char tmp_sym;
            std::cin >> tmp_sym;
            group.push_back(tmp_sym);
        }
    }

    void input(std::ifstream& in)
    {
        for (unsigned i = 0; i < 5; i++)
        {
            int tmp_sym;
            in >> tmp_sym;
            group.push_back(tmp_sym);
        }
    }

    void output()
    {
        for (unsigned i = 0; i < 10; i++)
        {
            std::cout << group[i];
        }
    }
};

struct Student_Vector
{
    std::string zachotka;
    std::string full_name;
    Group_Vector group;
    Marks_Vector marks;

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

struct Table_Vector
{
    std::vector<Student_Vector>students;
    int tmp_st = 0;

    void input_one()
    {
        Student_Vector tmpStudent;
        tmpStudent.input();
        students.push_back(tmpStudent);
        ++tmp_st;
    }
     
    void input()
    {
        std::cout << "Enter amount of students: ";
        int value_of_students;
        std::cin >> value_of_students;
        for (unsigned i = 0; i < value_of_students; i++)
        {
            Student_Vector tmpStudent;
            tmpStudent.input();
            students.push_back(tmpStudent);
            ++tmp_st;
        }
    }

    void input(std::ifstream& in)
    {
        while (!in.eof())
        {
            Student_Vector tmpStudent;
            tmpStudent.input(in);
            students.push_back(tmpStudent);
            ++tmp_st;
        }
    }

    void output()
    {
        for (unsigned i = 0; i < tmp_st; i++)
        {
            Student_Vector student = students[i];
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

    
    void RemoveByAvg(float avg)
    {
        for (unsigned i = 0; i < tmp_st; i++)
        {
            if (students[i].marks.countAvg() <= avg)
            {
                students.erase(students.begin() + i);
            }
        }
    }
};