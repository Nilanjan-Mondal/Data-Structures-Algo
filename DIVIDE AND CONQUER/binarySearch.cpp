#include <stdio.h>

int count = 0; 

int binarySearch(int arr[], int low, int high, int ele) {
    if (low > high) 
        return -1;  
    
    int mid = (high + low) / 2;
    
    if (arr[mid] == ele) {
        return mid; 
    }
    
    if (arr[mid] > ele) {
        count++;
        return binarySearch(arr, low, mid - 1, ele);
        
    } else {
        count++;
        return binarySearch(arr, mid + 1, high, ele);
        
    }
}

int main() {
    int arr[] = {2, 3, 5, 7, 9, 10, 11, 12};
    int result = binarySearch(arr, 0, 7, 12); 
    printf("Index: %d\n", result);
    printf("Count: %d\n", count); 
}