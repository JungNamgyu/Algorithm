import java.util.Arrays;
import java.util.Scanner;

public class Binary_Search {

	private static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		
		System.out.print("�迭 ũ�⸦ �Է��ϼ��� : ");
		int n = input.nextInt();
		
		int[] arr = new int[n];
		System.out.print("�迭 ���Ҹ� �Է��ϼ��� : ");
		for(int i=0;i<n;i++)
			arr[i]=input.nextInt();
		Arrays.sort(arr);

		System.out.print("ã������ ���Ҹ� �Է��ϼ��� : ");
		int d = input.nextInt();
		int le = 0, ri = n-1;
		while(le<=ri) {
			int mid = (le+ri)/2;
			if(arr[mid]==d) {
				System.out.println("�迭 �ȿ� �ֽ��ϴ�");
				break;
			}
			if(arr[mid] < d)
				le=mid+1;
			else
				ri=mid-1;
		}
		if(ri<le)
			System.out.println("�迭 �ȿ� �����ϴ�.");
	}
}