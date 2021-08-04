/**
*
* Solution to homework assignment 3
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

int StrLenght(char* niz) {
    int count = 0;
    while (niz[count] != '\0')
        count++;
    return count;
}

void StrSort(char* niz) {
    int i, j;
    int n = StrLenght(niz);
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            if (niz[i] > niz[j])
            {
                char temp = niz[j];
                niz[j] = niz[i];
                niz[i] = temp;
            }
}

bool CheckEqualCharacter(char* niz) {
    int n = StrLenght(niz);
    char c = niz[0];
    for (int i = 0; i < n; i++) {
        if (niz[i] != c) {
            return false;
        }
    }
    return true;
}

void InitString(char* niz, int n) {
    for (int i = 0; i < n; i++) {
        niz[i] = 0;
    }
}

bool IsStringCorrect(char* niz) {
    
    const int MAX_SIZE = 151;
   
    StrSort(niz);

    int n = StrLenght(niz);
    for (int i = -1; i < n; i++) {
        if (CheckEqualCharacter(niz)) {
            return true;
        }
        int counter = 1;
        int times = 0;
        bool correct = true;
        char niz2[MAX_SIZE];
        InitString(niz2, MAX_SIZE);
        int l = 0;
        for (int k = 0; k < n; k++) {
            if (k != i)
                niz2[l++] = niz[k];
        }

        int n2 = StrLenght(niz2);

        for (int j = 0; j < n2 - 1; j++) {

            if (niz2[j + 1] == niz2[j]) {
                counter++;
            }
            else {
                if (times == 0) {
                    times = counter;
                }
                else if (times != counter) {
                    correct = false;
                    break;
                }
                if (j < n - 1)
                    counter = 1;
            }
        }
        if (correct == true && times == counter) {
            return true;
        }
    }

    return false;
}

int main()
{
    const int MAX_SIZE = 151;
    char niz[MAX_SIZE];

    cin >> niz;

    cout << IsStringCorrect(niz);
 
    return 0;
}

