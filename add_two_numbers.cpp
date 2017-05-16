/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		int bit = l1->val + l2->val;
		if (bit >= 10)
		{
			carry = 1;
			bit -= 10;
		}
		ListNode *ans = new ListNode(bit);
		ListNode *ini = ans;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 && l2)
		{
			bit = l1->val + l2->val + carry;
			carry = 0;
			if (bit >= 10)
			{
				carry = 1;
				bit -= 10;
			}
			ListNode *temp = new ListNode(bit);
			ans->next = temp;
			ans = temp;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == nullptr && l2)
		{
			do
			{
				bit = l2->val + carry;
				carry = 0;
				if (bit >= 10)
				{
					carry = 1;
					bit -= 10;
				}
				ListNode *temp = new ListNode(bit);
				ans->next = temp;
				ans = temp;
				l2 = l2->next;
			} while (l2);
		}
		else if (l2 == nullptr && l1)
		{
			do
			{
				bit = l1->val + carry;
				carry = 0;
				if (bit >= 10)
				{
					carry = 1;
					bit -= 10;
				}
				ListNode *temp = new ListNode(bit);
				ans->next = temp;
				ans = temp;
				l1 = l1->next;
			} while (l1);
		}
		if (carry)
		{
			ListNode *temp = new ListNode(carry);
			ans->next = temp;
			ans = temp;
		}
		return ini;
	}
};