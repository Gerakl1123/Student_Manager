#include "gtest/gtest.h"
#include "Student.h"
#include <fstream>
#include"Contest.h"

TEST(StudentTests, FindStudent_Instance) {
    std::ofstream file("test.txt");
    file << "German 99.5\n";
    file.close();

    Stud s("LogTest.yml");
    bool found = s.findStudent("test.txt", "German", 99.5);

    EXPECT_TRUE(found);

    std::remove("test.txt");
}

TEST(StudentTests, FindStudent_NotFound) {
    std::ofstream file("test.txt");
    file << "German 99.5\n";
    file.close();

    Stud s("LogTest.yml");
    bool found = s.findStudent("test.txt", "Ivan", 80.0);

    EXPECT_FALSE(found);  

    std::remove("test.txt");
}

TEST(ContestTests, currentContestTest)
{
    std::shared_ptr<std::vector<Student>> temp;
    temp = std::make_shared<std::vector<Student>>();

    temp->push_back({ "German", 88.9 });
    temp->push_back({ "iLYA", 188.9 });
    temp->push_back({ "Ramran", 5.9 });
    
    CurretContest tempCurr("certificate", temp, "logt.txt");
    
    EXPECT_EQ(tempCurr.currentContest("Win.txt"), temp->at(1).name); //temp->at(1).name = iLYA
       
}


TEST(ContestTests, NEcurrentContestTest)
{
    std::shared_ptr<std::vector<Student>> temp;
    temp = std::make_shared<std::vector<Student>>();

    temp->push_back({ "German", 88.9 });
    temp->push_back({ "iLYA", 188.9 });
    temp->push_back({ "Ramran", 5.9 });

    CurretContest tempCurr("certificate", temp, "logt.txt");

    EXPECT_NE(tempCurr.currentContest("Win.txt"), temp->at(0).name); //temp->at(1).name = iLYA

}


TEST(ContestTests, BudgetStud)
{
    std::shared_ptr<std::vector<Student>> temp;
    temp = std::make_shared<std::vector<Student>>();

    temp->push_back({ "German", 3.4 });
    temp->push_back({ "iLYA", 3.6 });
    temp->push_back({ "Ramran", 3.2 });
    temp->push_back({ "Roma", 4.2 });
    temp->push_back({ "Igor", 4.3 });
    temp->push_back({ "Alina", 5.0 });
    temp->push_back({ "Sveta", 4.6 });

    CurretContest tempCurr("certificate", temp, "logt.txt");

    std::vector<Student> tempVec;
    tempVec.push_back({ "Alina", 5.0 });
    tempVec.push_back({ "Sveta", 4.6 });
    auto curr = tempCurr.ContestBudget(4.5,"Budg.txt");
    EXPECT_EQ(curr.at(0).ball, tempVec.at(0).ball);
    
}

TEST(ContestTests, NeBudgetStud)
{
    std::shared_ptr<std::vector<Student>> temp;
    temp = std::make_shared<std::vector<Student>>();

    temp->push_back({ "German", 3.4 });
    temp->push_back({ "iLYA", 3.6 });
    temp->push_back({ "Ramran", 3.2 });
    temp->push_back({ "Roma", 4.2 });
    temp->push_back({ "Igor", 4.3 });
    temp->push_back({ "Alina", 5.0 });
    temp->push_back({ "Sveta", 4.6 });

    CurretContest tempCurr("certificate", temp, "logt.txt");

    std::vector<Student> tempVec;
    tempVec.push_back({ "Alina", 5.0 });
    tempVec.push_back({ "Sveta", 4.6 });
    auto curr = tempCurr.ContestBudget(4.5, "Budg.txt");
    EXPECT_NE(curr.at(0).ball, tempVec.at(1).ball);

}
