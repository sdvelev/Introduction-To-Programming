/**
*
* Solution to homework assignment 3
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

int StrLength(char arr[]) {
	int counter = 0;

	for (int i = 0; arr[i] != '\0'; i++)
		counter++;

	return counter;
}

int CountOfAllSubarrays(char arr[], int n) {
	int counter = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			counter++;
		}
	}
	return counter;
}


int main()
{
	char a[101];
	cin >> a;
	int lengtha = StrLength(a);
	cout << CountOfAllSubarrays(a, lengtha);
	return 0;
}











//#include<iostream>
//#include <bitset>
//
//using namespace std;
//
//
//
//int StrLength(char* niz) {
//	int count = 0;
//	while (niz[count] != '\0')
//		count++;
//	return count;
//}
//
//void sort(char niz[]) {
//	int i, j;
//	int n = StrLength(niz);
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			if (niz[i] > niz[j])
//			{
//				char temp = niz[j];
//				niz[j] = niz[i];
//				niz[i] = temp;
//			}
//}
//
//void printCombinations(char q[]) {
//	cout << "We are now printing out all the combinations of " << q << endl;
//	sort(q);
//	bitset<10> b;
//	int count = 0;
//	for (int i = 0; i < pow(2,StrLength(q)); ++i) {
//		for (int x = 0; x < 10; x++) {
//			if (b[x] == 1) {
//				cout << q[x];
//			}
//		}
//		count++;
//		cout << endl;
//		for (int j = 0; j < 10; j++) {
//			if (b[j] == 1) {
//				b[j].flip();
//			}
//			else {
//				b[j].flip();
//				break;
//			}
//		}
//	}
//	cout << "There are " << count << " combinations" << endl;
//}
//
//int main() {
//
//	char std[100];
//	cin >> std;
//	printCombinations(std);
//	return 0;
//}
//









/*#include<iostream>


using namespace std;

int Binary(int n) {
	// array to store binary number
	int binaryNum[100];

	// counter for binary array 
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array 
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		return binaryNum[j];
}

int Length(char a[]) {
	int counter = 0;
	while (a[counter] != '\0')
		counter++;
	return counter;
	
}

int NumberOfAllCombinations(int comb[], int n) {

	int temp;
	int counter = 0;

	for (int i = 1; i <= n; i++) {
		comb[i - 1] = i;
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < n - 1; i++) {
			temp = comb[i];
			comb[i] = comb[i + 1];
			comb[i + 1] = temp;
			counter++;
		}
	}

	return counter;

 }

int main() {

	const int MAX_SIZE = 100;
	char niz[MAX_SIZE];

	cin >> niz;

	int n = Length(niz);

	int comb[100];
	
	cout << NumberOfAllCombinations(comb, n);
	return 0;

}
*/

