#include <iostream>
using namespace std;

int binary_search(int number) {

	int choice, step_count = 0, size = 1, mid = 0, left = 1, right = number - 1;
	int* array = new int[size];

	while (left <= right && mid != 1) {
		mid = (left + right) / 2;
		array[step_count] = mid;
		step_count++;
		do {
			cout << "��� ����� " << mid << "?" << endl;
			cout << "�������� ���� �� ���������: " << endl;
			cout << "1 - ����;" << endl;
			cout << "2 - �����;" << endl;
			cout << "3 - ������." << endl;
			cout << "�����: ";  cin >> choice;
		} while (choice != 1 && choice != 2 && choice != 3);
		switch (choice) {
		case 1: {
			left = mid + 1;
			size++;
		} break;
		case 2: {
			right = mid - 1;
			size++;
		} break;
		case 3: {
			cout << "������������ ��������� ����� " << step_count << endl;
			cout << "���� ��������� ������: ";
			for (int i = 0; i < step_count; i++) {
				cout << array[i] << " ";
			}
			cout << endl;
			return 0;
		} break;
		default: break;
		}
	}
	delete[] array;
	return 0;
}

int main() {
	setlocale(LC_ALL, "ru");
	int number;
	cout << "_____��������______" << endl;
	do {
		cout << "������� ����� �����: "; cin >> number;
	} while (number <= 1);
	
	binary_search(number);

	return 0;
}