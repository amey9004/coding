using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cdoingCSharp
{
    public static class DisjointSet_CityCramper
    {
        static void Execute()
        {
            var splits = Console.ReadLine().Split();
            int n = int.Parse(splits[0]);
            int q = int.Parse(splits[1]);
            int[] a = new int[n];
            int[] size = new int[n];
            for (int i = 0; i < n; i++)
            {
                size[i] = 1;
                a[i] = i;
            }

            while (q > 0)
            {
                q--;
                splits = Console.ReadLine().Split();
                int b = int.Parse(splits[0]);
                int c = int.Parse(splits[1]);
                b--; c--;
                int pb = GetParent(b, a);
                int pc = GetParent(c, a);
                Merge(pb, pc, a, size);
                int max = size.Max();
                int min = size.Where(t => t > 0).Min();
                Console.WriteLine(max - min);
            }
        }
        
        static void Merge(int a, int b, int[] parent, int[] size)
        {
            if (a == b)
            {
                return;
            }

            if (size[a] < size[b])
            {
                int t = a;
                a = b;
                b = t;
            }

            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }

        static int GetParent(int a, int[] parent)
        {
            while (parent[a] != a)
            {
                a = parent[a];
            }

            return a;
        }
    }

}