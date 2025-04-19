#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool string_chek(string& users_str);

int main() {
	setlocale(LC_ALL, "ru");
	string users_str;
	cout << "Введите символьую строку, которая может содержать цифры, буквы, знаки математических операций и три вида скобок" << endl;
	cout << "Строка "; getline(cin, users_str);

	if (!string_chek(users_str)) {
		cout << "Скобки расставлены неверно." << endl;
	}
	else {
		cout << "Скобки расставлены верно." << endl;
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