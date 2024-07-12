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

shmtulqrypy

oxcpqrsvwf