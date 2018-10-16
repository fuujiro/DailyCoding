class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> sol;
        permuteHelp(sol, nums, index, nums.size());
        return sol;
    }
    
    void permuteHelp(vector<vector<int>> &sol, vector<int>& nums, int index, int size){
        if(index == size){
            sol.emplace_back(nums);
            return;
        }
        
        for(int i = index; i < size; i++){
            swap(nums[i], nums[index]);
            permuteHelp(sol, nums, index + 1, size);
            swap(nums[i], nums[index]);
        }
    }
};