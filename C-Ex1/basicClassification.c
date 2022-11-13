#include "NumClass.h"

// Implemetnation of 'isPrime' function declaration from NumClass.h
int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    else if (num == 2)
    {
        return 1;
    }
    else if (num % 2 == 0)
    {
        return 0;
    }
    else
    {
        int x;
        int step_size = 2;
        for (x = 3; x < num; x += step_size)
        {
            if (num % x == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

// Implemetnation of 'isStrong' function declaration from NumClass.h
int isStrong(int num)
{
    int temp_num = num;
    int fact;
    int x;
    int res = 0;

    if (temp_num <= 0)
    {
        return 0;
    }

    while (temp_num > 0)
    {
        fact = 1;
        for (x = 2; x <= temp_num % 10; x++)
        {
            fact = fact * x;
        }
        res += fact;
        temp_num = temp_num / 10;
    }
    return (res == num);
}