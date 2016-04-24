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
            Bts("84 o150 01101001 x73 x20 x63 x6f o165 108 01100100 00100000 01100010 01100101 o40 x74 01101000 01100101 o40 o153 x65 01111001 x20 116 x6f o40 121 x6f 117 x72 o40 o143 o150 97 x6c x6c 101 01101110 01100111 x65 x3a 00100000 01100100 69 x67 o172 01001010 71 01101000 112 01001101 50 x78 o105 o141 o123 01010010 x6b 01001101 01001000 01100100 01110101 01011000 o62 01011010 65 x5a x44 o153 o172 01100100 00110010 82 x6d o143 01100111 o75 x3d");
        }

        static bool IsValid(string s)
        {
            if (s.Contains("'")){
                return false;
            }

            return true;
        }

        static void Bts(string input)
        {
            var splits = input.Split();
            string output =string.Empty;
            foreach(var s in splits){
                int num;
                if (!int.TryParse(s, out num))
                {
                    if (s.StartsWith("x"))
                    {
                        num = Convert.ToInt16(s.Substring(1), 16);
                    }
                    else if (s.StartsWith("o"))
                    {
                        num = Convert.ToInt16(s.Substring(1), 8);
                    }
                }
                else if (s.Length > 4)
                {
                     num = Convert.ToInt16(s, 2);
                }
                output = output + num + " ";
            }

            splits = output.Split();
            string answer = string.Empty;
            foreach (var s in splits)
            {
                if (string.IsNullOrWhiteSpace(s))
                {
                    continue;
                }
                answer += Convert.ToChar(int.Parse(s));
            }
        }

    }
}

