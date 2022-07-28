#include <iostream>
#include <string>

using namespace std;


int main() {
	string str;
	char dat[200] = { 0 };
	int max = 0;
	int min = 21e8;
	int maxIdx, minIdx;

	cin >> str;

	for (int i = 0; str.length(); i++) {
		dat[str[i]]++;
	}

	for (char i = 'A'; i < 'Z'; i++) {
		if (dat[i] > max) {
			max = dat[i];
			maxIdx = i;
		}
		if (dat[i] < min) {
			min = dat[i];
			minIdx = i;
		}
	}


	cout << dat[maxIdx] << "\n";
	cout << dat[minIdx] << "\n";


}