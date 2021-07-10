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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {

        if (a == nullptr)
            return b;
        else if (b == nullptr)
            return a;
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        while (1)
        {

            if (a == NULL)
            {
                tail->next = NULL;
                break;
            }

            else if (b == NULL)
            {
                tail->next = a;
                break;
            }

            else
            {
                tail->next = a;
                tail = a;
                a = a->next;

                tail->next = b;
                tail = b;
                b = b->next;
            }
        }

        return dummy.next;
    }
};