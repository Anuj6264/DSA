
// For Problems involving atleast k (>=):
// Example: Count Subarrays Where Max Element Appears at Least K Times (LC 2962)

include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int maxEl = 0, i = 0, j = 0, cnt = 0;
        for(auto it: nums)
            maxEl = max(maxEl, it);
        while(j < nums.size()) {
            if(nums[j] == maxEl)
                cnt++;
            while(cnt >= k) {
                if(nums[i++] == maxEl)
                    cnt--;
                res += nums.size() - j; // To count all subarrays starting from i and goes through all the way to end of array
                                        // as if i..j is a valid subarray, then i..j+1, i..j+2, ...i..n-1 are also valid subarrays
            }
            j++;
        }
        return res;
    }
};


//For Problems involving atmost k (<=):
// Example: Count Subarrays Where Max Element Appears At Most K Times (LC 2962)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        int maxEl = 0, i = 0, j = 0, cnt = 0;
        for(auto it: nums)
            maxEl = max(maxEl, it);
        while(j < nums.size()) {
            if(nums[j] == maxEl)
                cnt++;
            while(cnt > k) {
                if(nums[i++] == maxEl)
                    cnt--;
            }
            res += j - i + 1; // To count all subarrays ending at j, includes all elements between i and j only
            j++;
        }
        return res;
    }
};

// For Problems involving exactly k (==):
// Ans = Atmost k - Atmost k - 1 OR Aleast k + 1 - Atleast k
