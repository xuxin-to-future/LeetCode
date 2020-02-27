int findDuplicate(int* nums, int numsSize){
    int slow = 0;
    int fast = 0;
    while (1) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        } 
    }
    int finder = 0;
    while (1) {
        finder = nums[finder];
        slow = nums[slow];
        if(slow == finder)
            return slow;        
    }
    return 0;
}

