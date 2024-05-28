/*************************************************************************
	> File Name: S1q1475.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 09:20:47 PM CST
 ************************************************************************/

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * pricesSize);
    for (int i = 0; i < pricesSize; ++i) {
        int discount = 0;
        for (int j = i + 1; j < pricesSize; ++j) {
            if(prices[j] <= prices[i]){
                discount = prices[j];
                break;
            }
        }
        ans[i] = prices[i] - discount;
    }
    *returnSize = pricesSize;
    return ans;
}
