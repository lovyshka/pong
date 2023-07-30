#include <stdio.h>

int main() {
    int HEIGTH = 80;
    int LENGTH = 25;
    int x = 40, y = 3;  //  вброс мяча х - номер строки,у - позиция в строке 
    int dx = 1;
    int dy = 1;
    char ball = '*';
    int pos_left_rock = 10; //позиция левой и правой ракетки
    int pos_right_rock = 10;
    int cnt1 = 0; //счетчик первого и второго игрока
    int cnt2 = 0;
    while (cnt1 < 21 && cnt2 < 21) { //пока счет меньше 21 у любого
        if (x > 1 && x < 78) { //пока мячик на поле
            x = x + dx; // изменяем позици мячика
            y = y + dy;
            int m1 = 0; //переменная для ввода управляющей клавиши
            m1 = getchar();
            if (m1 == 'a' && pos_left_rock - 1 > 1) { //проверяем что можем двигать ракетки чтобы не вылететь за поле
                pos_left_rock -= 1;  // если ввели букву А
                continue;
            }
            if (m1 == 'z' && pos_left_rock + 1 < 23) {
                pos_left_rock += 1;  // если ввели букву Z
                continue;
            }
            if (m1 == 'k' && pos_right_rock - 1 > 1) {
                pos_right_rock -= 1;  //если ввели букву K
                continue;
            }
            if (m1 == 'm' && pos_right_rock + 1 < 23) {
                pos_right_rock += 1;  //если ввели букву M
                continue;
            }
            for (int i = 0; i < LENGTH; i++) {        // строки
                for (int j = 0; j < HEIGTH; j++) {    // символы в строке
                    if (i == 0 || i == LENGTH - 1) {  // печать верхней границы
                        printf("-"); 
                        continue;
                    }
                    if (i == 1 && j == 40) { //печать счета
                        printf("%d:%d", cnt1, cnt2);
                        continue;
                    }

                    if ((i == 1 && j >= 50 && j <= 53 && cnt1 >= 10 && cnt2 >= 10) ||
                        (i == 1 && j >= 50 && j <= 51 && cnt1 < 10 && cnt2 < 10) ||
                        (i == 1 && j >= 50 && j <= 52 && cnt2 < 10 && cnt1 >= 10) ||
                        (i == 1 && j >= 50 && j <= 52 && cnt2 >= 10 && cnt1 < 10)) {   //дополнение строки
                        continue;
                    }
                    if (((i == pos_left_rock && j == 3) ||
                         (i == pos_left_rock - 1 && j == 3) ||  // обработка отскакивания от ракетки
                         (i == pos_left_rock + 1 && j == 3)) ||
                        (((i == pos_right_rock && j == 76) || (i == pos_right_rock - 1 && j == 76) ||
                          (i == pos_right_rock + 1 && j == 76)))) {
                        if (i == y + dy && j == x + dx) {
                            dx *= -1;
                            dy *= -1;
                            printf("|");
                            printf("\a");
                            continue;
                        } else {
                            printf("|");
                            continue;
                        }
                    }

                    if (y + dy <= 0 || y + dy >= 25) {
                        printf("\a"); //отскок от пола и потолка
                        dy *= -1;
                        continue;
                    }

                    if (i == y && j == x) {  // печать мячика
                        printf("%c", ball);
                        continue;
                    }

                    else {
                        printf(" ");
                        continue;  // во всех остальных случаях печатаем пробел
                    }
                }
                printf("\n");
            }
        } else {
            if (x >= 78) {  //если мяч улетел вправо
                cnt1 += 1;
                x = 40;
                y = 2;
                dx *= -1;
                continue;
            } else if (x <= 2) {  //если мяч улетел вправо
                cnt2 += 1;
                x = 40;
                y = 2;
                dx = 1;
            }
        }
    }
    printf("%d:%d\n", cnt1, cnt2);
    if (cnt1 == 21) {
        printf("Поздравляем первого игрока с победой!\n\a");  // если выиграл левый
    }

    if (cnt2 == 21) {
        printf("Поздравляем второго игрока с победой!\n\a");  // если выиграл правый
    }
    return 0;
}
