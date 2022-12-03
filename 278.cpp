// https://www.youtube.com/watch?v=SiDMFIMldgg reference

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {

        // brute approach but a lot of api calls not feasable time exceed
        /*    long  int min = n;
              bool ans;
              while(n!=0){
                  ans = isBadVersion(n);
              if(ans == true){
                  if(n<min)
                      min = n;
                      n = n-1;
              }
              else
                 n = n-1;
              }
              return min; */

        // can do binary search here as all bad and good are sorted g,g,b,b,b so low , high,and mid find a mid , if mid==bad then change high to mid-1 as lowest bad needed . simple binary search implementation
        long int low = 0, high = n, mid = 0;
        long int min = n;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isBadVersion(mid))
            {
                min = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return min;
    }
};