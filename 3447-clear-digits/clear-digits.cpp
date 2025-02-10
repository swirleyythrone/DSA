class Solution {
public:
    string clearDigits(string s) {
        while (true) {
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (i > 0) s.erase(i - 1, 2); // Remove the character before and the digit
                else s.erase(i, 1); // If digit is first, remove only itself
                flag = true;
                break; // Restart loop after modification
            }
        }
        if (!flag) break; // Stop when no more digits are found
    }
    return s;
    }
};