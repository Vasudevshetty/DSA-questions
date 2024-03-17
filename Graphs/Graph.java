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
            ArrayList<Integer> neighbours = queue.poll();

            for (Integer neighbour : neighbours) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    traversal.add(neighbour);
                    queue.add(graphList.get(neighbour));
                }
            }
        }
        return traversal;
    }

    private void DFSR(final Graph graph, boolean visited[], ArrayList<Integer> traversal, int startingVertex) {
        if (!visited[startingVertex]) {
            visited[startingVertex] = true;
            traversal.add(startingVertex);
            for (Integer node : graph.graphList.get(startingVertex))
                DFSR(graph, visited, traversal, node);
        }
    }

    public ArrayList<Integer> DFS() {
        return DFS(1);
    }

    public ArrayList<Integer> DFS(int startingVertex) {
        boolean visited[] = new boolean[vertex + 1];
        ArrayList<Integer> traversal = new ArrayList<>();

        DFSR(this, visited, traversal, startingVertex);
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
        System.out.println(graph.BFS());
        System.out.println(graph.DFS());
        System.out.println(graph.BFS(startingVertex));
        System.out.println(graph.DFS(startingVertex));
        scan.close();
    }
}