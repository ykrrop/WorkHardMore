#include<iostream>
#include <vector>
#include <string>
using namespace std;

//бинарный поиск
int binarySearch(vector <int> arr, int left, int right, int key) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key) {
			return mid; // Искомый элемент найден, возвращаем его индекс
		}
		else if (arr[mid] < key) {
			left = mid + 1; // Искомый элемент находится справа от mid
		}
		else {
			right = mid - 1; // Искомый элемент находится слева от mid
		}
	}
	return -1; // Искомый элемент не найден, возвращаем -1
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector <int> arr { 1, 2, 3, 5, 6, 7, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 9;

	int result = binarySearch(arr, 0, size - 1, key);
	if (result != -1) {
		std::cout << "Искомый элемент " << key << " найден по индексу " << result << std::endl;
	}
	else {
		std::cout << "Искомый элемент " << key << " не найден." << std::endl;
	}

	return 0;
}