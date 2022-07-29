#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str = "012345";

	// 문자열 삽입, 3번 인덱스에 AAA삽입
	str.insert(3, "AAA"); // 012AAA345
	cout << str << "\n";
	// 문자열 지우기, 3번 인덱스에서 4개를 지워라
	str.erase(3, 4);
	cout << str << "\n";
}