class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int pt1 = 0;
        int pt2 = 0;
        vector<vector<int>> ans;
        while (pt1 < A.size() && pt2 < B.size())
        {
            if (A[pt1][1] >= B[pt2][1])
            {
                if (B[pt2][1] >= A[pt1][0])
                {
                    ans.push_back(
                        {max(A[pt1][0], B[pt2][0]), B[pt2][1]});
                }
                ++pt2;
            }
            else if (A[pt1][1] < B[pt2][1])
            {
                if (A[pt1][1] >= B[pt2][0])
                {
                    ans.push_back(
                        {max(A[pt1][0], B[pt2][0]),
                         A[pt1][1]});
                }
                ++pt1;
            }
        }
        return ans;
    }
};

//[[0,2],[5,10],[13,23],pt2[24,25]]

// [[1,5],[8,12],[15,24],pt1[25,26]]

// ans = [1,2] , [5,5] , [8,10] , [15,23] , [24,24] , [25,25]
