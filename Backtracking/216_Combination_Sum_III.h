class Solution {

	void dfs(int index, int k, vector<int>& list, int n)
	{
		if (list.size() == k)
		{
			if (accumulate(list.begin(), list.end(), 0) == n)
			{
				sort(list.begin(), list.end());

				auto it = std::find(ret.begin(), ret.end(), list);

				if (ret.end() == it)
				{
					ret.push_back(list);
				}
			}
			return;
		}

		for (int i = index; i <= 9; i++)
		{
			int sum = accumulate(list.begin(), list.end(), 0);

			if (n < sum)
				break;

			list.push_back(i);

			dfs(i + 1, k, list, n);

			list.pop_back();
		}
	}

	vector<vector<int>> ret;

public:
	vector<vector<int>> combinationSum3(int k, int n) {

		vector<int> l;

		dfs(1, k, l, n);

		return ret;
	}
};

