/*
Author: Muhammad Hasnain Naeem
Description: Implementation of Breadth First Search to list urls a website points to
Dated: 8//18/2018
 */
public class Main {

    public static void main(String[] args) {

        String root = "http://www.youtube.com";
        BFS bfs = new BFS();
        bfs.discoverWeb(root);

    }
}
