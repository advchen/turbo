/*************************************************************************
	> File Name: HZoj504.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Sep 2024 07:27:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(){
    int k;
    string s;
    cin >> s;
    cin >> k;
    char arr[505];
    for (int i = 0; i < k; i++){
        int j = 0;
        while(s[j + 1] && s[j] <= s[j + 1]) ++j;
        while(s[j]) s[j] = s[j + 1], j += 1;
    }
    for (int i = 0, flag = 1; s[i]; i++){
        if (s[i] == '0' && flag) continue;
        cout << s[i];
        flag = 0;
    }
    cout << endl;


    return 0;
}
