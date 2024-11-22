#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

#define MAX_NUMBER 75

int getRandomNumber(std::vector<bool>& selected);
void displayHistory(const std::vector<int>& history);

int main() {
    std::vector<bool> selected(MAX_NUMBER + 1, false);
    std::vector<int> history;                         
    int randomNumber;
    char choice;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    printf("===ビンゴ===\n");
    printf("Enterキーを押してランダムな数字を選びます。\n");
    printf("終了するには 'q' を入力してください。\n\n");

    while (history.size() < MAX_NUMBER) {
        printf("Enterキーを押して次の数字を選ぶ (終了: q): ");
        choice = getchar();

        if (choice == 'q' || choice == 'Q') {
            break;
        }

        randomNumber = getRandomNumber(selected);
        history.push_back(randomNumber);

        printf("選ばれた数字: %d\n", randomNumber);

        displayHistory(history);

        while (getchar() != '\n');
    }

    if (history.size() == MAX_NUMBER) {
        printf("\n全ての数字が選ばれました\n");
    }

    return 0;
}

int getRandomNumber(std::vector<bool>& selected) {
    int num;
    do {
        num = std::rand() % MAX_NUMBER + 1;
    } while (selected[num]);              
    selected[num] = true;                 
    return num;
}

void displayHistory(const std::vector<int>& history) {
    printf("これまでの履歴: ");
    for (int num : history) {
        printf("%d ", num);
    }
    printf("\n\n");
}