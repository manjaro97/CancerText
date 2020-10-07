#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>

std::string asciiCap(std::string str);

int main() {

	std::ifstream t("Input.txt");
	std::string str;

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	//std::cout << str << std::endl << std::endl;

	str = asciiCap(str);

	//std::cout << str << std::endl << std::endl;

	std::ofstream out("Output.txt");
	out << str;
	out.close();

	return 0;
}

std::string asciiCap(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		int Ascii = str[i];
		int num = Ascii / 2;
		if (num * 2 == Ascii) {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
	return str;
}