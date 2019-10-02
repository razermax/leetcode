

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
	int j = 0;
	int sub = 0;
	int *returnValue = NULL;

	if(nums == NULL){
		return NULL;
	}

	returnValue = (int *)malloc(sizeof(int)*2);
	if(returnValue == NULL){
		return NULL;
	}

	for(i=0;i<numsSize - 1;i++){
		sub = target - nums[i];
		for(j=i+1;j<numsSize;j++){
			if(nums[j] == sub){
				returnValue[0] = i;
				returnValue[1] = j;
				*returnSize = 2;
				return returnValue;
			}
		}
	}
	return NULL;
}
