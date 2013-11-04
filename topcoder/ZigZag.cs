using System;
using System.Collections.Generic;
using System.Text;
 
    class ZigZag
    {
        private static int _max;
 
        private static bool _lastPositive;
 
        private static int _index = 0;
 
        private static bool _first = true;
 
 
        private static bool DiffPositive(int X, int Y)
        {
            return (Y - X) > 0;
        }
 
        private static void Check(int[] sequence)
        {
            if (_index + 1 == sequence.Length)
            {
                _max++;
 
                return;
            }
 
            bool diffPos = DiffPositive(sequence[_index], sequence[_index + 1]);
 
            if (diffPos != _lastPositive || _first)
            {
                _max++;
 
                _lastPositive = diffPos;
            }
 
            _first = false;
 
            _index++;
 
            Check(sequence);
        }
 
        public int longestZigZag(int[] sequence)
        {
               Check( sequence );
               return _max;
        }
    }



// Powered by FileEdit
