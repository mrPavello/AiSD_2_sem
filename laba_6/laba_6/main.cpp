#include <iostream>
#include <string>

using namespace std;
#define INT_MAX 32767

class Person {
private:
	string name;
	int age;
public:
	void print() {
		cout << "���: " << name << "\t�������: " << age << endl;
	}
	Person(string p_name, int p_age) {
		name = p_name;
		age = p_age;
		cout << "������ �����������" << endl;
	}
	Person(string p_name) : Person(p_name, 18) {
		cout << "������ ����������� " << endl;
	}
	Person() : Person("�����������") {
		cout << "������ �����������" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	Person person("����", 45);
	Person young("����");
	Person some;
	person.print();
	young.print();
	some.print();


	return 0;
}