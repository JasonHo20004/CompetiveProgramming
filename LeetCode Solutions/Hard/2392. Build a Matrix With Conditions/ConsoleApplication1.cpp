class Solution {
public:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
    vector<int> inDegree(k + 1, 0);
    vector<vector<int>> graph(k + 1);
    for (auto& cond : conditions) {
        int u = cond[0], v = cond[1];
        graph[u].push_back(v);
        inDegree[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int neighbor : graph[node]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (order.size() != k) return {}; // Cycle detected or not all nodes processed
    return order;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topologicalSort(k, rowConditions);
    vector<int> colOrder = topologicalSort(k, colConditions);
    
    if (rowOrder.empty() || colOrder.empty()) return {};
    
    vector<vector<int>> matrix(k, vector<int>(k, 0));
    vector<int> rowIndex(k + 1), colIndex(k + 1);
    
    for (int i = 0; i < k; ++i) {
        rowIndex[rowOrder[i]] = i;
        colIndex[colOrder[i]] = i;
    }
    
    for (int num = 1; num <= k; ++num) {
        matrix[rowIndex[num]][colIndex[num]] = num;
    }
    
    return matrix;
}
};