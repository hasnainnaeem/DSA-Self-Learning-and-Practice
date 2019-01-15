import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstSearch {

    private Queue<Vertex> queue;

    public BreadthFirstSearch(){
        queue = new LinkedList<>();
    }

    public void BFS(Vertex root){
        queue.add(root);
        root.setVisited(true);

        while( !queue.isEmpty() ){

            Vertex currentVertex = queue.remove();
            currentVertex.setVisited(true);
            System.out.println(currentVertex.getData()); //Printing value of each vertex we transverse through

            for(Vertex neighbour: currentVertex.getNeighbours()){

                if ( !neighbour.isVisited() ) {
                    queue.add(neighbour);
                    neighbour.setVisited(true);
                }

            }
        }

    }
}
