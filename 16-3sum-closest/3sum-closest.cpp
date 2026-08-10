class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int current_sum = nums[i] + nums[j] + nums[k];
                if (abs(current_sum - target) < abs(ans - target)) {
                    ans = current_sum;
                }
                if (current_sum < target) {
                    ++j;
                } else if (current_sum > target) {
                    --k;
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
};