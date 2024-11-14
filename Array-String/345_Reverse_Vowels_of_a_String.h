
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


class Solution {

	bool isVowel(char c)
	{
		static unordered_set<char> v = { 'a', 'e','i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

		return v.count(c);
	}

public:
	string reverseVowels(string s) {

		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			while (left < right && false == isVowel(s[left])) left++;
			
			while (left < right  && false == isVowel(s[right])) right--;

			swap(s[left], s[right]);
			right--;
			left++;
		}

		return s;
	}
};
