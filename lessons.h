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

class Lessons : public Student
{
private:
	short grade=0;
	std::string book;

	static std::vector<std::string> lesson;
	
public:
	
	Lessons(const std::string& NameGradeBook,const std::string& nameStudent,double ball) : book(NameGradeBook),Student(nameStudent,ball)
	{

	};

	void setGradeStudent(const std::string& fileStudents ,const std::string& less);

};