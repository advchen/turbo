/*************************************************************************
	> File Name: icpc2010.c
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Aug 2024 09:40:17 AM CST
 ************************************************************************/

#include <stdio.h>

int a[1005], b[1005];

int main(){
	int n, m, x, ans;
	scanf("%d%d", &m, &n);
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &x);
		if (a[x] == 0){
			ans++;
			r++;
			b[r] = x;
			a[x] = 1;
			if (r > m){
				l++;
				a[b[l]] = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
