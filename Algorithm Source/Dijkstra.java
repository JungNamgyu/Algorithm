import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Dijkstra {
	public static void main(String[] args) {
		Algorithm host = new Algorithm();
		host.Input();
		host.Dijkstra();
		host.Output();
	}
}

class Algorithm {
	int[] Distance;
	int V, E, Start;
	boolean[] Visit;
	ArrayList < Integer >[] Edge;
	public void Dijkstra() {
		Visit = new boolean[V + 1]; Arrays.fill(Visit, false);
		Distance = new int[V + 1]; Arrays.fill(Distance, Integer.MAX_VALUE);
		int inx = Start;
		Visit[Start] = true; Distance[Start] = 0;
		while(true) {
			for(int i=0;i<Edge[inx].size();i+=2) {
				if(!Visit[Edge[inx].get(i)]) {
					if(Distance[Edge[inx].get(i)] > Distance[inx] + Edge[inx].get(i+1)){
						Distance[Edge[inx].get(i)] = Distance [inx] + Edge[inx].get(i+1);
					}
				}
			}
			int MAX = Integer.MAX_VALUE;
			for(int i=1;i<=V;i++) {
				if(!Visit[i] && MAX > Distance[i]) {
					inx = i;
					MAX = Distance[i];
				}
			}
			if(MAX == Integer.MAX_VALUE)
				break;
			Visit[inx] = true;
		}
	}
	public void Input() {
		Scanner sc = new Scanner(System.in);
		V = sc.nextInt();
		E = sc.nextInt();
		Start = sc.nextInt();
		Edge = new ArrayList[V+1];
		for(int i=1;i<=V;i++)
			Edge[i] = new ArrayList<Integer>();
		for(int i=0;i<E;i++) {
			int u = sc.nextInt();
			int v = sc.nextInt();
			int e = sc.nextInt();
			Edge[u].add(v); Edge[u].add(e);
		}
	}
	public void Output() {
		for(int i=1;i<=V;i++) {
			if(Distance[i] == Integer.MAX_VALUE)
				System.out.println("INF");
			else
				System.out.println(Distance[i]);
		}
	}
}