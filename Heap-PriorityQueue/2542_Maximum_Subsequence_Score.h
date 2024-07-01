class Solution {

    void dfs(int index, int sum, int min, vector<int>& nums1, vector<int>& nums2, vector<bool>& visited, int k)
    {
        if (0 == k)
        {
            ret = std::max(ret, sum * min);
            return;
        }

        int size = nums1.size();

        for (int i = index; i < size; i++)
        {
            if (visited[i])
                continue;

            sum += nums1[index];

            min = std::min(min, nums2[index]);

            visited[index] = true;

            dfs(index + 1, sum, min, nums1, nums2, visited, k - 1);

            sum -= nums1[index];

            visited[index] = false;
        }

    }

    int ret = 0;

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<bool> visited(nums1.size());

        dfs(0, 0, 1, nums1, nums2, visited, k);

        return ret;
    }
};