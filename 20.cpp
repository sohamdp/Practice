
int dfs(int src,vector<vector<int>>& g,vector<int>& size)
    {
         int ans = 1;// for curent node
         for(auto child : g[src]){
             ans += dfs(child,g,size);
         }
         return size[src] = ans; 
     }
    
//caling function from main
int countHighestScoreNodes(vector<int>& parents) 
{    
	int n=parents.size();
	vector<int>size(n,0);  // size[i] indicates size of subtree(rooted at i node) + 1
	vector<vector<int>>v(n);  // storing left and right child of a node
	for(int i=1;i<n;i++)
	{
  	  v[parents[i]].push_back(i); // 'There is no parent for 0th node'
	}

	dfs(0,v,size); //calculating size of each subtree(rooted at ith node)

	long long int maxCount = 0;
	long long int maxScore = 0;
	for(int i=0;i<n;i++) // Nodes from '0' to 'n-1'
	{
	    // calculate score of each node after removal their 'edge' or 'node itself'.
	    long long int product = 1;
	    product = max(product, (long long int)(n - size[i])); // calculating leftover nodes excluding child nodes 
	    for(auto x : v[i])
	    {
		product = product*size[x];
	    }
	    
	    if(product > maxScore){
		maxScore = product;
		maxCount = 1;
	    }
	    else if(product == maxScore){
		maxCount++; // store count of nodes which have maximum score equal to "maxScore"
	    }
	}
    
  return maxCount;
}
