class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        // or      return distance (A.begin (), max_element (A.begin (), A.end ()));

        int maxi = 0;
        int idx = 0;
        int n = arr.size();
        for (int i = 1; i <= n - 2;)
        {
            if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
            {
                int g = i;
                int c = 1;
                int j = i;
                while (j >= 1 && arr[j - 1] < arr[j])
                    c++, j--;
                while (i <= n - 2 && arr[i] > arr[i - 1])
                    c++, i++;

                if (maxi < c)
                {
                    idx = g;
                    maxi = c;
                }
            }
            else
                i++;
        }

        return idx;
    }
};