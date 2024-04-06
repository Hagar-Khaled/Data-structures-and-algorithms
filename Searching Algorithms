#include <iostream>
using namespace std;

//Linear search

int linear_search(int* arr, int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

//Binary search

int binary_search(int* arr, int first, int last, int key) {
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}
	return -1;
}

// Recursive Binary search

int rec_binary_search(int* arr, int first, int last, int key) {
	if (first > last) return -1;
	int mid = (first + last) / 2;
	if (arr[mid] == key) {
		return mid;
	}
	else if (arr[mid] < key) {
		rec_binary_search(arr, mid + 1, last, key);
	}
	else {
		rec_binary_search(arr, first, mid - 1, key);
	}
}
