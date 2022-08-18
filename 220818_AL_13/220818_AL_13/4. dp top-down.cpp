#include <iostream>
#include <vector>

using namespace std;

// ������ �迭 "�޸�"�� ����
// �̷� ����� �޸������̼�
// ž�ٿ� ����Ҷ� �޸������̼��� �ʼ�
// �޸������̼��� �ؾ� ���Ҿ� ���� ������ ����
int memo[100];

int run(int th) {

	//run(th)�� ���� ������ ���ϱ�?
	if (memo[th] != 0) return memo[th];

	if (th == 1) return 0;
	if (th == 2) return 1;

	int a = run(th - 2);
	int b = run(th - 1);

	memo[th] = a + b;
	return a + b;
}

// top - down
// ���� ������ �˰� �ִ� �Լ�
// ���� �� ��������� ������ ������ ������ �Լ��� �ֽ��ϴ�.
int main() {
	cout << run(50);
}