/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity? T(n) = O(n)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{ 
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}

/*
Approach:
1. Use Floyd's cycle detection algorithm to find the intersection point of the two runners.
2. Move slow to head. Keep fast at the intersection point. Each are k steps from the loop start. If they move at the same pace, they must meet at loop start.
3. Return slow or fast.

Time Complexity: O(n)
Space Complexity: O(1)

Ques - What is Floyd's cycle detection algorithm?
Ans - Floyd's cycle detection algorithm is a pointer algorithm that uses only two pointers, which move through the sequence at different speeds. This is also known as the "tortoise and the hare" algorithm. The space complexity is O(1). The algorithm is also known as the "tortoise and the hare" algorithm.
Approach for this algorithm:
1. Traverse the linked list using two pointers.
2. Move one pointer(slow_p) by one and another pointer(fast_p) by two. If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn't have a loop.

Ques - An example of Floyd's cycle detection algorithm?
Ans - Consider the following linked list, where E is the cylce entry and X, the crossing point of fast and slow.
    <---  H -----> E
    1 ----> 2 ---> 3 ----> 4 -----> 5
                   |                |
                   |                |
                   8 <---- 7 <----- 6
                           X
    H: distance from head to cycle entry E
    D: distance from E to X  ---> 4
    L: cycle length  ---> 6
    If fast and slow both start at H, when fast catches slow, slow has traveled H+D and fast 2(H+D). 
    Assume fast has traveled n loops in the cycle, we have:
    2H + 2D = H + D + L
    H + D = nL
    H + D = (n-1)L + L
    H + D = (n-1)L + C
    H = C - D
    Thus, when slow and fast meet at X, slow has traveled H+D and fast 2(H+D), and since H = C - D, they meet at C.

    Ques - What do you mean by cyclic entry?
    Ans - Cyclic entry is the point where the cycle starts.

    Ques - And what is head signifies here?
    Ans - Head signifies the starting point of the linked list.

    Ques - How can we relate this to the problem?
    Ans - We can relate this to the problem by using the same approach. We can use two pointers, one slow and one fast. We can move the slow pointer by one and the fast pointer by two. If they meet at the same node, then there is a loop. If they don't meet, then there is no loop.

    Ques - What is the time complexity of this algorithm?
    Ans - The time complexity of this algorithm is O(n).

    Ques - Why the time complexity is O(n)?
    Ans - The time complexity is O(n) because the slow pointer and the fast pointer traverse the linked list only once. So, the time complexity is O(n).

    Let's dry run on array [1,3,4,2,2]

    The linked list corresponding to the array is:
    1 ----> 3 ----> 2 ----> 4 -----> 2

    So, as we can see that there are n + 1 numbers in the array and the number of elements in the linked list is n, that says that one of the element is child or next of more than one element. So, there is a loop in the linked list.

    The linked list correseponding to array [1,3,4,2,3,4,5,2]
    1 ----> 3 ----> 2 ----> 4 -----> 3
                                    |
                                    |
                                    2  
                           



    The end
*/

