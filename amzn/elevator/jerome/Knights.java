
import java.util.HashMap;

/**
 * In how many distinct ways can 1 or more knights be placed on a 8x8 chessboard
 * so that no two attack each other?
 * 
 * Answer: 101693175441
 */
public class Knights {
	static HashMap<Integer, Long> M = new HashMap<Integer, Long>();
	static int B, D, E;

	static int encode(int U, int P, int R) {
		return R << D | P << B | U;
	}

	// Given (U)ltimate and (P)enultimate bitmasks and R rows left...

	static long F(int P, int U, int R) {
		int key = encode(P, U, R);
		if (M.containsKey(key))
			return M.get(key);

		long ans = 0;

		int W = P << 1, Q = U << 1;
		int blocked = (Q << 1 | Q >> 1 | W << 2 | W >> 2) >> 1;

		for (int i = 0; i < E; i++)
			if ((i & blocked) == 0)
				ans += F(i, P, R - 1);

		M.put(key, ans);
		return ans;
	}

	static long F(int n) {
		M.clear();
		B = n;
		D = B << 1;
		E = 1 << B;

		for (int i = 0; i < E; i++)
			for (int j = 0; j < E; j++)
				M.put(encode(i, j, 0), 1L);

		long ans = 0;
		for (int i = 0; i < E; i++)
			ans += F(i, 0, B - 1);

		return ans;
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();

		for (int i = 2; i <= 11; i++) {
			System.out.printf("%dx%d board: %d ways\n", i, i, F(i) - 1);
			System.out.printf("map size = %d\n", M.size());
		}

		System.out.printf("%d ms\n", System.currentTimeMillis() - time);
	}
}
