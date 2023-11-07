//  Write a program to solve a fractional Knapsack problem using a greedy method.
#include<bits/stdc++.h>
using namespace std;

// Comparator function to sort the items based on the value-to-weight ratio in descending order
bool compare(pair<int,int> p1, pair<int,int> p2){
    double v1 = (double) p1.first / p1.second; // Calculate the value-to-weight ratio for the first item
    double v2 = (double) p2.first / p2.second; // Calculate the value-to-weight ratio for the second item

    return v1 > v2; // Compare the value-to-weight ratios and return true if the first is greater than the second
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n); // Create a vector of pairs to store the values and weights of the items
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second; // Input the value and weight for the i-th item
    }
    int w;
    cin >> w; // Input the value and weight for the i-th item

    // Sort the items based on the value-to-weight ratio in descending order
    sort(a.begin(),a.end(),compare);

    double ans = 0; // Initialize the variable to store the total value of the items in the knapsack

    // Iterate through the items
    for(int i=0;i<n;i++){
        if(w>=a[i].second){ // If the current item can be completely added to the knapsack
            ans+=a[i].first; // Add the entire value of the current item to the total value
            w-=a[i].second;  // Reduce the remaining capacity of the knapsack
            continue; // Continue to the next item
        }
        double vw = (double) a[i].first / a[i].second; // Calculate the value-to-weight ratio of the current item
        ans += vw * w; // Add the fractional value of the current item to the total value
        w = 0; // Set the remaining capacity of the knapsack to 0, as it is fully utilized
        break; // Exit the loop
    }
    // Output the total value of the items in the knapsack
    cout << ans << endl;

    return 0;
}


// The provided code is for solving the fractional knapsack problem using the greedy approach. It sorts the items in descending order of value 
//per unit weight and then tries to fill the knapsack greedily. The code seems to be implementing the standard greedy algorithm for the fractional 
//knapsack problem.

// Here's a breakdown of the code:

// The compare function is used as a comparator in the sort function to sort the items based on their value-to-weight ratio in descending order.
// The input is taken for the number of items n, followed by the values and weights of each item. Then the capacity of the knapsack w is taken as input.
// The items are sorted based on the value-to-weight ratio.
// The code iterates through the items and adds them to the knapsack as long as there is space. If the entire item cannot be added, it adds a 
//fraction of the item based on the remaining capacity.
// The code appears to be correct and efficiently implements the greedy algorithm for the fractional knapsack problem. It should provide the 
//maximum value that can be obtained by filling the knapsack with fractional items.