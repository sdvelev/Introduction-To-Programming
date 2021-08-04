/**
*
* Solution to homework assignment 2
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
    int days;
    do {

        cin >> days;

    } while (days < 2 || days > 365);


    double price[365];
    double priceForDay;

    for (int i = 0; i < days; i++) {

        do {

            cin >> priceForDay;

        } while (priceForDay < 0.1 || priceForDay > 100);

        price[i] = priceForDay;
    }

    int count = 0;
    int count2 = 0;
    int temp = 0;
    double profit = 0;


    int solution[365][2];

    while (temp < days - 1) {

        while ((temp < days - 1) && (price[temp + 1] <= price[temp])) {

            temp++;
        }

        if (temp == (days - 1))
            break;

        int buy = temp;
        temp = temp + 1;

        while ((temp < days) && (price[temp] >= price[temp - 1])) {

            temp++;
        }

        int sell = temp - 1;
        solution[count2][0] = buy;
        solution[count2][1] = sell;

        count2++;
        count++;

    }

    for (int i = 0; i < count; i++) {

        double sold =  price[solution[i][1]];
        double purchase =  price[solution[i][0]];
        profit = profit + sold - purchase;
    }

    cout << profit;
    return 0;
}
