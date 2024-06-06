class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

		int m = 0;

		for (int i = 0; i < candies.size(); i++)
			m = max(m, candies[i]);

		vector<bool> ret;

		for (int i = 0; i < candies.size(); i++)
			ret.push_back(m <= candies[i] + extraCandies);

		return ret;
	}
};


class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

		int m = *std::max_element(candies.begin(), candies.end());

		vector<bool> ret(candies.size());

		for (int i = 0; i < candies.size(); i++)
			ret[i] = (m <= candies[i] + extraCandies);

		return ret;
	}
};
