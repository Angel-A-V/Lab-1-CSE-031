#include <stdio.h>

int main() {
    int num, sumEven = 0, sumOdd = 0, countEven = 0, countOdd = 0, firstInput = 1;
    float avgEven = 0.0, avgOdd = 0.0;
    int count = 1;

    while (1) {
        printf("Enter the %d%s value: ", count,
            (count % 10 == 1 && count % 100 != 11) ? "st" :
            (count % 10 == 2 && count % 100 != 12) ? "nd" :
            (count % 10 == 3 && count % 100 != 13) ? "rd" : "th");

        scanf("%d", &num);

        if (num == 0) {
            if (firstInput) {
                printf("\nThere is no average to compute.");
            }
            break;
        }
        firstInput = 0;

        // Calculate sum of digits
        int temp = num, digitSum = 0;
        while (temp != 0) {
            digitSum += temp % 10;
            temp /= 10;
        }

        // Check if the sum of digits is even or odd
        if (digitSum % 2 == 0) {
            sumEven += num;
            countEven++;
        } else {
            sumOdd += num;
            countOdd++;
        }

        count++;
    }

    // Calculate averages
    if (countEven > 0) {
        avgEven = (float)sumEven / countEven;
    }

    if (countOdd > 0) {
        avgOdd = (float)sumOdd / countOdd;
    }

    // Print results with two decimal places
    if (!firstInput) { // Only print if there are valid inputs
        printf("\nAverage of input values whose digits sum up to an even number: %.2f\n", avgEven);
        printf("Average of input values whose digits sum up to an odd number:  %.2f\n", avgOdd);
    }

    return 0;
}