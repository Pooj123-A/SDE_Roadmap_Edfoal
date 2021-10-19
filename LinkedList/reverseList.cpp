
 Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Reverse {
public:
       ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||left==right)
            return head;
        ListNode *tempNode=new ListNode(0);
        tempNode->next=head;
        ListNode* nodeBeforeSubList=tempNode;
        int pos=1;
        while(pos<left){
            nodeBeforeSubList=nodeBeforeSubList->next;
            pos++;
        }
        auto workingNode=nodeBeforeSubList->next;
        while(left<right){
            auto nodeToBeExtracted=workingNode->next;
            workingNode->next=nodeToBeExtracted->next;
            
            nodeToBeExtracted->next=nodeBeforeSubList->next;
            nodeBeforeSubList->next=  nodeToBeExtracted;
            left++;
        }
       return tempNode->next; 
    }
};