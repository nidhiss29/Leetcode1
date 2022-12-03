class Solution
{
public:
    int tribonacci(int n)
    {
        /*      if(n<2) return n;
              if(n==2) return 1;
              int t0 = 0,t1=1,t2=1;
              int tn=0;
              for(int i = 2;i<n;i++){
                  tn= t0+t1+t2;
                  t0 = t1;
                  t1 = t2;
                  t2= tn;
              }
              return tn;    */

        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> v(n + 1, 0);
        v[0] = 0, v[1] = 1, v[2] = 1;
        for (int i = 3; i <= n; i++)
            v[i] = v[i - 1] + v[i - 2] + v[i - 3];

        return v[n];
    }
};