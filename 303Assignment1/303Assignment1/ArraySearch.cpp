#include "ArraySearch.h"

int findIntegerIndex(const int dataArray[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (dataArray[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}