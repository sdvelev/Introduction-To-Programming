/**
*
* Solution to homework assignment 3
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

bool AreEqual(double a, double b) {

    double EPS = 0.00000001;
    return ((a - b) < EPS);
}

bool isMagicSquare(double table[100][100], int n) {

    double sums[5];

    double sumOfRows = 0, sumOfRowsTemp = 0;

    for (int rows = 0; rows < n; rows++) {

        sumOfRows = 0;
        for (int i = 0; i < n; i++) {
            sumOfRows += table[rows][i];
        }

        if (rows == 0) {
            sumOfRowsTemp = sumOfRows;
        }

        if (!AreEqual(sumOfRows, sumOfRowsTemp)){
            return false;
        }
    }

    sums[0] = sumOfRowsTemp;

    double sumOfCols = 0, sumOfColsTemp = 0;


    for (int cols = 0; cols < n; cols++) {

        sumOfCols = 0;
        for (int i = 0; i < n; i++) {
            sumOfCols += table[i][cols];
        }

        if (cols == 0) {
            sumOfColsTemp = sumOfCols;
        }

        if (!AreEqual(sumOfCols, sumOfColsTemp)){
            return false;
        }
    }

    sums[1] = sumOfColsTemp;

    double sumOfMainDiagonal = 0;

    for (int mainDiag = 0; mainDiag < n; mainDiag++) {

        sumOfMainDiagonal += table[mainDiag][mainDiag];
    }

    sums[2] = sumOfMainDiagonal;


    double sumOfSecondDiagonal = 0;

    for (int secDiag = 0; secDiag < n; secDiag++) {

        sumOfSecondDiagonal += table[secDiag][n - 1 - secDiag];
    }

    sums[3] = sumOfSecondDiagonal;

    if (AreEqual(AreEqual(sums[0], sums[1]),AreEqual(sums[2], sums[3])))
    {
        return true;

    }
    else {
        return false;
    }

}

int main()
{
    int n;
    cin >> n;

    if (n <=1 or n >= 1000) {

        cout << "-1";
        return 0;

    }

    double table[100][100];

    for (int r = 0; r < n; r++) {
        for (int col = 0; col < n; col++) {
            cin >> table[r][col];
            if (table[r][col] < 0 || table[r][col] > 100) {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << (isMagicSquare(table,n) == 1 ? "true" : "false");
    return 0;
}
