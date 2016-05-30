using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdoingCSharp.Impementations
{
    public class Heap<T> where T : IComparable<T>
    {
        private List<T> arr = new List<T>();

        public virtual void Add(T input)
        {
            arr.Add(input);
            int pos = arr.Count - 1;
            while (pos > 0)
            {
                int parent = (pos - 1) / 2;
                if (arr[pos].CompareTo(arr[parent]) >= 0)
                {
                    break;
                }

                T temp = arr[pos];
                arr[pos] = arr[parent];
                arr[parent] = temp;
                pos = parent;
            }
        }

        public T Pop()
        {
            int size = arr.Count;
            if (size == 0)
            {
                return default(T);
            }

            T ret = arr[0];
            arr[0] = arr[size - 1];
            arr.RemoveAt(size - 1);
            int pos = 0;
            size = size--;
            while (pos < size)
            {
                int left = 2 * pos + 1;
                int right = 2 * pos + 2;
                int min = pos;
                if (left < size && arr[left].CompareTo(arr[min]) < 0)
                {
                    min = left;
                }
                if (right < size && arr[right].CompareTo(arr[min]) < 0)
                {
                    min = right;
                }

                if (min == pos)
                {
                    break;
                }

                T temp = arr[pos];
                arr[pos] = arr[min];
                arr[min] = temp;
                pos = min;
            }

            return ret;
        }

        public T Top()
        {
            if (arr.Count == 0)
            {
                return default(T);
            }

            return arr[0];
        }

        public int Count()
        {
            return arr.Count;
        }
    }
}