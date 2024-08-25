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

	int GetListSize(ListNode* head)
	{
		ListNode* cur = head;

		int count = 0;

		while (cur)
		{
			cur = cur->next;
			count++;
		}

		return count;
	}

public:
	ListNode* deleteMiddle(ListNode* head) {

		int count = GetListSize(head);

		if (1 == count)
		{
			return nullptr;
		}

		ListNode* pre = nullptr;

		ListNode* cur = head;

		int mid = count / 2;

		int i = 0;

		while (cur)
		{
			if (i == mid)
			{
				pre->next = cur->next;
				break;
			}
			else
			{
				pre = cur;
				cur = cur->next;
				i++;
			}
			
		}
		
		return head;
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
	ListNode* deleteMiddle(ListNode* head) {

		if (!head->next)
		{
			delete head;
			return nullptr;
		}

		auto* n = head;
		auto* fn = head;
		auto* p = head;

		while (n && fn && fn->next)
		{
			p = n;
			n = n->next;
			fn = fn->next->next;
		}

		p->next = n->next;

		return head;
	}
};