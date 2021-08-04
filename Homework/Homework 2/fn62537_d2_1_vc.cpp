/**
*
* Solution to homework assignment 2
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

int main()
{
    int n;
    do {
        cin >> n;
    } while (n < 3 || n > 100);

    int numbers[100];

    
    for (int i = 0; i < n; i++) {

        do {

            cin >> numbers[i];

        } while (numbers[i] < 1 );

    }

    for (int j = 0; j < n / 2; j++)
    {
        if (abs(numbers[j]- numbers[j+1]) == abs(numbers[n-1-j] - numbers[n-2-j]))
        {
            continue;
        }
        else
        {
            cout << "0";
            return 0;
        }
   }

    cout << "1";
    return 0;

}


 