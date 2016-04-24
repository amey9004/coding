/*
 * 
 */ 

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace cdoingCSharp
{
    public class BitMask_CatepillarNum
    {
        static int countUneatenLeaves(int N, int[] A)
        {
            long ans = 0;
            int size = A.Length;
            int bitmask = 1 << size;
            for (int i = 1; i < bitmask; i++)
            {
                bool isOdd = false;
                long lcm = 1;
                for (int j = 0; j < size; j++)
                {
                    if (((1 << j) & i) != 0)
                    {
                        isOdd = !isOdd;
                        lcm = LCM(lcm, A[j]);
                    }
                }

                ans = isOdd ? ans + (N / lcm) : ans - (N / lcm);
            }
            return (int)(N - ans);
        }

        static long GCD(long a, long b)
        {
            return (b > 0 ? GCD(b, a % b) : a);
        }

        static long LCM(long a, long b)
        {
            return (a / GCD(a, b)) * b;
        }

    }
}