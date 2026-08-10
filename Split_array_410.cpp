class Solution {
public:
    bool possible(vector<int>& nums, int mid, int m) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (total + nums[i] > mid) {
                m--;
                total = nums[i];
                if (m == 0) break; 
            } else {
                total += nums[i];
            }
        }
        return m > 0;
    }

    int splitArray(vector<int>& nums, int m) {
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int low = *max_element(nums.begin(), nums.end());
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, mid, m)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
