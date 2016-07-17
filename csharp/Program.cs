using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{

    class Program
    {
        static void Main(string[] args)
        {
            Solve();
        }

        public static void Solve()
        {
            short key = short.Parse(Console.ReadLine().Trim());
            string line = Console.ReadLine().Trim();
            int answer = 0;
            for (int i = 0; i < line.Length; i++)
            {
                int dist = 0;
                int[] hash = new int[26];
                for (int k = 0; k < 26; k++)
                {
                    hash[k] = 0;
                }
                for (int j = i; j < line.Length; j++)
                {
                    int num = line[j] - 'a';
                    if (hash[num] == 0)
                    {
                        dist++;
                        hash[num] = 1;
                    }
                    if (dist == key)
                    {
                        answer++;
                    }
                }
            }

            Console.WriteLine(answer);
        }
    }
}
