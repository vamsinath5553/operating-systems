#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

void generateFibonacci(int n) {
    int first = 0, second = 1;
    printf("Fibonacci Series: %d %d ", first, second);

    for (int i = 2; i < n; i++) {
        int next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    pid_t pid;
    int status;


    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        int n;
        printf("Enter the number of terms for Fibonacci series: ");
        scanf("%d", &n);

        generateFibonacci(n);
    } else {
     

        printf("Prime Numbers: ");
        for (int i = 2; i <= 100; i++) {
            if (isPrime(i))
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}

