#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void write_in_file(std::string file_name);
std::vector<std::string> read_all_the_file(std::string file_name);

int main()
{
	// you can use u8 before the text ti incode in utf-8
	std::vector<std::string> const phrases
	{
		u8"Voici un mot important.\n",
		u8"Russe : резиновые перчатки",
		u8"Polonais : gumowe rękawiczki",
		u8"Roumain : mănusi de cauciuc"
	};

	std::cout << R"(the path is /documents/here.txt or C:\documents\here)" << std::endl;
	std::cout << R"m(I can use any delimiter I want )m" << std::endl;

	auto const file_name{ "test_file.txt" };
	std::vector<std::string> content{};

	write_in_file(file_name);
	content = read_all_the_file(file_name);
	for (auto const raw : content)
	{
		std::cout << raw << std::endl;
	}
	return 0;
}

void open_file()
{
	// if the file doesn't exist, it will be created, else it will erase it's content
	std::ofstream file { "file_name.txt" };
}

void write_in_file(std::string file_name)
{
	std::ofstream file { file_name };
	file << 3 << " " << 4;
}

void append_to_file(std::string file_name, std::string content)
{
	if (file_name.empty())
		return;
	std::ofstream file{ file_name, std::ios::app };
	file << content;
}

void read_file(std::string file_name)
{
	int nbr { 0 };
	std::string raw { "" };

	// open the file for read
	std::ifstream file{ file_name };
	// std::ws remove the space or the backline at the and of the nbr
	file >> nbr >> std::ws;
	std::getline(file, raw);

	std::cout << nbr << std::endl << raw << std::endl;
}

std::vector<std::string> read_all_the_file(std::string file_name)
{
	std::ifstream file { file_name };
	std::string raw{ "" };
	std::vector<std::string> content {};
	int index = 0;

	while (std::getline(file, raw))
	{
		content.push_back(raw);
	}
	return content;
}

void string_as_stream()
{
	double const nbr{ 42.42 };

	std::ostringstream string_stream;
	string_stream << std::scientific << std::showpos << nbr << std::endl;
	std::string result{ string_stream.str() };

	std::istringstream input_stream{ "f8 ad 32" };
	int red{ 0 };
	int green{ 0 };
	int blue{ 0 };

	input_stream >> std::hex >> red >> green >> blue;
}
