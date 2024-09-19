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



class Solution {

	void dfs(int k, int n,  vector<bool> &visit, vector<int>& list)
	{
		if (0 == k)
		{
			if (n == accumulate(list.begin(), list.end(), 0))
			{
				std::sort(list.begin(), list.end());

				auto it = find(ret.begin(), ret.end(), list);

				if(it == ret.end())
					ret.push_back(list);
			}

			return;
		}

		for (int i = 1; i < 10; i++)
		{
			//if(n < accumulate(list.begin(), list.end(), 0) + i)
			//{
			//	break;
			//}

			if (visit[i])
			{
				continue;
			}

			//if (list.end() != find(list.begin(), list.end(), i))
			//{
			//	continue;
			//}


			visit[i] = true;

			list.push_back(i);

			dfs(k - 1, n, visit, list);

			list.pop_back();

			visit[i] = false;
		}
	}

	vector<vector<int>> ret;

	vector<bool> visit;

public:
	vector<vector<int>> combinationSum3(int k, int n) {

		visit.resize(10, false);

		vector<int> list;

		dfs(k, n, visit, list);

		return ret;
	}
};

class Solution {

	void dfs(vector<vector<int>>& ret, vector<int>& list)
	{
		if (list.size() == k)
		{
			if (n == accumulate(list.begin(), list.end(), 0))
			{
				auto list2 = list;

				sort(list2.begin(), list2.end());

				if (ret.end() == find(ret.begin(), ret.end(), list2))
				{
					ret.push_back(list);
				}
			}

			return;
		}

		for (int i = 1; i <= 9; i++)
		{
			if (v.count(i))
				continue;

			v.insert(i);

			list.push_back(i);

			if (n < accumulate(list.begin(), list.end(), 0))
			{
				list.pop_back();
				v.erase(i);
				return;
			}

			dfs(ret, list);

			list.pop_back();

			v.erase(i);
		}

	}

	unordered_set<int> v;

private:
	int k = 0;
	int n = 0;

public:
	vector<vector<int>> combinationSum3(int k, int n) {

		this->k = k;
		this->n = n;

		vector<vector<int>> ret;
		vector<int> list;

		dfs(ret, list);

		return ret;
	}
};

class Solution {

	void dfs(int index, int remain, vector<int>& list, vector<vector<int>>& ret)
	{
		if (list.size() == k && 0 == remain)
		{
			ret.push_back(list);
			return;
		}

		if (remain < 0 || list.size() == k)
			return;


		for (int i = index; i <= 9; i++)
		{
			list.push_back(i);
			dfs(i + 1, remain - i, list, ret);
			list.pop_back();
		}
	}


	int k = 0;


public:
	vector<vector<int>> combinationSum3(int k, int n) {

		this->k = k;

		vector<vector<int>> ret;
		vector<int> list;

		dfs(1, n, list, ret);

		return ret;
	}
};
