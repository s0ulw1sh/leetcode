

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



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void hash(int *k1, int *k2, int *num, int size)
{
    unsigned char *p = (unsigned char*) num;
    int i;
    
    *k1 = 0;
    *k2 = 0;
    
    for (i = 0; i < sizeof(int)-1; ++i) {
        *k1 = ((size+1) * (*k1) + *(p+i)) % size;
        *k2 = ((size-1) * (*k2) + *(p+i)) % size;
    }
    
    *k1 = ((*k1) * 2 + 1) % size;
    *k2 = ((*k2) * 2 + 1) % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, diff, z, k1, k2;
    int *map = calloc(numsSize, sizeof(int));
    
    *returnSize = 2;
    
    for (i = 0; i < numsSize; i++) {
        hash(&k1, &k2, nums + i, numsSize);
        
        for(z = numsSize/2-1; map[k1] != NULL && z != 0; z--)
            k1 = (k1 + k2) % numsSize;
        
        map[k1] = i+1;
    }
   
    for (i = 0; i < numsSize; i++) {
        diff = target - nums[i];
     
        hash(&k1, &k2, &diff, numsSize);
        
        if (map[k1] == 0 || (map[k1]-1) == i)
            continue;
       
        for(z = numsSize/2; map[k1] != 0 && z != 0; z--) {
            if (*(nums + (map[k1]-1)) == diff) {
                map[1] = (map[k1]-1);
                map[0] = i;
                
                return map;
            }
            
            k1 = (k1 + k2) % numsSize;
        }
    }
    
    map[0] = -1;
    map[1] = -1;

    return map;
}
