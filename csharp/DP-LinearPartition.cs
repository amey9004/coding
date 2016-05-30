using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{
    static class DP_LinearPartition
    {
        // https://www.hackerearth.com/may-circuits/algorithm/booboo-and-upsolving-circuits/

        static void Problem2()
        {
            var splits = Console.ReadLine().Split();
            int n = int.Parse(splits[0]);
            int m = int.Parse(splits[1]);
            splits = Console.ReadLine().Split();
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = long.Parse(splits[i]);
            }

            long[,] DP = new long[n, m];
            long sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                DP[i, 0] = sum;
            }

            for (int i = 0; i < m; i++)
            {
                DP[0, i] = a[0];
            }

            int[,] pos = new int[n, m];
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    long localSum = long.MaxValue;
                    int p = -1;
                    for (int k = 0; k < j; k++)
                    {
                        long lastPart = DP[j, 0] - DP[k, 0];
                        long max = lastPart > DP[k, i - 1] ? lastPart : DP[k, i - 1];
                        if (max < localSum)
                        {
                            localSum = max;
                            p = k;
                        }
                    }
                    DP[j, i] = localSum;
                    pos[j, i] = p;
                }
            }

            Console.WriteLine(DP[n - 1, m - 1]);
        }
    }
}
