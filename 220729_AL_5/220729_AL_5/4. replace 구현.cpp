#include <iostream>
#include <string>
using namespace std;
string bbq = "ABC##KFC##BTS##KFC####KFC####KFC";

void replace(string before, string after) {

	int a = 0;
	while (1) {
		a = bbq.find(before, a);
		if (a == -1) break;

		bbq.erase(a, before.size());
		bbq.insert(a, after);

		a++;
	}
}

int main() {

	//KFC 라는단어를 MC 변경 (KFC는 여러개가 존재할 수 있다)

	cout << bbq << '\n';
	replace("KFC", "MC");
	cout << bbq << '\n';
	return 0;
}