/*************************************************************************
	> File Name: S2q71.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 May 2024 03:29:50 PM CST
 ************************************************************************/

char* simplifyPath(char* path) {
    // 动态分配栈的内存
    char** stack = (char**)malloc(strlen(path) * sizeof(char*));
    int top = -1; // 栈指针

    // 创建一个副本，以便不修改原始路径
    char* pathCopy = strdup(path);
    char* token = strtok(pathCopy, "/");

    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top >= 0) {
                top--; // 弹出栈顶元素
            }
        } else if (strcmp(token, ".") != 0 && strcmp(token, "") != 0) {
            stack[++top] = token; // 将目录名压入栈
        }
        token = strtok(NULL, "/");
    }

    // 构建简化后的路径
    char* result = (char*)malloc(strlen(path) + 1);
    result[0] = '\0'; // 初始化为空字符串

    for (int i = 0; i <= top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    if (strlen(result) == 0) {
        strcpy(result, "/");
    }

    free(pathCopy); // 释放副本的内存
    free(stack); // 释放栈的内存

    return result;
}
