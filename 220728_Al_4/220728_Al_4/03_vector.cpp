#include <iostream>
#include <vector>
using namespace std;

// 1. 기본 문법

//int main() {
//	vector<int> v;
//
//	for (int i = 0; i < 5; i++) {
//		int n;
//		cin >> n;
//
//		v.push_back(n);
//	}
//
//	for (int i = v.size() - 1; i >= 0; i--) {
//		cout << v[i];
//	}
//
//	return 0;
//}

// 2. 이중 vector

//int main() {
//
//	//<> C++ 템플릿 문법
//	//STL 스텐다드 템플릿 라이브러리
//
//	vector<int> t = { 3, 4, 5 };
//
//	vector<vector<int>> v = {
//		{1, 4, 3, 6, 4},
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{8, 8, 67, 5, 4, 3}
//	};
//
//
//	cout << v[3].size();
//
//
//	v[2].push_back(119); //{5, 6, 7, 8, 119}
//
//	v.push_back({ 1, 2, 3, 4 });
//
//
//	return 0;
//}

// 3. 이중 vector 출력해보기

//int main() {
//
//    vector<vector<int>> v = {
//        {1, 4, 3, 6, 4},
//        {1, 2, 3, 4},
//        {5, 6, 7, 8},
//        {8, 8, 67, 5, 4, 3}
//    };
//
//    //2중 for 돌려서
//    //몽땅 출력하기
//    for (int y = 0; y < v.size(); y++) {
//
//        for (int x = 0; x < v[y].size(); x++) {
//            cout << v[y][x];
//        }
//        cout << endl;
//    }
//
//
//    return 0;
//}

// 4. vector를 함수에서 값을 변경하면 return을 꼭 해줘야함!!

//vector<int> bbq(vector<int> gg) {
//
//	gg[0] = 341;
//
//	return gg;
//}
//
//int main() {
//
//	vector<int> arr = { 1, 3, 4, 5 };
//
//	arr = bbq(arr);
//	cout << arr[0];
//
//	return 0;
//}

// 5. 이중 vector 반환 함수 + swap 함수

//vector<vector<int>> bbq(vector<vector<int>> arr) {
//	swap(arr[0], arr[1]);
//
//	return arr;
//}
//
//int main() {
//
//	vector<vector<int>> m = {
//		{1, 5, 4},
//		{1, 9, 9}
//	};
//
//	vector<vector<int>> z = bbq(m);
//
//	for (int y = 0; y < z.size(); y++) {
//		for (int x = 0; x < z[y].size(); x++) {
//			cout << z[y][x];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

// 6. 이중 vector 출력

vector<vector<int>> alist(6);
int main() {

    alist[1] = { 3, 4, 5 };
    alist[3] = { 4 };
    alist[4] = { 2, 5 };
    alist[5] = { 2 };

    int n;
    cin >> n;

    for (int i = 0; i < alist[n].size(); i++) {
        cout << alist[n][i];
    }
    return 0;
}