class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        // 1. normal search in 2d matrix each element O(m*n)

        /*     vector< vector<int> >::const_iterator row;
               for (row = matrix.begin(); row != matrix.end(); row++) {
                if(find(row->begin(), row->end(), target) != row->end() )
                    return true;  }
            return false;     */

        // 2. Or n(logm) complexity as each row sorted so go to each row one by one and by binary search find value row wise

        /*      vector< vector<int> >::const_iterator row;
               for (row = matrix.begin(); row != matrix.end(); row++) {
                   if (binary_search(row->begin(), row->end(), target))
                   { return true;
                       break; }
                   else
                       continue; }
             return false;   */

        // 3. Optimal

        // as all values are sorted in rows and in columns so if 40 last element of row and to search 25 we go to its left if need to search 45 go in its column or move ptr left and downward as required take i and j gfg question.
        // but here in leetcode prblm first integer of row> last integer of prev so it acts as a sorted array.

        int lo = 0;
        if (!matrix.size())
            return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;

        while (lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
            {
                return true;
            }
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return false;
    }
};