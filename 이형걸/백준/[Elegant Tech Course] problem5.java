import java.util.*;

public class Solution4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        Deque<Integer> answer = new LinkedList<>();
        int cnt = 1;
        char prev = s.charAt(0);

        for(int i = 1; i < s.length(); ++i) {
            if(prev == s.charAt(i)) {
                ++cnt;
            }
            else {
                answer.addLast(cnt);
                prev = s.charAt(i);
                cnt = 1;
            }
        }

        if(answer.isEmpty()) {
            answer.addLast(cnt);
        }
        else if(s.charAt(0) == s.charAt(s.length()-1) && cnt != 0) {
            int value = answer.removeFirst();
            answer.addFirst(cnt+value);
        }
        else {
            answer.addLast(cnt);
        }

        // 오름차순 정렬 해야함!!
    }
}
