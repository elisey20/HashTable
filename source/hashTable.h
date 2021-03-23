//
// Created by elise on 01.03.2021.
//

#include <string>
#include <iostream>

#pragma once

struct student
{
    student() = default;
    student(unsigned int passport, std::string fio, unsigned short numHostel, unsigned short numRoom);

    unsigned int id = 0;
    char pos = 0;

    std::string fio;
    unsigned short numHostel = 0;
    unsigned short numRoom = 0;
    unsigned int passport = 0;
};

class hashTable
{
private:
    student *table;
    unsigned int N;
    unsigned int fix = 3;
    unsigned int hashFunc1(student &stud);
    unsigned int hashFunc2(unsigned int addr, int i);


public:
    explicit hashTable(unsigned int N = 10);
    ~hashTable();

    int add(student &stud);
    int del(student &stud);
    bool search(student &stud);
    void print();
};

std::ostream& operator<<(std::ostream &ofs, student &stud);