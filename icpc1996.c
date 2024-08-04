/*************************************************************************
	> File Name: icpc1996.c
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Aug 2024 04:31:07 PM CST
 ************************************************************************/
#include <stdio.h>

int n, m, next[101], i, p; 

int main(){
	scanf("%d%d", &n, &m);
	//if (!n && !m) return 0;
	for (i = 0; i < n; i++) next[i] = i + 1; //一个循环链表
	next[n] = 1, p = 0;
	for (i = 1; i <= n; i++){//有多少给人要出去
		for (int j = 1; j < m; j++){
			p = next[p];//走到下一个要出去的人那里
		}
		printf("%d ", next[p]);//输出要出去的人
		next[p] = next[next[p]];//删除链表节点
	}
	return 0;
}
