#include "lessons.h"

std::vector<std::string> Lessons::lesson = {
    "Math",
    "History",
    "Information",
    "Ximia",
    "Geometry",
    "Physics",
    "Letarytyre"
};

void Lessons::setGradeStudent(const std::string& nameStudent, const std::string& fileStudents,double ball)
{
    std::ifstream ifile(fileStudents);
    std::string line;
    std::vector<std::string> students;
    if (!ifile) {
        std::cerr << "Failed to open file: " << fileStudents << std::endl;
        return;
    }
    while (ifile >> line >> grade)
    {
        students.push_back(std::move(line));

    }

    auto it = std::find(students.begin(), students.end(), nameStudent);

    
    if (it != students.end())
    {
        std::string less;
        std::cin >> less;

        auto it_2 = std::find(lesson.begin(), lesson.end(), less);

        if (it_2 != lesson.end())
        {
            std::ofstream gradebok(book, std::ios::app);
            if (!gradebok) {
                std::cerr << "Failed to open file: " << book << std::endl;
                return;
            }
            gradebok << nameStudent << " " << less << " " << std::to_string(ball) << "\n";
        }
        else
        {
            return ;
        }
    }
    else
    {
        std::cout << " Noy name in file\n";
        return;
    }
    
}