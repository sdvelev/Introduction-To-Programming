/**
*
* Solution to homework assignment 4
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

int gcd(int a, int b) {

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int* Result(int firstNumerator, int firstDenominator, char operation, int secondNumerator, int secondDenominator) {

    static int result[2];
    
    int firstFractionGCD;
    int secondFractionGCD;
    int resultNumerator;
    int resultDenominator;

    if (firstNumerator == 0) {
        firstFractionGCD = 0;
    }
    else if (firstNumerator < 0) {
        firstFractionGCD = gcd(-firstNumerator, firstDenominator);
    }
    else {
        firstFractionGCD = gcd(firstNumerator, firstDenominator);
    }

    if (secondNumerator == 0) {
        secondFractionGCD = 0;
    }
    else if (secondNumerator < 0) {
        secondFractionGCD = gcd(-secondNumerator, secondDenominator);
    }
    else {
        secondFractionGCD = gcd(secondNumerator, secondDenominator);
    }

    if (firstFractionGCD != 1 && firstFractionGCD != 0) {
        firstNumerator = firstNumerator / firstFractionGCD;
        firstDenominator = firstDenominator / firstFractionGCD;
    }

    if (secondFractionGCD != 1 && secondFractionGCD != 0) {
        secondNumerator = secondNumerator / secondFractionGCD;
        secondDenominator = secondDenominator / secondFractionGCD;
    }


    if (operation == '+') {
        resultNumerator = firstNumerator * secondDenominator + firstDenominator * secondNumerator;
        resultDenominator = firstDenominator * secondDenominator;
    }

    if (operation == '-') {
        resultNumerator = firstNumerator * secondDenominator - firstDenominator * secondNumerator;
        resultDenominator = firstDenominator * secondDenominator;
    }

    if (operation == '*') {
        resultNumerator = firstNumerator * secondNumerator;
        resultDenominator = firstDenominator * secondDenominator;
    }

    if (operation == '/') {
        resultNumerator = firstNumerator * secondDenominator;
        resultDenominator = firstDenominator * secondNumerator;
    }
    if (operation == '/' && secondNumerator < 0) {
        resultNumerator *= (-1);
        resultDenominator *= (-1);
    }
    int resultFractionGCD;
    if (resultNumerator == 0) {
        resultFractionGCD = 0;
    }
    else if (resultNumerator < 0) {
        resultFractionGCD = gcd(-resultNumerator, resultDenominator);
    }
    else {
        resultFractionGCD = gcd(resultNumerator, resultDenominator);
    }

    if (resultFractionGCD != 1 && resultFractionGCD != 0) {
        resultNumerator = resultNumerator / resultFractionGCD;
        resultDenominator = resultDenominator / resultFractionGCD;
    }
    
    if (resultNumerator == 0) {
        resultDenominator = 1;
    }

    if (resultNumerator < -100000000 || resultNumerator > 100000000) {
        return nullptr;
    }

    if (resultDenominator < -100000000 || resultDenominator > 100000000) {
        return nullptr;
    }

    result[0] = resultNumerator;
    result[1] = resultDenominator;

    return result;

}


int main()
{
    int firstNumerator;
    int firstDenominator;
    int secondNumerator;
    int secondDenominator;

    char operation;

     cin >> firstNumerator;
     if (firstNumerator < -100000000 || firstNumerator > 100000000) {
        cout << "-1";
        return 0;
    }

     cin >> firstDenominator;
     if (firstDenominator == 0 || (firstDenominator < -100000000 || firstDenominator > 100000000)) {
         cout << "-1";
         return 0;
     }

   
    cin >> operation;
    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout << "-1";
        return 0;
    }
   

    cin >> secondNumerator;
    if ((operation == '/' && secondNumerator == 0) || (secondNumerator < -100000000 || secondNumerator > 100000000)) {
        cout << "-1";
        return 0;
    }

   
    cin >> secondDenominator;
    if (secondDenominator == 0 || (secondDenominator < -100000000 || secondDenominator > 100000000)) {
        cout << "-1";
        return 0;
    }

    int * result =  Result(firstNumerator, firstDenominator, operation, secondNumerator, secondDenominator);

    if (result == nullptr) {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        cout << *(result + i) << " ";
    }

    return 0;
}
