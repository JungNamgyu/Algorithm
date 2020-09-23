import java.util.Scanner;
import java.util.Arrays;

public class Selection_Sort {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("배열 크기를 입력하세요 : ");
		int n = input.nextInt();

		int[] arr = new int[n];
		System.out.print("배열 원소를 입력하세요 : ");
		for (int i = 0; i < n; i++)
			arr[i] = input.nextInt();
		
		System.out.println("정렬 전 : " + Arrays.toString(arr));
		for (int i = 0; i < n; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[min] > arr[j])
					min = j;
			}
			int t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
		System.out.println("정렬 후 : " + Arrays.toString(arr));
	}
}
