#include <iostream>
#include <vector>
#include <algorithm> // For std::advance and std::copy

using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {10, 20, 30, 40, 50};
    
    vector<int>::iterator ptr = a.begin();
    vector<int>::iterator ptr1 = b.begin();
    
    advance(ptr1, 2);   // Move ptr1 to point to the 3rd element in b
    *ptr1 = 100;        // Set the value at ptr1 to 100 (i.e., b[2] = 100)
    
    advance(ptr, 2);    // Move ptr to point to the 3rd element in a
    copy(b.begin() + 2, b.end(), ptr);  // Copy elements from b[2] to b[end()] to a[2] onwards
    
    for (int x : a) {
        cout << x << " ";
    }
    
    return 0;
}
