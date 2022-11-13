#include "NumClass.h"

// Implemetnation of 'isPalindrom' function declaration from NumClass.h using recursions
int isPalindrome(int num)
{
    int n_digit;
    int first_digit;
    int sub_num;
    if (num < 0)
    {
        return 0;
    }
     if (num < 10)
    {
        return 1;
    }

    n_digit = ((1 / num) * 10) % 10;
    sub_num = 1/ ((1 / num) - ((1 / num) * 10) % 10);
    sub_num = sub_num/10;
    first_digit = num % 10;

    return (n_digit == first_digit) && isPalindrome(sub_num);
}

// find armstrong declaration
int findArmstrong(int, int);

// Implemetnation of 'isArmstrong' function declaration from NumClass.h using recursions
int isArmstrong(int num)
{
    return findArmstrong(num, num);
}

// This function support isArmstrong to implement recursion algorithm to determine if the number is amstrong
int findArmstrong(int num, int ex_res)
{
    if (num < 0)
    {
        return 0;
    }
    if (num < 10)
    {
        return (num * num * num == ex_res);
    }

    ex_res = num - ((num % 10) * (num % 10) * (num % 10));
    return findArmstrong(num / 10, ex_res);
}
