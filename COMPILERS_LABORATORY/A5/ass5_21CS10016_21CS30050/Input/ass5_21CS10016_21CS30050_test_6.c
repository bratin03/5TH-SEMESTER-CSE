/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void merge(int arr[6], int l, int m, int r)
{
	int i, j, k;
	int n1;
	n1 = m - l + 1;
	int n2;
	n2 = r - m;

	int L[6], R[6];

	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	i = 0;

	j = 0;

	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[6], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main()
{
	int arr[6];
	arr[0] = 12;
	arr[1] = 11;
	arr[2] = 14;
	arr[3] = 2;
	arr[4] = 28;
	arr[5] = 7;
	int arr_size = 6;

	mergeSort(arr, 0, arr_size - 1);
	return 0;
}
