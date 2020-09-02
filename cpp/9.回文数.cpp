/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x % 10 == 0 && x != 0) return false;
        int reverseNum = 0;
        while(reverseNum < x) {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        return (x == reverseNum) || (x == reverseNum / 10);
    }
};
// @lc code=end

