#include <iostream>
#include "FileReader.h"
#include "ArraySearch.h"
#include "ArrayModifier.h"
#include "ArrayAddition.h"
#include "ReplaceRemove.h"

// Function to display the array
void displayArray(int dataArray[], int size) {
    std::cout << "Updated array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << dataArray[i] << " ";
        if ((i + 1) % 10 == 0) { // Print a newline every 10 elements for better readability
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}


int main() {
    int dataArray[MAX_SIZE];
    int size = 0; // Current size of the array
    int rows, cols;

    // Provide the input file name (Array.txt)
    std::string filename = "Array.txt";

    // Attempt to read data from file
    if (readDataFromFile(filename, dataArray, rows, cols)) {
        size = rows * cols; // Calculate the size of the array
        // Display the data read from the file
        std::cout << "Data read from file " << filename << ":" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int index = i * cols + j;
                std::cout << dataArray[index] << " ";
            }
            std::cout << std::endl;
        }

        try {
            // findIntegerIndex function:
            int target;
            std::cout << "Enter the integer you want to search for: ";
            std::cin >> target;

            int targetIndex = findIntegerIndex(dataArray, size, target);
            if (targetIndex != -1) {
                std::cout << "The integer " << target << " is present at index " << targetIndex << std::endl;
            }
            else {
                std::cout << "The integer " << target << " is not present in the array." << std::endl;
            }

            // modifyValueAtIndex function:
            int indexToModify;
            std::cout << "Enter the index you want to modify: ";
            std::cin >> indexToModify;

            if (indexToModify < 0 || indexToModify >= size) {
                throw std::out_of_range("Index out of range");
            }

            int newValue;
            std::cout << "Enter the new value: ";
            std::cin >> newValue;

            std::pair<int, int> oldValueAndNewValue = modifyValueAtIndex(dataArray, indexToModify, newValue);
            std::cout << "Old value at index " << indexToModify << ": " << oldValueAndNewValue.first << std::endl;
            std::cout << "New value at index " << indexToModify << ": " << oldValueAndNewValue.second << std::endl;

            // addIntegerToEnd function:
            int newElement;
            std::cout << "Enter the new integer to add to the end of the array: ";
            std::cin >> newElement;

            std::pair<bool, int> addResult = addIntegerToEnd(dataArray, size, newElement, MAX_SIZE);
            if (addResult.first) {
                std::cout << "Integer " << newElement << " added successfully at index " << addResult.second << std::endl;
            }
            else {
                std::cout << "Failed to add integer. Array is full." << std::endl;
            }

            // replaceValueAtIndex function:
            int indexToReplace;
            std::cout << "Enter the index you want to replace value at: ";
            std::cin >> indexToReplace;

            if (indexToReplace < 0 || indexToReplace >= size) {
                throw std::out_of_range("Index out of range");
            }

            int replaceValue;
            std::cout << "Enter the new value to replace at index " << indexToReplace << ": ";
            std::cin >> replaceValue;

            bool replaceResult = replaceValueAtIndex(dataArray, indexToReplace, replaceValue);
            if (replaceResult) {
                std::cout << "Value replaced successfully at index " << indexToReplace << std::endl;
            }
            else {
                std::cout << "Failed to replace value. Index out of bounds." << std::endl;
            }

            // removeIntegerAtIndex function:
            int indexToRemove;
            std::cout << "Enter the index you want to remove value at: ";
            std::cin >> indexToRemove;

            if (indexToRemove < 0 || indexToRemove >= size) {
                throw std::out_of_range("Index out of range");
            }

            removeIntegerAtIndex(dataArray, size, indexToRemove);
            std::cout << "Integer removed successfully from index " << indexToRemove << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    // Display the updated array after modifications
    displayArray(dataArray, size);

    return 0;
}