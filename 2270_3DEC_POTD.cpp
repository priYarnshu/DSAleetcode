class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(n, 0);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            temp[i] = sum;
        }

        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            long long a = sum - temp[i];
            if (temp[i] >= a) {
                count++;
            }
        }

        return count;
    }
};
