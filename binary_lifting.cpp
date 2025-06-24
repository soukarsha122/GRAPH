// kth ancestor in a tree

class TreeAncestor
{
    int MAX = 17;
    vector<vector<int>> table;

public:
    void build(vector<int> &parent)
    {
        table = vector<vector<int>>(MAX, vector<int>(parent.size()));
        for (int i = 0; i < parent.size(); i++)
        {
            table[0][i] = parent[i];
        }
        for (int level = 1; level < MAX; level++)
        {
            for (int node = 0; node < table[0].size(); node++)
            {
                int ancestor1 = table[level - 1][node];
                if (ancestor1 == -1)
                {
                    table[level][node] = -1;
                    continue;
                }
                int final_ancestor = table[level - 1][ancestor1];
                // int final_ancestor = table[level - 1][];
                table[level][node] = final_ancestor;
            }
        }
    }

    TreeAncestor(int n, vector<int> &parent)
    {
        build(parent);
    }

    int getKthAncestor(int node, int k)
    {
        int idx = 0;
        while (k > 0)
        {
            if (k % 2 == 1)
            {
                int par = table[idx][node];
                if (par == -1)
                    return -1;
                node = par;
            }
            k /= 2;
            idx++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */