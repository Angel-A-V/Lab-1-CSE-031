#include <stdio.h>

//Function for the suffix changes
const char* thesuffix(int count){
    if(count % 10 == 1 && count % 100 != 11){
        return "st";
    } else if(count % 10 == 2){
        return "nd";
    } else if(count % 10 == 3){
        return "rd";
    } else {
        return "th";
    }
}

int main(){

    int count = 1, evencount = 0, oddcount = 0, num, firstnum = 1, sumEven = 0.0, sumOdd = 0.0;
    float avgeven = 0.0, avgodd = 0.0;
    
    while(1){

        printf("Enter the %d%s value: ", count, thesuffix(count));
        scanf("%d", &num);

        //if num equal zero end the program test case senario
        if(num == 0){
            if(firstnum){
                printf("\nThere is no average to compute.");
            }
            break;
        }
        firstnum = 0;

        // Calculate sum of digits
        int temp = num, digitSum = 0;
        while (temp != 0) {
            digitSum += temp % 10;
            temp /= 10;
        }

        // Check if the sum of digits is even or odd
        if (digitSum % 2 == 0) {
            sumEven += num;
            evencount++;
        } else {
            sumOdd += num;
            oddcount++;
        }
        count++;
    }

    if (evencount > 0) {
        avgeven = (float)sumEven / evencount;
    }

    if (oddcount > 0) {
        avgodd = (float)sumOdd / oddcount;
    }

    printf("\n");

    if (!firstnum && evencount > 0) { // Only print if there are valid inputs
        printf("Average of input values whose digits sum up to an even number: %.2f\n", avgeven);
    }

    if (!firstnum && oddcount > 0) { // Only print if there are valid inputs
        printf("Average of input values whose digits sum up to an odd number:  %.2f\n", avgodd);
    }

    return 0;
}