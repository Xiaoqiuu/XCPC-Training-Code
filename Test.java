import java.util.Scanner;
public class Test {
    public static void main(String[] args) {
        system.out.println("请输入整数：");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int[][] a = new int[num][];
        for (int i = 0; i < a.length; i++) {
            a[i] = new int[i + 1];
            for (int j = 0; j < a[i].length; j++) {
                if (j == 0 || j == i) a[i][j] = 1;
                else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }
        }
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}