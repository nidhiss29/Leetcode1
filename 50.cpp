class Solution
{
public:
    double myPow(double x, int n)
    {
        /*       double ans;

               if(x<100 || x>-100){
                   ans = pow(x,n);
               }
              return ans;

          // or
           double ans = 1.0;   //O(n)
             for (int i = 0; i < n; i++) {
               ans = ans * x; */

        // binary exponentiation dpnd on whether k even or odd
        // If k is even (nk) can be written as  (n2)k/2. As we can see that computation steps were reduced from k to k/2 in just one step. If k is odd (nk) can be written as n.(n)k-1, so now  (k-1) is even.

        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};