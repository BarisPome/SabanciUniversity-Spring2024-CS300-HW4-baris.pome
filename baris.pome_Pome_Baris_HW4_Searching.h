//
// Created by Barış Pome on 22.05.2024.
//

#ifndef BARIS_POME_POME_BARIS_HW4_SEARCHING_H
#define BARIS_POME_POME_BARIS_HW4_SEARCHING_H

#include <vector>
#include <string>
#include <algorithm>

#include "baris.pome_Pome_Baris_HW4_Contact.h"


using namespace std;

// The BinarySearch function searches for the key in the vector c and returns the indices of the elements that are equal to the key.
template <class T>
vector<int> BinarySearch(const vector<T>& c, const string& key) { // Binary Search
    vector<int> indices; // Create a vector to store the indices of the elements that are equal to the key
    int left = 0; // Initialize the left index
    int right = c.size() - 1; // Initialize the right index
    while (left <= right) { // While the left index is less than or equal to the right index
        int mid = (left + right) / 2; // Calculate the middle index
        if (c[mid] == key) { // If the element at the middle index is equal to the key
            indices.push_back(mid); // Add the index of the element to the vector
            int i = mid - 1; // Initialize the left index
            while (i >= 0 && c[i] == key) { // While the left index is greater than or equal to 0 and the element at the left index is equal to the key
                indices.push_back(i);   // Add the index of the element to the vector
                i--; // Decrement the left index
            }
            i = mid + 1; // Initialize the right index
            while (i < c.size() && c[i] == key) {   // While the right index is less than the size of the vector and the element at the right index is equal to the key
                indices.push_back(i); // Add the index of the element to the vector
                i++; // Increment the right index
            }
            return indices; // Return the vector of indices
        }
        else if (c[mid] < key) { // If the element at the middle index is less than the key
            left = mid + 1;
        }
        else { // If the element at the middle index is greater than the key
            right = mid - 1;
        }
    }
    return indices; // Return an empty vector if the key is not found
}


// The SequentialSearch function searches for the key in the vector v and returns the indices of the elements that are equal to the key.
template <class T>
vector<int> SequentialSearch(const vector<T>& v, const string& key) {
    vector<int> indices; // Create a vector to store the indices of the elements that are equal to the key
    for (int i = 0; i < v.size(); i++) { // Iterate over the elements of the vector
        if (v[i] == key) // If the element is equal to the key
            indices.push_back(i); // Add the index of the element to the vector
    }
    return indices; // Return the vector of indices
}

#endif //BARIS_POME_POME_BARIS_HW4_SEARCHING_H
