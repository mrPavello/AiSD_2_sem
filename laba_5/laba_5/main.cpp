#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool string_chek(string& users_str);

int main() {
	setlocale(LC_ALL, "ru");
	string users_str;
	cout << "������� ��������� ������, ������� ����� ��������� �����, �����, ����� �������������� �������� � ��� ���� ������" << endl;
	cout << "������ "; getline(cin, users_str);

	if (!string_chek(users_str)) {
		cout << "������ ����������� �������." << endl;
	}
	else {
		cout << "������ ����������� �����." << endl;
	}

	return 0;
}

bool string_chek(string& users_str) {
	stack<char> stk;
	
	for (char s : users_str) {
		if (s == '(' || s == '{' || s == '[') {
			stk.push(s);
		}
		else if (s == ')' || s == '}' || s == ']') {
			if (stk.empty()) {
				return false;
			}
			char last = stk.top();
			if ((s == ')' && last != '(') || (s == '}' && last != '{') || (s == ']' && last != '[')) {
				return false;
			}
			stk.pop();
		}
	}
	
	return stk.empty();
}