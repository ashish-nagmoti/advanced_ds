#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

void MinHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;

        if (temp < a[j])
            break;

        else if (temp >= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void maxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;

        if (temp > a[j])
            break;

        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void Build_MinHeap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        MinHeapify(a, i, n);
    }
}

void Build_maxHeap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(a, i, n);
    }
}

void printHeap(int arr[], int n, int index, int level)
{
    if (index > n)
    {
        return;
    }    

    printHeap(arr, n, 2 * index + 1, level + 1);

    cout << setw(level * 4) << " ";
    cout << arr[index] << endl;

    printHeap(arr, n, 2 * index, level + 1);
}

int main()
{
    int n;
    cout << "\nEnter the number of Students : ";
    cin >> n;
    n++;
    int arr_min[n];
    int arr_max[n];
    bool minHeapBuilt = false;
    bool maxHeapBuilt = false;

    int choice;
    do {
        cout << "\n.....Menu:......\n";
        cout << "1. Build Min Heap\n";
        cout << "2. Build max Heap\n";
        cout << "3. Display Min Heap\n";
        cout << "4. Display max Heap\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                for (int i = 1; i < n; i++)
                {
                    cout << "Enter the marks :  " << i << ": ";
                    cin >> arr_min[i];
                }
                Build_MinHeap(arr_min, n - 1);
                minHeapBuilt = true;
                cout << "\nMin Heap Tree constructed.\n";
                break;

            case 2:
                for (int i = 1; i < n; i++)
                {
                    cout << "Enter the marks :  " << i << ": ";
                    cin >> arr_max[i];
                }
                Build_maxHeap(arr_max, n - 1);
                maxHeapBuilt = true;
                cout << "\nmax Heap Tree constructed.\n";
                break;

            case 3:
                if (minHeapBuilt)
                {
                    cout << "\nMin Heap Tree:\n";
                    printHeap(arr_min, n - 1, 1, 0);
                }
                else
                {
                    cout << "\nMin Heap has not been built yet.\n";
                }
                break;

            case 4:
                if (maxHeapBuilt)
                {
                    cout << "\nmax Heap Tree:\n";
                    printHeap(arr_max, n - 1, 1, 0);
                }
                else
                {
                    cout << "\nmax Heap has not been built yet.\n";
                }
                break;

            case 5:
                cout << "\nExiting the program.\n";
                break;

            default:
                cout << "\nInvalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}

