//. Write a program non-recursive and recursive program to calculate Fibonacci numbers and 
// analyze their time and space complexity

#include <iostream>
#include <vector>

using namespace std;

// Iteratively using dynamic programming
int iStepFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}


int rSteps = 0;


// Recursively using dynamic programming
int rStepFibonacci(int n, vector<int> &fib) {
    rSteps++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (fib[n] != -1) return fib[n];// This line checks if the Fibonacci number at index n has already been computed and stored in the vector fib.  
    fib[n] = rStepFibonacci(n - 1, fib) + rStepFibonacci(n - 2, fib);
    return fib[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Non-recursive approach
    cout << "Fibonacci Value using Iteration : " << iStepFibonacci(n) << endl;

    // Recursive approach with dynamic programming
    vector<int> fib(n + 1, -1);
    cout << "Fibonacci Value using Recursion: " << rStepFibonacci(n, fib) << endl;
    cout << "Steps required using recursion : " << rSteps << '\n';


    return 0;
}

// Recursive fibbonacci:
// Time Complexity: O(2^n)
// Auxiliary Space: O(n), For recursion call stack.

// Iterative fibbonacci:
// Time Complexity: O(n) 
// Auxiliary Space: O(n)


















// #include<iostream>
// #include<vector>

// using namespace std;

// //Iteratively using memoization
// int iStepFibbonacci(int n){
//     vector<int> f;
//     f.push_back(0);
//     f.push_back(1);
//     //[]
//     int cnt = 2;
//     for(int i = 2; i < n; i++){
//         cnt++;
//         f.push_back(f[i - 1] + f[i - 2]);
//     }
//     return n;
// }

// int rSteps = 0;

// //Recursively
// int rStepFibbonacci(int n){
//     rSteps++;
//     if(n < 0) return 0;
//     if(n == 1 || n == 0) return 1;
//     return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);
// }

// int main(){
//     int n;
//     cin >> n;
//     cout << "Fibbonacci Value : " << rStepFibbonacci(n) << '\n';
//     cout << "Steps required using Iteration : " << iStepFibbonacci(n) << '\n';
//     cout << "Steps required using recursion : " << rSteps << '\n';
//     return 0;
// }

/*
Recursive fibbonacci:
Time Complexity: O(n*2n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/



// The code provided seems to have a minor issue, mainly in the `iStepFibbonacci` function. It is returning the value of `n` instead of the Fibonacci number. Here's the corrected version of the code:

// ```cpp
// #include <iostream>
// #include <vector>
// using namespace std;

// Iteratively using memoization
// int iStepFibonacci(int n) {
//     vector<int> f;
//     f.push_back(0);
//     f.push_back(1);
//     for (int i = 2; i <= n; i++) {
//         f.push_back(f[i - 1] + f[i - 2]);
//     }
//     return f[n];
// }

// int rSteps = 0;

// // Recursively
// int rStepFibonacci(int n) {
//     rSteps++;
//     if (n <= 1) return n;
//     return rStepFibonacci(n - 1) + rStepFibonacci(n - 2);
// }

// int main() {
//     int n;
//     cin >> n;
//     cout << "Fibonacci Value using Recursion: " << rStepFibonacci(n) << '\n';
//     cout << "Fibonacci Value using Iteration : " << iStepFibonacci(n) << '\n';
//     cout << "Steps required using recursion : " << rSteps << '\n';
//     return 0;
// }
// ```

// The code now correctly computes the Fibonacci numbers both recursively and iteratively and also counts the number of steps required for the recursive computation.

// The time and space complexity analysis you provided is also correct:

// Recursive Fibonacci:
// - Time Complexity: Exponential O(2^n) since each call branches into two subsequent calls.
// - Auxiliary Space: O(n) for the recursion call stack.

// Iterative Fibonacci:
// - Time Complexity: O(n) since it computes the Fibonacci numbers iteratively.
// - Auxiliary Space: O(1) since it uses only a constant amount of extra space.