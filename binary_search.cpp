#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoids overflow

        if (arr[mid] == target) {
            return mid;  // found
        } 
        else if (arr[mid] < target) {
            low = mid + 1;  // search right half
        } 
        else {
            high = mid - 1; // search left half
        }
    }
    return -1;  // not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Found at index " << result << endl;
    } else {
        cout << "Not found" << endl;
    }
}
