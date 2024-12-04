#include <stdio.h>

void printTime(int hour, int minute) {
    printf("%d:%d\n", hour, minute);
}

int main() {
    int hour = 11;
    int minute = 59;
    printTime(hour, minute);
    return 0;
}