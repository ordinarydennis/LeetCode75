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
	ListNode* reverseList(ListNode* head) {

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

		return pre;
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
	ListNode* reverseList(ListNode* head) {

		ListNode* pre = nullptr;
		ListNode* cur = head;

		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}

		return pre;
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
	ListNode* reverseList(ListNode* head) {

		if (!head)
		{
			return nullptr;
		}

		auto* node = head;

		vector<ListNode*> vec;

		while(node)
		{
			vec.push_back(node);
			node = node->next;
		}

		for (int i = vec.size() - 1; 1 <= i; i--)
		{
			vec[i]->next = vec[i - 1];
		}

		vec[0]->next = nullptr;


		return vec[vec.size() - 1];


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
	ListNode* reverseList(ListNode* head) {

		if (!head)
		{
			return nullptr;
		}

		ListNode* pre = nullptr;
		ListNode* cur = head;

		while(cur)
		{
			auto* n = cur->next;

			cur->next = pre;

			pre = cur;

			if (n)
			{
				cur = n;
			}
			else
			{
				break;
			}
		}

		return cur;
	}
};