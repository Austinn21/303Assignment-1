#include "ArrayModifier.h"

bool replaceValueAtIndex(int dataArray[], int index, int newValue) {
    if (index >= 0) {
        dataArray[index] = newValue;
        return true; // Successfully replaced value
    }
    return false; // Index out of bounds
}

void removeIntegerAtIndex(int dataArray[], int& size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; ++i) {
            dataArray[i] = dataArray[i + 1]; // Shift elements to the left
        }
        --size; // Decrease the size
    }
}