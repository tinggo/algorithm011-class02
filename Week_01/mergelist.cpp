#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tempNode( -1 );
        ListNode *prevHead = &tempNode;
        ListNode *prevNode = prevHead;
        while ( l1 && l2 ) {
            if ( l1->val < l2->val ) {
                prevNode->next = l1;
                l1 = l1->next;
            }
            else if ( l1->val >= l2->val ) {
                prevNode->next = l2;
                l2 = l2->next;
            }
            prevNode = prevNode->next;
        }
        prevNode->next = l1 == nullptr ? l2 : l1;
        return prevHead->next;
    }
};

int main() {
    vector<int> v1 = { 1, 2, 3, 4 };
    vector<int> v2 = { 2, 2, 4 };

    auto createList = []( const vector<int>& v )->ListNode* {
        ListNode *h = nullptr;
        for ( auto it = v.rbegin(); it != v.rend(); ++it ) {
            h = new ListNode ( *it, h );
        }
        return h;
    };

    auto destroyList = []( ListNode* h ) {
        while ( h ) {
            ListNode* n = h;
            h = n->next;
            delete n;
        }
    };

    ListNode *l1 = createList( v1 );
    ListNode *l2 = createList( v2 );

    Solution solution;
    ListNode *rl = solution.mergeTwoLists( l1, l2 );
    ListNode *tn = rl;
    while ( tn ) {
        if ( tn != rl )
            cout << "->";
        cout << tn->val;
        tn = tn->next;
    }
    cout<<endl;

    destroyList( rl );
    system("pause");
    return 0;
}