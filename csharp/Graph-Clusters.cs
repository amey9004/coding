/*
 * https://www.hackerearth.com/code-monk-graph-theory-i/algorithm/kingdom-of-monkeys/
 */
 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cdoingCSharp
{
    public class Graph_Clusters
    {
        public static void Run()
        {
            var t = Int32.Parse(Console.ReadLine().Trim());
            while (t-- > 0)
            {
                var line = (Console.ReadLine().Trim().Split()).Select(x => Int32.Parse(x)).ToArray();
                var n = line[0];
                var m = line[1];
                var adjList = new List<List<int>>();
                while (m-- > 0)
                {
                    line = (Console.ReadLine().Trim().Split()).Select(x => Int32.Parse(x)).ToArray();
                    var cluster = adjList.Where(r => r.Contains(line[0]) || r.Contains(line[1]));
                    if (!cluster.Any())
                    {
                        var collection = new List<int>();
                        adjList.Add(collection);
                        collection.Add(line[0]);
                        collection.Add(line[1]);
                    }
                    else if (cluster.Count() == 1)
                    {
                        var collection = cluster.First();
                        collection.Add(line[0]);
                        collection.Add(line[1]);
                    }
                    else
                    {
                        cluster.First().AddRange(cluster.Last());
                        adjList.Remove(cluster.Last());
                    }
                }
                var bananas = (Console.ReadLine().Trim().Split()).Select(x => Int64.Parse(x)).ToArray();
                Int64 ans = 0;
                var visitedNodes = new List<Int64>();
                for (int i = 1; i <= n; i++)
                {
                    if (!visitedNodes.Contains(i))
                    {
                        Int64 lAns = 0;
                        var cluster = adjList.FirstOrDefault(r => r.Contains(i));
                        if (null == cluster)
                        {
                            lAns = bananas[i - 1];
                        }
                        else
                        {
                            foreach (var ele in cluster.Distinct())
                            {
                                lAns += bananas[ele - 1];
                                visitedNodes.Add(ele);
                            }
                        }
                        ans = lAns > ans ? lAns : ans;
                    }
                }
                Console.WriteLine(ans);
            }
        }
    }
}