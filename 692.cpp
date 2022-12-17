class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (string s : words)
            m[s]++;

        vector<pair<string, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(),
             [](pair<string, int> a, pair<string, int> b)
             {
                 return (a.second != b.second) ? a.second > b.second : a.first < b.first;
             });

        vector<string> out;
        int cnt = 0;
        while (cnt < k)
        {
            out.push_back(v[cnt].first);
            cnt++;
        }
        return out;
    }
};