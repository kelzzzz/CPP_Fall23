#include<fstream> //fin,fout
#include<iostream> //cin, cout

using std::string, std::ifstream, std::cout, std::endl, std::left;

string getEncodedLName(string &encode, int len, char filler);

int main()
{
	string fname, lname;
	ifstream fin;

	fin.open("data.txt");

	if (fin.is_open()) {
		while (fin >> fname >> lname) {
			int len = lname.length();

			cout << "Name length: " << len << endl;

			cout << left << fname << " ";

			cout << getEncodedLName(lname, len, '#') << endl; //tell our encoder to use our string, length, and fill with '#'
		}
	}

	fin.close();
}

///******** solution ************////
string getEncodedLName(string &encode, int len, char filler) {
	string ans = encode;
	for (int i = 7; i < len; i++) {
		//simply loop over the string array, and change the character to the filler for every char past 7
		ans[i] = filler;
	}
	return ans;
}

