#include <iostream>

using namespace std;

// function
int fac(int arr1[], int arr2[], int index) {
	/*	1�� ������� 2�� ����� �� ����
	// 1�����
	for (int i = index; i < 4+index; i++) {
		if (arr1[i-index] != arr2[i]) {
			return 0;
		}
	}

	return 1;
	*/

	// 2�� ���
	for (int i = 0; i < 4; i++) {
		if (arr1[i] != arr2[index + i])	return 0;
	}

	return 1;
}

// �迭�� �迭�� � �ִ��� Ȯ���ϱ�
// �Լ��� ���� ����
int main() {
	int arr1[4] = { 1,5,4,9 };
	int arr2[28] = { 
		1,1,1,5,
		1,5,4,9,
		1,5,4,9,
		1,5,4,9,
		1,5,4,9,
		1,3,1,5,
		4,9,1,2
	};

	int result = 1;
	int sum = 0;

	for (int i = 0; i <= 28 - 4; i++) {
		result = fac(arr1, arr2, i);
		if (result == 1) sum++;
	}

	cout << sum << endl;

}