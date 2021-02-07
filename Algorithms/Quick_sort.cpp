#include <iostream>
#include <vector>

void print_array(int *a, int size)
{
	static int i = 0;
	printf("|");
	for (int j = 0; j < size; ++j)
	{
		printf("%d ", a[j]);
	}
	printf("| %d\n", i);
	i++;
}

int partition(int *a, int l, int r)
{
	int x = a[l];
	int j = l;
	for (int i = l + 1; i < r; ++i)
	{
		if (a[i] <= x)
			j++;
	}
	std::swap(a[l], a[j]);
	return j;
}

void quickSort(int *a, int l, int r)
{
	if (l >= r)
		return;
	int m = partition(a, l, r);
	quickSort(a, 0, m - 1);
	quickSort(a, m + 1, r);

}

int main(void)
{
	int SIZE;
	std::cin >> SIZE;
	int a[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		std::cin >> a[i];
	}
	quickSort(a, 0, SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << a[i] << " ";
	}
	return 0;
}