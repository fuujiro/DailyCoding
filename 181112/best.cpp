class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=1, dup=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                dup++;
                if(dup<=2) {nums[res]=nums[i]; res++;}
            }else{ // nums[i]!=nums[i-1]
                dup=1; nums[res]=nums[i]; res++;
            }
        }
        return res;
    }
};