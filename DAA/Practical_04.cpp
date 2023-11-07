//  Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and 
//  bound strategy

#include<iostream>

using namespace std;

int main(){
    int capacity = 10;
    int items = 4;
    int price[items + 1] = {0, 3, 7, 2, 9};
    int wt[items + 1] = {0, 2, 2, 4, 5};
    // 2D array to store the maximum profit for different subproblems
    int dp[items + 1][capacity + 1];
    
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            // If there are no items or the capacity is 0, then the maximum profit is 0
            if(i == 0 || j == 0){
                //There's nothing to add to Knapsack
                dp[i][j] = 0;
            }
            // If the weight of the current item is less than or equal to the current capacity
            // Choose the maximum of the previously calculated maximum or
            // the value of the current item plus the value of the remaining weight
            else if(wt[i] <= j){
                //Choose previously maximum or value of current item + value of remaining weight
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            // If the weight of the current item is more than the current capacity, then
            // the maximum profit remains the same as the maximum profit calculated so far
            else{
                //Add previously added item to knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/


// #include <iostream>
// using namespace std;

// int main() {
//     int capacity, items;
//     cout << "Enter the capacity of the knapsack: ";
//     cin >> capacity;
//     cout << "Enter the number of items: ";
//     cin >> items;

//     int price[items + 1];
//     int wt[items + 1];

//     price[0] = 0;
//     wt[0] = 0;

//     cout << "Enter the prices of the items:" << endl;
//     for (int i = 1; i <= items; i++) {
//         cout << "Item " << i << ": ";
//         cin >> price[i];
//     }

//     cout << "Enter the weights of the items:" << endl;
//     for (int i = 1; i <= items; i++) {
//         cout << "Item " << i << ": ";
//         cin >> wt[i];
//     }

//     int dp[items + 1][capacity + 1];

//     for (int i = 0; i <= items; i++) {
//         for (int j = 0; j <= capacity; j++) {
//             if (i == 0 || j == 0) {
//                 dp[i][j] = 0;
//             } else if (wt[i] <= j) {
//                 dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
//     return 0;
// }
