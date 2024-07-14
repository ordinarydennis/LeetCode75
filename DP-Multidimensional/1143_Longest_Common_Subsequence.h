class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        string source;
        string target;

        if (text1.size() < text2.size())
        {
            source = text2;
            target = text1;
        }
        else 
        {
            source = text1;
            target = text2;
        }


        int index = 0;

        int ret = 0;

        while (index < source.size())
        {
            int max = 0;

            int f = 0;

            for (int s1 = index; s1 < source.size(); s1++)
            {
                for (int s2 = f; s2 < target.size(); s2++)
                {
                    if (source[s1] == target[s2])
                    {
                        f = s2 + 1;
                        max++;
                        break;
                    }
                }

            }

            ret = max(ret, max);

            index++;
        }


        return max;
    }
};


//Brute force
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcsHelper(text1, text2, 0, 0);
    }

private:
    int lcsHelper(const string& text1, const string& text2, int i, int j) {
        // Base case: if we've reached the end of either string
        if (i == text1.length() || j == text2.length()) {
            return 0;
        }

        // If the current characters match, we can include this character in the LCS
        if (text1[i] == text2[j]) {
            return 1 + lcsHelper(text1, text2, i + 1, j + 1);
        }
        else {
            // Otherwise, we consider two possibilities:
            // 1. Skip the current character of text1 and proceed with the next character
            // 2. Skip the current character of text2 and proceed with the next character
            // We take the maximum of these two possibilities
            int option1 = lcsHelper(text1, text2, i + 1, j);
            int option2 = lcsHelper(text1, text2, i, j + 1);
            return max(option1, option2);
        }
    }
};

//dp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // DP table to store lengths of longest common subsequences.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill dp array.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};


//https://leetcode.com/problems/longest-common-subsequence/editorial/?envType=study-plan-v2&envId=leetcode-75
