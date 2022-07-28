#include <iostream>
#include <string>

using namespace std;


int main() {
	// string to char
	string str = "ABCD";
	char buf[10];
	strcpy(buf, str.c_str());


	// char to string
	char bbq[10] = "ASDADA";
	string temp = bbq; 


	// string to int
	string str = "12345";
	int a = stoi(str);

	
	// int to string
	int tt = 32132;
	string str = to_string(tt);
	



}