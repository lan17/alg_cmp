package com.levneiman.alg_cmp;
import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.lang.reflect.Array;
import java.math.*;

import java.awt.geom.*;

/**
 * Google Code Jam problems solved (sometimes incorrectly) by Lev. A. Neiman.
 *
 * @author Lev Neiman - lev.neiman@gmail.com
 *
 */
public class Problems
{

	public static PrintStream SO = System.out;

	public interface Problem
	{
		public void solve( InputStream in, PrintStream out ) throws Exception;
	}

	public interface acm_problem extends Problem
	{

	}

	public interface facebook_problem extends Problem
	{
	}

	public static class facebook_problems
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

	public static class Util< T >
	{

		public static class Pair< T, U >
		{
			private final T first;
			private final U second;
			private transient final int hash;

			public Pair( T f, U s )
			{
				this.first = f;
				this.second = s;
				hash = ( first == null ? 0 : first.hashCode() * 31 )
						+ ( second == null ? 0 : second.hashCode() );
			}

			@Override
			public boolean equals( Object oth )
			{
				if( this == oth )
				{
					return true;
				}
				if( oth == null || !( getClass().isInstance( oth ) ) )
				{
					return false;
				}
				Pair< T, U > other = getClass().cast( oth );
				return ( first == null ? other.first == null : first
						.equals( other.first ) )
						&& ( second == null ? other.second == null : second
								.equals( other.second ) );
			}

			public T getFirst()
			{
				return first;
			}

			public U getSecond()
			{
				return second;
			}

			@Override
			public int hashCode()
			{
				return hash;
			}

		}

		public static class Primes
		{
			public static boolean [] primes = null;

			public static boolean [] prime_numbers( int lim )
			{
				if( primes != null )
					return primes;
				primes = new boolean[lim];
				for( int i = 0; i < lim; ++i )
					primes[i] = true;
				primes[0] = primes[1] = false;
				for( int k = 2; k < lim; ++k )
					if( primes[k] )
						for( int c = 2; c * k < lim; ++c )
							primes[c * k] = false;

				return primes;
			}

			public void testPrimes()
			{
				boolean [] p = prime_numbers( ( int ) 1e6 );
				for( int i = 0; i < 100; ++i )
					if( p[i] )
						System.out.println( i );
			}
		}

		public static class TrivialComporator< T > implements Comparator
		{
			@Override
            public int compare( Object a, Object b )
			{
				if( a instanceof Comparable && b instanceof Comparable )
					return ( ( Comparable ) a ).compareTo( b );
				throw new IllegalArgumentException(
						"passed arguments are not Comparable!" );
			}
		}

		/**
		 * Convert number in given base given as a string into base 10.
		 *
		 * @param numb
		 * @param base
		 * @return
		 */
		public static int convert( String numb, int base )
		{
			int ret = 0;
			int c = 0;
			for( int i = numb.length() - 1; i >= 0; --i )
			{
				ret += Math.pow( base, c ) * ( numb.charAt( i ) - 48 );
				++c;
			}
			return ret;
		}

		public static void main( String [] arg )
		{
			Integer [] a = { 0, 1, 2, 3 };
			reverseArray( a, 0, a.length );
			System.out.println( Arrays.toString( a ) );
		}

		public static boolean next_permutation( Comparable [] s )
		{
			int i = -1, j = 0;

			for( int x = s.length - 2; x >= 0; x-- )
				if( s[x].compareTo( s[x + 1] ) < 0 )
				{
					i = x;
					break;
				}

			if( -1 == i )
				return false;

			for( int x = s.length - 1; x > i; x-- )
				if( s[x].compareTo( s[i] ) > 0 )
				{
					j = x;
					break;
				}

			// Swapping elements pointed by i and j;
			swap( s, i, j );

			// Reversing elements after i

			reverseArray( s, i + 1, s.length - ( i + 1 ) );
			return true;
		}

		public static < T > boolean next_permutation( T [] s,
				Comparator< T > comp )
		{

			int i = -1, j = 0;

			for( int x = s.length - 2; x >= 0; x-- )
				if( comp.compare( s[x], s[x + 1] ) < 0 )
				{
					i = x;
					break;
				}

			if( -1 == i )
				return false;

			for( int x = s.length - 1; x > i; x-- )
				if( comp.compare( s[x], s[i] ) > 0 )
				{
					j = x;
					break;
				}

			// Swapping elements pointed by i and j;
			swap( s, i, j );

			// Reversing elements after i

			reverseArray( s, i + 1, s.length - ( i + 1 ) );
			return true;
		}

		public static < T > void reverseArray( T [] a, int start, int length )
		{
			int end = start + length - 1;
			while( start < end )
			{
				swap( a, start++, end-- );
			}
		}

		public static String Stream2String( InputStream is ) throws IOException
		{
			String ret = "";
			while( is.available() > 0 )
			{
				byte [] buff = new byte[is.available()];
				is.read( buff );
				String t = new String( buff );
				ret += t;
			}
			return ret;
		}

		public static < T > void swap( T [] a, int i, int k )
		{
			T t = a[i];
			a[i] = a[k];
			a[k] = t;
		}

	}


	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main( String [] args )
	{
		try
		{
			solveProblem(
					new GCJ_2014.QualificationRound.D(),
					"input.txt", "output.txt" );
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
	}

	public static void solveProblem( Problem prob, String input_file,
			String output_file ) throws Exception
	{
		boolean gcj_problem = true;

		PrintStream out;
		InputStream in;
		if( prob instanceof acm_problem )
		{
			in = System.in;
			out = System.out;
			gcj_problem = false;
		}
		else
		{
			in = new FileInputStream( input_file );
			if( !( prob instanceof facebook_problem ) )
			{
				FileOutputStream ofs = new FileOutputStream( output_file );
				out = new PrintStream( ofs );
			}
			else
			{
				out = System.out;
				gcj_problem = false;
			}
		}

		long start = System.currentTimeMillis();
		prob.solve( in, out );
		long end = System.currentTimeMillis();
		double duration = ( end - start ) / 1e3;

		if( gcj_problem )
			System.out.println( "Problem was solved in " + duration
					+ " seconds." );
	}
}