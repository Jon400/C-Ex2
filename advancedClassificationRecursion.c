#include "NumClass.h"
#include <stdio.h>

// pal function declaration
int pal(int, int);

// find armstrong declaration
int findArmstrong(int, int);

// Implemetnation of 'isPalindrom' function declaration from NumClass.h using recursions
int isPalindrome(int num)
{
    //int n_digit;
    //int first_digit;
    //int sub_num;
    if (num < 0)
    {
        return 0;
    }
    if (num == 0){
        return 1;
    }
    if (num % 10 == 0){
        return 0;
    }
     
    return pal(num, 0);
}

// This function support isPalindrome to implement recursion algorithm to determine if the number is palindrome
int pal (int num1, int num2){
    if (num1 >= num2){
        if (num1 == num2 || num2 * 10 + (num1 % 10) == num1){
            return 1;
        }
        return pal(num1 / 10, num2 * 10 + (num1 % 10));
    }
    return 0;
}

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
