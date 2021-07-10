#include<bits/stdc++.h>


Node * evenNodesToEnd(Node *head)
{
    if(head == nullptr)
      return nullptr;

    Node * odd = head;
    Node * even = nullptr; Node * prev = nullptr;


    while(odd != nullptr && odd->next != nullptr)
    {
        if(odd != nullptr && odd->next != nullptr)
        {
            Node * new_Node = odd->next;
            odd->next = odd->next->next;
            new_Node->next = even;
            even = new_Node;
        }

        prev = odd;
        odd = odd->next;

    }

    if(odd != nullptr)
    odd->next = even;
    else
    prev->next = even;
    return head;



}