class Solution {
public:
	int findPeakElement(vector<int>& nums) {


		for (int i = 1; i < nums.size(); i++)
		{
			if (i < nums.size() - 1)
			{
				if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
				{
					return i;
				}
			}
			else
			{
				if (nums[i - 1] < nums[i])
				{
					return i;
				}
			}
		}

		return 0;
	}
};


class Solution {

	int dfs(int s, int e, vector<int>& nums)
	{
		if (s == e)
		{
			return 0;
		}

		if (e - 1 == s)
		{
			return nums[s];
		}

		int m = (s + e) / 2;

		int l = dfs(s, m, nums);
		int r = dfs(m + 1, e, nums);

		if (l < nums[m] && nums[m] > r)
		{
			ret = m;
		}

		return nums[l] < nums[r] ? nums[r] : nums[l];
	}


	int ret = 0;

public:
	int findPeakElement(vector<int>& nums) {

		if (nums.size() == 2)
		{
			return nums[0] < nums[1] ? 1 : 0;
		}

		dfs(0, nums.size(), nums);

		return ret;
	}
};


class Solution {

	int dfs(int s, int e, vector<int>& nums)
	{
		if (s == e)
			return s;

		int m = (s + e) / 2;

		if (nums[m] > nums[m + 1])
			return dfs(s, m, nums);
		else
			return dfs(m + 1, e, nums);
	}

public:
	int findPeakElement(vector<int>& nums) {

		return dfs(0, nums.size() - 1, nums);

	}
};

class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int l = 0, r = nums.size() - 1;

		while (l < r)
		{
			int mid = (l + r) / 2;

			if (nums[mid] > nums[mid + 1])
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}
};



class Solution {
public:
    int findPeakElement(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			bool l = true;

			if (0 <= i - 1)
			{
				l = nums[i - 1] <= nums[i];
			}

			bool r = true;
			if (i + 1 < nums.size())
			{
				r = nums[i + 1] <= nums[i];
			}

			if (l && r)
			{
				return i;
			}
		}

		return 0;
    }
};



class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				return i;
			}
		}

		return nums.size() - 1;
	}
};

class Solution {

	int dfs(vector<int>& nums, int l , int r)
	{
		if (l == r)
			return l;

		int m = (l + r) / 2;

		return (nums[m] < nums[m + 1]) ? dfs(nums, m + 1, r) : dfs(nums, l, m);
	}


public:
	int findPeakElement(vector<int>& nums) {

		return dfs(nums, 0, nums.size() - 1);

	}
};



class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			int mid = (left + right) / 2;

			//mid + 1 is valid index, so need to include mid + 1
			if (nums[mid] < nums[mid + 1])
			{
				left = mid + 1;
			}
			//mid is valid index, so need to include mid, not mid - 1
			else
			{
				right = mid;
			}
		}

		return left;
	}
};


class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (nums[mid] > nums[mid + 1])
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}
};

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return search(nums, 0, nums.size() - 1);
	}

private:
	int search(vector<int>& nums, int l, int r) {
		if (l == r) return l;
		int mid = (l + r) / 2;
		if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
		return search(nums, mid + 1, r);
	}
};


class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			int mid = (left + right) / 2;

			if (nums[mid] < nums[mid + 1])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return left;
	}
};


//코드에서 `left = mid + 1`은 하지만 `right = mid`로 대입하는 이유는, **이진 탐색 * *의 특성을 활용하여 효율적으로 피크 엘리먼트를 찾기 위함입니다.
// 이를 더 자세히 설명하겠습니다.
//
//### 로직의 설명
//
//1. * *이진 탐색의 원리 * *:
//-이 코드는 배열 `nums`에서 피크 엘리먼트(주변 원소보다 큰 값)를 찾는 문제를 풀고 있습니다.
// 이 문제에서 피크 엘리먼트는 하나 이상 존재하므로, 이진 탐색을 통해 효율적으로 찾을 수 있습니다.
//
//2. * *mid와 그 주변 요소 비교 * *:
//-`mid` 인덱스와 `mid + 1` 인덱스를 비교하여 배열의 탐색 범위를 줄여나갑니다.
//- `nums[mid] < nums[mid + 1]`인 경우, 즉 `mid`보다 `mid + 1`이 더 크다면, **오른쪽 부분에 피크가 존재** 할 가능성이 더 큽니다.
// 이 경우 `left`를 `mid + 1`로 이동시킵니다.
//	- 왜냐하면 `nums[mid + 1]`이 더 크기 때문에, 현재 `mid`가 피크일 가능성은 없으며, 피크는 반드시 오른쪽에 있을 수밖에 없습니다.
//
//	3. * *right = mid로 대입하는 이유 * *:
//-반대로, `nums[mid] >= nums[mid + 1]`인 경우, ** 왼쪽 부분에 피크가 존재할 가능성** 이 더 큽니다.이 경우 `right`를 `mid`로 설정합니다.
//- 여기서 `right = mid`로 설정하는 이유는, `nums[mid]` 자체가 피크일 가능성이 있기 때문입니다. 
// `nums[mid]`는 그다음 요소보다 크거나 같기 때문에, 피크는 왼쪽이나 현재 위치에 있을 수 있습니다.따라서 `right`는 `mid`로 그대로 유지해도 됩니다.
//
//### 정리
//
//- **`left = mid + 1`* * : `nums[mid] < nums[mid + 1]`이므로, 피크는 `mid + 1` 이상의 범위에 존재합니다.따라서 탐색 범위를 오른쪽으로 좁힙니다.
//	- **`right = mid`* * : `nums[mid] >= nums[mid + 1]`이므로, 피크는 `mid` 이하의 범위에 존재할 가능성이 있습니다.따라서 `right`를 `mid`로 설정하여 탐색 범위를 왼쪽으로 좁힙니다.
//
//	이 방법을 통해 효율적으로 피크 엘리먼트를 찾을 수 있습니다.