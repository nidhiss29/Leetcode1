class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr1.begin(), arr1.end(), [&](auto &a, auto &b)
             { return a < b; });
        sort(arr2.begin(), arr2.end(), [&](auto &a, auto &b)
             { return a < b; });
        int c = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            int val = arr1[i];
            int in = upper_bound(arr2.begin(), arr2.end(), val + d) - arr2.begin();
            int bn = lower_bound(arr2.begin(), arr2.end(), val - d) - arr2.begin();

            if (in == bn)
            {
                c++;
            }
        }
        return c;
    }
};
// ar1[i]-ar2[j]<=d