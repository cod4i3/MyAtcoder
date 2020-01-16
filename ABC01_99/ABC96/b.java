import java.util.*;

public class b {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    ArrayList<Integer> n = new ArrayList<>();
    for (int i = 0; i < 3; i++) {
      n.add(sc.nextInt());
    }
    int k = sc.nextInt();

    Collections.sort(n);
    for (int i = 0; i < k; i++)
      n.set(2, ((Integer) n.get(2) * 2));
    int ans = 0;
    for (Integer num : n)
      ans += num;
    System.out.println(ans);
  }
}