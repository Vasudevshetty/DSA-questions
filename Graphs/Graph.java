package Graphs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Graph {
    private ArrayList<ArrayList<Integer>> graphList;
    private int vertex, edges;

    public Graph(int vertex, int edges) {
        this.vertex = vertex;
        this.edges = edges;
        graphList = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i <= vertex; i++)
            graphList.add(new ArrayList<>());
    }

    public ArrayList<Integer> BFS() {
        return BFS(1);
    }

    public ArrayList<Integer> BFS(int startingVertex) {
        ArrayList<Integer> traversal = new ArrayList<>();
        Queue<ArrayList<Integer>> queue = new LinkedList<>();
        boolean visited[] = new boolean[vertex + 1];

        queue.add(graphList.get(startingVertex));
        traversal.add(startingVertex);
        visited[startingVertex] = true;

        while (!queue.isEmpty()) {
            ArrayList<Integer> list = queue.poll();

            for (Integer node : list) {
                if (!visited[node]) {
                    visited[node] = true;
                    traversal.add(node);
                    queue.add(graphList.get(node));
                }
            }
        }
        return traversal;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int vertex = scan.nextInt();
        int edges = scan.nextInt();
        Graph graph = new Graph(vertex, edges);

        for (int i = 0; i < edges; i++) {
            int u = scan.nextInt();
            int v = scan.nextInt();

            graph.graphList.get(u).add(v);
            graph.graphList.get(v).add(u);
        }
        int startingVertex = scan.nextInt();
        ArrayList<Integer> traversal = graph.BFS(startingVertex);
        System.out.println(traversal);
        scan.close();
    }
}