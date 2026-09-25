class Solution {
public:

    bool isAlphaNumeric(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9'); 
    }

    bool isPalindrome(string s) {
        // do a two pointers approach
        // one ptr in the end and the other one in the start
        // converge checking if the letters check
        int l = 0, r = s.size() - 1;

        while (l < r) {

            while (!isAlphaNumeric(s[l])) {
                l++;
            }

            while (!isAlphaNumeric(s[r])) {
                r--;
            }

            if (l > r) {
                break;
            }

            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
