class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {

		sort(intervals.begin(), intervals.end());

		int start = intervals[0][0];
		int end = intervals[0][1];

		int ret = 0;

		for (int i = 1; i < intervals.size(); i++)
		{
			if (end <= intervals[i][0])
			{
				end = max(end, intervals[i][1]);
			}
			else
			{
				ret++;
			}
		}

		return ret;
	}
};

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {

		sort(intervals.begin(), intervals.end(), [](vector<int>& l, vector<int>& r) {

			return l[1] < r[1];

			}
		);

		int max = intervals[0][1];

		int ret = 0;

		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] < max)
			{
				ret++;
			}
			else
			{
				max = intervals[i][1];
			}
		}

		return ret;
	}
};

//시작점으로 정렬했을 때와 끝점으로 정렬했을 때 다른 결과가 나오는 구체적인 예시를 들어 설명하겠습니다.
//이 예시는 시작점 정렬 방식이 끝점 정렬 방식보다 덜 효율적인 경우를 보여줍니다.
//
//예시:
//다음과 같은 구간들이 있다고 가정합시다 :
//[1, 10], [2, 3], [4, 5], [6,7]
//시작점으로 정렬할 경우 :
//정렬된 구간 :
//[1, 10], [2, 3], [4, 5], [6, 7]
//
//[1, 10]을 선택합니다.
//이 선택으로 인해 나머지 모든 구간([2, 3], [4, 5], [6, 7])은[1, 10]과 겹치므로 선택할 수 없습니다.
//결과적으로 선택된 구간은 [1, 10] 하나뿐입니다.
//끝점으로 정렬할 경우 :
//정렬된 구간 :
//[2, 3], [4, 5], [6, 7], [1, 10]
//
//[2, 3]을 선택합니다.
//다음으로[4, 5]를 선택합니다.
//그 다음으로[6, 7]을 선택합니다.
//[1, 10]은 앞선 모든 선택과 겹치므로 제외됩니다.
//결과적으로 선택된 구간은 [2, 3], [4, 5], [6, 7] 세 개입니다.
//결과 비교 :
//시작점 정렬 : 단 1개의 구간만 선택 가능.
//끝점 정렬 : 3개의 구간을 선택, 더 많은 구간 선택 가능.
//이 예시에서 볼 수 있듯이, 끝점으로 정렬하는 방식은 각 구간이 가능한 한 빨리 끝나도록 하여 다음 구간 선택의 여지를 최대한 확보하는 전략입니다.
//이는 겹침을 최소화하고, 가능한 많은 구간을 선택하는 데 유리합니다.따라서, 각 구간을 끝점 기준으로 정렬하고 선택하는 것이 종종 최적의 해를 제공하는 전략이 됩니다.