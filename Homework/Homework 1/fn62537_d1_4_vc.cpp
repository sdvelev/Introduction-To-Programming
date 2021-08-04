/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
    
    unsigned int number;
    unsigned int firstMultiplier = 0;
    unsigned int secondMultiplier = 0;
    unsigned int thirdMultiplier = 0;

    int sum = 0;
    int sumMin = 0;

    int firstMultiplierMin = 0;
    int secondMultiplierMin = 0;
    int thirdMultiplierMin = 0;

  
    do
    {
        cin >> number;

    } while (number < 1 || number > 1000000000);

    for (int i = 1; i <= number; i++) {
        firstMultiplier = i;
        for (int j = 1; j <= number; j++) {
            secondMultiplier = j;
            for (int t = 1; t <= number; t++) {
                thirdMultiplier = t;
                if (firstMultiplier * secondMultiplier * thirdMultiplier == number)
                {
                    sum = firstMultiplier + secondMultiplier + thirdMultiplier;
                    if (sum <= sumMin)
                    {
                        sumMin = sum;
                        firstMultiplierMin = firstMultiplier;
                        secondMultiplierMin = secondMultiplier;
                        thirdMultiplierMin = thirdMultiplier;
                    }
                    sumMin = sum;
                    sum = 0;
                }  
            }
        }
    }

    if (number == 1)
    {
        firstMultiplierMin = 1;
        secondMultiplierMin = 1;
        thirdMultiplierMin = 1;
    }

    cout << thirdMultiplierMin << " " << secondMultiplierMin << " " << firstMultiplierMin << endl;

    return 0;
}

