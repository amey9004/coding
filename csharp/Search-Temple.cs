using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{
    // https://www.hackerearth.com/problem/algorithm/the-enlightened-ones/description/
    public class Search_Temple
    {
        private static List<int> temples;

        public static void Solve(){
            int n, k;
            var splits = Console.ReadLine().Split();
            n = int.Parse(splits[0].Trim());
            k = int.Parse(splits[1].Trim());
            temples = Console.ReadLine().Split().Select(int.Parse).ToList();
            temples.Sort();
            int l = 1, r = 10000000;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                var valid = IsValid(mid, k);
                if (valid)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            Console.WriteLine(l);
        }

        private static bool IsValid(int val, int k)
        {
            int i = 0;
            while (k > 0)
            {
                int current = temples[i] + val;
                while (i < temples.Count && temples[i] <= current + val)
                {
                    i++;
                }
                if (i == temples.Count)
                {
                    return true;
                }

                k--;
            }

            return false;
        }
    }
}
