#include "NumClass.h"

// Implemetnation of 'isPalindrom' function declaration from NumClass.h using loops
int isPalindrome(int num)
{
    int res = 0;
    int temp_num = num;
    if (temp_num < 0)
    {
        return 0;
    }

    if (temp_num ==0)
    {
        return 1;
    }

    while (temp_num > 0)
    {
        res *= 10;
        res += temp_num % 10;
        temp_num /= 10;
    }
    
    return (num == res);
}

// Implemetnation of 'isArmstrong' function declaration from NumClass.h using loops
int isArmstrong(int num)
{
    int res = 0;
    int temp_num = num;
    if (temp_num < 0)
    {
        return 0;
    }

    if (temp_num ==0)
    {
        return 1;
    }

    while (temp_num > 0)
    {
        res += (temp_num % 10) * (temp_num % 10) * (temp_num % 10);
        temp_num /= 10;
    }
    return (num == res);
}