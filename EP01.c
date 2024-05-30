/*************************************************************************
	> File Name: EP01.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 May 2024 09:08:02 PM CST
 ************************************************************************/

#include <stdio.h>

int is_val(int x) {
    if (x % 3 == 0 || x % 5 == 0) return 1;
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}


int main() {
    int sum3 = (3 + 999) * 333 / 2;
    int sum5 = (5 + 995) * 199 / 2;
    int sum15 = (15 + (1000 / 15) * 15) * (1000/ 15) / 2;
    printf("%d\n", sum3 + sum5 - sum15);
    return 0;
}
