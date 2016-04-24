/*
 * https://www.hackerearth.com/gieom-hiring-challenge/problems/cabce62d1124418296d5727b49ec5119/
 * https://www.hackerearth.com/gieom-hiring-challenge/problems/e37847102e5a41a880b090f9aeaede06/
 * */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp
{
    public class Stack_Paranthesis
    {
        public static void Execute()
        {
            var line1 = System.Console.ReadLine().Trim();
            var N = Int32.Parse(line1);
            while (N-- > 0)
            {
                var line2 = System.Console.ReadLine().Trim();
                var output = line2;
                int val = 0;
                foreach (var ch in line2)
                {
                    if (ch == ')')
                    {
                        val--;
                        if (val < 0)
                        {
                            output = '(' + output;
                            val = 0;
                        }
                    }
                    else
                    {
                        val++;
                    }
                }
                while (val-- > 0)
                {
                    output = output + ')';
                }

                Console.WriteLine(output);
            }
        }

        public static void Execute2()
        {
            var line1 = System.Console.ReadLine().Trim();
            var N = Int32.Parse(line1);
            while (N-- > 0)
            {
                var str = System.Console.ReadLine().Trim();
                var weights = Array.ConvertAll(System.Console.ReadLine().Trim().Split(), int.Parse);
                var UniqueWords = new HashSet<char>();
                double score = 0, tw = 0;
                foreach (char ch in str)
                {
                    if (!UniqueWords.Contains(ch))
                    {
                        UniqueWords.Add(ch);
                        tw = tw + weights[ch - 'a'];
                    }
                    score += weights[ch - 'a'];
                }
                score = 10 * score / (tw * str.Length);
                Console.WriteLine(Math.Round(score, 2));
            }
        }

    }
}
