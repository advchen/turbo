/*************************************************************************
	> File Name: S1q496.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 May 2024 09:19:59 PM CST
 ************************************************************************/

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int stackdat[nums2Size];
    int stacktop = 0;
    int hashset[100001] = {0};
    for (int i = 0; i < nums1Size; i++){
        hashset[nums1[i]] = i + 1;
    }
    *returnSize = nums1Size;
    int *returnnums = (int *)malloc(sizeof(int) * nums1Size);
    for (int i = 0; i < nums2Size; i++){
        while (stacktop && (nums2[i] > stackdat[stacktop - 1])){
            int hashindex = hashset[stackdat[stacktop - 1]];
            if (hashindex != 0){
                returnnums[hashindex - 1] = nums2[i];
            }
            stacktop--;
        }
        stackdat[stacktop++] = nums2[i];
    }
    while (stacktop){
        int hashindex = hashset[stackdat[stacktop -  1]];
        if (hashindex != 0){
            returnnums[hashindex - 1] = -1;
        }
        stacktop--;
    }
    return returnnums;
}
