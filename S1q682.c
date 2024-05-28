/*************************************************************************
	> File Name: S1q682.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 07:59:19 PM CST
 ************************************************************************/

int calPoints(char ** ops, int opsSize){
    int ret = 0;
    int *points = (int *)malloc(sizeof(int) * opsSize);
    int pos = 0;
    for (int i = 0; i < opsSize; i++) {
        switch (ops[i][0]) {
            case '+':
                ret += points[pos - 1] + points[pos - 2];
                points[pos++] = points[pos - 1] + points[pos - 2];
                break;
            case 'D':
                ret += 2 * points[pos - 1];
                points[pos++] = 2 * points[pos - 1];
                break;
            case 'C':
                ret -= points[pos - 1];
                pos--;
                break;
            default:
                ret += atoi(ops[i]);
                points[pos++] = atoi(ops[i]);
                break;
        }
    }
    free(points);
    return ret;
}

