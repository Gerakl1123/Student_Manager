#include <iostream>
#include "Student.h"
#include"StudntFileMnager.h"
#include <iterator>
#include <list>
#include <crtdbg.h>


#define _CRTDBG_MAP_ALLOC

int main()
{
    //
    //int dec = -8;
    //auto result = [&dec]()->bool{
    //    while (dec>0)
    //    {
    //        dec--;
    //    }
    //    return dec == 0;
    //};
    //
    //bool isZero = result();
    //std::cout << isZero;

    setlocale(LC_ALL, "RU");
    Stud s("log.yml");

    s.addProject("Math", "900");


    std::string log;
    std::string password;
    
    std::getline(std::cin, log);
    std::getline(std::cin, password);
  
    s.loginStudent(log, password);

    while (true) {
        std::cout << "1. Загрузить студентов\n2. Отсортировать\n3. Показать\n4. Откат\n5. Удалить студента\n6. Выйти\n";
        int choice;
        std::string name;
        double ball;
        std::cin >> choice;
        switch (choice) {
        case 1: s.uploadDataToFile("students.txt"); break;
        case 2: s.uploadInfoStud("students.txt"); break;
        case 3: s.cast(); break;
        case 4: s.SortStudent(); break;
        case 5: s.uploadReadyFile("sort_stud.txt"); break;
        case 6: s.RezervSort(); break;
        case 7: s.PrintSortStud("sort_stud.txt"); break;
        case 8: return 0;
        }
    }


    _CrtDumpMemoryLeaks();

    //std::string path;
    //StudFileMngr manager;
    //manager.CreateDir(path, "sort_studets.txt", s, "sort_stud.txt");
    //std::cout << manager.SizeFileByte(path) << " Byte\n";
    //
}

