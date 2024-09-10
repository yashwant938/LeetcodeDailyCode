#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to calculate gcd
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* cur = head;
    
    while (cur != nullptr && cur->next != nullptr) {
        // Calculate GCD of current node and next node
        int gcdValue = gcd(cur->val, cur->next->val);
        
        // Create a new node with the GCD value
        ListNode* gcdNode = new ListNode(gcdValue);
        
        // Insert the GCD node between cur and cur->next
        gcdNode->next = cur->next;
        cur->next = gcdNode;
        
        // Move to the next pair of nodes (skipping over the newly inserted gcdNode)
        cur = gcdNode->next;
    }
    
    return head;
}

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur
