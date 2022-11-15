#include <stdio.h>
#include "NumClass.h"

int main() {
    int start_num, end_num;
    int num;
    int res;

    res = 1;
    res = scanf("%d%d",&start_num, &end_num);
    if(res == 0 || res == 26){
        printf("input is invalid");
        return 0;
    }


    // Print all armstong numbers in the given range
    printf("The Armstrong numbers are:");
    for (num = start_num; num <= end_num; num++)
    {
        if(isArmstrong(num)){
            printf(" %d", num);
        }
    }
    printf("\n");

    // Print all palindrome numbers in the given range
    printf("The Palindromes are:");
    for (num = start_num; num <= end_num; num++)
    {
        if(isPalindrome(num)){
            printf(" %d", num);
        }
    }
    printf("\n");

    // Print all prime numbers in the given range
    printf("The Prime numbers are:");
    for (num = start_num; num <= end_num; num++)
    {
        if(isPrime(num)){
            printf(" %d", num);
        }
    }
    printf("\n");

    // Print all strong numbers in the given range
    printf("The Strong numbers are:");
    for (num = start_num; num <= end_num; num++)
    {
        if(isStrong(num)){
            printf(" %d", num);
        }
    }
    printf("\n");

    // Terminator
    return 0;
}