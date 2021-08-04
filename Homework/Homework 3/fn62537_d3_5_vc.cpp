/**
*
* Solution to homework assignment 3
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
#include<fstream>


using namespace std;

int Length(char a[]) {
    int counter = 0;

    for (int i = 0; a[i] != '\0'; i++)
        counter++;

    return counter;
}

void Swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main()
{
    const int MAX_SYMBOLS = 151;

    fstream myFile;

    myFile.open("message.txt", fstream::in);
    
    if (!myFile.is_open()) {
        cout << "-2";
        return 0;
    }
    
   
    char row[MAX_SYMBOLS];
    int symbols[MAX_SYMBOLS - 1];
   
    int lines = 0;
    while (myFile >> row) {
        lines++;
    }
    myFile.close();

    if (lines > 1000) {
        cout << "-1";
        return 0;
    }

    myFile.open("message.txt", fstream::in);
  
    while (myFile >> row) {
        int length = Length(row);
        for (int i = 0; i < length; i++) {
            if (row[i] < 'а' || row[i] > 'z') {
                if (row[i] < 'A' || row[i] > 'Z') {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    myFile.close();


    myFile.open("message.txt", fstream::in);

    while (myFile >> row) {

        int length = Length(row);
        for (int i = 0; i < length; i++) {
            symbols[i] = row[i];
        }

        int min;
        for
            (int i = 0; i < length; i++)
        {
            min = i;
            for
                (int j = i + 1; j < length; j++)
            {
                if
                    (symbols[j] < symbols[min])
                    min = j;
            }
            if (min != i)
                Swap(symbols[i], symbols[min]);
        }

        int secondMinimumElement = 0;

        for (int i = 0; i <length; i++) {
            if (abs(symbols[i + 1] - symbols[i]) > 1) {

                secondMinimumElement = symbols[i] + 1;
                if (secondMinimumElement ==91) {
                    continue;
                }
                else {
                    break;
                }
            }
       }

        if (secondMinimumElement == 123) {
            secondMinimumElement = 46;
        }
      
       cout << (char)secondMinimumElement;
    }

    myFile.close();
    return 0;
}

