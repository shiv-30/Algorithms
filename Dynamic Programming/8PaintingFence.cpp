// Painting Fence Algorithm
// Difficulty Level : Hard
//  Last Updated : 05 Nov, 2020
// Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.
// Examples:

// Input : n = 2 k = 4
// Output : 16
// We have 4 colors and 2 posts.
// Ways when both posts have same color : 4
// Ways when both posts have diff color :
// 4*(choices for 1st post) * 3(choices for
// 2nd post) = 12

// Input : n = 3 k = 2
// Output : 6
// Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
// Following image depicts the 6 possible ways of painting 3 posts with 2 colors:



// Consider the following image in which c, c’ and c” are respective colors of posts i, i-1 and i -2.






// According to the constraint of the problem, c = c’ = c” is not possible simultaneously, so either c’ != c or c” != c or both. There are k – 1 possibilities for c’ != c and k – 1 for c” != c.

//  diff = no of ways when color of last
//         two posts is different
//  same = no of ways when color of last
//         two posts is same
//  total ways = diff + sum

// for n = 1
//     diff = k, same = 0
//     total = k

// for n = 2
//     diff = k * (k-1) //k choices for
//            first post, k-1 for next
//     same = k //k choices for common
//            color of two posts
//     total = k +  k * (k-1)

// for n = 3
//     diff = k * (k-1)* (k-1)
//            //(k-1) choices for the first place
//         // k choices for the second place
//         //(k-1) choices for the third place
//     same = k * (k-1) * 2
//         // 2 is multiplied because consider two color R and B
//         // R R B or B R R
//         // B B R or R B B
//            c'' != c, (k-1) choices for it

// Hence we deduce that,
// total[i] = same[i] + diff[i]
// same[i]  = diff[i-1]
// diff[i]  = (diff[i-1] + diff[i-2]) * (k-1)
//          = total[i-1] * (k-1)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int paintFence(int n, int k) {
    if (n == 1) {
        return k;
    }
    else if (n == 2) {
        return k + k * (k - 1);
    }
    else {
        int same = k;
        int diff = k * (k - 1);
        int total = same + diff;
        for (int i = 3; i <= n; ++i) {
            same = diff;
            diff = total * (k - 1);
            total = same + diff;
        }
        return total;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << paintFence(n, k) << "\n";
    return 0;
}