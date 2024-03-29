class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        vector<int> closestFromLeft = vector<int>(s.size(), 0);
        vector<int> closestFromRight = vector<int>(s.size(), 0);
        vector<int> sums = vector<int>(s.size(), 0);

        int sum = 0;
        int closest = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '|')
                closest = i;
            closestFromLeft[i] = closest;

            if (s[i] == '*')
                sum++;
            sums[i] = sum;
        }

        closest = s.size();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '|')
                closest = i;
            closestFromRight[i] = closest;
        }

        vector<int> res;
        for (auto query : queries)
        {
            int start = closestFromRight[query[0]];
            int end = closestFromLeft[query[1]];
            int curr = end > start ? sums[end] - sums[start] : 0;
            res.push_back(curr);
        }

        return res;
    }
};