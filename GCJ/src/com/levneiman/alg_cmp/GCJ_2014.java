package com.levneiman.alg_cmp;

import java.io.InputStream;

import static com.levneiman.alg_cmp.Problems.SO;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

import com.levneiman.alg_cmp.Problems.GCJProblem;
import com.levneiman.alg_cmp.Problems.Util;
import com.levneiman.alg_cmp.Problems.Util.MultiMap;
import com.levneiman.alg_cmp.Problems.Util.Pair;

public class GCJ_2014
{
	public static class QualificationRound
	{
		public static class A implements Problems.Problem
		{
			static int [][] board1 = new int[4][4];
			static int [][] board2 = new int[4][4];

			static String format = "Case #%d: %s";

			@Override
			public void solve( InputStream in, PrintStream out )
					throws Exception
			{
				Scanner scanner = new Scanner(in);
				int T = scanner.nextInt();
				for (int CASE = 1; CASE <=T; ++CASE)
				{
					SO.println("Solving case " + CASE);
					int row1, row2;
					row1 = scanner.nextInt();
					for (int i = 0; i < 16; ++i)
					{
						board1[i/4][i%4] = scanner.nextInt();
					}
					row2 = scanner.nextInt();
					for (int i = 0; i < 16; ++i)
					{
						board2[i/4][i%4] = scanner.nextInt();
					}
					Set<Integer> row1Set = new HashSet<Integer>();
					Set<Integer> row2Set = new HashSet<Integer>();
					for (int i = 0; i < 4; ++i)
					{
						row1Set.add( board1[row1-1][i] );
						row2Set.add( board2[row2-1][i] );
					}

					row1Set.retainAll( row2Set );

					String answer = row1Set.size() == 1 ? Integer.toString( row1Set.iterator().next() ) :
						(row1Set.size() == 0  ? "Volunteer cheated!" : "Bad magician!");
					out.println(String.format(format, CASE, answer));
				}
				scanner.close();
			}
		}


		public static class B implements Problems.Problem
		{
			double time(double V, double x, double D)
			{
				return (D-x)/V;
			}

			double [] mem = new double[100000];

			void farmTimes(double C, double F, int lim)
			{
				mem[0] = time(2.0, 0, C);
				for (int i = 1; i < lim; ++i)
				{
					mem[i] = mem[i-1] + time(2.0 + F * i, 0, C);
				}
			}

			double brute(double C, double F, double X)
			{
				double x = 0.0;
				double v = 2.0;
				double answer = time(v, x, X);
				for (int i = 0; i < mem.length; ++i)
				{
					double farmAnswer = mem[i] + time(2.0 + F *(i+1), 0, X);
					if (farmAnswer > answer)
					{
						SO.println( "Number of farms used " + (i+1));
						return answer;
					}
					answer = farmAnswer;
				}
				return answer;
			}

			@Override
			public void solve( InputStream in, PrintStream out )
					throws Exception
			{
				Scanner scanner = new Scanner(in);
				int T = scanner.nextInt();
				for (int CASE = 1; CASE <=T; ++CASE)
				{
					double C,F,X;
					C = scanner.nextDouble();  // farm cost
					F = scanner.nextDouble();  // farm boost.
					X = scanner.nextDouble(); // needed.

					farmTimes(C, F, (int)X);

					out.println(String.format("Case #%d: %f", CASE, brute(C,F,X)));
				}

			}

		}

		public static class D implements Problems.Problem
		{

			int dwar( double[] naomi, double[] ken)
			{
				int ret = 0;
				int N = naomi.length;
				int j = 0;
				for (int i = 0; i < N; ++i)
				{
					if (naomi[i] > ken[j] )
					{
						++ret;
						++j;
					}
				}
				return ret;
			}

			Double findClosest( TreeSet<Double> set, double num)
			{
				for (Double d : set)
				{
					if( d > num ) return d;
				}
				return null;
			}

