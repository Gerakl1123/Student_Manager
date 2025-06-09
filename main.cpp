#include <iostream>
#include "Student.h"
#include"StudntFileMnager.h"
#include <iterator>
#include <list>
#include <crtdbg.h>
#include"lessons.h"

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
  
  Lessons book("gradeBook.txt");
  book.setGradeStudent("German", "sort_stud.txt", 4);

    _CrtDumpMemoryLeaks();

    //std::string path;
    //StudFileMngr manager;
    //manager.CreateDir(path, "sort_studets.txt", s, "sort_stud.txt");
    //std::cout << manager.SizeFileByte(path) << " Byte\n";
    //
}

