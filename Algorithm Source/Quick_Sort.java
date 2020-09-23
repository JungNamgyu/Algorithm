import java.util.Arrays;

public class Quick_Sort {
	static void Swap(int[] data, int a, int b){
		int tmp = data[a];
		data[a] = data[b];
		data[b] = tmp;
	}
	static void Quick_Sort(int[] data, int L, int H) { 
		if(L<H) {
			int pivot = data[L];
			int le = L + 1, ri = H;
			while(le<=ri) {
				while(data[le]<=pivot && le < H) le++;
				while(data[ri]>=pivot && ri > L) ri--;
				if(ri<le)
					break;
				Swap(data, le, ri);
			}
			Swap(data, L, ri);
			Quick_Sort(data, L, ri); Quick_Sort(data, le, H);
		}
	}
	public static void main(String[] args) {
		int[] data = {5,3,8,4,9,1,6,2,7,10};
		System.out.println(Arrays.toString(data));
		Quick_Sort(data, 0, data.length - 1);
		System.out.println(Arrays.toString(data));
	}
}
