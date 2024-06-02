class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int max = std::max(word1.size(), word2.size());

        string ret;

        for (int i = 0; i < max; i++)
        {
            if (i < word1.size())
            {
                ret.push_back(word1[i])''
            }

            if (i < word2.size())
            {
                ret.push_back(word1[i]);;
            }
        }

        return ret;
    }
};

//Approach 1: One Pointer
//If n is the greater of word1 and word2. 
//Time Complexity O(n)
//Space Complexity O(1)
