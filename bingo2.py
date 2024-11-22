import random

# ビンゴカードを生成
def generate_bingo_card():
    card = []
    ranges = [(1, 15), (16, 30), (31, 45), (46, 60), (61, 75)]

    for i, (start, end) in enumerate(ranges):
        column = random.sample(range(start, end + 1), 5)
        card.append(column)

    # 中央をFREEにする
    card[2][2] = "FREE"
    return list(map(list, zip(*card)))

# ビンゴカードを表示する
def print_bingo_card(card):
    print(" B   I   N   G   O")
    for row in card:
        print(" ".join(f"{str(num):^4}" for num in row))

# カードの中から番号をマークする
def mark_number(card, number):
    for row in card:
        for i in range(len(row)):
            if row[i] == number:
                row[i] = "XX"

# ビンゴ判定を行う
def check_bingo(card):
    # 横
    for row in card:
        if all(cell in ("XX", "FREE") for cell in row):
            return True

    # 縦
    for col in range(5):
        if all(row[col] in ("XX", "FREE") for row in card):
            return True

    # 斜め
    if all(card[i][i] in ("XX", "FREE") for i in range(5)):
        return True
    if all(card[i][4 - i] in ("XX", "FREE") for i in range(5)):
        return True

    return False

def main():
    card = generate_bingo_card()
    print("=== ビンゴカード ===")
    print_bingo_card(card)

    while True:
        number = input("\n番号を入力してください (終了: q): ")
        if number.lower() == 'q':
            print("ゲームを終了します。")
            break

        if not number.isdigit():
            print("無効な入力です。数字を入力してください。")
            continue

        number = int(number)
        if not (1 <= number <= 75):
            print("無効な番号です。1から75の範囲で入力してください。")
            continue

        mark_number(card, number)
        print("\n=== 現在のビンゴカード ===")
        print_bingo_card(card)

        if check_bingo(card):
            print("\nビンゴです！おめでとうございます！")
            break

if __name__ == "__main__":
    main()