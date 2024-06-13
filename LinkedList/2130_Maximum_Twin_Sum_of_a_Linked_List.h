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