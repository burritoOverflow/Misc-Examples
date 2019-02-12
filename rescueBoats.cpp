// An imminent hurricane threatens the coastal town of Codeville.
// If at most two people can fit in a rescue boat, and the maximum
// weight limit for a given boat is k, determine how many boats
// will be needed to save everyone.

// For example, given a population with weights [100, 200, 150, 80]
// and a boat limit of 200, the smallest number of boats required
// will be three.
// 
#include <iostream>

int nBoats(int arr[], int size, int limit) {
    int boats = 0;
    for(int i = 0; i < size; i++) {
        if (arr[i] + arr[i + 1] > limit) {
            boats++;
        }
    }
    return boats;
}


int main()
{
    int arr[] = {100, 200, 150, 80};
    std::cout << nBoats(arr, (sizeof(arr)/sizeof(*arr)), 200) << std::endl;

}
