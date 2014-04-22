package com.levneiman.alg_cmp;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.levneiman.alg_cmp.Problems.GCJProblem;
import com.levneiman.alg_cmp.Problems.Problem;
import com.levneiman.alg_cmp.Problems.Util;
import com.levneiman.alg_cmp.Problems.Util.MultiMap;
import com.levneiman.alg_cmp.Problems.Util.Pair;

import static com.levneiman.alg_cmp.Problems.SO;

public class GCJ_CHINA_2014
{
    public static class A extends GCJProblem
    {

        boolean check(MultiMap<String,String> hate, String jerk, Boolean parentColor, Map<String, Boolean> group, HashSet<String> seen)
        {
            if (seen.contains(jerk))
            {
                return true;
            }
            seen.add(jerk);
            Boolean thisColor = group.get(jerk);
            if (thisColor == null) thisColor = (parentColor == null ? true : !parentColor);
            group.put(jerk, thisColor);
            SO.println(jerk + " ----> " + thisColor);
            if (parentColor != null && parentColor.equals(thisColor)) return false;

            for (String frienemy : hate.get(jerk))
            {
                if (group.get(frienemy) !=null)
                {
                    if(thisColor.equals(group.get(frienemy)))
                    {
                        return false;
                    }
                }
                if (!check(hate, frienemy, thisColor, group, seen))
                {
                    return false;
                }
            }
            return true;
        }

        @Override
        public String solve(Scanner in)
        {
            SO.println("=====");
            int M = in.nextInt();
            MultiMap<String,String> hate = new MultiMap<String,String>(MultiMap.<String>HASH_SET());

            for (int i = 0; i < M; ++i)
            {
                String a = in.next();
                String b = in.next();
                SO.println( String.format("%s - %s", a, b ));
                hate.put(a, b);
                hate.put(b, a);
            }

            boolean ret = true;
            HashMap<String,Boolean> group = new HashMap<String,Boolean>();
            HashSet<String> seen = new HashSet<String>();
            for (String jerk : hate.keySet())
            {
                ret &= check(hate, jerk, null, group, seen);
                SO.println(jerk + " -- " +ret);
                if (!ret) break;
            }
            SO.println(ret);
            return !ret ? "No" : "Yes";
        }
    }

    public static class B extends GCJProblem
    {

        static double a = -9.8;
        static double eps = 10-6;

        double distance(double V, double theta)
        {
            double Vx = Math.cos(theta)*V;
            double Vy = Math.sin(theta)*V;

            // double t = 0;
            //Vy*t = .5*a*t^2;
            //  t = (.5*a*t^2)/Vy;
          //  1 = (.5*a*t)/Vy;
           // t = Vy / (.5*a);

            double t = Vy / (.5*a);

            return Vx*t;
        }

        @Override
        public String solve(Scanner in)
        {
            int V, D;
            V = in.nextInt();
            D = in.nextInt();

            double aT = 90;
            double bT = 0;
            double d = distance(V, 45);
            while( Math.abs(d-D) > eps)
            {
                if (d < D)
                {

                }
            }

            return Double.toString(aT);
        }
    }

    public static class C extends GCJProblem
    {
        int bubbleSort(String [] arr, Map<String,Integer> finalPos)
        {
            int ret = 0;
            int N = arr.length;
            boolean done = false;
            while (!done)
            {
                done = true;
                for (int i = 1; i < N; ++i)
                {
                    if (arr[i].compareTo(arr[i-1]) < 0)
                    {
                        done = false;
                        int j = finalPos.get(arr[i]);
                        if ( i == j ) continue;
                        ++ret;
                        for (int k = i; k > j; --k)
                        {
                            Util.swap(arr, k, k-1);
                        }
                        SO.println(Util.PrettyPrint.print(arr));
                    }
                }
            }
            return ret;
        }

        @Override
        public String solve(Scanner in)
        {
            int N = Integer.parseInt(in.nextLine());
            String [] cards = new String[N];
            for (int i = 0; i < N; ++i)
            {
                cards[i] = in.nextLine();
                SO.println(cards[i]);
            }
            String [] sorted = cards.clone();
            Arrays.sort(sorted);
            Map<String,Integer> finalPos = new HashMap<String,Integer>();
            for (int i = 0; i < N; ++i)
            {
                finalPos.put(sorted[i], i);
            }
            return Integer.toString(bubbleSort(cards, finalPos));
        }

    }
}
