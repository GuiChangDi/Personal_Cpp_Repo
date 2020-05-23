#include <iostream>
#include <string>
using namespace std;

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.size() ; i++){

        }
    }
};

/*
Dynamic Dynamic Programming
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));// dp[n][n]
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
*/