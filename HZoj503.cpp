/*************************************************************************
	> File Name: HZoj503.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Sep 2024 07:53:02 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int w, n;
    cin >> w >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i =0, j = n - 1, cnt = 0;
    while (i < j){
        if (arr[i] + arr[j] <= w){
            i++;
            j--;
        }else{
            j--;
        }
        cnt += 1;
    }
    if (i == j) cnt += 1;
    cout << cnt << endl;

    return 0;
}
