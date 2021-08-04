/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 2
* @compiler VC
*
*/


#include <iostream>

using namespace std;

int main()
{
	
	int number = 0;
	int maximum = 0;
	int secondMaximum = 0;

	cin >> number;

	while (number >= 1)
	{
		if (maximum < number)
		{
			secondMaximum = maximum;
			maximum = number;
		}
	

		if (secondMaximum < number && number < maximum)
		{
			secondMaximum = number;
		}
		
		
		cin >> number;

	}


	if (secondMaximum == 0)
	{
		cout << "-1";
	}
	else
	{
		cout << secondMaximum;
	}
	
	return 0;


}

