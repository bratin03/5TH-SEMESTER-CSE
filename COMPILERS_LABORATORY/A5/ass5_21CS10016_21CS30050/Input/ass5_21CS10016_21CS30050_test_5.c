/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void reverse_array(int arr[100], int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int main()
{

    int arr[5];
    arr[0] = 10;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 50;
    arr[4] = 70;
    int size = 5;

    reverse_array(arr, size);

    return 0;
}
