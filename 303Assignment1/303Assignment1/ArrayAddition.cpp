#include "ArrayAddition.h"

std::pair<bool, int> addIntegerToEnd(int dataArray[], int& size, int newValue, int maxSize) {
    if (size >= maxSize) {
        return std::make_pair(false, -1); // Unable to add, array is full
    }
    dataArray[size] = newValue;
    ++size; // Increase the size
    return std::make_pair(true, size - 1); // Added successfully, return true and index of the added element
}