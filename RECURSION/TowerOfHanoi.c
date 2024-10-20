#include <stdio.h>

void hanoi(int n, char a, char b, char c) {
    if (n == 0) {
        return;  // Base case: no more disks to move
    }

    // Move n-1 disks from 'a'(source) to 'b'(destination) using 'c' as helper
    hanoi(n-1, a, c, b);

    // Move the nth disk from 'a' to 'c'
    printf("%c -> %c\n", a, c);

    // Move n-1 disks from 'b'(source) to 'c'(destination) using 'a' as helper
    hanoi(n-1, b, a, c);
}

int main() {
    int n = 4;  // Number of disks
    hanoi(n, 'A', 'B', 'C');  // 'A' is source, 'B' is helper, 'C' is destination
    return 0;
}
