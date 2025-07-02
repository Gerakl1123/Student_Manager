#pragma once
#include"Libs.h"
#include <functional>
#include"Logger.h"
#include "Student.h"

class BaseContest {
public:

	BaseContest() = default;
	BaseContest(const std::string& contest, std::shared_ptr<std::vector<Student>>& otherStudent, const std::string& LogFILE)
		: Contest(contest), CurretStudents(otherStudent)
	{
		Logger = Log::create(LogFILE);
	};

	virtual std::string currentContest(const std::string&) = 0;
	virtual	std::vector<Student> ContestBudget(double, const std::string&)  = 0;

	~BaseContest() = default;

protected:
	std::string Contest;
	static std::shared_ptr<std::vector<std::string>> contestVec;
	std::shared_ptr<std::vector<Student>> CurretStudents;
	 std::shared_ptr<Log> Logger;
	static std::shared_ptr<std::vector<std::string>> createContest();
	std::shared_ptr<std::ofstream> ofile;

};


class CurretContest : public BaseContest
{
public:
	CurretContest() = default;
	CurretContest(const std::string& contest, std::shared_ptr<std::vector<Student>>& otherStudent, const std::string& FILE)
		: BaseContest(contest, otherStudent, FILE) {

	};

	std::string currentContest(const std::string& File) override;

	std::vector<Student>ContestBudget(double score, const std::string& File) override;


};
