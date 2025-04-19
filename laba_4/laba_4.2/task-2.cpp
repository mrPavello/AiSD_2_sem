#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

int win_num(int* participant_points, int participant_num);

int main() {
	setlocale(LC_ALL, "ru");
	const int MAX_PARTICIPANTS = 10000;
	cout << "������� 2\n";
	cout << setfill('-') << setw(10) << '\n';

	int participant_num;
	cout << "������� ���������� ���������� ���������: "; cin >> participant_num; cout << endl;
	if (participant_num > MAX_PARTICIPANTS) {
		cout << "�������� ����� ����������" << endl;
		return 0;
	}

	srand(time(0));
	int* participant_points = new int[participant_num];
	for (int i = 0; i < participant_num; i++) {
		participant_points[i] = rand() % 100;
	}

	cout << "���������� ������� ���������: " << win_num(participant_points, participant_num) << endl;
	cout << "������ - ��� ��������, ��������� ����� 70 ������ �� 100." << endl;

	return 0;
}

int win_num(int* participant_points, int participant_num) {
	int number = 0;

	for (int i = 0; i < participant_num; i++) {
		if (participant_points[i] > 70) {
			number++;
		}
	}

	return number;
}