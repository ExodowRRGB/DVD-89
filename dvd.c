#define USE_TI89
#include <tigcclib.h>

#define SPRITE_HEIGHT 8
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

void delayer(int time);

void _main(void) {
    void *kbq = kbd_queue();
    unsigned short key = 0;
    int x1 = 20, y1 = 20, direction1 = RIGHT, direction2 = DOWN;
    unsigned long int DVD[] = {0xFFFFFFFF, 0x80000001, 0x83881701, 0x82C81581, 0x826424C1, 0x82242441, 0x826244C1, 0x82C24581, 0x83010601, 0x80000001, 0xFFFFFFFF};
    ClrScr();
    Sprite32(x1, y1, 11, DVD, LCD_MEM, SPRT_XOR);

    while (key != 264) {
        OSdequeue(&key, kbq);
        delayer(4);
        Sprite32(x1, y1, 11, DVD, LCD_MEM, SPRT_XOR);

        if (direction1 == LEFT) {
            x1 -= 5;
            if (x1 < 0) {
                x1 += 5;
                direction1 = RIGHT;
            }
        } else {
            x1 += 5;
            if (x1 > (128)) {
                x1 -= 5;
                direction1 = LEFT;
            }
        }

        if (direction2 == UP) {
            y1 -= 5;
            if (y1 < 2) {
                y1 += 5;
                direction2 = DOWN;
            }
        } else {
            y1 += 5;
            if (y1 > 89) {
                y1 -= 5;
                direction2 = UP;
            }
        }

        Sprite32(x1, y1, 11, DVD, LCD_MEM, SPRT_XOR);
    }
}

void delayer(int time) {
    OSFreeTimer(USER_TIMER);
    OSRegisterTimer(USER_TIMER, time);
    while (!OSTimerExpired(USER_TIMER));
}
