#include "StudntFileMnager.h"

void StudFileMngr::CreateDir(std::string& path_dir, const std::string name_ofile, Stud& other, const std::string& fileName)
{
	Logger->write("!!!Used NEW CLASS!!! ");

	std::string nameFolder;

	std::cout << "Enter new name directory: ";
	std::getline(std::cin >> std::ws, nameFolder); 

	std::cout << "Enter Path: ";
	std::getline(std::cin, path_dir);

	fs::path folderPath = fs::path(path_dir) / nameFolder;

	if (!fs::exists(folderPath))
	{
		fs::create_directory(folderPath);
		std::string pathStr = folderPath.string();

		Logger->write("StudFileMngr->  Create directory path " + pathStr);

	}

	path_dir = folderPath.string();

	fs::path newFilePath = folderPath / name_ofile;
		

	std::ifstream ifile(fileName);
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


	ofile << "\n# Îáíîâë¸ííûå äàííûå:\n";
	for (const auto& [name , ball] : other.rezerv_info_stud)
	{
		ofile << name << ball <<  "\n";
	}

	ofile.close();

	std::cout << "? Ôàéë ñîõðàí¸í: " << newFilePath << "\n";
}


uintmax_t StudFileMngr::SizeFileByte(std::string& path_dir)
{
	std::cout << "Enter Path: ";
	std::getline(std::cin, path_dir);
	uintmax_t Res = fs::file_size(path_dir);
	return Res;
	
}
