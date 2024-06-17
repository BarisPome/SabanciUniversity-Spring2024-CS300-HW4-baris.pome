// CS300 – Spring 2023-2024 - Sabancı University
//Homework #4 – Sorting and Searching
// Barış Pome - 31311

// baris.pome_Pome_Baris_HW4.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

#include "baris.pome_Pome_Baris_HW4_Contact.h" // The header file contains the implementation of the Contact class
#include "baris.pome_Pome_Baris_HW4_Searching.h" // The header file contains the implementation of the BinarySearch and SequentialSearch functions
#include "baris.pome_Pome_Baris_HW4_Sorting.h" // The header file contains the implementation of the InsertionSort, QuickSort, MergeSort, and HeapSort functions

using namespace std;

// Convert a string to uppercase
string UpperCase(string str) {
    string result;
    for (char c : str) {
        result += toupper(c);
    }
    return result;
}

// the function reads the contacts from the file and returns a vector of contacts
vector<Contact> loadContactsFromFile(const string& filename) {
    ifstream input(filename);
    vector<Contact> contacts;
    if (!input) {
        cout << "Failed to open the file!" << endl;
        return contacts;
    }
    string line;
    while (getline(input, line)) {
        istringstream ss(line);
        string name, surname, number, city;
        ss >> name >> surname >> number >> city;
        contacts.push_back(Contact(UpperCase(name), UpperCase(surname), number, city));
    }
    input.close();
    return contacts;
}



int main() {
    string filename;
    cout << "Please enter the contact file name: " << endl;
    cin >> filename;

    vector<Contact> contacts = loadContactsFromFile(filename);

    // taking the query from the user
    string query;
    cout << "Please enter the word to be queried: " << endl;
    getline(cin >> ws, query); // Read the query from the user (including spaces
    query = UpperCase(query);

    cout << endl << "Sorting the vector copies" << endl;
    cout << "======================================" << endl;

    //Quick Sort
    vector<Contact> contactsCopyQuickSort = contacts;
    int n = contactsCopyQuickSort.size();
    auto start = chrono::high_resolution_clock::now();
    QuickSort(contactsCopyQuickSort, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto QuickSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Quick Sort Time: " << QuickSortTime << " Nanoseconds" << endl; // Print the time taken for Quick Sort

    //Insertion Sort
    vector<Contact> contactsCopyInsertionSort = contacts;
    start = chrono::high_resolution_clock::now();
    InsertionSort(contactsCopyInsertionSort);
    end = chrono::high_resolution_clock::now();
    auto InsertionSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Insertion Sort Time: " << InsertionSortTime << " Nanoseconds" << endl; // Print the time taken for Insertion Sort

    //Merge Sort
    vector<Contact> contactsCopyMergeSort = contacts;
    start = chrono::high_resolution_clock::now();
    MergeSort(contactsCopyMergeSort, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    auto MergeSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Merge Sort Time: " << MergeSortTime << " Nanoseconds" << endl; // Print the time taken for Merge Sort

    //Heap Sort
    vector<Contact> contactsCopyHeapSort = contacts;
    start = chrono::high_resolution_clock::now();
    HeapSort(contactsCopyHeapSort);
    end = chrono::high_resolution_clock::now();
    auto HeapSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Heap Sort Time: " << HeapSortTime << " Nanoseconds" << endl; // Print the time taken for Heap Sort


    // Searching
    cout << endl << "Searching for " << query << endl;
    cout << "======================================" << endl;
    int k = 100;


    //Binary Search
    start = chrono::high_resolution_clock::now();
    vector<int> indicesBinarySearch;
    for (int i = 0; i < k; i++) {
        indicesBinarySearch = BinarySearch(contactsCopyQuickSort, query);
    }
    end = chrono::high_resolution_clock::now();
    auto BinarySearchTime = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count() / k; // Calculate the average time taken for Binary Search

    vector <Contact> resultsBinarySearch; // Create a vector to store the search results
    if (indicesBinarySearch.size() > 0){
        for (int i = 0; i < indicesBinarySearch.size(); i++) { // Iterate over the indices of the search results
            resultsBinarySearch.push_back(contactsCopyQuickSort[indicesBinarySearch[i]]); // Add the contacts to the vector
        }
        QuickSort(resultsBinarySearch, 0, resultsBinarySearch.size() - 1); // Sort the search results
        for (int i = 0; i < resultsBinarySearch.size(); i++) { // Print the search results
            resultsBinarySearch[i].print();
        }
        cout << endl;
    }
    else {
        cout << query << " does NOT exist in the dataset" << endl; // Print a message if the query does not exist in the dataset
    }

    cout << "Binary Search Time: " << BinarySearchTime << " Nanoseconds" << endl << endl; // Print the time taken for Binary Search

    //Sequential Search
    vector<int> indicesSequentialSearch;
    cout << "Search results for Sequential Search:" << endl; // Print the search results for Sequential Search
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++) {
        indicesSequentialSearch = SequentialSearch(contactsCopyHeapSort,query);
    }
    end = chrono::high_resolution_clock::now();
    auto SequentialSearchTime = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count() / k; // Calculate the average time taken for Sequential Search

    vector <Contact> resultsSequentialSearch; // Create a vector to store the search results
    if (indicesSequentialSearch.size() > 0){
        for (int i = 0; i < indicesSequentialSearch.size(); i++) { // Iterate over the indices of the search results
            resultsSequentialSearch.push_back(contactsCopyHeapSort[indicesSequentialSearch[i]]); // Add the contacts to the vector
        }
        QuickSort(resultsSequentialSearch, 0, resultsSequentialSearch.size() - 1); // Sort the search results
        for (int i = 0; i < resultsSequentialSearch.size(); i++) {  // Print the search results
            resultsSequentialSearch[i].print();
        }
        cout << endl;
    }
    else {
        cout << query << " does NOT exist in the dataset" << endl << endl; // Print a message if the query does not exist in the dataset
    }
    cout << "Sequential Search Time: " << SequentialSearchTime << " Nanoseconds" << endl; // Print the time taken for Sequential Search

    //SpeedUps

    // SpeedUp between Search Algorithms
    cout << endl << "SpeedUp between Search Algorithms" << endl;
    cout << "======================================" << endl;
    cout << "(Sequential Search/ Binary Search) SpeedUp = " << double(SequentialSearchTime)/BinarySearchTime << endl; // Calculate the SpeedUp between Sequential Search and Binary Search

    // SpeedUp between Sorting Algorithms
    cout << endl << "SpeedUps between Sorting Algorithms" << endl;
    cout << "======================================" << endl;
    cout << "(Insertion Sort/ Quick Sort) SpeedUp = " << double(InsertionSortTime)/QuickSortTime << endl; // Calculate the SpeedUp between Insertion Sort and Quick Sort
    cout << "(Merge Sort / Quick Sort) SpeedUp = " << double(MergeSortTime)/QuickSortTime << endl; // Calculate the SpeedUp between Merge Sort and Quick Sort
    cout << "(Heap Sort / Quick Sort) SpeedUp = " << double(HeapSortTime)/QuickSortTime << endl; // Calculate the SpeedUp between Heap Sort and Quick Sort

    return 0;
}




