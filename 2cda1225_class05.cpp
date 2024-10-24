#include <stdio.h>

void calculate_change(int n, int x) {
    int change = n - x; 
    int coins[] = {500, 100, 50, 10};
    int count, i;

    printf("支払額: %d円, 商品価格: %d円, おつり: %d円\n", n, x, change);

    for (i = 0; i < 4; i++) {
        if (change >= coins[i]) {
            count = change / coins[i];
            change = change % coins[i];
            printf("%d円: %d枚\n", coins[i], count);
        }
    }

    if (change > 0) {
        printf("残りのおつり: %d円（対応できる硬貨がありません）\n", change);
    }
}

int main() {
    int n, x;


    printf("支払額を入力してください: ");
    scanf("%d", &n);
    printf("商品価格を入力してください: ");
    scanf("%d", &x);

    if (n < x) {
        printf("支払額が商品価格より少ないため、取引が成立しません。\n");
    } else {
        calculate_change(n, x);
    }

    return 0;
}
