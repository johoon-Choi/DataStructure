#include <stdio.h>

typedef int E;

void swap(E& a, E& b) {
	E temp = a;
	a = b;
	b = temp;
}

// Ascending Order
void bubble_sort_asc(E arr[], const int& n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (arr[j + 1] < arr[j])
				swap(arr[j + 1], arr[j]);
}

// Ascending Order
void bubble_sort_desc(E arr[], const int& n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (arr[j + 1] > arr[j])
				swap(arr[j + 1], arr[j]);
}

int main() {
	E arr[10] = { 4, 6, 2, 1, 9, 7, 8, 11, 2, 13 };

	bubble_sort_asc(arr, 10);

	printf(" Ascending Order : ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	bubble_sort_desc(arr, 10);

	printf("\n Descending Order : ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}
