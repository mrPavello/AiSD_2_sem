#include <iostream>
#include <ctime>

using namespace std;

unsigned long int recursive(unsigned long int number) {
	
	if (number == 0) return number;
	if (number == 1 || number == 2) return 1;
	
	return (recursive(number - 1) + recursive(number - 2));
}

unsigned long int loop(unsigned long int number) {
	unsigned long long int a = 0, b = 1, c;
	if (number == 0 || number == 1) {
		return number;
	}
	for (int i = 2; i <= number; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	setlocale(LC_ALL, "ru");

	unsigned long int number;
	
	cout << "Введите номер числа: "; cin >> number;
	cout << endl;

	if (number < 0) {
		cout << "Ошибка!" << endl;
		main();
	}
	clock_t start_recursive = clock();
	unsigned long int res_recursive = recursive(number);
	clock_t end_recursive = clock();

	clock_t start_loop = clock();
	unsigned long int res_loop = loop(number);
	clock_t end_loop = clock();

	
	int time_loop = ((end_loop - start_loop) / CLOCKS_PER_SEC);
	int time_recursive = ((end_recursive - start_recursive) / CLOCKS_PER_SEC);

	cout << "Расчёт с помощью цикла: " << res_loop << endl; 
	cout << "Расчёт с помощью рекурсии: " << res_recursive << endl;
	cout << "Расчётное время циклом " << (time_loop / 60) << " минут " << (time_loop % 60) << " секунд." << endl;
	cout << "Расчётное время рекурсией " << (time_recursive / 60) << " минут " << (time_recursive % 60) << " секунд." << endl;
	return 0;
}