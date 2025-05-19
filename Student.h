#pragma once
#include <string>
#include <vector>
#include <list>
#include<fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include<stdexcept>
#include<map>
#include<iomanip>
#include "StudntFileMnager.h"
#include<cctype>
#include<unordered_map>
#include"Logger.h"

class StudFileMngr;
class Stud;

class Log;

class Project
{
public:
    std::string name = "", group = "";
    Project(const std::string& name, const std::string& group)
    {
        this->name = name;
        this->group = group;
    };

};

struct Student
{

    Student() = default;

    std::string name = "";
    double ball = 0.0;
    Student(const std::string& n, double b) : name(n), ball(b) {};

    bool operator<(const Student& other) const {
        return name < other.name;
    }

    bool operator==(const Student& other) const {
        return name == other.name && ball == other.ball;
    }

    friend bool operator==(const Student& s, const std::pair<std::string, double>& item)
    {
        return s.name == item.first && s.ball == item.second;
    }

};

class Stud {
    friend class StudFileMngr;
    friend class Project;
   
    friend std::ostream& operator <<(std::ostream& os, const Student& other);
   
public:
   
    explicit Stud(const std::string& file)
        : Logger(Log::create(file)),
        ContributionProject(std::make_shared<std::vector<Project>>())
    {};

    Stud() = delete;
    
    void addProject(const std::string& name, const std::string& group)
    {
        ContributionProject->emplace_back(name, group); // push_back({name,group});
        std::ofstream os("Project.txt", std::ios::app);
        os << name << " " << group << " " << ContributionProject->size() << std::endl;
        
    }
    auto getCount() const
    {
       return ContributionProject.use_count();
    }


    Stud& operator=(const Stud& other)
    {
        if (ContributionProject)
        {
            ContributionProject.reset();
        }
        if (this != &other) { 
            this->info_stud = other.info_stud;
            this->rezerv_info_stud = other.rezerv_info_stud;
            this->Students = other.Students;
            this->BackUpStud = other.BackUpStud;
            this->Key = other.Key;
            this->ContributionProject = other.ContributionProject; 

            
        }
        return *this;
    }
    void clearProjects() {
        ContributionProject.reset(); 
    }
    void uploadInfoStud(const std::string& file);
    void cast();
    void SortStudent();
    void uploadReadyFile(const std::string& file);
    void uploadDataToFile(const std::string& file);
    void SwapStudents(size_t index, size_t index2);
    void RezervSort();
    void PrintSortStud(const std::string& file);
    bool DeleteStudent(size_t index);
    void DeleteStudentFromFile(const std::string& filename, const std::string& targetName, double targetBall);
    bool findStudent(const std::string& nameF, const std::string& name, const double& value);
    bool registerStudent(std::string& login, std::string password);
    bool loginStudent(std::string& login, std::string password);


private:
    void hashPassword(std::string& password, int shift);
    void UnHashPassword(std::string& password, int shift);
    std::list<std::string> info_stud;
    std::unordered_map<std::string,double> rezerv_info_stud;
    std::vector<Student> Students;
    std::vector<Student> BackUpStud;
    std::map<size_t, Student> Key;
    std::shared_ptr<std::vector<Project>> ContributionProject;
    std::shared_ptr<Log> Logger;
    static inline unsigned int i = 0;
    static inline size_t id = 1;
};


