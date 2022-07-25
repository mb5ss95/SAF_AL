#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[] = "ABAABBABEW";
	char dat[200] = { 0, }; // DAT

	int num = strlen(arr);

	for (int i = 0; i < num; i++) {
		dat[arr[i]] = 1;
	}

	for (int i = 0; i < 200; i++) {
		if (dat[i] == 0) continue;
		cout << char(i) << " ";
	}

	return 0;
}