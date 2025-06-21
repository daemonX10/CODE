class Solution {
public:
    long long calcSwaps(vector<int>& nums, int startParity) {
        int n = nums.size();
        vector<int> temp = nums;
        long long swaps = 0;
        
        for (int i = 0; i < n; i++) {
            int expectedParity = (startParity + i) % 2;
            if (temp[i] % 2 != expectedParity) {
                // Find nearest element with correct parity to the right
                int j = i + 1;
                while (j < n && temp[j] % 2 != expectedParity) {
                    j++;
                }
                if (j == n) return LLONG_MAX; // Should not happen if input is valid
                
                // Bubble sort to bring correct element to position i
                while (j > i) {
                    swap(temp[j], temp[j-1]);
                    swaps++;
                    j--;
                }
            }
        }
        return swaps;
    }
    
    int minSwaps(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int x : nums) {
            if (x % 2) odd++;
            else even++;
        }
        
        if (abs(odd - even) > 1) return -1;
        
        long long res = LLONG_MAX;
        if (even >= odd) res = min(res, calcSwaps(nums, 0));
        if (odd >= even) res = min(res, calcSwaps(nums, 1));
        
        return res == LLONG_MAX ? -1 : res;
    }
};
