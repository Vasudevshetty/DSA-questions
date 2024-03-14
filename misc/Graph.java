import java.util.*;

public class Graph {
    static class Edge {
        int dest, src;

        public Edge(int s, int d) {
            this.dest = d;
            this.src = s;
        }
    }

    public static void BFS(ArrayList<Edge> graph[], boolean visited[], int start) {
        Queue<Integer> que = new LinkedList<>();
        que.add(start);
        while (!que.isEmpty()) {
            int curr = que.remove();
            if (!visited[curr]) {
                System.out.print(curr + " ");
                visited[curr] = true;

                for (int i = 0; i < graph[curr].size(); i++) {
                    Edge e = graph[curr].get(i);
                    que.add(e.dest);
                }
            }
        }
    }

    public static void allPathsFromSrcToTarget(ArrayList<Edge> graph[], boolean visited[], int curr, int target, String path){
        if(curr == target){
            System.out.println(path);
            return;
        } 
        for(int i = 0; i < graph[curr].size(); i++){
            Edge e = graph[curr].get(i);
            if(visited[e.dest] == false){
                visited[curr] = true;
                allPathsFromSrcToTarget(graph, visited, e.dest, target, path+e.dest+" ");
                visited[curr] = false;
            }
        }
    }

    public static void DFS(ArrayList<Edge> graph[], boolean visited[], int curr){
        System.out.print(curr + " ");
        visited[curr] = true;
        for(int i = 0; i < graph[curr].size(); i++){
            if(visited[graph[curr].get(i).dest] == false)
            DFS(graph, visited, graph[curr].get(i).dest);
        }
    }

    @SuppressWarnings("unchecked")
    public static void main(String args[]) {
        ArrayList<Edge>[] graph = new ArrayList[7];
        for (int i = 0; i < graph.length; i++)
            graph[i] = new ArrayList<>();
        boolean visited[] = new boolean[graph.length];

        graph[0].add(new Edge(0, 1));
        graph[0].add(new Edge(0, 2));

        graph[1].add(new Edge(1, 0));
        graph[1].add(new Edge(1, 3));

        graph[2].add(new Edge(2, 0));
        graph[2].add(new Edge(2, 4));

        graph[3].add(new Edge(3, 1));
        graph[3].add(new Edge(3, 5));
        graph[3].add(new Edge(3, 4));

        graph[4].add(new Edge(4, 2));
        graph[4].add(new Edge(4, 3));
        graph[4].add(new Edge(4, 5));

        graph[5].add(new Edge(5, 3));
        graph[5].add(new Edge(5, 6));
        graph[5].add(new Edge(5, 4));

        graph[6].add(new Edge(6, 5));


        for(int i = 0; i < graph.length; i++) if(visited[i] == false) BFS(graph, visited, i);
        System.out.println();
        for(int i = 0; i < visited.length; i++) visited[i] = false;
        for(int i = 0; i < graph.length; i++) if(visited[i] == false) DFS(graph, visited, i);
        System.out.println();
        for(int i = 0; i < visited.length; i++) visited[i] = false;
        allPathsFromSrcToTarget(graph, visited, 0, 5, "0 ");
    }
}