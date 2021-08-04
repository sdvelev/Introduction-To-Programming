/**
*
* Solution to homework assignment 3
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

void InitString(char* niz, int n) {
    for (int i = 0; i < n; i++) {
        niz[i] = '\0';
    }
}

int StrLength(char* niz) {
    int count = 0;
    while (niz[count] != '\0')
        count++;
    return count;
}

void StrSort(char* niz) {
    int i, j;
    int n = StrLength(niz);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (niz[i] > niz[j])
            {
                char temp = niz[j];
                niz[j] = niz[i];
                niz[i] = temp;
            }
}

void StrConcat(char* niz1, char* niz2, char* inNiz, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        inNiz[k++] = niz1[i];
    }
    for (int i = 0; i < n; i++) {
        inNiz[k++] = niz2[i];
    }
}

bool StrAreEqual(char* niz1, char* niz2) {
    int n = StrLength(niz1);
    for (int i = 0; i < n; i++) {
        if (niz1[i] != niz2[i]) {
            return false;
        }
    }

    return true;
}

bool IsLowerCase(char* niz) {
    int n = StrLength(niz);
    for (int i = 0; i < n; i++) {
        if (niz[i] < 'a' || niz[i] > 'z') {
            return false;
        }
    }
    return true;
}

bool IsStringDerivedFromTheFirstTwo(char* niz1, char* niz2, char* niz3) {
    const int MAX_SIZE = 151;
    int n1 = StrLength(niz1);
    int n2 = StrLength(niz2);
    int n3 = StrLength(niz3);

    if (n1 + n2 != n3) {
        return false;
    }

    char temp[MAX_SIZE];
    InitString(temp, MAX_SIZE);

    StrConcat(niz1, niz2, temp, n1);

    StrSort(temp);

    StrSort(niz3);

    bool output = StrAreEqual(niz3, temp);
    return output;
}

int main()
{
    const int MAX_SIZE = 151;
    char niz1[MAX_SIZE], niz2[MAX_SIZE], niz3[MAX_SIZE];
    cin >> niz1;
    cin >> niz2;
    cin >> niz3;

    if (!IsLowerCase(niz1) || !IsLowerCase(niz2) || !IsLowerCase(niz3)) {
        cout << "-1";
        return 0;
    }

    cout << IsStringDerivedFromTheFirstTwo(niz1, niz2, niz3);

    return 0;
}
