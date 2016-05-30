using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp.Impementations
{
    public static class MinHeap
    {
        private static Heap<Element> priorityQ = new Heap<Element>();
    }

    internal class Element : IComparable<Element>
    {
        private int data;

        public Element(int val)
        {
            data = val;
        }

        public int CompareTo(Element second)
        {
            return this.data.CompareTo(second.data);
        }
    }
}
