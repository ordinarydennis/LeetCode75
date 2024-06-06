class Solution {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

		std::unordered_set<int> s1;
		std::unordered_set<int> s2;

		for (int i = 0; i < nums1.size(); i++)
			s1.insert(nums1[i]);

		for (int i = 0; i < nums2.size(); i++)
			s2.insert(nums2[i]);


		vector<vector<int>> ret(2);

		for (int n : s1)
		{
			if (0 == s2.count(n))
				ret[0].push_back(n);
		}

		for (int n : s2)
		{
			if (0 == s1.count(n))
				ret[1].push_back(n);
		}

		return ret;
	}
};