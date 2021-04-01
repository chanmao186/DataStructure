#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;



struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1)return head;
		ListNode * pre, *cur, *next, *last, *front1,*front2;
		bool isUpdateHead = true;
		pre = cur = last  = front1= front2 = head;


		while (isHaveK(&last, k)) {
			//cur->next = pre;
			pre = last;
			next = cur->next;

			for (int i = 0; i < k; ++i) {
				cur->next = pre;
				pre = cur;
				cur = next;
				if(next)
				next = next->next;
			}
			if (isUpdateHead) {
				isUpdateHead = false;
				head = pre;
			}
			else {
				front1->next = pre;
				front1 = front2;
			}
			front2 = last;
			//cur = last;
		}
		return head;
	}
private:

	//若有，则返回true
	//若无,则flag=
	bool isHaveK(ListNode** head, int k) {
		int i = 0;
		ListNode* temp = *head;
		for (; i < k && temp; ++i) {
			temp = temp->next;
		}
		*head = temp;
		return i == k;
	}
};
int main() {
	string s = "(]";
	//int n,num;
	//cin >> n;
	ListNode* head, * temp;
	head = (ListNode*)malloc(sizeof(ListNode));
	temp = head;
	for (int i = 0; i < 6; i++) {
		//cin >> num;
		temp->next = (ListNode*)malloc(sizeof(ListNode));
		temp = temp->next;
		temp->val = i + 1;

	}
	temp->next = nullptr;
	Solution f;
	f.reverseKGroup(head->next, 2);
	return 0;
}