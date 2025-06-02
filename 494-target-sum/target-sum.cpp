#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int findWays(vector<int>& arr, int k, int n) {
        unordered_map<int, int> prev;
        if (arr[0] == 0) {
            prev[0] = 2; // pick or not pick zero
        } else {
            prev[0] = 1;
            if (arr[0] <= k) prev[arr[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            unordered_map<int, int> curr;
            for (auto& [sum, count] : prev) {
                curr[sum] = (curr[sum] + count) % MOD;
                int new_sum = sum + arr[i];
                if (new_sum <= k)
                    curr[new_sum] = (curr[new_sum] + count) % MOD;
            }
            prev = move(curr);
        }

        return prev[k];
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        long long totsum = accumulate(arr.begin(), arr.end(), 0LL);
        if ((totsum + d) % 2 != 0 || totsum < d) return 0;
        int target = (totsum + d) / 2;
        return findWays(arr, target, n);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};
