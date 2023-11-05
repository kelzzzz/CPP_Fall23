#include "Names.h"
#include <iostream>
void printOptions(const char print[7]) {
	std::cout << print[0] << " - print \n"
		<< print[1] << " - search by last name \n"
		<< print[2] << " - delete by last name \n"
		<< print[3] << " - count lines of data \n"
		<< print[4] << " - check if name is present \n"
		<< print[5] << " - update or insert name \n"
		<< print[6] << " - print options \n"
		<< print[7] << " - quit\n";
}
int main() {
	Names names("names.txt"); //init names with map inside
	constexpr char options[] = {'p','s','d','c','e','u','o','q'}; //init options; they are constants so they can be easily adjusted in code

	std::cout << "Please choose an option to interact with the names database.\n";
	printOptions(options);

	while (true) { //infinite loop
		char option;
		std::string input;
		std::string first;
		std::cin >> option; //take option at start of loop
		switch (option) {
			case options[0]:
				std::cout << "Current names stored in the database:\n";
				std::cout << "--------------\n";
				names.printMap();
				std::cout << "--------------\n";
				break;
			case options[1]:
				std::cout << "Enter the last name you want to search for. Capitalization matters. \n";
				std::cin >> input;
				std::cout << "RESULT: " << names.search(input) << "\n";
				break;
			case options[2]:
				std::cout << "Enter the last name of who you would like to delete.\n";
				std::cin >> input;
				if (names.keyExists(input)) {
					std::cout << input << " " << names.search(input) << " is deleted.\n";
					names.remove(input);
					break;
				}
				else {
					std::cout << "That name is not in the database.\n";
				}
				break;
			case options[3]:
				std::cout << "There are " << names.size() << " names stored.\n";
				break;
			case options[4]:
				std::cout << "Enter the last name you would like to check.\n";
				std::cin >> input;
				if (names.keyExists(input)) {
					std::cout << input << " " << names.search(input) << " exists.\n";
				}
				else {
					std::cout << "That name is not in the database.\n";
				}
				break;
			case options[5]:
				std::cout << "Enter the last name you would like to update, or a new last name to add.\n";
				std::cin >> input;
				std::cout << "Enter the first name.\n";
				std::cin >> first;
				names.update(input, first);
				std::cout << input << " " << first << " updated.\n";
				break;
			case options[6]:
				printOptions(options);
				break;
			case options[7]:
				std::cout << "Goodbye.";
				exit(0);
				break;
			default:
				std::cout << "Unrecognized input, try again.\n";
				break;
		}
	}
}