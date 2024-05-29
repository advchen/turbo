/*************************************************************************
	> File Name: S1q1598.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 May 2024 01:55:04 PM CST
 ************************************************************************/

int minOperations(char** logs, int logsSize) {
    int n = 0;
    for (int i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "./") == 0) {
            continue;
        } else if (strcmp(logs[i], "../") == 0) {
            if (n > 0) {
                n--;
            }
        } else {
            n++;
        }
    }
    return n;
}
