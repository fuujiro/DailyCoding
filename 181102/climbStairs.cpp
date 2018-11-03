class Solution {
public:
    int climbStairs(int n) {
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int total,OneStepBefore,TwoStepsBefore;
        int i;
        OneStepBefore=2;
        TwoStepsBefore=1;
        total=OneStepBefore+TwoStepsBefore;
        for(i=0;i<n-3;i++){
            TwoStepsBefore=OneStepBefore;
            OneStepBefore=total;
            total=OneStepBefore+TwoStepsBefore;
        }
        return total;
    }
};
