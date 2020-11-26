// Logger_DLL_tester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Logger_H.h"
#include <thread>
#include <future>
#include <Windows.h>
using namespace std;
#pragma comment (lib, "LOGGER_DLL_.lib")

int main()
{	
	LOGGER::WRITE("DEBUG LOG", LOGGER::LEVEL::DEBUG);
	LOGGER::WRITE("INFO LOG", LOGGER::LEVEL::INFO);
	LOGGER::WRITE("WARNING LOG", LOGGER::LEVEL::WARNING);
	LOGGER::WRITE("CRITICAL LOG", LOGGER::LEVEL::CRITICAL);
	LOGGER::WRITE("FATAL LOG", LOGGER::LEVEL::FATAL);

	cout << LOGGER::READ(LOGGER::LEVEL::DEBUG) << endl;

	cout << LOGGER::READ(LOGGER::LEVEL::INFO) << endl;

	cout << LOGGER::READ(LOGGER::LEVEL::WARNING) << endl;

	cout << LOGGER::READ(LOGGER::LEVEL::CRITICAL) << endl;

	cout << LOGGER::READ(LOGGER::LEVEL::FATAL) << endl;

	cout << LOGGER::READ(LOGGER::LEVEL::ALL_xREAD_ONLY) << endl;

	EXPORT::TO_FILE(LOGGER::LEVEL::ALL_xREAD_ONLY, "D:\\Bruh.txt");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
