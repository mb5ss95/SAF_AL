int main() {
	// bit������
		// & -> && : and   <- Ư�� bit�� ����, Ư�� bit�� 0���� ����� ���� ��
		// | -> || : or    <- Ư�� bit�� 1�� ����� ���� ��
		// ^ : Xor <- �� ������ �ٸ� bit�� 1 ������ 0, Ư�� bit�� ����
		// << : a<<b a�� b��ŭ bit�� �Ű��ش�. a�� 2��b������ŭ ������ ��
		// >> : a>>b a�� b��ŭ bit�� �Ű��ش�. a�� 2��b������ŭ ������ ��

		////bit������
		//int a = 80;
		//int b = 5;
		//int c = a >> b;
		//cout << c;

		//int temp = 123;
		//for (int i = 0; i < 5; i++)
		//{
		//    int num = temp << i;
		//    cout << num;
		//}

		//// * �׷��� bit�����ڸ� � ��Ȳ���� ���°�?

		//int origin = 2315;
		//int bit = 0b000100000001;
		//int step1 = -1 ^ bit;
		//int step2 = origin & step1; // <- origin���� bit��� ������ 1�� �ִ� ��ġ�� 0���� �ٲ���


		//int a = 65;
		//int b = 123;
		//int c = 213;
		//
		//int d = a ^ b ^ c ^ b ^ c;
		//cout << d;




		//int a = 4865132; // <- 1�� ����
		//int temp = a;
		//int cnt = 0;
		//while (temp)
		//{
		//    if (temp & 1) // 1�� �ڸ��� bit�� �����ϴ°�?
		//    {
		//        cnt++;
		//    }
		//    temp = temp >> 1;
		//}

	int a = 4865132; // <- �����ؼ� 1�� �ִ°�찡 �� ����? ex) 0b 111 => 2����
	int temp = a;
	int cnt = 0;
	while (temp)
	{
		if ((temp & 0b11) == 0b11) // 1�� �ڸ��� bit�� �����ϴ°�?
		{
			cnt++;
		}
		temp = temp >> 1;
	}

	return 0;
}
}
