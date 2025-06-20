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

public:

	std::shared_ptr<Log> Logger;
	explicit StudFileMngr(const std::string& file)
		: Logger(Log::create(file)) {
	};



	void CreateDir( std::string& path_dir, const std::string& NameFolder,const std::string nameFileToUploadData, Stud& other, const std::string& fileNameInputData);
	uintmax_t SizeFileByte(std::string& path_dir);
};
	