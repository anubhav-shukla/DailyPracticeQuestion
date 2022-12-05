struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		vector<ListNode*>v1;
		ListNode* rt=head;
		while(rt){
			v1.push_back(rt);
			rt=rt->next;
		}
		return v1[v1.size()/2];
	}
};