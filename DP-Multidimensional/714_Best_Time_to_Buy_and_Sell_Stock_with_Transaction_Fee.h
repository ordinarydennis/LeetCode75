class Solution {

	int dfs(int index, vector<int>& prices, int fee, bool isBuy, int sum)
	{
		if (prices.size() <= index)
		{
			return sum;
		}

		int max = INT_MIN;

		for (int i = index; i < prices.size(); i++)
		{
			int sum2 = sum;

			if (isBuy)
			{
				sum2 = sum2 - prices[index];
			}
			else
			{
				sum2 += sum2 + prices[index] - fee;
			}

			max = std::max(max,
				dfs(i + 1, prices, fee, !isBuy, sum2)
			);
		}

		return max;
	}

public:
	int maxProfit(vector<int>& prices, int fee) {
		
		return dfs(0, prices, fee, true, 0);

	}
};