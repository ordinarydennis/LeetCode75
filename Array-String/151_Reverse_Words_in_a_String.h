class Solution {
public:
    string reverseWords(string s) {

        vector<string> list;

        string temp;

        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size()  || ' ' == s[i])
            {
                if (temp.size())
                {
                    list.emplace_back(std::move(temp));
                }
            }
            else
            {
                temp.push_back(s[i]);
            }
        }

        string ret;

        if (list.size())
        {
            for (auto it = list.rbegin(); it != list.rend(); ++it)
            {
                ret += *it + " ";
            }
        }

        ret.pop_back();

        return ret;
    }
};

//if the input string size is n,
//time complexity O(n)

//If the result string size is m, 
//space complexity O(m)