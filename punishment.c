#include <stdio.h>

int main() {
    int count, error;

    printf("Enter the repetition count for the punishment phrase: ");
    scanf("%d" , &count);

    while(count <= 0){
        printf("You entered an invalid value for the repetition count! Please re-enter: ");
        scanf("%d", &count);
    }

    printf("\n");
    
    printf("Enter the line where you want to insert the typo: ");
    scanf("%d", &error);

    while(error <= 0 || error > count){
        printf("You entered an invalid value for the typo placement! Please re-enter: ");
        scanf("%d", &error);
    }

    printf("\n");

    for(int i = 1; i <= count; i++){
        if(i == error){
            printf("Cading wiht is C avesone!\n");
        } else {
            printf("Coding with C is awesome!\n");
        }
    }

    return 0;
}