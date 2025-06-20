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

void Lessons::setGradeStudent(const std::string& fileStudents,const std::string& less)
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

    auto it = std::find(students.begin(), students.end(), name);

    
    if (it != students.end())
    {
        
        auto it_2 = std::find(lesson.begin(), lesson.end(), less);

        if (it_2 != lesson.end())
        {
            std::ofstream gradebok(book, std::ios::app);
            if (!gradebok) {
                std::cerr << "Failed to open file: " << book << std::endl;
                return;
            }
            gradebok << name << " " << less << " " << std::to_string(ball) << "\n";
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