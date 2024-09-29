class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {

		auto compare = [](pair<int, int>& a, pair<int, int>& b) {

			if (a.first != b.first)
				return a.first > b.first;

			return a.second > b.second;
		};

		priority_queue<
			pair<int, int>, vector<pair<int, int>>, decltype(compare)
		> q;


		for (int i = 0; i < costs.size(); i++)
		{
			q.push({ costs[i], i });
		}

		//for (int i = 0; i < costs.size(); i++)
		//{
		//	cout << q.top().first <<" " << q.top().second << endl;
		//	q.pop();
		//}

		long long ret = 0;

		for (int i = 0; i < k; i++)
		{
			ret += q.top().first;
			q.pop();
		}

		return ret;

	}
};



//time limit
class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {

		long long ret = 0;

		while (k)
		{
			pair<int, int> p1;
			pair<int, int> p2;

			int min = INT_MAX;

			for (int i = 0; i < candidates && i < costs.size(); i++)
			{
				if(costs[i] < min)
				{
					p1.first = i;
					p1.second = costs[i];
					min = p1.second;
				}
			}

			min = INT_MAX;

			int m = (0 < costs.size() - candidates) ? costs.size() - candidates : 0;


			for (int i = costs.size() - 1; 0 <= i && m <= i; i--)
			{
				if (costs[i] < min)
				{
					p2.first = i;
					p2.second = costs[i];
					min = p2.second;
				}
			}

			if (p1.second <= p2.second)
			{
				costs.erase(costs.begin() + p1.first);
				ret += p1.second;
			}
			else
			{
				costs.erase(costs.begin() + p2.first);
				ret += p2.second;
			}

			k--;
		}

		return ret;
	}
};



class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        // Min-heap priority queues to keep track of costs.
        std::priority_queue<int, std::vector<int>, std::greater<int>> headWorkers;
        std::priority_queue<int, std::vector<int>, std::greater<int>> tailWorkers;

        // Edge case: when the number of workers is smaller than 2 * candidates.
        int n = costs.size();
        if (n <= 2 * candidates) {
            std::priority_queue<int, std::vector<int>, std::greater<int>> combined;
            for (int i = 0; i < n; ++i) {
                combined.push(costs[i]);
            }
            long long totalCost = 0;
            for (int i = 0; i < k; ++i) {
                totalCost += combined.top();
                combined.pop();
            }
            return totalCost;
        }

        // Initialize headWorkers and tailWorkers with the first and last `candidates` workers.
        for (int i = 0; i < candidates; ++i) {
            headWorkers.push(costs[i]);
        }
        for (int i = n - candidates; i < n; ++i) {
            tailWorkers.push(costs[i]);
        }

        long long answer = 0;
        int nextHead = candidates;
        int nextTail = n - candidates - 1;

        for (int i = 0; i < k; ++i) {
            // Choose the smaller cost worker from head or tail.
            if (!headWorkers.empty() && !tailWorkers.empty())
            {
                if (headWorkers.top() <= tailWorkers.top())
                {
                    answer += headWorkers.top();
                    headWorkers.pop();

                    // Add a new worker from the head if available.
                    if (nextHead < n && nextHead <= nextTail)
                    {
                        headWorkers.push(costs[nextHead]);
                        ++nextHead;
                    }
                }
                else {
                    answer += tailWorkers.top();
                    tailWorkers.pop();

                    // Add a new worker from the tail if available.
                    if (nextTail >= 0 && nextTail >= nextHead) {
                        tailWorkers.push(costs[nextTail]);
                        --nextTail;
                    }
                }
            }
            else if (!headWorkers.empty()) {
                // If only headWorkers has elements.
                answer += headWorkers.top();
                headWorkers.pop();

                if (nextHead < n && nextHead <= nextTail) {
                    headWorkers.push(costs[nextHead]);
                    ++nextHead;
                }
            }
            else if (!tailWorkers.empty()) {
                // If only tailWorkers has elements.
                answer += tailWorkers.top();
                tailWorkers.pop();

                if (nextTail >= 0 && nextTail >= nextHead) {
                    tailWorkers.push(costs[nextTail]);
                    --nextTail;
                }
            }
        }

        return answer;
    }
};

class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        // Min-heap priority queues to keep track of costs.
        std::priority_queue<int, std::vector<int>, std::greater<int>> headWorkers;
        std::priority_queue<int, std::vector<int>, std::greater<int>> tailWorkers;

        // headWorkers stores the first `candidates` workers.
        // tailWorkers stores at most last `candidates` workers without any workers from the first `candidates` workers.
        for (int i = 0; i < candidates; ++i) {
            headWorkers.push(costs[i]);
        }
        for (int i = std::max(candidates, static_cast<int>(costs.size()) - candidates); i < costs.size(); ++i) {
            tailWorkers.push(costs[i]);
        }

        long long answer = 0;
        int nextHead = candidates;
        int nextTail = costs.size() - 1 - candidates;

        for (int i = 0; i < k; ++i) {
            // Choose the smaller cost worker from head or tail.
            if (tailWorkers.empty() || (!headWorkers.empty() && headWorkers.top() <= tailWorkers.top())) {
                answer += headWorkers.top();
                headWorkers.pop();

                // Refill headWorkers if there are remaining workers outside the two queues.
                if (nextHead <= nextTail) {
                    headWorkers.push(costs[nextHead]);
                    ++nextHead;
                }
            }
            else {
                answer += tailWorkers.top();
                tailWorkers.pop();

                // Refill tailWorkers if there are remaining workers outside the two queues.
                if (nextHead <= nextTail) {
                    tailWorkers.push(costs[nextTail]);
                    --nextTail;
                }
            }
        }

        return answer;
    }
};
