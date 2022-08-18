#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> v(1000);


unsigned long long run(int th) {
	if (v[th] != 0) return v[th];

	if (th == 1) return 0;
	if (th == 2) return 1;

	unsigned long long a = run(th - 1);
	unsigned long long b = run(th - 2);

	v[th] = a + b;

	return v[th];
}

int main() {
	cout << run(999);
}