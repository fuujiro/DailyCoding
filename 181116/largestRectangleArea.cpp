class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0) return 0; 
        stack<int> st;
        int MAX = 0;
        height.push_back(0);
        int leftarea = 0, rightarea = 0;
        for(int i = 0; i < height.size(); ++i){
            while(!st.empty() && height[st.top()] > height[i]){
                int tmp = st.top();
                st.pop();
                leftarea = (st.empty() ? tmp + 1 : tmp - st.top()) * height[tmp]; //以tmp为高度，tmp所在柱以及向左延伸出来的矩形面积
                rightarea = (i - tmp - 1) * height[tmp]; //以tmp为高度，向右边延伸出来的矩形面积
                if((leftarea + rightarea) > MAX) MAX = (leftarea + rightarea);
            }
            st.push(i);
        }
        return MAX;
    }
};