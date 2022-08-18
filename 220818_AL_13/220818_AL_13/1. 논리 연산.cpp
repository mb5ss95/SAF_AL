int main() {
	// bit연산자
		// & -> && : and   <- 특정 bit를 추출, 특정 bit를 0으로 만들고 싶을 때
		// | -> || : or    <- 특정 bit를 1로 만들고 싶을 때
		// ^ : Xor <- 두 수에서 다른 bit는 1 같으면 0, 특정 bit를 반전
		// << : a<<b a를 b만큼 bit를 옮겨준다. a가 2의b제곱만큼 곱해진 값
		// >> : a>>b a를 b만큼 bit를 옮겨준다. a가 2의b제곱만큼 나눠준 값

		////bit단위로
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

		//// * 그래서 bit연산자를 어떤 상황에서 쓰는가?

		//int origin = 2315;
		//int bit = 0b000100000001;
		//int step1 = -1 ^ bit;
		//int step2 = origin & step1; // <- origin에서 bit라는 변수의 1이 있는 위치를 0으로 바꿔줌


		//int a = 65;
		//int b = 123;
		//int c = 213;
		//
		//int d = a ^ b ^ c ^ b ^ c;
		//cout << d;




		//int a = 4865132; // <- 1의 개수
		//int temp = a;
		//int cnt = 0;
		//while (temp)
		//{
		//    if (temp & 1) // 1의 자리에 bit가 존재하는가?
		//    {
		//        cnt++;
		//    }
		//    temp = temp >> 1;
		//}

	int a = 4865132; // <- 연속해서 1이 있는경우가 몇 가지? ex) 0b 111 => 2가지
	int temp = a;
	int cnt = 0;
	while (temp)
	{
		if ((temp & 0b11) == 0b11) // 1의 자리에 bit가 존재하는가?
		{
			cnt++;
		}
		temp = temp >> 1;
	}

	return 0;
}
}
