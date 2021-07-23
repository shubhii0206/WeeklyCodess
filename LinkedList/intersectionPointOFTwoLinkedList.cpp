/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
class Solution
{
public:
    int count(ListNode *head)
    {
        int cnt = 0;
        while (head != nullptr)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode *intersectionPoint(int d, ListNode *head1, ListNode *head2)
    {
        for (int i = 0; i < d; i++)
        {
            if (head1 == nullptr)
                return nullptr;
            head1 = head1->next;
        }
        while (head1 != nullptr && head2 != nullptr)
        {

            if (head1 == head2)
                return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        ListNode *ptr1 = head1;
        ListNode *ptr2 = head2;

        if (ptr1 == nullptr || ptr2 == nullptr)
            return nullptr;

        int a = count(head1), b = count(head2);
        ListNode *p = nullptr;
        if (a > b)
            p = intersectionPoint(a - b, head1, head2);
        else
            p = intersectionPoint(b - a, head2, head1);
        return p;
    }
};

############################################## #another Solution

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        if (p1 == p2)
            return p1;
        while (p1 != nullptr && p2 != nullptr && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2)
                return p1;
            if (p1 == nullptr)
                p1 = headB;
            if (p2 == nullptr)
                p2 = headA;
        }

        return p1;
    }
};