
class Solution {
public:
    string reverseVowels(string s) {

        unordered_set<char> us = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < right && left < s.size() && 0 == us.count(s[left])) 
                left++;

            while (left < right && 0 <= right && 0 == us.count(s[right])) 
                right--;

            swap(s[left++], s[right--]);
        }

        return s;
    }
};