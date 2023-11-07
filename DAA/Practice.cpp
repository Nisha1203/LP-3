#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
	double v1 = (double) p1.first / p1.second; // Calculate the value-to-weight ratio for the first item
    double v2 = (double) p2.first / p2.second; // Calculate the value-to-weight ratio for the second item

    return v1 > v2;
}
int main()
{
	int n=0;
	cin>>n;

	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}

	int w=0;
	cin>>w;

	sort(a.begin(),a.end(),compare);

	int ans=0;
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