// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
#include<unordered_map>
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution {
public:
	// A1[] : the input array-1
	// N : size of the array A1[]
	// A2[] : the input array-2
	// M : size of the array A2[]

	//Function to sort an array according to the other array.
	vector<int> sortA1ByA2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//Your code here
		int maxElement = max(*max_element(nums2.begin(), nums2.end()), 
			*max_element(nums1.begin(),nums1.end()));
		vector<int> positions(maxElement + 1, -1);
		vector<pair<int,pair<int,int>>> result;

		for (int i = n - 1; i >= 0; --i) {
			positions[nums2[i]] = i;
		}

		for (int i = 0; i < m; ++i) {
			if (positions[nums1[i]] == -1) {
				result.push_back({ INT_MAX,{nums1[i],i} });
			}
			else {
				result.push_back({ positions[nums1[i]], {nums1[i], i} });
			}
		}

		sort(result.begin(), result.end());

		for (int i = 0; i < m; ++i) {
			nums1[i] = result[i].second.first;
		}

		return nums1;
	}
};

// { Driver Code Starts.

int main(int argc, char* argv[])
{

	int t;

	cin >> t;

	while (t--) {

		int n, m;
		cin >> n >> m;

		vector<int> a1(n);
		vector<int> a2(m);

		for (int i = 0; i < n; i++) {
			cin >> a1[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> a2[i];
		}

		Solution ob;
		a1 = ob.sortA1ByA2(a1, n, a2, m);


		for (int i = 0; i < n; i++)
			cout << a1[i] << " ";

		cout << endl;


	}
	return 0;
}
// } Driver Code Ends