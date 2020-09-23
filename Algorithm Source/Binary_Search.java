import java.util.Arrays;
import java.util.Scanner;

public class Binary_Search {

	private static Scanner input;

	public static void main(String[] args) {
		input = new Scanner(System.in);
		
		System.out.print("배열 크기를 입력하세요 : ");
		int n = input.nextInt();
		
		int[] arr = new int[n];
		System.out.print("배열 원소를 입력하세요 : ");
		for(int i=0;i<n;i++)
			arr[i]=input.nextInt();
		Arrays.sort(arr);

		System.out.print("찾을려는 원소를 입력하세요 : ");
		int d = input.nextInt();
		int le = 0, ri = n-1;
		while(le<=ri) {
			int mid = (le+ri)/2;
			if(arr[mid]==d) {
				System.out.println("배열 안에 있습니다");
				break;
			}
			if(arr[mid] < d)
				le=mid+1;
			else
				ri=mid-1;
		}
		if(ri<le)
			System.out.println("배열 안에 없습니다.");
	}
}