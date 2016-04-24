/*
 * https://www.hackerearth.com/problem/algorithm/2-vs-3/description/
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{
    class SegTree_Modulo3
    {
        static int[] tree;
        static int[] arr;
        public static void Run()
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            arr = new int[n];
            var level = (int)(Math.Ceiling(Math.Log(n, 2)) + 1);
            tree = new int[(1<<level) - 1];
            for (int i = 0; i < n; i++)
            {
                var c = Console.Read() - '0';
                var num = Int32.Parse(c.ToString());
                arr[i] = num;
            }
            Console.ReadLine();
            BuildSegTree(0, n, 0);
            var q = Int32.Parse(Console.ReadLine().Trim());
            while (q-- > 0)
            {
                var line = Console.ReadLine().Trim();
                var args = Array.ConvertAll(line.Split(), Int32.Parse);
                if (args[0] == 0)
                {
                    int ans = Query(0, n, args[1], args[2] + 1, 0);
                    Console.WriteLine(ans);
                }
                else
                {
                    if (arr[args[1]] == 0)
                    {
                        arr[args[1]] = 1;
                        Update(args[1], 0, n, 0);
                    }
                }
            }
        }

        public static void Update(int index, int start, int end, int treeIndex)
        {
            if (end - start == 1)
            {
                tree[treeIndex] = 1;
                return;
            }
            var mid = start + (end - start + 1) / 2;
            if (index >= mid)
            {
                Update(index, mid, end, (2 * treeIndex + 2));
            }
            else
            {
                Update(index, start, mid, (2 * treeIndex + 1));
            }

            var left = tree[2 * treeIndex + 1] == 0 ? 0 : ((end - mid) % 2) == 0 ? tree[2 * treeIndex + 1] : 3 - tree[2 * treeIndex + 1];
            tree[treeIndex] = (left + tree[2 * treeIndex + 2]) % 3;
            return;
        }

        public static int Query(int start, int end, int l, int r, int treeIndex)
        {
            if (start == l && end == r)
            {
                return tree[treeIndex];
            }
            var mid = start + (end - start + 1) / 2;
            if (l >= mid)
            {
                return Query(mid, end, l, r, 2 * treeIndex + 2);
            }
            else if (r <= mid)
            {
                return Query(start, mid, l, r, 2 * treeIndex + 1);
            }
            else
            {
                int leftVal = Query(start, mid, l, mid, 2 * treeIndex + 1);
                int rightVal = Query(mid, end, mid, r, 2 * treeIndex + 2);
                leftVal = leftVal == 0 ? 0 :((end - mid) % 2 == 0) ? leftVal : 3 - l;
                return (r + leftVal) % 3;
            }
        }

        public static void BuildSegTree(int start, int end, int index)
        {
            if (end <= start)
            {
                throw new InvalidOperationException();
            }
            if (end - start == 1)
            {
                 tree[index] = arr[start];
                 return;
            }
            var mid = start + ((end - start + 1)) / 2;
            BuildSegTree(start, mid, (2 * index + 1));
            BuildSegTree(mid, end, (2 * index + 2));
            var leftVal = ((end - mid) % 2) == 0 ? tree[2 * index + 1] : 3 - tree[2 * index + 1];
            tree[index] = (leftVal + tree[2 * index + 2]) % 3;
        }
    }
}