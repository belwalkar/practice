int minNumberOfRolls(int n, vector<int> moves) {
    if (n == 0)
        return -1;
    
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    
    int min_cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i=0; i<size; i++)
        {
            int cell = q.front();
            q.pop();
            if (visited[cell] == true)
                continue;
            visited[cell] = true;
            if (cell == n-1 && moves[cell] == -1)
                return min_cnt;
            if (moves[cell] != -1)
                q.push(moves[cell]);
            
            for (int j=1; j<=6; j++)
            {
                if (cell+j < n)
                {
                    if (moves[cell+j] == -1)
                        q.push(cell+j);
                    else
                        q.push(moves[cell+j]);
                }
            }
        }
        min_cnt++;
    }
    return -1;

}

