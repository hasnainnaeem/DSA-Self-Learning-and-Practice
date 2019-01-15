import java.util.LinkedList;
/*
Template of vertex for a directed graph
 */
public class Vertex {
    private int data;
    private LinkedList<Vertex> neighbours = new LinkedList<Vertex>();
    private boolean visited;

    public Vertex(int data){
        this.data = data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNeighbours(LinkedList<Vertex> neighbours) {
        this.neighbours = neighbours;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public int getData() {

        return data;
    }

    public LinkedList<Vertex> getNeighbours() {
        return neighbours;
    }

    public boolean isVisited() {
        return visited;
    }

    public void addNeighbour(Vertex vertex){
        neighbours.add(vertex);
    }

    @Override
    public String toString() {
        return "Vertex{" +
                "data=" + data +
                ", neighbours=" + neighbours +
                ", visited=" + visited +
                '}';
    }
}
