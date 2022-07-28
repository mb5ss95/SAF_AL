#include <iostream>
#include <string>

using namespace std;


int main() {
	string str = "ABCDEFG";

	/*
	문자열의 pos 번째 문자 부터 count 길이 만큼의 문자열을 리턴한다. 
	만약에, 인자로 전달된 부분 문자열의 길이가 문자열 보다 길다면, 그 이상을 반환하지 않고 문자열의 끝 까지만 리턴한다.

	str.substr(pos, count)
	pos : 첫번째 문자의 위치 (원래 문자열에서)
	count : 부분 문자열의 길이 --> endIndex - startIndex - 1
	*/
	string temp = str.substr(3, 3); // DE
	cout << temp << "\n";

	int startIndex = str.find("D");
	int endIndex = str.find("E");
	string temp2 = str.substr(0, 2);
	cout << temp2 << "\n";



}