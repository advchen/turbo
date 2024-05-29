/*************************************************************************
	> File Name: S1q1544.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 May 2024 01:34:36 PM CST
 ************************************************************************/

char* makeGood(char* s) {
    char *arr = (char *)malloc(sizeof(int) * 100);
    int n = strlen(s);
    int j = 0;
    for (int i = 0; i < n; i++){
         if (j > 0 && abs(arr[j - 1] - s[i]) == 'a' - 'A') {
            j--;
        } 
        else{
            arr[j++] = s[i];
        }
    }
    arr[j] = '\0';
    return arr;
}
