public class Recursive_Function {
	public static int RecFunc(int n) {
		if(n==1)
			return 1;
		return n + RecFunc(n-1);
	}
	public static void main(String[] args) {
		System.out.println("1���� 5������ ���� : " + RecFunc(5));
	}
}