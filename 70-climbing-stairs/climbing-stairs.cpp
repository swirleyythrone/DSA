class Solution {
public:
    using ll = long long;

    void multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        vector<vector<ll>> res(2, vector<ll>(2));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    res[i][j] += a[i][k] * b[k][j];
        a = res;
    }

    void matrixPower(vector<vector<ll>>& mat, int n) {
        vector<vector<ll>> res = {{1, 0}, {0, 1}}; // identity matrix
        while (n > 0) {
            if (n % 2 == 1)
                multiply(res, mat);
            multiply(mat, mat);
            n /= 2;
        }
        mat = res;
    }

    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        vector<vector<ll>> mat = {{1, 1}, {1, 0}};
        matrixPower(mat, n);
        return mat[0][0];
    }
};