			int war( double [] naomi, double[] ken)
			{
				int ret = 0;
				int N =  naomi.length;
				int j = N - 1;
				String dd = "";
				for ( int i = 0; i < N; ++i)dd += naomi[i] +"\t";
				dd += "\n";
				for (int i = 0; i < N; ++i ) dd += ken[i] +"\t";
				SO.println(dd);

				TreeSet<Double> kenSet = new TreeSet<Double>();
				for ( int i = 0; i < N; ++i ) kenSet.add( ken[i] );

				for (int i = 0; i < N; ++i)
				{
					if (naomi[i] > kenSet.last() )
					{
						++ret;
						kenSet.remove( kenSet.first() );
					}
					else
					{
						kenSet.remove( findClosest(kenSet, naomi[i]) );
					}
				}
				return ret;
			}

			@Override
			public void solve( InputStream in, PrintStream out )
					throws Exception
			{
				Scanner scanner = new Scanner(in);
				int T = scanner.nextInt();
				for (int CASE = 1; CASE <=T; ++CASE)
				{
					int N = scanner.nextInt();
					double[] naomi = new double[N];
					double [] ken = new double[N];
					for (int i = 0; i < N; ++i) naomi[i] = scanner.nextDouble();
					for (int i = 0; i < N; ++i) ken[i] = scanner.nextDouble();

					Arrays.sort( naomi );
					Arrays.sort( ken );

					out.println( String.format("Case #%d: %d %d", CASE, dwar(naomi, ken), war(naomi,ken)));

				}

			}

		}
	}

	public static class Round1A
	{
		public static class A extends GCJProblem
		{
			Set<Long> flip(Long [] arr, Long i)
			{
				 Set<Long> ret = new HashSet<Long>();
				 for (int j = 0; j < arr.length; ++j)
				 {
					 ret.add(arr[j] ^ i);
				 }
				 return ret;
			}
			
			boolean fits(Long [] arr, Long i, Set<Long> devices)
			{
				Set<Long> newOutlets = flip(arr,i);
				 newOutlets.retainAll( devices );
				 return newOutlets.size() == devices.size();
			}
			
			@Override
			public String solve( Scanner in )
			{
				int N, L;
				N = in.nextInt();
				L = in.nextInt();
				Long [] outlets = new Long[N];
				Long [] devices = new Long[N];
				
				Set<Long> sO = new HashSet<Long>();
				Set<Long> sD = new HashSet<Long>();
				
				for ( int i = 0; i < N; ++i ) 
				{
					outlets[i] = in.nextLong(2);
					sO.add(outlets[i]);
				}
				for (int i = 0; i < N; ++i ) 
				{
					devices[i] = in.nextLong( 2 );
					sD.add(devices[i]);
				}
				int min = Integer.MAX_VALUE;
				int i = 0;
				for (int j = 0; j < N; ++j ) 
				{
					Long mask = outlets[i] ^ devices[j];
					if (fits(outlets, mask, sD))
					{
						int numbits = Util.numberOfSetBits(mask);
						
						min = Math.min(min, numbits);
					}
				}
				if (min > L ) {
					return "NOT POSSIBLE";
				}
				else return Integer.toString( min );
			}
			
		}
		
		public static class B extends GCJProblem
		{			
			Pair<Integer,Integer> solve(MultiMap<Integer,Integer> G, int root, HashSet<Integer> seen)
			{
				seen.add(root);
				
				int nodes = 1;
				TreeSet<Integer> children = new TreeSet<Integer>();
				for (int child : G.get( root ))
				{
					if (seen.contains(child))
					{
						continue;
					}
					Pair<Integer,Integer> res = solve(G, child, seen);
					children.add(res.getSecond()-res.getFirst());
					nodes += res.getSecond();
				}
				int remove = 0;
				if (children.size() <= 1)
				{
					return Pair.make( nodes - 1, nodes );
				}
				return Pair.make( nodes - 1 - children.last() - children.lower( children.last() ), nodes );
				
			}
			
