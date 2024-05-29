
#define MAX_N 10000

char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int count[26] = {0}; // 统计每个字母出现的次数
    bool inStack[26] = {false}; // 记录字母是否在栈中

    // 统计每个字母出现的次数
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    char *stack = (char *)malloc(sizeof(char) * (len + 1)); // 用于存储结果的栈
    int stackTop = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];
        count[current - 'a']--;

        if (inStack[current - 'a']) {
            continue;
        }

        // 保证字典序，并且当前字符小于栈顶字符时，弹出栈顶字符
        while (stackTop >= 0 && stack[stackTop] > current && count[stack[stackTop] - 'a'] > 0) {
            inStack[stack[stackTop] - 'a'] = false;
            stackTop--;
        }

        // 将当前字符加入栈中
        stack[++stackTop] = current;
        inStack[current - 'a'] = true;
    }

    stack[++stackTop] = '\0'; // 结束符
    return stack;
}
