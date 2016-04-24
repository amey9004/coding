using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

namespace cdoingCSharp
{
    public class BitFlip
    {
        static int bitFlip(int[] arr)
        {
            int size = arr.Length;
            int count = 0;
            int max = 0;
            int ones = 0;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == 0)
                {
                    count++;
                }
                else
                {
                    if (count > max)
                    {
                        max = count;
                    }

                    ones++;
                    count--;
                    if (count <= 0)
                    {
                        count = 0;
                    }
                }
            }

            if (count > max)
            {
                max = count;
            }

            return ones + max;
        }
    }
}