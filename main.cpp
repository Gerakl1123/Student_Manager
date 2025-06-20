#include <iostream>
#include "Student.h"
#include"StudntFileMnager.h"
#include <iterator>
#include <list>
#include"lessons.h"

int main()
{

	Lessons less("D:\\Test\\gradeB.txt", "Sveta", 4.55);
	less.setGradeStudent("sort_stud.txt", "Math");

	std::string path("D:\\");
	Stud a("Log.yml");
	StudFileMngr m("Log.yml");
	m.CreateDir(path, "Test", "suka.txt", a, "sort_stud.txt");
}

