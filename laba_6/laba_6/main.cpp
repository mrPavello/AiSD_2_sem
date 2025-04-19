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
		cout << "Имя: " << name << "\tВозраст: " << age << endl;
	}
	Person(string p_name, int p_age) {
		name = p_name;
		age = p_age;
		cout << "Первый конструктор" << endl;
	}
	Person(string p_name) : Person(p_name, 18) {
		cout << "Второй конмтруктор " << endl;
	}
	Person() : Person("Неизвестный") {
		cout << "Третий конструктор" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	Person person("Саша", 45);
	Person young("Рома");
	Person some;
	person.print();
	young.print();
	some.print();


	return 0;
}