			@Override
			public String solve( Scanner in )
			{
				int N = in.nextInt();
				MultiMap<Integer,Integer> G = new MultiMap<Integer,Integer>(MultiMap.<Integer>ARRAY_LIST());
				for ( int i = 0; i < N -1; ++i) 
				{
					int A, B;
					A = in.nextInt();
					B = in.nextInt();
					G.put( A, B );
					G.put( B, A );
				}				
				
				int ret = Integer.MAX_VALUE;
				//SO.println(G);
				for (int i = 1; i <=N; ++i)
				{
					int tt = solve(G, i, new HashSet<Integer>()).getFirst();
					ret = Math.min(ret,tt );
				}
				return Integer.toString(ret);
			}
			
		}
		
		public static class C extends GCJProblem
		{
			
			@Override
			public String solve( Scanner in )
			{
				int N = in.nextInt();
				int cnt = 0;
				for ( int i = 0; i < N; ++i )
				{
					if (in.nextInt() > i) ++cnt;
				}
				int cutoff = N/2 + N/100 + 5;
				SO.println(cutoff);
				return cnt > cutoff ? "BAD" : "GOOD";
			}
			
		}
	}

    public static class Round1B {

        public static class A extends GCJProblem {

            public static  String smallest(String a, List<Integer> charLengths) {
                String ret = "";
                for (int i = 0; i < a.length();)
                {
                	int j = i;
                	while ((j < a.length()) && (a.charAt( j ) == a.charAt(i))) ++j;
                	ret += a.charAt( i );
                	charLengths.add( j-i );
                	i = j;
                }
                return ret;
            }

            @Override
            public String solve(Scanner in) {
                final int N = Integer.parseInt(in.nextLine());
                SO.println(N);

                String[] words = new String[N];                
                List<List<Integer>> charLengths = new ArrayList<List<Integer>>(N);               
                
                for (int i = 0; i < N; ++i) 
                {
                	charLengths.add( new ArrayList<Integer>() );                	
                }
                
                String smallWord = smallest(in.nextLine().trim(), charLengths.get( 0 ));
                
                boolean bad = false;
                for (int i = 1; i < N; ++i) {
                    words[i] = in.nextLine().trim();
                  //  SO.println(words[i]);
                    if (!smallWord.equals( smallest(words[i], charLengths.get(i)))) 
                    {
                    	bad = true;
                    }
                }
                if (bad)
                {
                	return "Fegla Won";                
                }
                
                int ret = 0;
                for (int i = 0; i < smallWord.length(); ++i)
                {
                	int charMin = Integer.MAX_VALUE;
                	for (int l = 1; l <= 100; ++l) 
                	{
                		int cunt = 0;
                		for (int j = 0; j < N; ++j)
                		{
                			cunt += Math.abs( l - charLengths.get(j).get( i ) );
                		}
                		charMin = Math.min(charMin, cunt);
                	}
                	ret += charMin;
                }
                
                return Integer.toString(ret);
            }

        }
    
        public static class B extends GCJProblem 
        {
        	
        	long brute( long A, long B, long K)
        	{
        		long cunt = 0;
        		for (long a = 0; a < A; ++a) 
        		{
        			for (long b = 0; b < B; ++b)
        			{
        				if ((a&b) < K)
        				{
        					SO.println(String.format("%d - %d", a, b));
        					++cunt;
        				}
        			}
        		}
        		return cunt;
        	}
        	
        	int highestBit(long X)
        	{
        		int ret = 63;
        		while (ret >= 0 && !Util.testBit(X,ret))
        		{
        			--ret;
        		}
        		return ret;        			
        	}
        	
        	long smart( long A, long B, long K)
        	{
        		A -= 1;
        		B -= 1;
        		K -= 1;
        		int aL, bL, kL;
        		aL = highestBit(A);
        		bL = highestBit(B);
        		kL = highestBit(K);
        		
        		long ways = 0;
        		for (int i = 0; i <= Math.max( Math.max(aL,bL), kL ); ++i)
        		{
        			boolean bitSet = Util.testBit( K, i );
        			
        		}       		
        		 		
        		return ways;
        	}

			@Override
			public String solve( Scanner in )
			{
				long A, B, K;
				A = in.nextLong();
				B = in.nextLong();
				K = in.nextLong();
				
				return Long.toString( brute(A,B,K) );
			}
        	
        }
    }
    
