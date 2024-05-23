/*
         Name------------------------------------------------------------ID

        1.)Melaku Azene-------------------------------------------1405424
        2.)Mastewal Loha-------------------------------------------1405072
        3.)Henok Worku---------------------------------------------1404652
        4.)Gerawork Zewudu------------------------------------------1404191

*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int ARr[10];
 void generatearrten(){
     for (int i = 0; i < 10; i++) {
        ARr[i] = rand() % 100;
 }
 }
// Function to generate random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Generate random numbers between 0 to 9999

    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find minimum value in the array
int findMin(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftMin = findMin(arr, low, mid);
    int rightMin = findMin(arr, mid + 1, high);
    return min(leftMin, rightMin);
}

// Function to find maximum value in the array
int findMax(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);
    return max(leftMax, rightMax);
}

// Bubble sort function
void bubbleSort(int arr[], int size) {
int temp;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                //swap(arr[j], arr[j + 1]);
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
        }
    }

}

// Merge sort functions
void merge(int arr[], int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];
    for (int i = 0; i < n1;i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Quick sort functions
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);

        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heap sort functions
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    system("color 09");
    const int SIZE = 10000;
    int arr[SIZE];

    while (true) {

        int choice;
        cout << "\nMain Menu:" << endl;
        cout << "1. Show Time Taken to sort 10,000 random numbers" << endl;
        cout << "2. Sort 10 Random Numbers b/n 0-100" << endl;
        cout << "3. Find minimum" << endl;
        cout << "4. Find maximum" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Display all in one
                {
                     system("cls");
                    system("color 0A");
                    // Generate random array
                    generateRandomArray(arr, SIZE);

                    // Bubble sort
                        clock_t start = clock();
                    bubbleSort(arr, SIZE);
                 clock_t end = clock();
          double durationBubble = double(end - start) / CLOCKS_PER_SEC ;
         cout << "Time taken for BUBBLE Sort: " << durationBubble<< " Seconds" << endl;
                    // Merge sort
                    clock_t start2=clock();
                    mergeSort(arr, 0, SIZE - 1);
                     clock_t end2 = clock();
           double durationMerge = double(end2 - start2) / CLOCKS_PER_SEC ;
             cout << "Time taken for MERGE Sort: " << durationMerge << " Seconds" << endl;


                    // Quick sort
                    clock_t start3=clock();
                    quickSort(arr, 0, SIZE - 1);
                      clock_t end3 = clock();
           double durationQuick = double(end3 - start3) / CLOCKS_PER_SEC ;
             cout << "Time taken for QUICK Sort: " << durationQuick << " Seconds" << endl;

                    // Heap sort
                    clock_t start4=clock();
                    heapSort(arr, SIZE);
                    clock_t end4 = clock();
           double durationHeap = double(end4 - start4) / CLOCKS_PER_SEC ;
             cout << "Time taken for HEAP Sort: " << durationHeap << " Seconds" << endl;
                }
                break;




                case 2: // Individually sort
{
    system("color 0B");
    // Generate random array
    generateRandomArray(arr, SIZE);

    int sortingChoice;
    cout << "\nSub Menu:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Heap Sort" << endl;
    cout << "Enter your choice: ";
    cin >> sortingChoice;

    switch (sortingChoice) {

        case 1: // Bubble sort
            {
              cout<<"Unsorted Array"<<endl;
                 generatearrten();
                 displayArray(ARr, 10);
                bubbleSort(ARr,10);

                // Display sorted array
                cout << "Sorted array:" << endl;
                displayArray(ARr, 10);

            }
            break;
        case 2: // Merge sort
            {  cout<<"Unsorted Array"<<endl;
                 generatearrten();
                 displayArray(ARr, 10);
                mergeSort(ARr,0,9);

                // Display sorted array
                cout << "Sorted array:" << endl;
                displayArray(ARr, 10);

            }
            break;
        case 3: // Quick sort
            {cout<<"Unsorted Array"<<endl;
                 generatearrten();
                 displayArray(ARr, 10);
                quickSort(ARr,0,9);

                // Display sorted array
                cout << "Sorted array:" << endl;
                displayArray(ARr, 10);

            }
            break;
        case 4: // Heap sort
            {cout<<"Unsorted Array"<<endl;
                 generatearrten();
                 displayArray(ARr, 10);
                heapSort(ARr,10);

                // Display sorted array
                cout << "Sorted array:" << endl;
                displayArray(ARr, 10);

            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    break;
}

            case 3: // Find minimum
                {
                    // Generate random array
                    generateRandomArray(arr, SIZE);


                    int minVal = findMin(arr, 0, SIZE - 1);


                    cout << "Minimum value: " << minVal << endl;

                }
                break;
            case 4: // Find maximum
                {
                    // Generate random array
                    generateRandomArray(arr, SIZE);


                    int maxVal = findMax(arr, 0, SIZE - 1);


                    cout << "Maximum value: " << maxVal << endl;

                }
                break;
            case 5: // Exit
                return 0;
                break;
            default:
                cout<<"invalid input"<<endl;

        }


    }
    return 0;
}
