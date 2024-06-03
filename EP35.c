/*************************************************************************
	> File Name: EP35.c
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Jun 2024 07:43:52 PM CST
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define MAX_N 1000000

int is_prime[MAX_N + 5] = {0, 1};
int prime[MAX_N + 5] = {0};
void init_prime(){
    for (int i = 2; i < MAX_N; i++){
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j < MAX_N; j++){
            if (i * prime[j] > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int n){
    int digit = floor(log10(n)) + 1, temp = n;
    for (int i = 0; i < digit; i++){
        temp = temp % 10 * pow(10, digit - 1) + temp / 10;
        if (is_prime[temp]) return 0;
    }
    return 1;
}


int main(){
    init_prime();
    int sum = 0;
    for (int i = 0; i <= prime; i++){
        sum += is_val(prime[i]);
    }
    printf("%d\n", sum);
    
    return 0;
}


