import java.util.Arrays;
import java.util.Scanner;

public class Solution5 {
    public static int[][] Arr;
    public static int[][] Visited;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows = scanner.nextInt();
        int columns = scanner.nextInt();

        Arr = new int[rows][columns];
        Visited = new int[rows][columns];

        for(int[] a : Arr) {
            Arrays.fill(a, 0);
        }
        for(int[] a : Visited) {
            Arrays.fill(a, 0);
        }

        int r = 0, c = 0, num = 1;

        Arr[r][c] = num;
        ++Visited[r][c];

        while(true) {
            if(isFinish(rows, columns)) break;
            if(num % 2 == 0) {
                ++r;
                if(r == rows) r = 0;
            }
            else {
                ++c;
                if(c == columns) c = 0;
            }
            Arr[r][c] = ++num;
            ++Visited[r][c];
        }
    }

    public static boolean isFinish(int rows, int columns) {
        boolean result = true;

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < columns; ++j) {
                if(Arr[i][j] == 0) {
                    result = false;
                    break;
                }
            }
        }

        if(rows == columns && rows != 2 && columns != 2) {
            if(Visited[0][0]>1) {
                result = true;
                Arr[0][0] = 1;
            }
        }

        return result;
    }
}
