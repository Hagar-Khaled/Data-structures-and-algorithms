#include <iostream>
using namespace std;

//Selection sort 
void selection_sort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		int index = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[index] > arr[j]) {
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

//Insertion sort 
void insertion_sort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i], j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//Bubble sort
void bubble_sort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		bool flag = true;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
				flag = false;
			}
		}
		if (flag) break;
	}
}

//Merge sort
void Merge(int* arr, int l, int mid, int r) {
	int n1 = mid - l + 1, n2 = r - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int a = 0; a < n1; a++) {
		L[a] = arr[l + a];
	}
	for (int b = 0; b < n2; b++) {
		R[b] = arr[mid + b + 1];
	}
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i]; i++;
		}
		else {
			arr[k] = R[j]; j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i]; i++; k++;
	}
	while (j < n2) {
		arr[k] = R[j]; j++; k++;
	}
	delete[] L;
	delete[] R;
}
void Merge_sort(int* arr, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		Merge_sort(arr, l, mid);
		Merge_sort(arr, mid + 1, r);
		Merge(arr, l, mid, r);
	}
}

//Quick sort
void Quick_sort(int* arr, int first, int last) {
	int pivot, temp, k1, k2;
	if (first >= last) return;
	pivot = arr[first];
	k1 = first + 1;
	k2 = last;
	while (k1 <= k2) {
		while ((k1 <= last) && (arr[k1] <= pivot)) {
			k1++;
		}
		while ((k2 > first) && (arr[k2] >= pivot)) {
			k2--;
		}
		if (k1 < k2) {
			temp = arr[k1]; arr[k1] = arr[k2]; arr[k2] = temp;
		}
	}
	arr[first] = arr[k2];
	arr[k2] = pivot;
	Quick_sort(arr, first, k2 - 1);
	Quick_sort(arr, k2 + 1, last);
}

