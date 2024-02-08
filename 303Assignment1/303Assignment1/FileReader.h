#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include "ArraySearch.h" // Include ArraySearch.h header

const int MAX_SIZE = 10000; // Maximum size of the array

bool readDataFromFile(const std::string& filename, int dataArray[], int& rows, int& cols);

#endif // FILEREADER_H
