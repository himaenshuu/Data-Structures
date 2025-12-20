    int V = 4;
    vector<vector<int>> v(V); // Create adjacency list with V nodes
    v[0] = {1};               // Edge from 0 to 1
    v[1] = {2};               // Edge from 1 to 2
    v[2] = {3};               // Edge from 2 to 3
    v[3] = {};                // Node 3 has no outgoing edges
    Solution sol;
    print1darray(sol.topoSort(V, v));