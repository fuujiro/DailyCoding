// 4ms 双指针法
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        else{
            int l = 0, r = height.size() - 1;

            int maxl = 0, maxr = 0;        
            int result = 0;

            while(l <= r){
                if(height[l] <= height[r]){
                    if(height[l] > maxl){
                        maxl = height[l];
                    }
                    else{
                        result += (maxl - height[l]);
                    }
                    l++;
                }
                else{
                    if(height[r] > maxr){
                        maxr = height[r];
                    }
                    else{
                        result += (maxr - height[r]);
                    }
                    r--;                
                }
            }

            return result;
        }
    }
};