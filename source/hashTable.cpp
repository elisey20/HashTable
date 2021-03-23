//
// Created by elise on 01.03.2021.
//

#include <string>
#include <iostream>
#include <fstream>

#include "hashTable.h"

hashTable::hashTable(unsigned int N)
{
    table = new student[N];
    this->N = N;
}

hashTable::~hashTable()
{
    delete[] table;
}

unsigned int hashTable::hashFunc1(student &stud)
{
    stud.id = 0;
    for (int i = 0; i < stud.fio.size(); i++)
        stud.id += stud.fio[i];
    stud.id += stud.passport;

    unsigned int addr = stud.id % N;
    return addr;
}

unsigned int hashTable::hashFunc2(unsigned int addr, int i)
{
    unsigned int addr2 = (addr + i*i*fix) % N;
    return addr2;
}

int hashTable::add(student &stud)
{
    unsigned int addr = hashFunc1(stud);

    for (int i = 0; i < N; i++)
    {
        unsigned int addr2 = hashFunc2(addr, i);
        if (table[addr2].pos != 1)
        {
            stud.pos = 1;
            table[addr2] = stud;
            return 0;
        }
    }

    std::cout << stud << " has not been added!\n";

    return 1;
}

int hashTable::del(student &stud)
{
    unsigned int addr = hashFunc1(stud);

    for (int i = 0; i < N; i++)
    {
        unsigned int addr2 = hashFunc2(addr, i);

        if (table[addr2].pos == 0)
            return 1;

        if (table[addr2].pos == 1)
        {
            if (table[addr2].id == stud.id &&
                table[addr2].passport == stud.passport &&
                table[addr2].numHostel == stud.numHostel &&
                table[addr2].numRoom == stud.numRoom &&
                table[addr2].fio == stud.fio)
            {
                table[addr2].pos = 2;
                return 0;
            }

        }
    }

    return 1;
}

bool hashTable::search(student &stud)
{
    unsigned int addr = hashFunc1(stud);

    for (int i = 0; i < N; i++)
    {
        unsigned int addr2 = hashFunc2(addr, i);

        if (table[addr2].pos == 0)
            return false;

        if (table[addr2].pos == 1)
        {
            if (table[addr2].id == stud.id &&
                table[addr2].passport == stud.passport &&
                table[addr2].numHostel == stud.numHostel &&
                table[addr2].numRoom == stud.numRoom &&
                table[addr2].fio == stud.fio)
            {
                return true;
            }
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream &ofs, student &stud)
{
    ofs << stud.passport << ' ' << stud.fio << ' ' << stud.numHostel << ' ' << stud.numRoom;
    return ofs;
}

void hashTable::print()
{
    //std::ofstream outf("../output.txt");

    std::cout << "---------------------\n";
    for (int i = 0; i < N; i++)
    {
        if (table[i].pos == 1)
            std::cout << i << ". " << table[i] << std::endl;
            //std::cout << table[i] << std::endl;
    }
    std::cout << "---------------------\n";

}

student::student(unsigned int passport, std::string fio, unsigned short numHostel, unsigned short numRoom)
{
    this->passport = passport;
    this->fio = fio;
    this->numHostel = numHostel;
    this->numRoom = numRoom;
}
