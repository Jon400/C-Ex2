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
    if (temp_num % 10 == 0){
        return 0;
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
    int temp_res;
    int n_digits = 0;
    int temp_num = num;
    int iter;

    if (temp_num < 0)
    {
        return 0;
    }

    if (temp_num == 0)
    {
        return 1;
    }

    while (temp_num > 0)
    {
        temp_num /= 10;
        n_digits += 1;
    }
    
    temp_num = num;

    while (temp_num > 0)
    {
        temp_res = 1;
        for (iter = 0; iter < n_digits; iter++){
            temp_res *= (temp_num % 10);
        }
        res += temp_res;
        temp_num /= 10;
    }
    return (num == res);
}