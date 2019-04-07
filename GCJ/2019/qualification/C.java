import java.util.*;

public class C {
    public static boolean isPrime(long x) {
        for (long i = 3; i < x / 2 + 1; i += 2) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    static List<Long> PRIMES = new ArrayList<>();

    static {
        PRIMES.add(2L);
        for (long i = 3; i < 10000; i += 2) {
            if (isPrime(i)) {

                PRIMES.add(i);
            }
        }
    }

    public static String solve(List<Long> nums) {
        List<Long> primes = new ArrayList<>();
        for (long prime : PRIMES) {
            if (nums.get(0) % prime == 0) {
                primes.add(prime);
                primes.add(nums.get(0) / prime);
                break;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            long lastPrime = primes.get(primes.size() - 1);
            primes.add(nums.get(i) / lastPrime);
        }
        TreeSet<Long> sortedPrimes = new TreeSet<>();
        sortedPrimes.addAll(primes);
        Map<Long, Character> primeToChar = new HashMap<>();

        int i = 0;
        for (long prime : sortedPrimes) {
           primeToChar.put(prime, new Character((char) ('A' + i++)));
        }

        StringBuilder builder = new StringBuilder();

        for (long prime : primes) {
            builder.append(primeToChar.get(prime));
        }
        return builder.toString();

    }

    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int case_num = 1; case_num <= T; ++case_num) {
           long N = scanner.nextLong();
           int L = scanner.nextInt();
            List<Long> nums = new ArrayList<>(L);
           for (int i = 0; i < L; i++) {
              nums.add(scanner.nextLong());
           }

           System.out.println(String.format("Case #%d: %s", case_num, solve(nums)));
        }
    }
}
