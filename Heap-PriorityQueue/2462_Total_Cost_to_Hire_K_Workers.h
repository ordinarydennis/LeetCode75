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


//fail
class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {

        priority_queue<int, vector<int>, greater<int>> q1;
        priority_queue<int, vector<int>, greater<int>> q2;

        int indexLeft = 0;
        int indexRight = costs.size() - 1;


        for (; indexLeft < candidates && indexLeft < costs.size(); indexLeft++)
        {
            q1.push(costs[indexLeft]);
        }

		for (; indexRight >= max(candidates, n - candidates) && indexLeft <= indexRight; indexRight--) {
			q2.push(costs[indexRight]);
		}

        int ret = 0;

        while (0 < k)
        {

            if (q1.size() && q2.size())
            {
                if (q1.top() <= q2.top())
                {
					ret += q1.top();
					q1.pop();

					if (indexLeft < costs.size() && indexLeft <= indexRight)
					{
						q1.push(costs[indexLeft]);
                        indexLeft++;
					}
                }
                else
                {
					ret += q2.top();
					q2.pop();

					if (0 <= indexRight && indexLeft < indexRight)
					{
						q2.push(costs[indexRight]);
                        indexRight--;
					}
                }

            }
            else if (q1.size())
            {
                ret += q1.top();
                q1.pop();

                if (indexLeft < costs.size() && indexLeft < indexRight)
                {
                    q1.push(costs[indexLeft]);
                    indexLeft++;
                }
            }
            else if (q2.size())
            {
				ret += q2.top();
				q2.pop();

				if (0 <= indexRight && indexLeft < indexRight)
				{
					q2.push(costs[indexRight]);
					indexRight--;
				}
            }

            k--;
        }

        return ret;
	}
};


//accepted
class Solution {
public:
	long long totalCost(vector<int>& costs, int k, int candidates) {

		priority_queue<int, vector<int>, greater<int>> q1;  // 최소 힙
		priority_queue<int, vector<int>, greater<int>> q2;  // 최소 힙

		int n = costs.size();
		int indexLeft = 0;
		int indexRight = n - 1;

		// 왼쪽에서 후보자 추가
		for (; indexLeft < candidates && indexLeft < n; indexLeft++) {
			q1.push(costs[indexLeft]);
		}

		// 오른쪽에서 후보자 추가
		for (; indexRight >= max(candidates, n - candidates) && indexLeft <= indexRight; indexRight--) {
			q2.push(costs[indexRight]);
		}

		long long ret = 0;  // 결과값을 long long 타입으로 설정

		// k번 반복
		while (k > 0) 
        {
			// q1과 q2 모두 값이 있는 경우, 최소값을 비교하여 더 작은 값을 선택
			if (!q1.empty() && !q2.empty())
            {
				if (q1.top() <= q2.top())
                {
					ret += q1.top();
					q1.pop();

					if (indexLeft <= indexRight)
                    {
						q1.push(costs[indexLeft]);
						indexLeft++;
					}
				}
				else
                {
					ret += q2.top();
					q2.pop();

					if (indexLeft <= indexRight)
                    {
						q2.push(costs[indexRight]);
						indexRight--;
					}
				}

			}
			// q1만 남아 있는 경우
			else if (!q1.empty())
            {
				ret += q1.top();
				q1.pop();

				if (indexLeft <= indexRight) {
					q1.push(costs[indexLeft]);
					indexLeft++;
				}
			}
			// q2만 남아 있는 경우
			else if (!q2.empty()) {
				ret += q2.top();
				q2.pop();

				if (indexLeft <= indexRight)
                {
					q2.push(costs[indexRight]);
					indexRight--;
				}
			}

			k--;
		}

		return ret;
	}
};
