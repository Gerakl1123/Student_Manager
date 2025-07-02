#pragma once
#include<fstream>
#include<chrono>
#include<iomanip>
#include<iostream>
#include<string>
#include <memory>

class Stud;
class StudFileMngr;


class Log
{
	friend class Stud;
	friend class StudFileMngr;

private:
	std::ofstream logFile;

	Log(const std::string& nameFile)
	{
		logFile.open(nameFile, std::ios::app);
	};


public:

	static std::shared_ptr<Log> create(const std::string& nameFile)
	{
		return std::shared_ptr<Log>(new Log(nameFile));
	}

	void write(const std::string& msg);

	~Log()
	{
		logFile.close();
	}

};