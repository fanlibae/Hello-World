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
      vector<int> v;
      int n = 0;
      int maxx = 0;
      while(head){
        n++;
        v.push_back(head->val);
        head = head->next;
      }
      
      for(int i = 0; i < n; i++){
        maxx = max(maxx,v[i]+v[n-i-1]);
      }
      
      return maxx;
        
    }
};