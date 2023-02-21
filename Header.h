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
            std::cout << marks[i]<<" ";
        }
    }

    float avg()
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
    long long zachotka;
    std::string fullname;
    Group group;
    Marks marks;

    void input()
    {
        std::cin >> zachotka;
        std::cin >> fullname;
        group.input();
        marks.input();
        
    }

    void input(std::ifstream& in)
    {
        in >> zachotka;
        in >> fullname;
        group.input(in);
        marks.input(in);
    }

    void output()
    {
        std::cout << zachotka << ' ';
        std::cout << fullname << ' ';
        group.output();
        std::cout << ' ';
        marks.output();
        std::cout << '\n';
    }

    bool IsGood()
    {
        return marks.avg() > 4.f;
    }
};

struct Table
{
    Student students[100];
    unsigned n = 0;
    const unsigned N = 100;

    void add()
    {
        Student newStudent;
        newStudent.input();
        //std::cout << newStudent.fullname << '\n';
        students[n] = newStudent;

        ++n;
    }

    void add(std::ifstream& in)
    {
        Student newStudent;
        newStudent.input(in);
        ++n;
    }

    void add(Student student)
    {
        ++n;
        int index = -1;
        for (unsigned i = 0; i < n; i++)
        {
            if (students[i].marks.avg() > student.marks.avg())
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            if (n == N)
            {
                std::cout << "Out of range";
            }
            else
            {
                students[n++] = student;
            }
        }
        else
        {
            for (int i = n++; i > index; i--)
            {
                std::swap(students[i], students[i - 1]);
            }
            students[index] = student;
        }
    }

    void input()
    {
        int count;
        std::cin >> count;
        for (unsigned i = 0; i < count; i++)
        {
            add();
        }
    }

    void input(std::ifstream& in)
    {
        while (!in.eof())
        {
            add(in);
        }
    }


    void remove(unsigned index)
    {
        for (unsigned i = 0; i < n - 1; i++)
        {
            std::swap(students[i], students[i + 1]);
        }
        n--;
    }

    void removeByAvg(float avg)
    {
        for (unsigned i = 0; i < n - 1; i++)
        {
            if (students[i].marks.avg() < avg)
            {
                remove(i);
            }
        }
    }

    void output()
    {
        for (unsigned i = 0; i < n; i++)
        {
            Student student = students[i];
            student.output();
        }
    }
};


Table formGoodTable(Table& table)
{
    Table newTable;

    for (unsigned i = 0; i < table.n; i++)
    {
        if (table.students[i].IsGood());
        {
            newTable.add(table.students[i]);
        }
    }

    return table;
}