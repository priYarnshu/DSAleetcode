// Problem: Jump Game
// Link: https://leetcode.com/problems/jump-game/
// Date: 2024-12-22
// Difficulty: Medium

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int max_reach = 0;
        for(int i=0;i<n;i++){
            if(i>max_reach){
                return false;
            }
            max_reach = max(max_reach, i + nums[i]);
            if(max_reach >= n - 1){
                return true;
            }
        }
        return false;
    }
};
