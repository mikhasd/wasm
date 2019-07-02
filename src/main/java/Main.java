public class Main {

    private static void iterateTest(int edges, int[] edges_data, int iteration) {
        System.out.println("iteration:\t" + iteration);

        long start = System.currentTimeMillis();
        Graph graph = new Graph(edges+1);
        for (int i = 0; i < edges * 2; i += 2) {
            int from = edges_data[i];
            int to = edges_data[i + 1];
            graph.addEdge(from, to, (byte)1);
        }
        long loaded = System.currentTimeMillis();

        for(int i = 0; i < 10; i++){
            graph.calculateShortestPath(0, 6);
            graph.calculateShortestPath(4, 7);
            graph.calculateShortestPath(7, 0);
            graph.calculateShortestPath(10631, 10630);
            graph.calculateShortestPath(956, 1092);
            graph.calculateShortestPath(10631, 10630);
            graph.calculateShortestPath(797, 816);
            graph.calculateShortestPath(29, 1175);
            graph.calculateShortestPath(29, 1175);
            graph.calculateShortestPath(232, 6055);
            graph.calculateShortestPath(32, 6007);
        }
        long end = System.currentTimeMillis();

        long timeToLoad = loaded - start;
        long timeToSearch = end - loaded;        
        long total = end - start;

        System.out.println("load:\t" + timeToLoad);
        System.out.println("search:\t" + timeToSearch);
        System.out.println("total:\t" + total);
    }

    public static void main(String... args) {
        if(args.length < 2){
            System.exit(1);
        }

	long startup = Long.parseLong(args[0]);
	System.out.println(String.format("Started in %dms", System.currentTimeMillis() - startup));

        int edges = Integer.parseInt(args[1]);
        int iterations = args.length > 1 ? Integer.parseInt(args[2]) : 1;

        int[] edges_data = DataLoader.load(edges);

        int max = edges_data[0];
        for(int i = 1; i < edges_data.length; i++){
            int current = edges_data[i];
            if(current > max)
                max = current;
        }

        for (int i = 0; i < iterations; i++)
            iterateTest(max, edges_data, i);
    }
}
