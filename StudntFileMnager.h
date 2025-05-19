#pragma once
#include <filesystem>
#include<string>
#include "Student.h"
#include<memory>
#include"Logger.h"
namespace fs = std::filesystem;

class Stud;
class Log;

class StudFileMngr{
private:
	std::shared_ptr<Log> Logger;
	explicit StudFileMngr(const std::string& file)
		: Logger(Log::create(file)) {};
public:

	void CreateDir(std::string& path_dir, const std::string name_ofile, Stud& other, const std::string& fileName);
	uintmax_t SizeFileByte(std::string& path_dir);
};
	