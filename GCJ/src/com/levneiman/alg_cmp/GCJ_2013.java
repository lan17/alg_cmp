package com.levneiman.alg_cmp;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

import com.levneiman.alg_cmp.Problems.Problem;
import static com.levneiman.alg_cmp.Problems.SO;


public class GCJ_2013
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
                SO.println( T );
                for( int CASE = 1; CASE <= T; ++CASE )
                {
                    String board [] = new String[4];
                    scanner.nextLine();
                    for( int i = 0; i < 4; ++i )
                    {
                        board[i] = scanner.nextLine();
                        SO.println( board[i] );
                    }
                    String ans = String.format( "Case #%d: %s", CASE, solve(board) );
                    SO.println( ans );
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


            //  return true;
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
                    SO.println( "=========");
                    SO.println( Arrays.toString(maxRow));
                    SO.println( Arrays.toString(maxCol));
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
                    SO.println( l );
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
                    SO.println( key_i );
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
                    SO.println( String.format("%d, %d, %d", a, b, c) );

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
                    SO.println( String.format( "%f, %f, %f", t, req, req1));
                    if( req1 > t && req <= t)return c;
                }
                double req = area(a, r );
                double req1 = area(b,r);
                if( req >= t ) return a;
                return b;
            }

            @Override
            public void solve(InputStream in, PrintStream out)  throws Exception
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
                        SO.println(String.format("FUCK %d, %d", AA, s[j] ));
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
                    SO.println(String.format("%d, %d - %s", CASE, A,Arrays.toString(s)));
                    out.println(String.format("Case #%d: %d", CASE, solve( A, N, 0, s)));

                }

            }

        }
    }
}

