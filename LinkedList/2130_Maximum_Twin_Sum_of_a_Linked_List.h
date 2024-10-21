/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	int pairSum(ListNode* head) {

		auto oHead = head->next;

		auto head2 = new ListNode(head->val);

		auto headIt = head2;

		int count = 1;

		while (oHead)
		{
			headIt->next = new ListNode(oHead->val);

			headIt = headIt->next;

			oHead = oHead->next;

			count++;
		}

		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* next = nullptr;

		while (cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		head = pre;

		int ret = 0;

		int i = 0;
		while (i < count / 2)
		{
			ret = std::max(ret, head->val + head2->val);
			i++;

			head = head->next;
			head2 = head2->next;
		}

		return ret;

	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
	int pairSum(ListNode* head) {

		vector<int> list;

		ListNode* cur = head;
		ListNode* pre = nullptr;

		while (cur)
		{
			list.push_back(cur->val);

			auto* next = cur->next;

			cur->next = pre;

			pre = cur;

			cur = next;
		}

		int ret = INT_MIN;

		for (int i = 0; i < list.size() / 2; i++)
		{
			ret = std::max(ret, list[i] + pre->val);

			pre = pre->next;
		}

		return ret;
	}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	int pairSum(ListNode* head) {

		vector<int> v;

		auto* node = head;

		while (node)
		{
			v.push_back(node->val);
			node = node->next;
		}

		int max = v.size() - 1;
		int ret = 0;

		for (int i = 0; i <= max / 2; i++)
		{
			ret = std::max(ret, v[i] + v[max - i]);
		}

		return ret;
	}
};


//fail
class Solution {

public:
	int pairSum(ListNode* head) {

		ListNode* pre = nullptr;
		ListNode* cur = head;

		int count = 0;

		while (cur)
		{
			count++;
			auto* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		auto* nodeLeft = head;
		auto* nodeRight = pre; //reverseHead

		int ret = 0;

		while (nodeLeft && nodeRight)
		{
			ret = max(ret, nodeLeft->val + nodeRight->val);
			nodeLeft = nodeLeft->next;
			nodeRight = nodeRight->next;
		}

		return ret;
	}
};