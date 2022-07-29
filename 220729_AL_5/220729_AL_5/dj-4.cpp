#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
S+N
s = 소문자 3이상 6이하
n = 0이상 6이하
n이 1이상이면 n의 첫자리는 0이 될수 없음

correct abc123, asd
not corrct ad 12ad 123asd13 asd21asd 123
*/

bool isAlpha(char ch) {
	for (char temp = 'a'; temp <= 'z'; temp++) {
		if (ch != temp) return false;
	}
	return true;
}

bool isDigit(char ch) {
	for (char temp = '0'; temp <= '9'; temp++) {
		if (ch != temp) return false;
	}
	return true;
}

int findAlpha(string str) {
	int idx;
	int min = 21e8;

	for (char ch = '0'; ch <= '9'; ch++) {
		idx = str.find(ch);
		if (idx < min) min = idx;
	}

	return min;
}


string solution(vector<string> registered_list, string new_id) {
	string answer = new_id;

	for (string str : registered_list) {
		if (str != new_id) continue;
		else {
			int idx = findAlpha(new_id);
		}
	}
		
	return answer;
	
}

int main(){
	vector<vector<string>> registered_list = {
		{ "card", "ace13", "ace16", "banker", "ace17", "ace14" },
		{ "cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"},
		{ "bird99", "bird98", "bird101", "gotoxy"},
		{ "apple1", "orange", "banana3"}
	};

	vector<string> result = {
		"ace15", "cow10", "bird100", "apple"
	};

	vector<string> newID = {
		"ace15", "cow", "bird98", "apple"
	};

	for (int i = 0; i < registered_list.size(); i++) {
		string yours = solution(registered_list[i], newID[i]);

		if (yours == result[i]) cout << "GOOD!!\n";
		else cout << "오답입니다\n";
	}

	return 0;
}