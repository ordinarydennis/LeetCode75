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
	ListNode* oddEvenList(ListNode* head) {

		if (nullptr == head)
			return nullptr;

		ListNode* tail = head;

		int n = 1;

		while (tail->next)
		{
			tail = tail->next;
			n++;
		}

		ListNode* cur = head;

		int i = 0;

		while (cur->next && i < n / 2)
		{
			tail->next = cur->next;

			cur->next = cur->next->next;

			tail->next->next = nullptr;

			tail = tail->next;

			cur = cur->next;

			i++;
		}

		return head;

	}
};