#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr, int n)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int index = low;

    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[index], arr[i]);
            index++;
        }
    }

    swap(arr[index], arr[high]);
    return index;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int BinarySearch(vector<int> &arr, int low, int high, int search)
{
    if (low > high)
        return -1;

    int mid = (high + low) / 2;

    if (search == arr[mid])
        return mid;
    else if (search < arr[mid])
        return BinarySearch(arr, low, mid - 1, search);
    else
        return BinarySearch(arr, mid + 1, high, search);
}

int main()
{
    int choice;
    vector<int> arr;
    bool arrayInitialized = false;

    do
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Press 0 to Exit" << endl;
        cout << "Press 1 for Insertion Sort" << endl;
        cout << "Press 2 for Quick Sort" << endl;
        cout << "Press 3 for Binary Search" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
        {
            int n;
            cout << "Enter the Size of the Array: ";
            cin >> n;

            arr.clear();
            for (int i = 0; i < n; i++)
            {
                int element;
                cout << "Enter arr[" << i << "]:";
                cin >> element;
                arr.push_back(element);
            }

            cout << "Original Array: ";
            printArray(arr, n);

            insertionSort(arr, n);
            arrayInitialized = true;

            cout << "Sorted Array: ";
            printArray(arr, n);
            
        }
        break;

        case 2:
        {
            int n;
            cout << "Enter the size of the array:";
            cin >> n;

            arr.clear();
            for (int i = 0; i < n; i++)
            {
                int element;
                cout << "Enter arr[" << i << "]:";
                cin >> element;
                arr.push_back(element);
            }

            cout << "Original Array: ";
            printArray(arr, n);

            quickSort(arr, 0, n - 1);
            arrayInitialized = true;

            cout << "Sorted Array: ";
            printArray(arr, n);
        }
            break;

        case 3:
        {
            if (!arrayInitialized)
            {
                cout << "Please sort the array first using option 1 or 2." << endl;
                break;
            }

            int search;
            cout << "Enter element to search: ";
            cin >> search;

            int index = BinarySearch(arr, 0, arr.size() - 1, search);

            if (index != -1)
                cout << "Element found at index " << index << endl;
            else
                cout << "Element not found!" << endl;
        }
        break;

        default:
            cout << "Invalid choice!" << endl;
        
        }

    } while (choice != 0);

    return 0;
}
