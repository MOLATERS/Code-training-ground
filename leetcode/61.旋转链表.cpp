// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem61.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* K = head;
        if(head == nullptr || head->next == nullptr) return head;
        int size = 1;
        while(temp->next != nullptr){
            size++;
            temp = temp->next;
        }
        if(size <= k) k = k % size;
        int step = size - k - 1;
        for(int i = 0; i < step; i++ )
        {
            K = K->next;
        }
        temp->next = head;
        head = K->next;
        K -> next = nullptr;
        return head;
    }

};

// @lc code=end

