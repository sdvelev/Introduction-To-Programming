/**
*
* Solution to homework assignment 1
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
	int numberBirthday = 0;
	double priceOfLaptop = 0;
	double receivedMoneyForToyOnUnevenBirthday = 0;


	do
	{
		cin >> numberBirthday;
	} while (numberBirthday <= 0);

	do
	{
		cin >> priceOfLaptop;
	
	} while (priceOfLaptop <= 0);

	do
	{
		cin >> receivedMoneyForToyOnUnevenBirthday;
	} while (receivedMoneyForToyOnUnevenBirthday <= 0);


	
	double totalMoneyForEvenBirthdays = 0;
	double totalMoneyForUnevenBirthdays = 0;
	double totalMoneyForBirthdays = 0;

	if (numberBirthday % 2 == 0)
	{
		totalMoneyForEvenBirthdays = (15 * (numberBirthday / 2) * (numberBirthday / 2) + 15* (numberBirthday / 2)) - 5 * (numberBirthday/2);
		totalMoneyForUnevenBirthdays = receivedMoneyForToyOnUnevenBirthday * (numberBirthday / 2);
	}
	else
	{
		totalMoneyForEvenBirthdays = (15 * ((numberBirthday - 1) / 2)* ((numberBirthday - 1) / 2) + 15 * ((numberBirthday - 1) / 2)) - 5 * ((numberBirthday-1)/2);
		totalMoneyForUnevenBirthdays =  (receivedMoneyForToyOnUnevenBirthday * ((numberBirthday + 1) / 2));
	}

	totalMoneyForBirthdays = totalMoneyForEvenBirthdays + totalMoneyForUnevenBirthdays;

	if (totalMoneyForBirthdays >= priceOfLaptop)
	{
		cout << "yes" << '\n';
		cout << (totalMoneyForBirthdays - priceOfLaptop);
	}
	else
	{
		cout << "no" << '\n';
		cout << (priceOfLaptop - totalMoneyForBirthdays);
	}

	return 0;

}
