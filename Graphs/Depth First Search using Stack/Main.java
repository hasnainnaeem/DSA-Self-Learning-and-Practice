/*
Depth Search Implementation in Java without using Recursion
Wriiten by: Muhammad Hasnain Naeem
Dated: 8/18/2018
 */

import java.util.ArrayList;
import java.util.List;


public class Main {
    public static void main(String argz[]){
        Vertex a = new Vertex(55);
        Vertex b = new Vertex(10);
        Vertex c = new Vertex(30);
        Vertex d = new Vertex(2);
        Vertex e = new Vertex(67);
        Vertex f = new Vertex(0);
        Vertex g = new Vertex(1000);
        a.addNeighbour(b);
        a.addNeighbour(c);

        b.addNeighbour(d);

        c.addNeighbour(e);
        c.addNeighbour(f);
        List<Vertex> vertices = new ArrayList<Vertex>();
        vertices.add(a);
        vertices.add(b);
        vertices.add(c);
        vertices.add(d);
        vertices.add(e);
        vertices.add(f);
        vertices.add(g);

        DFS dfs = new DFS();
        dfs.dfs(vertices);
    }
}
