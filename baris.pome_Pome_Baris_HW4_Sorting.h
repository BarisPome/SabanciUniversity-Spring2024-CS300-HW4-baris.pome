//
// Created by Barış Pome on 22.05.2024.
//

#ifndef BARIS_POME_POME_BARIS_HW4_SORTING_H
#define BARIS_POME_POME_BARIS_HW4_SORTING_H

#include <vector>
#include <algorithm>


using namespace std;


//The sorting algorithms you will compare are:
//● Insertion Sort
//● Quick Sort (pivot=median) (use Insertion Sort when size < 10)
//● Merge Sort (in place; without using auxiliary memory storage)
//● Heap Sort

//● Insertion Sort
//Insertion Sort Algorithm is taken from lecture slides.
template <class Comparable>
void InsertionSort(vector<Comparable>& a) { // Insertion Sort
    int j = 0;
    for (int i = 1; i < a.size(); i++) { //for each element in the array
        Comparable temp = a[i]; //store the element in a temp variable
        j = i - 1; //start from the previous element
        while (j >= 0 && a[j] > temp) { //while the previous element is greater than the current element
            a[j + 1] = a[j]; //shift the previous element to the right
            j--; //move to the next element
        }
        a[j + 1] = temp; //insert the current element to the correct position
    }
}


//● Quick Sort (pivot=median) (use Insertion Sort when size < 10)
//Quick Sort Algorithm is taken from lecture slides.
template <class Comparable>
const Comparable & median3(vector<Comparable>& a, int left, int right) { // Median of three partitioning
    int center = (left + right) / 2;
    if (a[center] < a[left]) { // Order left and center
        swap(a[left], a[center]);
    }
    if (a[right] < a[left]) { // Order left and right
        swap(a[left], a[right]);
    }
    if (a[right] < a[center]) { // Order center and right
        swap(a[center], a[right]);
    }
    // Place pivot at position right - 1
    swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <class Comparable>
void InsertionSortQuick(vector<Comparable>& a, int left, int right) { // Insertion Sort for Quick Sort
    for (int p = left + 1; p <= right; p++) { // Insertion Sort
        Comparable tmp = a[p]; // Store the element
        int j; // Shift larger elements to the right
        for (j = p; j > left && tmp < a[j - 1]; j--) { // Find the correct position
            a[j] = a[j - 1];
        } // Insert the element
        a[j] = tmp;
    }
}

template <class Comparable>
void QuickSort(vector<Comparable> & a, int left, int right) { // Quick Sort
    if (left + 10 <= right) { // If the size of the subarray is greater than 10
        Comparable pivot = median3(a, left, right);
        // Beginning of partitioning
        int i = left, j = right - 1;
        for (;;) { // Partitioning
            while (a[++i] < pivot) {} // Find the element larger than the pivot
            while (pivot < a[--j]) {} // Find the element smaller than the pivot
            if (i < j) { // Swap the elements
                swap(a[i], a[j]);
            } else {
                break;
            }
        }
        swap(a[i], a[right - 1]); // Restoring the pivot for the next partition
        QuickSort(a, left, i - 1);   // Sort the small elements
        QuickSort(a, i + 1, right); // Sort the large elements
    } else { // If the size of the subarray is less than 10
        InsertionSortQuick(a, left, right); // Do an insertion sort on the subarray
    }
}


//● Merge Sort (in place; without using auxiliary memory storage)
//Merge Sort Algorithm is taken from lecture slides.
template <class Comparable>
void merge(vector<Comparable>& arr, int start, int mid, int end) { // Merge
    int start2 = mid + 1; // If the direct merge is already sorted
    if (arr[mid] <= arr[start2]) { // No need to merge
        return;
    }
    while (start <= mid && start2 <= end) { // Two pointers to maintain start of both arrays to merge
        if (arr[start] <= arr[start2]) { // If element 1 is in right place
            start++; // Move the pointer
        } else {
            Comparable value = arr[start2]; // Store the second element and shift all elements to the right by 1
            int index = start2; // Move all elements to the right
            while (index != start) { // Move all elements to the right
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value; // Move the second element to its correct position
            start++; // Increment all pointers
            mid++; // Increment all pointers
            start2++; // Increment all pointers
        }
    }
}

template <class Comparable>
void MergeSort(vector<Comparable>& arr, int l, int r) { // Merge Sort
    if (l < r) { // If the left index is less than the right index
        int m = l + (r - l) / 2; // Find the middle point
        MergeSort(arr, l, m); // Sort the first and second halves
        MergeSort(arr, m + 1, r); // Merge the sorted halves
        merge(arr, l, m, r); // Merge the sorted halves
    }
}

//● Heap Sort
//The heap sort algorithm is implemented following a standard approach.
template <class Comparable>
void heapify(vector<Comparable>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <class Comparable>
void HeapSort(vector<Comparable>& arr) {
    int n = arr.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0);  // call max heapify on the reduced heap
    }
}




#endif //BARIS_POME_POME_BARIS_HW4_SORTING_H