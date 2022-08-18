#include <iostream>
#include <vector>

using namespace std;


// dp에 비트연산을 해서 이득을 봄
int main() {
	int dp[100] = { 0, 1 };

	for (int i = 2; i < 30; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[29];
}