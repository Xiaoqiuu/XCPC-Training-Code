using System;

namespace codeforces.CFR993
{
    public class B
    {
        static string Reverse(string text) {
            char[] charArray = text.ToCharArray();
            string reverse = String.Empty;
            for (int i = charArray.Length - 1; i >= 0; i--) {
                reverse += charArray[i];
            }
            return reverse;
        }
        static void Main(string[] args)
        {
            int _ = int.Parse(Console.ReadLine());
            while (_-- > 0) {
                string s = Console.ReadLine();
                s = Reverse(s);
                foreach(char c in s)
                {
                    switch(c)
                    {
                        case 'q':
                            Console.Write('p');
                            break;
                        case 'p':
                            Console.Write('q');
                            break;
                        case 'w':
                            Console.Write('w');
                            break;
                    }
                }
                Console.WriteLine();
            }
        }
    }
}