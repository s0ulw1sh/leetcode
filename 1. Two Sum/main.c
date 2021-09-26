

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*

Description:

  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
  
Examples:
  
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Output: Because nums[0] + nums[1] == 9, we return [0, 1].

  Input: nums = [3,2,4], target = 6
  Output: [1,2]
  
  Input: nums = [3,3], target = 6
  Output: [0,1]
  
Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/

struct node {
    int *data;
    int idx;
};

int hash(int *num, int size, int key)
{
    unsigned char *p = (unsigned char*) num;
    int i, res = 0;

    for (i = 0; i < sizeof(int); ++i)
        res = (key * res + *(p+i)) % size;
    
    return (res * 2 + 1) % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, diff, z, k1, k2,
        *res = (int*) malloc(sizeof(int)*2);
    struct node *map = (struct node*) malloc(sizeof(struct node)*numsSize);
    
    *returnSize = 2;
    
    memset(map, 0, sizeof(struct node)*numsSize);
    
    for (i = 0; i < numsSize; i++) {
        k1 = hash(nums + i, numsSize, numsSize + 1);
        k2 = hash(nums + i, numsSize, numsSize - 1);
        z = 0;
        
        while(map[k1].data != NULL && z < numsSize/2-1) {
            k1 = (k1 + k2) % numsSize;
            z++;
        }
        
        map[k1].data = nums + i;
        map[k1].idx  = i;
    }
   
    for (i = 0; i < numsSize; i++) {
        diff = target - nums[i];
        
        k1 = hash(&diff, numsSize, numsSize + 1);
        k2 = hash(&diff, numsSize, numsSize - 1);
        z  = 0;
        
        if (map[k1].data == NULL || map[k1].data == nums + i)
            continue;

        while(z < numsSize/2) {
            
            if (*(map[k1].data) == diff) {
                res[0] = i;
                res[1] = map[k1].idx;
                
                return res;
            }
            
            k1 = (k1 + k2) % numsSize;
            if (map[k1].data == NULL) break;
            z++;
        }
    }
    
    return res;
}
