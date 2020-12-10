#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

void mergeSortedLists(int valuesArg[], int tempArg[], int leftArg, int middleArg, int rightArg) {
    cout << "In mergeSortedLists with left: " << leftArg << ", middle: " << middleArg << ", right:" << rightArg << endl;

    int i = leftArg; // left array
    int j = middleArg; // right array
    int k = leftArg; // temp array

    while (i < middleArg && j < rightArg) {
        if (valuesArg[i] <= valuesArg [j]) {
            tempArg[k] = valuesArg[i];
            i++;
            k++;
        }

        else {
            tempArg[k] = valuesArg[j];
            j++;
            k++;
        }
    }

    for (i = i; i < middleArg; i++) {
        tempArg[k] = valuesArg[i];
        k++;
    }

    for (j = j; j < rightArg; j++) {
        tempArg[k] = valuesArg[j];
        k++;
    }

    //loop to get from temp array back into values array

    for (i = leftArg; i < rightArg; i++) {
        valuesArg[i] = tempArg[i];
    }

    //this sorts the temporary array
}

void mergeSort(int valuesArg[], int tempArg[], int leftArg, int rightArg) {
    cout << "In mergesort with left: " << leftArg << ", right:" << rightArg << endl;

    int middleArg;

    if (rightArg - leftArg <= 1) {
        return;
    }

    middleArg = (leftArg + rightArg)/2;

    mergeSort(valuesArg, tempArg, leftArg, middleArg);
    mergeSort(valuesArg, tempArg, middleArg, rightArg);
    mergeSortedLists(valuesArg, tempArg, leftArg, middleArg, rightArg);

    //to find index 1 in temporary array
//    int a = sizeof(valuesArg);
//    for (int i = leftArg; valuesArg[0] < a; i++) {
//        if (valuesArg[i] > valuesArg[a]) {
//            tempArg[0] = valuesArg[a]/2; //midpoint
//        }
//    }

    //this sorts the two arrays individually
}

int main() {

    // unit test for merge

    /*
     * TO DO: your code here
     */


    // Get input: first is random seed, second is array length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    int values[length];
    int temp[length];

    int index;

    // Initialize and prints array of size specified by user
    cout << "Printing array before sort:" << endl;
    for(index = 0; index < length; index = index + 1) {
        values[index] = rand() % 100;
        cout << values[index] << '\t';
    }
    cout << endl;

    // Sorts the values

    mergeSort(values, temp, 0, length);

    // Prints the output (sorted array)
    cout << "Printing array after sort:" << endl;
    for(index = 0; index < length; index = index + 1) {
        cout << values[index] << '\t';
    }
    cout << endl;

    // Checks the output (sorted array) to make sure it's sorted
    for(index = 1; index < length; index = index + 1) {
        assert(values[index-1] <= values[index]);
    }

    return 0;
}