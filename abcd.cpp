#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

class DSU
{
public:
    std::vector<int> parent;
    std::vector<int> max_val;
    DSU(const std::vector<int> &nums)
    {
        int n = nums.size();
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        max_val = nums;
    }

    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {

            parent[root_j] = root_i;
            max_val[root_i] = std::max(max_val[root_i], max_val[root_j]);
        }
    }
};

// ADD THIS CLASS DEFINITION
class SegTree
{
private:
    std::vector<int> tree;
    DSU &dsu;
    int rank_count;

    void query_and_unite(int node, int start, int end, int l, int r, int idx_to_unite)
    {
        if (r < start || end < l || tree[node] == -1)
        {
            return;
        }
        if (l <= start && end <= r)
        {
            dsu.unite(idx_to_unite, tree[node]);
            return;
        }
        int mid = start + (end - start) / 2;
        query_and_unite(2 * node, start, mid, l, r, idx_to_unite);
        query_and_unite(2 * node + 1, mid + 1, end, l, r, idx_to_unite);
    }

    void update_with_index(int node, int start, int end, int rank_to_update, int idx_to_add)
    {
        if (tree[node] != -1)
        {
            dsu.unite(tree[node], idx_to_add);
        }
        tree[node] = dsu.find(idx_to_add);

        if (start == end)
            return;

        int mid = start + (end - start) / 2;
        if (rank_to_update <= mid)
        {
            update_with_index(2 * node, start, mid, rank_to_update, idx_to_add);
        }
        else
        {
            update_with_index(2 * node + 1, mid + 1, end, rank_to_update, idx_to_add);
        }
    }

public:
    SegTree(int num_ranks, DSU &dsu_ref) : dsu(dsu_ref), rank_count(num_ranks)
    {
        tree.assign(4 * rank_count, -1);
    }

    void connect_and_insert(int rank, int idx)
    {
        if (rank + 1 < rank_count)
        {
            query_and_unite(1, 0, rank_count - 1, rank + 1, rank_count - 1, idx);
        }
        update_with_index(1, 0, rank_count - 1, rank, idx);
    }
};

class Solution
{
public:
    std::vector<int> maxValue(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        std::vector<int> sorted_unique_vals = nums;
        std::sort(sorted_unique_vals.begin(), sorted_unique_vals.end());
        sorted_unique_vals.erase(std::unique(sorted_unique_vals.begin(), sorted_unique_vals.end()), sorted_unique_vals.end());

        std::map<int, int> val_to_rank;
        for (int i = 0; i < sorted_unique_vals.size(); ++i)
        {
            val_to_rank[sorted_unique_vals[i]] = i;
        }
        int num_ranks = sorted_unique_vals.size();

        DSU dsu(nums);
        SegTree st(num_ranks, dsu);

        for (int i = 0; i < n; ++i)
        {
            int rank = val_to_rank[nums[i]];
            st.connect_and_insert(rank, i);
        }
        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = dsu.max_val[dsu.find(i)];
        }
        return ans;
    }
};

// It is for testing and learning
// It is rough work