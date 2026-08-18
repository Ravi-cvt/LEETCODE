class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int max_sum = nums[0];
        int cur_max = 0;
        int min_sum = nums[0];
        int cur_min = 0;

        for (int num : nums) {
            cur_max = max(cur_max + num, num);
            max_sum = max(max_sum, cur_max);
            
            cur_min = min(cur_min + num, num);
            min_sum = min(min_sum, cur_min);
            
            total_sum += num;
        }

        return max_sum > 0 ? max(max_sum, total_sum - min_sum) : max_sum;
    }
};