    public static class Round1C
    {
    	public static class A extends GCJProblem
    	{

			@Override
			public String solve( Scanner in )
			{
				
				return null;
			}
    		
    	}
    	
    	public static class B extends GCJProblem
    	{
    		final static int factor = 1000000007;
    		
    		class DiGraph
    		{
    			int N;
    			MultiMap<Integer,Integer> next;
    			MultiMap<Integer,Integer> prev;
    		}
    		
    		class BadTrain extends Exception
    		{
    			
    		}
    		
    		char firstChar( String a)
    		{
    			return a.charAt( 0 );    			
    		}
    		
    		char lastChar(String a)
    		{
    			return a.charAt( a.length()-1 );
    		}
    		
    		boolean goodWord(String a)
    		{
    			HashSet<Character> cs = new HashSet<Character>();
    			boolean ret = true;
    			cs.add(a.charAt( 0 ));
    			for (int i = 1; i < a.length(); ++i)
    			{
    				if (cs.contains( a.charAt(i) ))
    				{
    					if (a.charAt( i ) != a.charAt( i-1 ))
    					{
    						return false;
    					}    					
    				}
    				cs.add(a.charAt( i ));    				
    			}
    			return ret;
    		}
    		
    		boolean canNext( String a, String b) throws BadTrain
    		{
    			boolean ret = lastChar(a) == firstChar(b);
    			if (!goodWord(a+b))
    			{
    				SO.println("BAD !! -- " + a + " : " + b);
    				throw new BadTrain();
    			}
    			return true;
    		}
    		
    		int fact(int n)
    		{
    			int x = 1;
    			for (int i = 2; i <=n; ++i)
    			{
    				x *=n;
    				x %= factor;
    			}
    			return x;
    		}

			@Override
			public String solve( Scanner in )
			{				
				int N = Integer.parseInt( in.nextLine() );
				String line = in.nextLine();
				String [] words = line.split( " " );
				
				try
				{
					SO.println("can next - "  + canNext("ga", "abcd"));
					SO.println("good word - " + goodWord("abcdec"));
					
					for (String a : words)
					{
						if(!this.goodWord( a ))
						{
							return "0";
						}
					}
					for (int i = 0; i < N; ++i)
					{
						words[i] = Round1B.A.smallest( words[i], new ArrayList<Integer>() );
						//SO.println(words[i] );
					}
					
					Map<String,Integer> wordCount = new HashMap<String,Integer>();
					for (int i = 0; i < N; ++i)
					{
						Integer cnt = wordCount.get(words[i]);
						if (null == cnt) cnt = 0;
						wordCount.put(words[i], ++cnt);
					}
					int ret = 1;
					// make independent components.
					while (true)
					{
						boolean done = true;
						Set<String> toRemove = new HashSet<String>();
						Set<String> toAdd = new HashSet<String>();
						for (String a : wordCount.keySet())
						{							
							for (String b : wordCount.keySet())
							{
								if ( a == b ) continue;
								
								if (lastChar(a) == firstChar(b))
								{
									toRemove.add(a);
									toRemove.add(b);
									toAdd.add(a+b);
									done = false;
									break;
								}
							}
							if (!done) break;
						}
						for (String a : toRemove)
						{
							wordCount.remove( a );
						}
						for (String a : toAdd)
						{
							wordCount.put( a, 1 );
						}
						if (done) break;
					}
					
					for (String a : wordCount.keySet())
					{
						ret *= fact(wordCount.get( a ));
						for (String b : wordCount.keySet())
						{
							if (a == b) continue;
							canNext(a,b);							
						}
					}
					
					SO.println(Arrays.toString( wordCount.keySet().toArray() ));
					ret *= fact(wordCount.size());
					
					return Integer.toString( ret  );
				}
				catch(BadTrain e)
				{
					SO.println("BAD TRAIN!");
					return "0";
				}
				
			}
    		
    	}
    	
    	public static class C extends GCJProblem
    	{

			@Override
			public String solve( Scanner in )
			{
				// TODO Auto-generated method stub
				return null;
			}
    		
    	}
    }

}
