/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

bool IsAscending(int* arr, int lengthOfArray, int changes) {
    int counter = 0;
    int indexWrong = 0;
    for (int i = 0; i < lengthOfArray - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            counter++;
            indexWrong = i + 1;
            if (counter == 1) {
                int wrong = arr[i + 1];
                for (int j = 0; j < i - 1; j++) {
                    if (wrong < arr[i - 1]) {
                        counter++;
                    }
                }
            }
            else {
                int wrong = arr[i + 1];
                for (int j = indexWrong; j < i - 1; j++) {
                    if (wrong < arr[i - 1]) {
                        counter++;
                    }
                }
            }
        }       
    }

    for (int i = 2; i < lengthOfArray; i++) {
        
    }

    if (counter <= changes) {
        return true;
    }
    else {
        return false;
    }
    delete[] arr;
}

int main()
{
    int changes = 0;
    int lengthOfArray = 0;

    cin >> changes;
    if (changes < 1) {
        cout << "-1";
        return 0;
    }
    cin >> lengthOfArray;
    if (lengthOfArray < 1) {
        cout << "-1";
        return 0;
    }
    int* arr = new int[lengthOfArray];
    for (int i = 0; i < lengthOfArray; i++) {
        cin >> arr[i];
        if (arr[i] < 1) {
            cout << "-1";
            return 0;
        }
    }

    cout << IsAscending(arr, lengthOfArray, changes);

    return 0;
}
 