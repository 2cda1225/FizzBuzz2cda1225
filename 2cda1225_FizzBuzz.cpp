#include <stdio.h>

int main() {
    int n; // カウントする最大値を保存する変数
    printf("how much to count?");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            printf("Fizz Buzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}