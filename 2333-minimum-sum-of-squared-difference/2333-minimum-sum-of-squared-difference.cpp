class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        
        vector<int> diffs(n);
        int max_diff = 0;
        long long total_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diffs[i]);
            total_diff += diffs[i];
        }
        
        // If total modifications allowed can reduce all differences to 0
        if (total_diff <= k) {
            return 0;
        }
        
        // Frequency array to keep track of differences of each size
        vector<long long> diff_count(max_diff + 1, 0);
        for (int d : diffs) {
            diff_count[d]++;
        }
        
        // Greedily reduce largest differences down to smaller ones
        for (int d = max_diff; d > 0; --d) {
            if (diff_count[d] == 0) continue;
            
            long long cnt = diff_count[d];
            if (k >= cnt) {
                k -= cnt;
                diff_count[d - 1] += cnt;
                diff_count[d] = 0;
            } else {
                diff_count[d] -= k;
                diff_count[d - 1] += k;
                k = 0;
                break;
            }
        }
        
        // Calculate the final sum of squared differences
        long long ans = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (diff_count[d] > 0) {
                ans += d * d * diff_count[d];
            }
        }
        
        return ans;
    }
};