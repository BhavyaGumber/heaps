class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    vector<int> v;
	    priority_queue <int, vector<int>, greater<int>> g;
	    for(int i =0;i<n;i++){
	        g.push(arr[i]);
	        if(g.size()>k){
	            g.pop();
	        }
	    }
	    while(g.size()>0){
	        v.push_back(g.top());
	        g.pop();
	    }
	     sort(v.begin(), v.end(), greater<int>());
	    return v;
	    // code here
	}

};
