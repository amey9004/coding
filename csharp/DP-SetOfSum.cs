/// given a   positive integer n print all distinct ordered sets of positive integer which have sum equal n. 
/// eg:- for n=2 output: { [1, 1] } for n=3 output: { [1, 1, 1], [1, 2], [2, 1] } 
/// for n=4 output: { [1, 1, 1, 1], [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2], [1, 3], [3, 1] }
namespace cdoingCSharp
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public class DP_SetOfSum
    {
        public static void Solve(int n)
        {
            if (n <= 1)
            {
                throw new ArgumentException();
            }

            var compare = new ListCompare();
            HashSet<List<int>> sets = new HashSet<List<int>>();
            sets.Add(new List<int> { 1, 1 });
            for (int i = 3; i <= n; i++)
            {
                HashSet<List<int>> currSets = new HashSet<List<int>>(compare);
                foreach (var l in sets)
                {
                    for (int j = 0; j <= l.Count; j++)
                    {
                        var templ = new List<int>(l);
                        templ.Insert(j, 1);
                        if (!currSets.Contains(templ))
                        {
                            currSets.Add(templ);
                        }

                        if (j < l.Count)
                        {
                            templ = new List<int>(l);
                            templ[j] = templ[j] + 1;
                            if (!currSets.Contains(templ))
                            {
                                currSets.Add(templ);
                            }
                        }
                    }
                }

                sets = currSets;
            }

            foreach (var l in sets)
            {
                Console.Write("{");
                foreach (var item in l)
                {
                    Console.Write(item + ",");
                }
                Console.Write("}\n");
            }
        }
    }

    public class ListCompare : EqualityComparer<List<int>>
    {
        public override bool Equals(List<int> l1, List<int> l2)
        {
            if (l1.Count != l2.Count)
            {
                return false;
            }

            return l1.SequenceEqual(l2);
        }


        public override int GetHashCode(List<int> s)
        {
            return base.GetHashCode();
        }
    }
}