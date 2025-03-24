// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using namespace std;

// struct ListNode{
//     int val;
//     ListNode * next;
//     ListNode(): val(0), next(nullptr) {}
//     ListNode(int x): val(x), next(nullptr){}
//     ListNode(int x, ListNode* next): val(x), next(next) {}
// };

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* l = head;
        ListNode* p = nullptr;
        ListNode* r = head;
        ListNode* q = r->next;

        while(r!= nullptr && --right > 0)
        {
            r = r->next;
            p = r->next;
        }

        while(l!= nullptr && --left > 0)
        {
            q = l;
            l = l->next;
        }

        ListNode* temp = p;
        ListNode* h = l;
        ListNode* e = h->next;
        while(1)
        {
            h->next = temp;
            if(h == r) break;
            temp = h;
            h = e;
            e = h->next;
        }
        if(q == nullptr)
        {
            q->next = h;
            return head;
        }
        return h;
    }
};
// @lc code=end


