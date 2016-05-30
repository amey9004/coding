using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{
    // https://www.hackerearth.com/code-monk-bit-manipulation/algorithm/monk-in-the-magical-land/
    // could have been solved with bit mask
    class Greedy_Numbers
    {
        static int GetGcd(int u, int v)
        {
            return (v != 0) ? GetGcd(v, u % v) : u;
        }

        static void Solve(string[] args)
        {
            int t = int.Parse(Console.ReadLine().Trim());
            while (t-- > 0)
            {
                var splits = Console.ReadLine().Split();
                int n = int.Parse(splits[0]), m = int.Parse(splits[1]), k = int.Parse(splits[2]);
                int[] keys = new int[n];
                int[] cost = new int[m];
                int[] award = new int[m];
                var splits2 = Console.ReadLine().Split().Select(int.Parse).ToList();
                for (int i = 0; i < n; i++)
                {
                    keys[i] = splits2[i];
                }
                splits2 = Console.ReadLine().Split().Select(int.Parse).ToList();
                var splits3 = Console.ReadLine().Split().Select(int.Parse).ToList();
                for (int i = 0; i < m; i++)
                {
                    cost[i] = splits2[i];
                    award[i] = splits3[i];
                }

                List<List<int>> coprimes = new List<List<int>>();

                for (int i = 0; i < n; i++)
                {
                    var list = new List<int>();
                    for (int j = 0; j < m; j++)
                    {
                        int gcd = keys[i] > cost[j] ? GetGcd(keys[i], cost[j]) : GetGcd(cost[j], keys[i]);
                        if (gcd > 1)
                        {
                            list.Add(j);
                        }
                    }

                    coprimes.Add(list);
                }

                int ans = 0;
                var print = true;
                while (m > 0 && k > 0)
                {
                    int num = -1;
                    int sum = 0;
                    for (int i = 0; i < n; i++)
                    {
                        int s = 0;
                        foreach (var e in coprimes[i])
                        {
                            s += award[e];
                        }

                        if (s > sum)
                        {
                            sum = s;
                            num = i;
                        }
                    }

                    if (num == -1)
                    {
                        print = false;
                        Console.WriteLine(ans);
                        break;
                    }

                    var nums = new List<int>(coprimes[num]);
                    ans += sum;
                    for (int i = 0; i < n; i++)
                    {
                        coprimes[i].RemoveAll(ele => nums.Contains(ele));
                    }

                    m -= nums.Count;
                    k--;
                }

                if (print)
                {
                    Console.WriteLine(ans);
                }
            }
        }
    }
}
