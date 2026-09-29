class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> v;
    
        for(int i = 0; i < n; i++) {
            v.push_back({score[i], i}); 
        }
        sort(v.rbegin(), v.rend());
        
        vector<string> ans(n);
        
        for(int rank = 0; rank < n; rank++) {
            if(rank == 0) {
                ans[v[rank].second] = "Gold Medal";
            } else if(rank == 1) {
                ans[v[rank].second] = "Silver Medal";
            } else if(rank == 2) {
                ans[v[rank].second] = "Bronze Medal";
            } else {
                ans[v[rank].second] = to_string(rank + 1);
            }
        }
        
        return ans;
    }
};