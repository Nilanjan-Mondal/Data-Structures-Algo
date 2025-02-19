#include<stdio.h>

int main () {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int temp = n;
    int count = 0;
    while (temp) {
        int digit = temp % 10;
        if (digit != 0 && n % digit == 0) {
            count++;
        }
        temp /= 10;
    }
    printf("%d\n", count);
    return 0;
}