#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

int max_check(int* goods_prices, int goods_num);

int main() {
	setlocale(LC_ALL, "ru");
	const int MAX_GOODS = 10000;
	cout << "Задание 1\n";
	cout << setfill('-') << setw(10) << '\n';

	int goods_num;
	cout << "Введите количество товаров: "; cin >> goods_num; cout << endl;
	if (goods_num > MAX_GOODS) {
		cout << "Превышен лимит товаров" << endl;
		return 0;
	}
	
	srand(time(0));
	int* goods_prices = new int[goods_num];
	for (int i = 0; i < goods_num; i++) {
		goods_prices[i] = rand() % 100 + 1;
	}

	cout << "Максимальная сумма чека " << max_check(goods_prices, goods_num) << endl;
	cout << "Порядок пробивания на кассе: ";
	for (int i = 0; i < goods_num; i++) {
		cout << goods_prices[i] << " ";
	}
	cout << endl;

	return 0;
}

void quick_sort(int* array, int first, int last) {
	int mid;
	int f = first, l = last;
	mid = array[(f + l) / 2];
	do
	{
		while (array[f] < mid) f++;
		while (array[l] > mid) l--;
		if (f <= l)
		{
			swap(array[f], array[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quick_sort(array, first, l);
	if (f < last) quick_sort(array, f, last);
}

int max_check(int* goods_prices, int goods_num) {
	int check = 0;
	
	quick_sort(goods_prices, 0, goods_num - 1);
	for (int i = 0; i < goods_num; i += 2) {
		swap(goods_prices[i], goods_prices[i + 1]);
		check += goods_prices[i];
	}
	return check;
}
