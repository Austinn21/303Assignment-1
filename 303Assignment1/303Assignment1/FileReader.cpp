#include "FileReader.h"
#include <iostream>
#include <fstream>

bool readDataFromFile(const std::string& filename, int dataArray[], int& rows, int& cols) {
    std::ifstream inputFile(filename); // Open the input file
    if (!inputFile.is_open()) { // Check if file is opened successfully
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false; // Return false if file open fails
    }

    // Initialize rows and cols to 0
    rows = 0;
    cols = 0;

    // Read data from the file until the end
    int value;
    while (inputFile >> value) {
        dataArray[rows * MAX_SIZE + cols] = value; // Store value in 1D array
        ++cols; // Increment column count

        // Check if we need to move to the next row
        if (cols == MAX_SIZE) {
            ++rows; // Increment row count
            cols = 0; // Reset column count
        }
    }

    // Close the input file
    inputFile.close();

    // Calculate the number of rows if not fully filled
    if (cols > 0) {
        ++rows;
    }

    return true; // Return true upon successful read
}
