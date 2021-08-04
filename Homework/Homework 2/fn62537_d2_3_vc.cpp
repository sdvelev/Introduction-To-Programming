/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 3
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main()
{
    int n;

    do {
        cin >> n;
    } while (n < 3 || n > 1000);

    int numbers;
    int initNumbersArray[1000];


    for (int i = 0; i < n; i++) {

        do {
            cin >> numbers;
        } while (numbers < 0 || numbers > 9);

        initNumbersArray[i] = numbers;

    }

    int count = 0;
    int count2 = 0;
    int originalLength = n;


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < originalLength - 2; j++) {

            int count3 = 0;

            int tempNumbersArray[1000];
            for (int s = j; s < n; s++) {
                tempNumbersArray[count3] = initNumbersArray[s];
                count3++;
            }

            bool isPalindrome = true;

            int start = 0;
            int end = n - i - j - 1;

            while (end > start) {
                int a1 = tempNumbersArray[start];
                int t2 = tempNumbersArray[end];
                if (a1 != t2)
                {
                    isPalindrome = false;
                    break;

                }
                start++;
                end--;
            }

            if (isPalindrome) {
                count++;
            }
        }
        count2++;
        originalLength--;
    }


    if (count == 0) {
        count = -1;
    }

    cout << count;;
    return 0;
}