#include <iostream>
#include "hashTable.h"

const int N = 40;

int main() {
    hashTable table = hashTable(40);
    student arrayStuds;

    student stud1, stud2;
    stud1.fio = "Morozov1";
    stud1.numHostel = 1;
    stud1.numRoom = 1;
    stud1.passport = 100000;

    stud2.fio = "Morozov2";
    stud2.numHostel =2;
    stud2.numRoom = 2;
    stud2.passport = 200000;


    for (int i = 1; i < N; i++)
    {
        stud1.fio[0]-=1;
        stud2.fio[0]-=1;
        stud1.passport = 100000+i;
        stud2.passport = 200000+i;
        table.add(stud1);
        table.add(stud2);
    }

    table.print();
    stud2.fio = "Morozov2";
    stud2.numHostel =2;
    stud2.numRoom = 3;
    stud2.passport = 200000;

    for (int i = 0; i < N; i++)
    {
       std::cout<<stud2.fio<<" "<<stud2.passport<<std::endl;
        stud2.fio[0]-=1;
        stud2.passport+=1;

      //  table.add(stud2);
        table.del(stud2);
    }

    table.print();

    for (int i = 0; i < N; i++)
    {
        std::cout<<stud2.fio<<" "<<stud2.passport<<std::endl;
        stud2.fio[0]+=1;
        stud2.passport-=1;

        //  table.add(stud2);
        table.add(stud2);
    }

    table.print();

    student stud3(100004, "Iorozov1", 1, 1);

    std::cout << table.search(stud3);

    return 0;
}