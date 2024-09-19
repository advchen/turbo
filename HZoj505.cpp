/*************************************************************************
	> File Name: HZoj505.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Sep 2024 07:15:09 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool cmp(string &a, string &b){
    return a + b > b + a;
}

int main(){
    int n;
    string s;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++){
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i ++){
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
