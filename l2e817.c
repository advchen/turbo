/*************************************************************************
	> File Name: l2e817.c
	> Author: 
	> Mail: 
	> Created Time: Sat 25 May 2024 09:50:07 PM CST
 ************************************************************************/

int* createHashSet(int* nums, int numsSize, int* setSize) {
    int* hashSet = (int*)malloc(sizeof(int) * 10000); // Assuming values are in the range [0, 9999]
    for (int i = 0; i < 10000; ++i) {
        hashSet[i] = 0;
    }
    for (int i = 0; i < numsSize; ++i) {
        hashSet[nums[i]] = 1;
    }
    *setSize = 10000;
    return hashSet;
}

// Function to return the number of connected components in the linked list
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int setSize;
    int* hashSet = createHashSet(nums, numsSize, &setSize);
    int components = 0;
    int inComponent = 0;

    struct ListNode* curr = head;
    while (curr != NULL) {
        if (hashSet[curr->val]) {
            if (!inComponent) {
                components++;
                inComponent = 1;
            }
        } else {
            inComponent = 0;
        }
        curr = curr->next;
    }

    free(hashSet);
    return components;
}
