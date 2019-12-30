import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);

		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			int r, e, c;
			r = input.nextInt();
			e = input.nextInt();
			c = input.nextInt();
			if(r < e - c)
				System.out.println("advertise");
			if(r > e - c)
				System.out.println("do not advertise");
			if(r == e - c)
				System.out.println("does not matter");
		}
	}
}
