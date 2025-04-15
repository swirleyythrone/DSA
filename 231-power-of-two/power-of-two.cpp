class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if((n&(n-1))!=0 || n==0)return false;
        return true;
    }
};