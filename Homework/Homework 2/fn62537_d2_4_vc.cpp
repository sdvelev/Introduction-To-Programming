/**
*
* Solution to homework assignment 2
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
#include <vector>
using namespace std;

int main()
{
    int n;
    do {
        cin >> n;
    } while (n < 3 || n > 100);

    vector<int> numbers;
 
    int counter = 1;
    int number = 0;
    int number1 = 0;

    int counterSum = 0;
        cin >> number;
    numbers.push_back(number);

    while (counter != n) {

        cin >> number1;
        if (number1 == number || count(numbers.begin(), numbers.end(), number1) == 1)
        {

        }
        else {

            counter++;
            numbers.push_back(number1);
            number = number1;
        }
    }
    

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] > numbers[j]) swap(numbers[i], numbers[j]);
        }
    }


    for (int i = 0; i < (numbers.size() - 2); i++) {

        for (int j = i+1; j < (numbers.size()-1); j++)
        {
            for (int k = j+1; k < numbers.size(); k++)
            {
                if (numbers[i] + numbers[j] + numbers[k] == 0) {
                    counterSum++;
                }
            }
        }

    }

    cout << counterSum;
    return 0;
}

