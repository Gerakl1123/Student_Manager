#include "Student.h"

bool Stud::findStudent(const std::string& nameF, const std::string& name, const double& value)
{
	Students.clear();
	std::ifstream ifile(nameF);
	std::string line;
	std::string nameStud;
	double ballStud;

	while (std::getline(ifile, line))
	{
		std::istringstream iss(line);
		iss >> nameStud >> ballStud;
		Stud::Students.emplace_back(nameStud, ballStud);
	
	}
		//std::pair <std::string, double > Key = {name,value};
		//old solution
		//auto result = std::find(Students.begin(), Students.end(), Key);
		// 
		auto result = std::find_if(Students.begin(), Students.end(), [&](const Student& other)->bool{ 
		

			Logger->write("Succeful find student " + name + " " + std::to_string(ballStud));
			return other.name == name && other.ball == value;

		});
		Logger->write("Fail find student " + name + " " + std::to_string(ballStud));
		return result != Students.end();
		

}


// Блок Регестрации и авторизацийй + ХЕШ/DEHASH 

void Stud::hashPassword(std::string& password,int shift)
{
	std::string result = "";
	for (char c : password) {
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';
			 result += static_cast<char>((c - base + shift) % 26 + base);
		}
		else {
			result += c; 
		}
	}
	password = result;

}

void Stud::UnHashPassword(std::string& password,int shift)
{
	hashPassword(password, 26 - shift % 26);
}

bool Stud::registerStudent(std::string& login, std::string password)
{
	std::ofstream regStud("data.yml", std::ios::app);

	if (!regStud.is_open())
	{
		std::cerr << "Error not open file!\n";
		return false;
	}

	if (login.empty() || password.empty())
	{
		std::cerr << "Error!\n";
		Logger->write("Fail register account " + login);
		return false;
	}
	hashPassword(password, 3);

	regStud << login << " " << password;
	Logger->write("register account " + login);
	return true;
}

bool Stud::loginStudent(std::string& login, std::string password)
{
	std::ifstream logStud("data.yml");
	std::string fileUserName, filePassword;

	if (!logStud.is_open())
	{
		std::cerr << "Error not open file!\n";
		return false;
	}

	if (login.empty() || password.empty())
	{
		std::cerr << "Error!\n";
		return false;
	}


	std::string temp = "";
	while (std::getline(logStud, temp))
	{
		std::istringstream iss(temp);

		iss >> fileUserName >> filePassword;
		UnHashPassword(filePassword, 3);
			
		if (login == fileUserName && password == filePassword)
		{
			std::cout << " Suceful!";
			Logger->write("login to account " + login);
			return true;
		}

	}
	Logger->write("Fail login to account " + login);
	return false;
}

//======================================================================

void Stud::uploadInfoStud(const std::string& file)
{
	std::string line;
	std::ifstream ifile(file);

	while (std::getline(ifile, line))
	{
		info_stud.push_back(line);

		std::istringstream iss(line);
		std::string name;
		double ball;

		iss >> name >> ball;
		rezerv_info_stud.emplace(name, ball);
	}

	Logger->write("Successful Backup!");
	ifile.close();
}
//Fix
void Stud::uploadDataToFile(const std::string& file)
{
	std::ofstream ofile(file, std::ios::app);
	std::string data;
	while (std::getline(std::cin, data))
	{
		if (data == "0")
		{
			break;
		}
		
		std::istringstream iss(data);
		std::string name = "";
		double ball = 0.0;
		iss >> name >> ball;

		ofile<<name << " " << std::to_string(ball) << "\n";
		Logger->write("Student sucewfful " + name + std::to_string(ball));

	}

	ofile.close();
}

void Stud::SortStudent()
{

	std::sort(Students.begin(), Students.end(), [](const Student& a, const Student& b) {
		return a.ball > b.ball;
	});

	rezerv_info_stud.clear();
	Stud::i = 0;
	for (const auto& st : Students)
	{
		rezerv_info_stud.emplace(st.name ,st.ball);
	}

	Logger->write("Sorsted Seccuful!");

}

void Stud::cast()
{
	for (const auto& [name, ball] : rezerv_info_stud)
	{
		if (std::isfinite(ball))
		{
			Students.emplace_back(name, ball);
		}
		else
		{
			Logger->write("Error: Invalid ball value for " + name + ": " + std::to_string(ball));
		}
	}
	Logger->write("cast Successful");
}

void Stud::uploadReadyFile(const std::string& file)
{
	std::ofstream ofile(file);

	for (const auto& [name, ball] : rezerv_info_stud)
	{
		ofile << name;
		ofile << " " << double(ball) << "\n";
	}
	Logger->write("Upload data to ready file! ");
	ofile.close();
}

void Stud::SwapStudents(size_t index, size_t index2)
{

	std::swap(Students[index], Students[index2]);
	Logger->write("swap Student!");
}

void Stud::RezervSort()
{
	BackUpStud.assign(Students.begin(), Students.end());
	BackUpStud.swap(Students);

	Logger->write("BackUp 2x Student!");

}

void Stud::PrintSortStud(const std::string& file)
{
	std::ifstream ifile(file);
	std::string line = "";
	Key.clear();
	while (std::getline(ifile, line))
	{
		std::istringstream iss(line);
		Student s;
		if (iss>>s.name>>s.ball)
		{
			Key[id++] = s;
		}	
	}
	for (const auto& [k, stud] : Key)
	{
		std::cout << k << ") " << stud.name << " — "
			<< std::fixed << std::setprecision(2) << stud.ball << "\n";

	}
	Logger->write("Output data to Student!");
	ifile.close();
}

bool Stud::DeleteStudent(size_t index)
{
	if (index >= 0 && index < Students.size())
	{
		Students.erase(Students.begin() + index);

		Logger->write("Seccuful delete Student" + index);
		return true;
	}

	Logger->write("Fail delete Student" + index);
	return false;
}

void Stud::DeleteStudentFromFile(const std::string& filename, const std::string& targetName, double targetBall)
{
	std::ifstream ifile(filename);
	std::string line;
	std::list<std::string> filter;
	std::string index,name;
	double ball = 0.0;

	while (std::getline(ifile,line))
	{

		std::istringstream iss(line);
		iss>>index >> name >> ball;
		if (name == targetName && ball == targetBall)
		{
			Logger->write("Deleted Student from file " + targetName + " " + std::to_string(targetBall));
			continue;

		}
		else
		{
			filter.push_back(line);
		}

	}
	ifile.close();

	std::ofstream ofile(filename, std::ios::trunc);
	for (const auto& s : filter)
	{
		ofile << s << "\n";	
	}
	ofile.close();
}

std::ostream& operator<<(std::ostream& os, const Student& other)
{
	os << other.name << " " << other.ball;

	return os;
}
