package com.levneiman.alg_cmp;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

import com.levneiman.alg_cmp.Problems.Util;
import com.levneiman.alg_cmp.Problems.facebook_problem;


public class facebook_problems
{
    public static class liarliar implements facebook_problem
    {

        boolean find_liars( Map< String, Set< String >> people,
                Set< String > peeps, Set< String > liars,
                Set< String > truthers, String liar )
        {
            if( !peeps.contains( liar ) )
                return false;
            System.out.println( "LIAR ! " + liar );
            peeps.remove( liar );
            liars.add( liar );
            for( String truthee : people.get( liar ) )
            {
                if( liars.contains( truthee ) )
                    return false;
                System.out.println( "TRUTHER ! " + truthee );
                truthers.add( truthee );
                peeps.remove( truthee );
                for( String liarz : people.get( truthee ) )
                {
                    find_liars( people, peeps, liars, truthers, liarz );
                }
            }
            return true;
        }

        void printPeople( Map< String, Set< String >> people )
        {
            for( String person : people.keySet() )
            {
                System.out.println( person + ":" );
                for( String liar : people.get( person ) )
                {
                    System.out.println( "\t" + liar );
                }
            }
        }

        @Override
        public void solve( InputStream inFile, PrintStream out )
                throws Exception
        {
            String input = Util.Stream2String( inFile );
            StringTokenizer tokenizer = new StringTokenizer( input, " \n\r" );
            int n;
            Map< String, Set< String >> people = new HashMap< String, Set< String >>();
            Set< String > peeps = new HashSet< String >();
            n = Integer.parseInt( tokenizer.nextToken() );
            String first_liar = null;
            while( tokenizer.hasMoreTokens() )
            {
                String name = tokenizer.nextToken();
                peeps.add( name );
                int m = Integer.parseInt( tokenizer.nextToken() );
                if( m > 0 && first_liar == null )
                    first_liar = name;
                Set liars = new HashSet< String >();
                people.put( name, liars );
                for( int i = 0; i < m; ++i )
                {
                    liars.add( tokenizer.nextToken() );
                }
            }
            // printPeople( people );
            Set< String > liars, goodies;
            liars = new HashSet< String >();
            goodies = new HashSet< String >();
            find_liars( people, peeps, liars, goodies, first_liar );
            while( peeps.size() > 0 )
            {
                String liar = peeps.iterator().next();
                find_liars( people, peeps, liars, goodies, liar );
            }
            System.out.print( Math.max( liars.size(), goodies.size() )
                    + " " );
            System.out.print( Math.min( liars.size(), goodies.size() ) );

        }

    }
}