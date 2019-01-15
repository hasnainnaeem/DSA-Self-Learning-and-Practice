/*
Reused code of Balazs Holczer, creator of Algorithms in Java course on Udemy.

This class creates a string of html code of website. Uses regular expression to find urls to which website points.
It uses Breadth First Search for its implementation.
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class BFS {

    private Queue<String> queue;
    private List<String> discoveredWebsiteList;

    public BFS() {
        queue = new LinkedList<>();
        this.discoveredWebsiteList = new ArrayList<>();
    }

    public void discoverWeb(String root) {

        this.queue.add(root);
        this.discoveredWebsiteList.add(root);

        while ( !queue.isEmpty() ) {

            String v = this.queue.remove();
            String webHTML = fetchWebHTML(v);

            String regExpression = "http://(\\w+\\.)*(\\w+)"; // Regular Expression for a url
            Pattern pattern = Pattern.compile(regExpression); // To find links in HTML code fetched from website
            Matcher matcher = pattern.matcher(webHTML);

            while( matcher.find() ){
                String linkFound = matcher.group();

                if( !discoveredWebsiteList.contains(linkFound) ){
                    discoveredWebsiteList.add(linkFound);
                    if (linkFound.length() > 11) { // Ignore links of type "http://***."
                        System.out.println("Website found with URL: " + linkFound);
                        queue.add(linkFound);
                    }
                }
            }
        }
    }

    private String fetchWebHTML(String v) {

        String htmlString = "";

        try {
            URL url = new URL(v);
            BufferedReader webReader = new BufferedReader(new InputStreamReader(url.openStream()));

            String line = "";
            while ((line = webReader.readLine()) != null) {
                htmlString += line;
            }

            webReader.close();
        } catch (Exception e) { // Ignore errors, as not all websites are accessible
        }

        return htmlString;
    }
}
