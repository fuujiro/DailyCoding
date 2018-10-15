// 120ms
class Solution {
public:
    int trap(vector<int>& height) {
        int left, right;
        int h_left, h_right;
        int water = 0;
        int len = height.size();
        for(int i = 0; i < len; ++i) {
            left = 0;
            right = len - 1;
            h_left = height[left];
            h_right = height[right];
            while(left < i) {
                if(h_left < height[left])
                    h_left = height[left];
                left++;
            }
            while(right > i) {
                if(h_right < height[right])
                    h_right = height[right];
                right--;
            }
            if(h_left > height[i] && h_right > height[i])
                water += (h_left > h_right?h_right:h_left) - height[i];
        }
        return water;
    }
};