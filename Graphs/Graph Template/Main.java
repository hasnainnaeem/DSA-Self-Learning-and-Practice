public class Main {
    public static void main(String argz[]){
        Graph graph = new Graph(105,22,9,155,1,0,77,89);

        graph.addNeighbour(graph.vertices.get(0), graph.vertices.get(1));
        graph.addNeighbour(graph.vertices.get(0), graph.vertices.get(2));
        graph.addNeighbour(graph.vertices.get(0), graph.vertices.get(3));
        graph.addNeighbour(graph.vertices.get(1), graph.vertices.get(5));
        graph.addNeighbour(graph.vertices.get(1), graph.vertices.get(4));
        graph.addNeighbour(graph.vertices.get(1), graph.vertices.get(5));
        graph.addNeighbour(graph.vertices.get(3), graph.vertices.get(6));
        graph.addNeighbour(graph.vertices.get(5), graph.vertices.get(7));


        BreadthFirstSearch bfs = new BreadthFirstSearch();
        bfs.BFS(graph.vertices.get(0));
    }
}
