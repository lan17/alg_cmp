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

	public static PrintStream dOut = System.out;
	
	public interface Problem
	{
		public void solve( InputStream in, PrintStream out ) throws Exception;
	}

	public interface acm_problem extends Problem
	{

	}

	public static class ACM_Problems
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
							a_int[i] = ( int ) a.charAt( i ) - '0';
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
	

	public static class GCJ_2013
	{
		public static class QualificationRound
		{
			public static class A implements Problem
			{
				int dx[] = {1,-1,1,0};
				int dy[] = {1, 1,0,1};
				
				String solve( String[] board )
				{
					String ret="Game has not completed";
					boolean someEmpty = false;
					boolean done = false;
					boolean won = false;
					for( int i = 0; i < 4; ++i )
					{
						for( int j = 0; j < 4; ++j )
						{
							char c = board[i].charAt( j ); 
							if( c == '.' )
							{
								someEmpty = true;
							}
							else
							{
								for (int k = 0; k < 4; ++k )
								{
									int ii = i + dx[k];
									int jj = j + dy[k];
									int cnt = 1;
									while( ii >= 0 && ii < 4 && jj >= 0 && jj < 4 )
									{
										char cc = board[ii].charAt( jj );
										if( c == 'T' )
										{
											c = cc;
										}
										else
										{
											if( cc != 'T' )
												if(cc != board[ii-dx[k]].charAt(jj-dy[k]))
													break;
										}
										++cnt;
										ii += dx[k];
										jj += dy[k];
									}
									if( cnt == 4 )
									{
										ret = c == 'X' ? "X won" : "O won";
										won = done = true;
										break;
									}
								}
							}
							if( done )
								break;
						}
						if( done )
							break;
					}
					if( ! won && ! someEmpty )
						ret = "Draw";
					return ret;
				}
				
				@Override
				public void solve( InputStream in, PrintStream out )
						throws Exception
				{
					Scanner scanner = new Scanner(in);
					int T = scanner.nextInt();
					dOut.println( T );					
					for( int CASE = 1; CASE <= T; ++CASE )
					{
						String board [] = new String[4];
						scanner.nextLine();
						for( int i = 0; i < 4; ++i )
						{
							board[i] = scanner.nextLine();
							dOut.println( board[i] );
						}
						String ans = String.format( "Case #%d: %s", CASE, solve(board) );
						dOut.println( ans );
						out.println(ans);
					}
					
				}
				
			}
			
			public static class B implements Problem
			{
				boolean checkRow( int i, int j, int board[][], int N, int M, int maxRow[], int maxCol[] )
				{					
					int n = board[i][j];
					int nn = board[i][maxRow[i]];
					return nn <= n;
					/*
					for( int jj = 0; jj < M; ++jj  )
					{
						if( board[i][jj] > n )
							return false;
					}
					*/
					
					
				//	return true;
				}
				
				boolean checkCol( int i, int j, int board[][], int N, int M, int maxRow[], int maxCol[] )
				{					
					int n = board[i][j];
					int nn = board[maxCol[j]][j];
					return nn <= n;
					/*
					for( int ii = 0; ii < N; ++ii  )
					{
						if( board[ii][j] > n )
							return false;
					}						
					return true;
					*/
				}
				
				boolean check( int i, int j, int board[][], int N, int M, int maxRow[], int maxCol[])
				{
					return checkRow(i,j,board,N,M, maxRow, maxCol) || checkCol(i,j,board,N,M, maxRow, maxCol);
				}
				
				boolean solve( int N, int M, int board[][], int [] maxRow, int[] maxCol)
				{
					boolean ret = true;
					/*
					for( int i = 0; i < N; ++i )
					{
						int j = minRow[i];
						if( ! check(i,j,board,N,M))
							return false;
					}
					for( int j = 0; j < M; ++j )
					{
						int i = minCol[j];
						if( ! check(i,j,board,N,M))
							return false;
					}
					*/
					
					for( int i = 0; i < N; ++i )
					{
						for( int j = 0; j < M; ++j )
						{
							if( ! check(i,j,board,N,M, maxRow, maxCol))
								return false;
						}
					}
					
					return ret;
				}
	
				@Override
				public void solve( InputStream in, PrintStream out )
						throws Exception
				{
					Scanner scanner = new Scanner( in );
					int T = scanner.nextInt();
					for( int CASE = 1; CASE <= T; ++CASE )
					{
						int N = scanner.nextInt();
						int M = scanner.nextInt();
						int a[][] = new int[N][M];
						int maxRow[] = new int[N];
						int maxCol[] = new int[M];
						for( int i = 0; i < N; ++i )
						{
							maxRow[i] = -1;
							int max = Integer.MIN_VALUE;
							for( int j = 0; j < M; ++j )
							{
								int n = scanner.nextInt();
								if(max <= n )
								{
									maxRow[i] = j;
									max = n;
								}
								a[i][j] = n;
							}
						}
						for( int j = 0; j < M; ++j )
						{
							maxCol[j] = -1;
							int max = Integer.MIN_VALUE;
							for( int i =0; i < N; ++i )
							{
								int n = a[i][j];
								if( max <= n )
								{
									maxCol[j] = i;
									max = n;
								}
							}
						}
						dOut.println( "=========");
						dOut.println( Arrays.toString(maxRow));
						dOut.println( Arrays.toString(maxCol));
						String ans = String.format("Case #%d: %s ", CASE, solve(N,M,a,maxRow,maxCol) ? "YES":"NO");
						out.println(ans);
					}
					
				}
				
			}
			
			public static class C implements Problem
			{
				
				public Set<Long> demSquares(long limit) 
				{

				    TreeSet<Long> result = new TreeSet<Long>();

				    for (int i = 0; i <= 9 && i <= limit; i++)
				    {
				    	long ii = i *i;
				    	if( isPalindrome(ii))
				    		result.add(ii);
				    }

				    boolean cont = true;
				    for (long i = 1; cont; i++) 
				    {
				        StringBuffer rev = new StringBuffer("" + i).reverse();
				        cont = false;
				        for (String d : "0123456789".split("")) 
				        {
				        	long n = Long.parseLong("" + i + d + rev);
				        	long nn = n*n;
				            if (n <= limit) 
				            {
				                cont = true;
				                if(isPalindrome(nn))
				                	result.add(nn);
				            }
				        }
				    }

				    return result;
				}

				boolean isPalindrome(String num)
				{
					int n = num.length()-1;
					for( int i = 0 ; i < n; ++i )
					{
						if( num.charAt(i) != num.charAt(n-i))
							return false;
					}
					return true;
				}
				
				boolean isPalindrome(long number)
				{
					return isPalindrome( Long.toString(number) );
					
				}

				@Override
				public void solve(InputStream in, PrintStream out)
						throws Exception 
				{
					Set<Long> demSquares = demSquares((long)Math.sqrt(10e15));
					for( Long l : demSquares )
					{
						dOut.println( l );
					}
					Scanner scanner = new Scanner(in );
					int T = scanner.nextInt();
					for( int CASE = 1; CASE <= T; ++CASE )
					{
						long A = scanner.nextLong();
						long B = scanner.nextLong();
						long cnt = 0;
						/*
						for( long i = 0; i <=B; ++i )
						{
							if( isPalindrome(i))
							{
								long ii = i * i;
								if( isPalindrome(ii) && ii <= B && ii >= A)
								{
									dOut.println( ii );
									cnt++;
								}
							}
						}
						*/
						
						for( Long i : demSquares )
						{
							if( i >= A && i <= B)
								++cnt;
						}
						out.println( String.format("Case #%d: %d", CASE, cnt));
					}
					
					
				}
				
			}
			
			public static class D implements Problem
			{
				public static class Chest
				{
					public Chest()
					{
						for( int i = 1; i <= 200; ++i )
						{
							k.put(i, 0);
						}
					}
					int i;
					int T,K;
					Map<Integer,Integer> k = new HashMap<Integer,Integer>();
				}
				
				LinkedList<Integer> canDo( int chest_i, HashMap<Integer,Integer> myKeys, Chest chests[], TreeMap<Integer,Chest> key2Chest, HashSet<Integer> visited, LinkedList<Integer> path )
				{
					int N = chests.length;
					visited.add(chest_i);
					path.add(chest_i);
					
					for( Integer key_i : chests[chest_i].k.keySet() )
					{
						dOut.println( key_i );
						myKeys.put( key_i, myKeys.get(key_i) + chests[chest_i].k.get(key_i));
					}
					
					if( visited.size() == N )
						return path;
					
					for( int i = 0; i < N; ++i )
					{
						if( i == chest_i ) 
							continue;
						if( visited.contains( i ))
							continue;
						if( myKeys.containsKey(chests[i].T))
						{
							LinkedList<Integer> ans = canDo(i, (HashMap<Integer,Integer>) myKeys.clone(), chests, key2Chest, visited,(LinkedList<Integer>)path.clone() );
							if( null != ans )
							{
								return ans;
							}
						}							
					}						
					return null;
					
				}

				@Override
				public void solve(InputStream in, PrintStream out)
						throws Exception 
				{
					Scanner scanner = new Scanner(in);
					int T = scanner.nextInt();
					
					for( int CASE = 1; CASE <= T; ++ CASE )
					{
						int K,N;
						K = scanner.nextInt();
						N = scanner.nextInt();
						HashMap<Integer,Integer> k = new HashMap<Integer,Integer>();
						for( int i = 1; i <= 200; ++i )
						{
							k.put(i, 0);
						}
						for( int i = 0; i < K; ++i )
							k.put( scanner.nextInt(), 1 );
						Chest chests[] = new Chest[N];
						TreeMap<Integer,Chest> key2Chest = new TreeMap<Integer,Chest>();
						for( int i = 0; i < N; ++i )
						{
							Chest chest = new Chest();
							chest.i = i;
							chest.T = scanner.nextInt();
							chest.K = scanner.nextInt();
							for( int j = 0; j < K; ++j )
							{
								//chest.k[j] = scanner.nextInt();
								chest.k.put( scanner.nextInt(), 1);
							}
							key2Chest.put( chest.T, chest);
							chests[i] = chest;
						}
						LinkedList<Integer>  ans = null;
						for( int i = 0; i < N; ++i )
						{
							ans = canDo(i, (HashMap<Integer,Integer>) k.clone(), chests, key2Chest, new HashSet<Integer>(), new LinkedList<Integer>());
							if( ans != null )
								break;
						}
						String answer = "";
						if( ans != null )
						{
							for( int i = 0; i < ans.size(); ++i )
							{
								answer += ans.get(i);
								answer += " ";
							}
						}
						else
						{
							answer = "IMPOSSIBLE";
						}
						out.println( String.format( "Case #%d: %s", CASE, answer ));
					}
					
				}
				
			}
		}
		
		public static class Round1A
		{
			public static class A implements Problem
			{
				double area( long n, double r )
				{
					double a1, a2;
					a1 = 2*r + 1 + 4 * n;
					a2 = 2*r + 1;
					return (n * (a1+a2)) / 2;
				}
				
				long search(double r, double t )
				{
					long a = 1;
					long b = 1 * 10^18;
					while( a < b )
					{
						long c = (a + b )/2;
						dOut.println( String.format("%d, %d, %d", a, b, c) );
						
						double req = area(c, r );
						double req1 = area(c+1,r);
						if( req > t )
						{
							b = c;
						}
						else
						{
							a = c;
						}
						if( c == a || c == b ) break;
						dOut.println( String.format( "%f, %f, %f", t, req, req1));
						if( req1 > t && req <= t)return c;
					}
					double req = area(a, r );
					double req1 = area(b,r);
					if( req >= t ) return a;
					return b;
				}

				@Override
				public void solve(InputStream in, PrintStream out)	throws Exception 
				{
					Scanner scanner = new Scanner(in);
					int T = scanner.nextInt();
					for( int CASE = 1; CASE <= T; ++CASE)
					{
						double r,t;
						r = scanner.nextDouble();
						t = scanner.nextDouble();							
						double rr = r + 1;
						long cnt = 0;
						/*
						while(true)
						{
							//double req = rr*rr - (rr-1) *(rr-1);
							double req = 2 * r + 1 + 4 * cnt;
							if( req > t )
								break;
							t -= req;
							++cnt;								
							rr += 2;
						}
						*/
						out.println( String.format( "Case #%d: %d", CASE, search(r,t) ) );							
					}
					
				}
				
			}
			
			public static class B implements Problem
			{
				
				int findMax( int E, int R, int N, int [] v, int i, int EE )
				{
					if( E > EE )
						E = EE;
					if( i == N - 1 )
					{
						return E * v[i];
					}
					int ret = 0;
					for( int j = 0; j <= E; ++j )
					{
						int t = j * v[i] + findMax( E-j+R, R, N, v, i+1, EE );
						ret = Math.max(ret,t);
					}
					return ret;
					
				}

				@Override
				public void solve(InputStream in, PrintStream out)
						throws Exception 
				{
					
					
					Scanner scanner = new Scanner(in);
					int T = scanner.nextInt();
					for( int CASE = 1; CASE <= T; ++ CASE )
					{
						int E,R,N;
						E = scanner.nextInt();
						R = scanner.nextInt();
						N = scanner.nextInt();
						int v[] = new int [N];
						for( int i = 0; i < N; ++i )
							v[i] = scanner.nextInt();
						out.println(String.format("Case #%d: %d", CASE, findMax( E, R, N, v, 0, E )));
					}
					
				}
				
			}
			
			public static class C implements Problem
			{
				
				void find( int [] k, int i, int M, int N )
				{
					
				}
				
				@Override
				public void solve(InputStream in, PrintStream out)
						throws Exception 
				{
					Scanner scanner = new Scanner(in);
					scanner.nextInt();
					int R,N,M,K;
					R = scanner.nextInt();
					N = scanner.nextInt();
					M = scanner.nextInt();
					K = scanner.nextInt();
					for( int i = 0; i < R; ++i )
					{
						int [] k = new int [K];
						for( int j = 0; j < K; ++j )
							k[i] = scanner.nextInt();
						
					}
					
				}
				
			}
			
			public static class D implements Problem
			{

				@Override
				public void solve(InputStream in, PrintStream out)
						throws Exception {
					// TODO Auto-generated method stub
					
				}
				
			}
		}
	
		public static class Round1B
		{
			public static class Osmos implements Problem
			{
				
				int solve( int A, int N, int i, int [] s )
				{
					if( i >= N ) return 0;
					int moves = 0;
					for( int j = i; j < N; ++j )
					{
						if( s[j] < A )
							A += s[j];
						else
						{
							int needed = 0;
							int cutoff = N - j;
							int AA = A;
							if( AA == 1 ) return cutoff;
							dOut.println(String.format("FUCK %d, %d", AA, s[j] ));
							while( AA <= s[j] )
							{
								AA += AA - 1;
								++needed;
							}
							if( needed >= cutoff )
							{
								moves += cutoff;
								break;
							}
							else
							{
								moves += needed;
							}
							A = AA + s[j];
						}
					}
					return Math.min(moves,N);
				}

				@Override
				public void solve(InputStream in, PrintStream out) throws Exception 
				{
					Scanner scanner = new Scanner(in);
					int T = scanner.nextInt();
					for( int CASE = 1; CASE <= T; ++CASE)
					{
						int A,N;
						A = scanner.nextInt();
						N = scanner.nextInt();
						int s [] = new int[N];
						for( int i = 0; i < N; ++i )
							s[i] = scanner.nextInt();
						Arrays.sort(s);
						dOut.println(String.format("%d, %d - %s", CASE, A,Arrays.toString(s)));
						out.println(String.format("Case #%d: %d", CASE, solve( A, N, 0, s)));
						
					}
					
				}
				
			}
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
		double duration = ( ( double ) ( end - start ) ) / 1e3;

		if( gcj_problem )
			System.out.println( "Problem was solved in " + duration
					+ " seconds." );
	}
}