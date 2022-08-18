#include <iostream>
#include <vector>

using namespace std;


// bottom - up
int main() {
	int dp[100] = { 0, 1 };

	for (int i = 2; i < 30; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[29];
}