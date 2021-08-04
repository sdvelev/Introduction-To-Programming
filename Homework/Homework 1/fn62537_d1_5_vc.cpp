/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned int number;
	int counter = 0;

	do
	{
		cin >> number;

	} while (number < 2 || number > 1000000000);

	for(int i = 2; i <= number; i++)
	{
		if (number % i  == 0)
		{
			if (i != 2 && i != 5 && i % 2 !=0 && i % 5 != 0)
			{
				cout << "NO";
				return 0;
			}
		}
	}

	if (number % 2 == 0 || number % 5 == 0)
	{
		
			double decimalNumber = 1 / (double) number;
			
			while (decimalNumber != 0)
			{
				decimalNumber = decimalNumber * 10;
				decimalNumber = decimalNumber - (int) decimalNumber;
				counter ++;
			}
			 
			cout << counter;
	}

	return 0;
}


