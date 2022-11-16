#include "NumClass.h"
#include <stdio.h>

// pal function declaration
int pal(int, int);

// find armstrong declaration
int calcArmstrong(int, int);

// numOfDigits function declareation
int numOfDigits(int);

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
    int n_digits = numOfDigits(num);
    if (num < 0){
        return 0;
    }
    return (calcArmstrong(num, n_digits) == num);
}

// This function support isArmstrong to implement recursion algorithm to determine if the number is amstrong
int calcArmstrong(int num, int power)
{
    if (num < 10 && power > 0){
        power--;
        return num * calcArmstrong(num, power);
    }
    else if (power > 0){
        return calcArmstrong (num / 10, power) + calcArmstrong (num % 10, power);
    }
    return 1;
}

// This function find recursively the number of digits on base 10
int numOfDigits(int num){
    if (num < 10){
        return 1;
    }
    return (numOfDigits(num / 10) + 1);
}