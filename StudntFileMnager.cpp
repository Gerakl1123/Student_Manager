#include "StudntFileMnager.h"

void StudFileMngr::CreateDir(std::string& path_dir,const std::string& nameFolder, const std::string nameFileToUploadData, Stud& other, const std::string& fileNameInputData)
{
	Logger->write("!!!Used NEW CLASS!!! ");

	
	fs::path folderPath = fs::path(path_dir) / nameFolder;

	if (!fs::exists(folderPath))
	{
		fs::create_directory(folderPath);
		std::string pathStr = folderPath.string();

		Logger->write("StudFileMngr->  Create directory path " + pathStr);

	}

	//path_dir = folderPath.string();
	 
	fs::path newFilePath = folderPath / nameFileToUploadData;
		

	std::ifstream ifile(fileNameInputData);
	std::ofstream ofile(newFilePath);

	if (!ifile.is_open() || !ofile.is_open()) {
		std::cerr << "Îøèáêà ïðè îòêðûòèè ôàéëîâ!\n";
		return;
	}

	std::string line;
	while (std::getline(ifile, line))
	{
		ofile << line << "\n";
	}
	ifile.close();


	ofile << "\n# Данные:\n";
	for (const auto& [name , ball] : other.rezerv_info_stud)
	{
		ofile << name << ball <<  "\n";
	}

	ofile.close();

	std::cout << "Directore sucefful! " << newFilePath << "\n";
	std::string pathStr = newFilePath.string();

	Logger->write("StudFileMngr->  SECCUFUL DIRECTORY ! " + pathStr);

}


uintmax_t StudFileMngr::SizeFileByte(std::string& path_dir)
{

	uintmax_t Res = fs::file_size(path_dir);
	return Res;
	
}
