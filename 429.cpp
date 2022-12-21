/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return vector<vector<int>>();

        queue<Node *> q;

        q.push(root);
        q.push(NULL);

        vector<int> v;
        vector<vector<int>> ans;

        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();

            if (t)
            {
                v.push_back(t->val);

                for (int i = 0; i < t->children.size(); i++)
                {
                    if (t->children[i])
                        q.push(t->children[i]);
                }
            }
            else
            {
                ans.push_back(v);
                v.clear();

                if (q.empty())
                    break;

                q.push(NULL);
            }
        }

        return ans;
    }
};
