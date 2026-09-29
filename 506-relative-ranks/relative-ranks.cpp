class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        
        int rank = 1;
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            int original_index = current.second;
            if (rank == 1) {
                ans[original_index] = "Gold Medal";
            } else if (rank == 2) {
                ans[original_index] = "Silver Medal";
            } else if (rank == 3) {
                ans[original_index] = "Bronze Medal";
            } else {
                ans[original_index] = to_string(rank);
            }
            
            rank++;
        }
        
        return ans;
    }
};