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
#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i=0;i<n;i++) {
            fast = fast->next;
        }

        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete slow->next
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;
        free(deleteNode);
    }
};