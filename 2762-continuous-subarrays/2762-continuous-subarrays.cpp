class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> max_q;
        deque<int> min_q;

        int left = 0;
        long long ans = 0;

        for(int right = 0 ; right < nums.size() ; right++){
            while(!max_q.empty() && max_q.back() < nums[right]){
                max_q.pop_back();
            }
            max_q.push_back(nums[right]);
            
            // Maintain min deque
            while (!min_q.empty() && min_q.back() > nums[right]) {
                min_q.pop_back();
            }
            min_q.push_back(nums[right]);
            
            // Shrink window if maximum element - minimum element > 2
            while (max_q.front() - min_q.front() > 2) {
                if (max_q.front() == nums[left]) {
                    max_q.pop_front();
                }
                if (min_q.front() == nums[left]) {
                    min_q.pop_front();
                }
                left++;
            }
            
            // Add number of valid continuous subarrays ending at 'right'
            ans += (right - left + 1);
        }

        return ans;
    }
};