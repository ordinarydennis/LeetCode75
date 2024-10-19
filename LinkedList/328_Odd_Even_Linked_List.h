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

		if (!head)
			return nullptr;

		ListNode* oddHead = head;
		ListNode* evenHead = head->next;

		ListNode* odd = oddHead;
		ListNode* even = evenHead;

		while (odd->next && even->next)
		{
			odd->next = even->next;
			odd = odd->next;

			even->next = odd->next;
			even = even->next;
		}

		odd->next = evenHead;

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
	ListNode* oddEvenList(ListNode* head) {

		if(!head)
			return nullptr;

		auto oddHead = head;
		auto evenHead = head->next;

		auto odd = head;
		auto even = head->next;

		while (odd && even)
		{
			odd->next = even->next;

			if (odd->next)
			{
				odd = odd->next;
			}
			else
			{
				break;
			}
			
			even->next = odd->next;
			even = even->next;
		}

		odd->next = evenHead;

		return oddHead;
	}
};