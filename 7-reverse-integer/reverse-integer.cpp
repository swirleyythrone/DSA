class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while(x!=0){
            rev = rev*10 + x%10;
            x/=10;
        }
        return (rev<INT_MIN || rev>INT_MAX) ? 0 : (int)rev;
    }
};