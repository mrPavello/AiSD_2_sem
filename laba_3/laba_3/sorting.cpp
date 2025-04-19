#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void bubble_sort(int* array, int number) {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

void insertion_sort(int* array, int number) {
	int current_element;
	for (int i = 1; i < number; i++) {
		current_element = array[i];
		for (int j = i - 1; j >= 0 && array[j] > current_element; j--) {
			swap(array[j], array[j + 1]);
		}
	}
}

void selection_sort(int* array, int number) {
	int min;
	for (int i = 0; i < number; i++) {
		min = i;
		for (int j = i + 1; j < number; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (i != min) {
			swap(array[min], array[i]);
		}
	}
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

int main() {
	setlocale(LC_ALL, "ru");
	int number;
	
	cout << "Введите число: "; cin >> number;

	int* array_a = new int[number];
	int* array_b = new int[number];
	int* array_c = new int[number];
	int* array_d = new int[number];
	int* array_e = new int[number];

	srand(time(0));
	cout << endl << "Исходный массив: ";
	for (int i = 0; i < number; i++) {
		array_a[i] = rand() % 150;
		cout << array_a[i] << " ";
		array_b[i] = array_a[i];
		array_c[i] = array_a[i];
		array_d[i] = array_a[i];
		array_e[i] = array_a[i];
	}
	
	
	clock_t start, end;
	double result;
	cout << endl << endl << "Пузырьковая сортировка: " << endl;
	start = clock();
	bubble_sort(array_b, number);
	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC * 1000000000;
	cout << "Отсортированный массив: ";
	for (int i = 0; i < number; i++) {
		cout << array_b[i] << " ";
	}
	cout << endl << "Время работы алгоритма: " << result << " наносекунд." << endl << endl;


	cout << endl << "Сортировка вставкой:" << endl;
	start = clock();
	insertion_sort(array_c, number);
	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC * 1000000000;
	cout << "Отсортированный массив: ";
	for (int i = 0; i < number; i++) {
		cout << array_c[i] << " ";
	}
	cout << endl << "Время работы алгоритма: " << result << " наносекунд." << endl;


	cout << endl << "Сортировка выбором:" << endl;
	start = clock();
	insertion_sort(array_d, number);
	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC * 1000000000;
	cout << "Отсортированный массив: ";
	for (int i = 0; i < number; i++) {
		cout << array_d[i] << " ";
	}
	cout << endl << "Время работы алгоритма: " << result << " наносекунд." << endl;


	cout << endl << "Быстрая сортировка:" << endl;
	start = clock();
	quick_sort(array_e, 0, number - 1);
	end = clock();
	result = (double)(end - start) / CLOCKS_PER_SEC * 1000000000;
	cout << "Отсортированный массив: ";
	for (int i = 0; i < number; i++) {
		cout << array_e[i] << " ";
	}
	cout << endl << "Время работы алгоритма: " << result << " наносекунд." << endl;
	
	return 0;
}