class Solution {
public:
    int longestValidParentheses(string s) {
     stack<int> paranStack;
        int maxLength=0;
        int lastValidIndx=0;
        for (int indx=0; indx<s.length(); indx++) {
            if (s[indx]=='(') //遇到左括号，直接存入。
                paranStack.push(indx);
            else { //遇到右括号，分情况讨论
                if (paranStack.empty()) //如果此时栈里左括号已经被消耗完了，没有额外的左括号用来配对当前的右括号了，那么当前的右括号就被单出来了，表明当前子串可以结束了，此时的右括号也成为了下一个group的分界点，此时右括号下标为index，所以下一个group的起始点为index+1,相当于skip掉当前的右括号。
                    lastValidIndx=indx+1;
                else { //如果此时栈不空，可能有两种情况，1）栈正好剩下1个左括号和当前右括号配对 2)栈剩下不止1个左括号，
                    paranStack.pop();
                    if (paranStack.empty())  //栈pop()之前正好剩下1个左括号，pop()之后，栈空了，此时group长度为indx-lastValidIndx
                        maxLength=max(maxLength, indx-lastValidIndx+1);
                    else  //栈有pop()之前剩下不止1个左括号，此时额外多出的左括号使得新的group形成。如()(()())中index=4时，stack中有2个左括号
                        maxLength=max(maxLength, indx-paranStack.top());
                }
            }
        }
        return maxLength;
    }
};
