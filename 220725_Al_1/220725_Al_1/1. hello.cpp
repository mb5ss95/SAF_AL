#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	// trace : �ڵ带 ���� �������ϰ� �ϳ��ϳ� Ȯ��
	//		   �ڵ带 '���� ����' ���� ����

	// break point : F9
	//				 �ڵ带 ��𿡼� ������(���� ���� �����ϱ� ������ �κ�)
	// ����� ��� : F5

	// step over : F10
	// step into : F11

	// resume : F5
	//			���� �ڵ���� �̾ �� ����, �� breakpoint�� ������ ��ž
	// �������(trace) ���� : shift + F5

	// ����� : ������ �������� ��� ���ذ����� Ȯ���ϱ� ������ â (Ȯ���ϰ� ���� ������ �̸��� �Է��ϸ� �˾Ƽ� ã�Ƽ� ����)
	// ����� -> â -> �����

	// ����Ŀ��� ����.b �ϸ� �������� �� �� ���� (ex. a.b)
	int a = 1;

	for (int i = 0; i < 10; i++) {
		a = a + 2;
		cout << a << "\n";
	}

	return 0;
}