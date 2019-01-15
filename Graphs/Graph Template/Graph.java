import java.util.LinkedList;
/*
Important: This class makes a graph and adds number to vertices.
But you have add neighbours by yourself, for example: graph.vertices[0].addNeighbour(vertices[0])
 */
public class Graph {

    LinkedList<Vertex> vertices;
    public Graph(int ... datalist){
         vertices = new LinkedList<Vertex>();

        for (int number: datalist){ // Adding each number in dataList in difference vertices
            vertices.add(new Vertex(number));
        }
    }

    public void addNeighbour(Vertex vertex, Vertex neighbour){
        vertex.addNeighbour(neighbour);
    }
}
