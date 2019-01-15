import java.util.List;
import java.util.Stack;

public class DFS {

    private Stack<Vertex> stack;

    public DFS(){
        stack = new Stack<>();
    }

    public void dfs(List<Vertex> vertices){
        for(Vertex v: vertices){
            if(!v.isVisited()) {
                v.setVisited(true);
                dfsForConnected(v);
            }
        }
    }

    public void dfsForConnected(Vertex root){ //It transverses through only a connected graph
        stack.add(root);
        root.setVisited(true);

        while( !stack.isEmpty() ){

            Vertex currentVertex = stack.pop(); //
            currentVertex.setVisited(true);
            System.out.println(currentVertex.getData()); //Printing value of each vertex we transverse through

            for( Vertex neighbour: currentVertex.getNeighbours() ){

                if ( !neighbour.isVisited() ) {
                    stack.add(neighbour);
                    neighbour.setVisited(true);
                }

            }
        }

    }
}
