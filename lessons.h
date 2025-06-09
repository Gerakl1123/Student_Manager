#pragma once
#include"Libs.h"
#include"Student.h"

//enum class LessonsEnum
//{
//	Math,
//	History,
//	Information,
//	Ximia,
//	Geometry,
//	Physics,
//	Letarytyre
//}; 

class Lessons
{
private:
	short grade=0;
	std::string book;

	static std::vector<std::string> lesson;
	
public:
	
	Lessons(const std::string& NameGradeBook) : book(NameGradeBook)
	{

	};

	void setGradeStudent(const std::string& nameStudent,const std::string& fileStudents,double ball);

};