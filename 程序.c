/*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
//第一种
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> array;
    vector<int> temp;
    while(head != nullptr)
    {
        temp.push_back(head->val);
        head = head->next;
    }
    for(int i = temp.size()-1;i >= 0;i--)
    {
        array.push_back(temp[i]);
    }
    return array;
}
//第二种:未通过
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> array;
    array.push_back(head->val);
    head = head->next;
    auto it = head.begin();
    while(head != nullptr)
    {
        array.insert(it,head->val);
        head = head->next;
        it = head.begin();
    }
    return array;
}

/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp;
        while(stack1.size() != 0)
        {
            stack2.push(stack1.top());
            //cout << stack2.top() << endl;
            stack1.pop();
        }
        temp = stack2.top();
        stack2.pop();
        while(stack2.size() != 0)
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转
数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于
0，若数组大小为0，请返回0。
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        for(int i = 1;i < rotateArray.size();i++)
        {
            if(rotateArray[i] < rotateArray[i-1])
                return rotateArray[i];
        }
    }
};

/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode *p1,*p2,*pre1,*p3;
        pre1 = p1 = pHead1; p2 = pHead2;
        while(p1 && p2)
        {
            if(p1->val > p2->val)
            {
                pre1->next = p2;
                p3 = p2->next;
                p2->next = p1;
                p2 = p3;
            }
            pre1 = p1;
            p1 = p1->next;
        }
        if(p2)
            pre1->next = p2;
         
        return pHead1;
    }
};