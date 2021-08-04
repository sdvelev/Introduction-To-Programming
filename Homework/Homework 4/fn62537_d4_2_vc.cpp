/**
*
* Solution to homework assignment 4
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

bool CanKnightReachPosition(int width, int length, int p, int q, int p1, int q1, int k) {
	if (p == p1 && q == q1) return true;
	if (k == 0) return false;
	if (p < 0 || p > width-1 || q < 0 || q > length-1) return false;
	if (CanKnightReachPosition(width, length, p + 2, q + 1, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p + 1, q + 2, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p - 1, q - 2, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p - 2, q - 1, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p + 2, q - 1, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p + 1, q - 2, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p - 1, q + 2, p1, q1, k - 1)) return true;
	if (CanKnightReachPosition(width, length, p - 2, q + 1, p1, q1, k - 1)) return true;
	return false;
}

int main()
{
	int width, length, p, q, p1, q1, k;
	cin >> width;
	if (width <= 3 || width > 200) {
		cout << "-1";
		return 0;
	}
	cin >> length;
	if (length <= 3 || length > 200) {
		cout << "-1";
		return 0;
	}
	cin >> p;
	if (p < 0 || p > width - 1) {
		cout << "-1";
		return 0;
	}
	cin >> q;
	if (q < 0 || q > length - 1) {
		cout << "-1";
		return 0;
	}
	cin >> p1;
	if (p1 < 0 || p1 > width - 1) {
		cout << "-1";
		return 0;
	}
	cin >> q1;
	if (q1 < 0 || q1 > length - 1) {
		cout << "-1";
		return 0;
	}
	cin >> k;
	if (k <= 0 || k > 30) {
		cout << "-1";
		return 0;
	}
	cout  << ((CanKnightReachPosition(width, length, p, q, p1, q1, k)) ? "True" : "False");
	return 0;
}

