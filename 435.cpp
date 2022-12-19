class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());
        int c = 1;
        int mn = arr[0][1];
        for (int i = 0; i < arr.size(); i++)
        {
            if (mn > arr[i][0])
            {
                mn = min(mn, arr[i][1]);
            }
            else
            {
                c++;
                mn = arr[i][1];
            }
        }
        return arr.size() - c;
    }
};