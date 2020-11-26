struct Node {
     int v;
     int parent;
 };

bool hasCycle(int N, int M, vector<vector<int>> edges) {
	// Write your code here
	vector<vector<int>> g;
	g.resize(N);
	vector<bool> visited(N, false);
	vector<int> indeg(N);
	queue<int> q;
	int total = 0;
	for(auto e: edges) {
	    g[e[0]].push_back(e[1]);
	    indeg[e[1]]++;
	}
	for(int i = 0; i < N -1; i ++){
	  if(indeg[i] == 0)  { 
	
  	   q.push(i);
	  }
	}
	visited[0] = true;
	while(!q.empty()) {
	    total++;
	   
	    int cell = q.front();
	              q.pop();
	    
	        for(auto neigh: g[cell]) {
	            indeg[neigh] --;
	            if(!visited[neigh]  && indeg[neigh] == 0) {
       
	               visited[neigh] = true;
	               q.push(neigh);
	            }
	        }
	    
	}
	if(total == N) return 0;
	else return 1;

}

