package com.levneiman.alg_cmp;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

import com.levneiman.alg_cmp.Problems.Util;
import com.levneiman.alg_cmp.Problems.acm_problem;

public class ACM_Problems
{
    public static class Codeforces
    {
        public static class Round12
        {
            public static class CorrectSolution implements acm_problem
            {

                @Override
                public void solve( InputStream in, PrintStream out )
                        throws Exception
                {
                    Scanner scanner = new Scanner( in );
                    String a = scanner.nextLine();
                    String b = scanner.nextLine();
                    if( a.length() != b.length() )
                    {
                        out.println( "WRONG_ANSWER" );
                        return;
                    }

                    Integer [] a_int = new Integer[a.length()];
                    for( int i = 0; i < a_int.length; ++i )
                        a_int[i] = a.charAt( i ) - '0';
                    Arrays.sort( a_int );
                    // System.out.println( Arrays.toString( a_int ) );

                    while( a_int[0] == 0
                            && Util.next_permutation( a_int,
                                    new Util.TrivialComporator< Integer >() ) )
                        ;

                    // System.out.println( Arrays.toString( a_int ) );
                    for( int i = 0; i < a_int.length; ++i )
                    {
                        if( b.charAt( i ) - '0' != a_int[i] )
                        {
                            out.println( "WRONG_ANSWER" );
                            return;
                        }
                    }
                    out.println( "OK" );
                }
            }

            public static class SuperAgent implements acm_problem
            {

                @Override
                public void solve( InputStream in, PrintStream out )
                        throws Exception
                {
                    Scanner scanner = new Scanner( in );
                    String combo[] = new String[3];
                    combo[0] = scanner.nextLine();
                    combo[1] = scanner.nextLine();
                    combo[2] = scanner.nextLine();
                    for( int i = 0; i < 3; ++i )
                    {
                        for( int j = 0; j < 3; ++j )
                        {
                            if( combo[i].charAt( j ) != combo[2 - i]
                                    .charAt( 2 - j ) )
                            {
                                System.out.print( "NO" );
                                return;
                            }
                        }
                    }
                    System.out.print( "YES" );
                }

            }
        }

        public static class Round9

        {
            public static class A implements acm_problem
            {

                @Override
                public void solve( InputStream in, PrintStream out )
                        throws Exception
                {
                    Scanner scanner = new Scanner( in );
                    Integer Y, W;
                    Y = scanner.nextInt();
                    W = scanner.nextInt();
                    Integer M = Math.max( Y, W );
                    if( M == 1 )
                    {
                        out.println( "1/1" );
                    }
                    if( M == 2 )
                    {
                        out.println( "5/6" );
                    }
                    if( M == 3 )
                    {
                        out.println( "2/3" );
                    }
                    if( M == 4 )
                    {
                        out.println( "1/2" );
                    }
                    if( M == 5 )
                    {
                        out.println( "1/3" );
                    }
                    if( M == 6 )
                    {
                        out.println( "1/6" );
                    }
                }
            }
        }
    }
}


