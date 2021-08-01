#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <Windows.h>
#include <conio.h>



void HienThiFileAnhASCII(std::string imgFileName)
{
	std::ifstream imgFile;
	std::ifstream configFile;

	// Open file
	imgFile.open(imgFileName.c_str());
	if (!imgFile.is_open())
	{
		std::cout << "Can't open '" << imgFileName << "'";
		return;
	}
	

	// Read image
	std::stringstream imgSS;
	imgSS << imgFile.rdbuf();

	// Visual 
	system("cls");

	std::string aLine;
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	Sleep(500);

	while (!imgSS.eof())
	{
		std::getline(imgSS, aLine);
		std::cout << aLine << std::endl;
		Sleep(100);
	}
}

int main()
{
	HienThiFileAnhASCII("image.txt");
	_getch();

	return 0;
}