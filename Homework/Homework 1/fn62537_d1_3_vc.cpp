/**
*
* Solution to homework assignment 1
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

int main()
{
    int firstDigit, secondDigit, thirdDigit;
    int maxDigit, midDigit, minDigit;
  
    do
    {
        cin >> firstDigit;

    } while (firstDigit <0 || firstDigit > 9);

    do
    {
        cin >> secondDigit;

    } while (secondDigit < 0 || secondDigit > 9);

    do
    {
        cin >> thirdDigit;

    } while (thirdDigit< 0 || thirdDigit > 9);
    

    if (firstDigit>=secondDigit && firstDigit>=thirdDigit)
    {
        maxDigit = firstDigit;
        if (secondDigit > thirdDigit)
        {
            midDigit = secondDigit;
            minDigit = thirdDigit;
        }
        else
        {
            midDigit = thirdDigit;
            minDigit = secondDigit;
        }

    }

    if (secondDigit >= thirdDigit && secondDigit >= firstDigit)
    {
        maxDigit = secondDigit;
        if (firstDigit > thirdDigit)
        {
            midDigit = firstDigit;
            minDigit = thirdDigit;
        }
        else
        {
            midDigit = thirdDigit;
            minDigit = firstDigit;
        }

    }

    if (thirdDigit >= firstDigit && thirdDigit >= secondDigit)
    {
        maxDigit = thirdDigit;
        if (firstDigit > secondDigit)
        {
            midDigit = firstDigit;
            minDigit = secondDigit;
        }
        else
        {
            midDigit = secondDigit;
            minDigit = firstDigit;
        }

    }


    int palindrom = 0;

    palindrom = minDigit * 10000 + midDigit * 1000 + maxDigit * 100 + midDigit * 10 + minDigit;


    if (firstDigit == 0 && secondDigit > thirdDigit && secondDigit != 0 && thirdDigit !=0)
    {
        minDigit = thirdDigit;
        midDigit = firstDigit;
        maxDigit = secondDigit;

        palindrom = minDigit * 10000 + maxDigit * 100 + minDigit;
    }
    else if (firstDigit == 0 && secondDigit < thirdDigit && secondDigit != 0 && thirdDigit != 0)
    {
        minDigit = secondDigit;
        midDigit = firstDigit;
        maxDigit = thirdDigit;
        palindrom = minDigit * 10000 + maxDigit * 100 + minDigit;
    }
    else if (secondDigit == 0 && firstDigit > thirdDigit && firstDigit != 0 && thirdDigit != 0)
    {
        minDigit = thirdDigit;
        midDigit = secondDigit;
        maxDigit = firstDigit;
        palindrom = minDigit * 10000 + maxDigit * 100 + minDigit;
    }
    else if (secondDigit == 0 && firstDigit < thirdDigit && firstDigit != 0 && thirdDigit != 0)
    {
        minDigit = firstDigit;
        midDigit = secondDigit;
        maxDigit = thirdDigit;
        palindrom = minDigit * 10000 + maxDigit * 100 + minDigit;
    }
    else if (thirdDigit == 0 && firstDigit > secondDigit && secondDigit != 0 && firstDigit != 0)
    {
        minDigit = secondDigit;
        midDigit = thirdDigit;
        maxDigit = firstDigit;
        palindrom = minDigit * 10000 + maxDigit * 100 + minDigit;
    }
    else if (thirdDigit == 0 && firstDigit < secondDigit && secondDigit != 0 && firstDigit != 0)
    {
        minDigit = firstDigit;
        midDigit = thirdDigit;
        maxDigit = secondDigit;
        palindrom = minDigit * 10000 + maxDigit * 100 + minDigit;
    }
    else if (firstDigit == 0 && secondDigit == 0 && thirdDigit !=0)
    {
        minDigit = thirdDigit;
        midDigit = firstDigit;
        maxDigit = secondDigit;
        palindrom = minDigit * 1000 + minDigit;
    }
    else if (secondDigit == 0 && thirdDigit == 0 && firstDigit !=0)
    {
        minDigit = firstDigit;
        midDigit = thirdDigit;
        maxDigit = secondDigit;
        palindrom = minDigit * 1000 + minDigit;
    }
    else if (firstDigit == 0 && thirdDigit == 0 && secondDigit != 0)
    {
        minDigit = secondDigit;
        midDigit = thirdDigit;
        maxDigit = firstDigit;
        palindrom = minDigit * 1000 + minDigit;
        
    }
    else if (firstDigit == 0 && secondDigit == 0 && thirdDigit == 0)
    {
        cout << "0";
        return  0;
    }
    
    
    if (firstDigit == secondDigit && secondDigit == thirdDigit)
    {
        palindrom = firstDigit * 100 + secondDigit * 10 + thirdDigit;
    }

    if (firstDigit == secondDigit && firstDigit > thirdDigit && firstDigit!=0 && secondDigit !=0 && thirdDigit!=0)
    {
        palindrom = thirdDigit * 1000 + firstDigit * 100 + firstDigit * 10 + thirdDigit;
    }
 
    if (firstDigit == secondDigit && firstDigit < thirdDigit && firstDigit != 0 && secondDigit != 0 && thirdDigit != 0)
    {
        palindrom = firstDigit * 1000 + thirdDigit * 100 + thirdDigit * 10 + firstDigit;
    }

    if (secondDigit == thirdDigit && firstDigit < thirdDigit && firstDigit != 0 && secondDigit != 0 && thirdDigit != 0)
    {
        palindrom = firstDigit * 1000 + thirdDigit * 100 + thirdDigit * 10 + firstDigit;
    }

    if (secondDigit == thirdDigit && firstDigit > thirdDigit && firstDigit != 0 && secondDigit != 0 && thirdDigit != 0)
    {
        palindrom = thirdDigit * 1000 + firstDigit * 100 + firstDigit * 10 + thirdDigit;
    }

    if (firstDigit == thirdDigit && firstDigit < secondDigit && firstDigit != 0 && secondDigit != 0 && thirdDigit != 0)
    {
        palindrom = firstDigit * 1000 + secondDigit * 100 + secondDigit * 10 + firstDigit;
    }

    if (firstDigit == thirdDigit && firstDigit > secondDigit && firstDigit != 0 && secondDigit != 0 && thirdDigit != 0)
    {
        palindrom = secondDigit * 1000 + firstDigit * 100 + firstDigit * 10 + secondDigit;
    }

    if (firstDigit == secondDigit && thirdDigit == 0)
    {
        palindrom = firstDigit * 1000 + secondDigit;
    }

    if (firstDigit == thirdDigit && secondDigit == 0)
    {
        palindrom = firstDigit * 1000 + secondDigit;
    }

    if (secondDigit == thirdDigit && firstDigit == 0)
    {
        palindrom = secondDigit * 1000 + secondDigit;
    }


    cout << palindrom;

    return 0;

}

