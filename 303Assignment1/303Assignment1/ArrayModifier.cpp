#include "ArrayModifier.h"

std::pair<int, int> modifyValueAtIndex(int dataArray[], int index, int newValue) {
    int oldValue = dataArray[index];
    dataArray[index] = newValue;
    return std::make_pair(oldValue, newValue);
}