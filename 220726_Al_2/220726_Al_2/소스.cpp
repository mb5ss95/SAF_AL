#include <iostream>
#include <cstring>

using namespace std;


int main() {
	char ch[3][10];
	int max = 0;
	int maxIndex;

	for (int i = 0; i < 3; i++) {
		cin >> ch[i];
	}

	for (int i = 0; i < 3; i++) {
		if (strlen(ch[i]) > max) {
			max = strlen(ch[i]);
			maxIndex = i;
		}
	}

	char temp[10];
	strcpy(temp, ch[maxIndex]);
	strcpy(ch[maxIndex], ch[0]);
	strcpy(ch[0], temp);

	for (int i = 0; i < 3; i++) {
		cout << ch[i] << endl;
	}
}
