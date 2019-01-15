import java.util.List;
import java.util.Stack;

public class DFS {

    private Stack<Vertex> stack;

    public DFS(){
        stack = new Stack<>();
    }

    public void dfs(List<Vertex> vertices){

        for(Vertex v: vertices){ //This makes sure that vertices of unconnected regions are transversed
            if(!v.isVisited()) {
                v.setVisited(true);
                System.out.println("Value of ");
                dfsForConnected(v);
            }
        }

    }

    public void dfsForConnected(Vertex root) { //It transverses through only a connected graph
        for(Vertex v: root.getNeighbours()){
            if( !v.isVisited() ){
                v.setVisited(true);
                dfsForConnected(v);
            }
        }

    }
}
