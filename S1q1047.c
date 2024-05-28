/*************************************************************************
	> File Name: S1q1047.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 09:00:06 PM CST
 ************************************************************************/
char* removeDuplicates(char* s) {
    int n = strlen(s);
    char* stk = malloc(sizeof(char) * (n + 1));
    int retSize = 0;
    for (int i = 0; i < n; i++) {
        if (retSize > 0 && stk[retSize - 1] == s[i]) {
            retSize--;
        } else {
            stk[retSize++] = s[i];
        }
    }
    stk[retSize] = '\0';
    return stk;
}

