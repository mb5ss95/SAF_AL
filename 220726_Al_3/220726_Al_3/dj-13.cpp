#include <iostream>
#include <string>

using namespace std;


// [] 사이에 있는 수들의 합 출력

int main() {
	string str = "ABC[200]DEFG[200]GGAG[2000]";
	int sum = 0;
	int startIndex = -1;
	int endIndex = -1;

	while (1) {
		startIndex = str.find("[", ++startIndex);
		endIndex = str.find("]", ++endIndex);
		if (startIndex == -1 && endIndex == -1) break;
		string temp = str.substr(startIndex+1, endIndex - startIndex - 1); 
		sum = sum + stoi(temp);
		cout << sum << "\n";
	}


}