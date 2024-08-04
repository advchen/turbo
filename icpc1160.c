/*************************************************************************
	> File Name: icpc1160.c
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Aug 2024 05:42:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define max 100005
int n, m;

struct T {
	int val ;
	int l, r;
}t[max] = {0};


void add(int i, int k, int f){       //新增同学 
    if (f == 1)         //右 
    {
        t[k].r = t[i].r;
        t[k].l = i; 
        t[i].r = k;
        t[t[k].r].l = k;
    }
    else             //左
    {
        t[k].r = i;
        t[k].l = t[i].l;
        t[i].l = k;
        t[t[k].l].r = k;
    }
}


int main(){
	int x, k, f;
	scanf("%d", &n);
	t[0].r = 0, t[0].l = 0;
	add(0, 1, 1);
	for (int i = 2; i <= n; i++){
		scanf("%d%d", &x, &f);
		add(x, i, f);
	}
	scanf("%d", &m);
	while (m --){
		scanf("%d", &x);
		t[x].val = 1;
	}
	for (int i = t[0].r; i; i = t[i].r){
		if (t[i].val == 0){
			printf("%d ", i);
		}
	}
	
	return 0;
}
