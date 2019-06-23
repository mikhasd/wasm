public class Main {

    private static void iterateTest(int edges, int[] edges_data, int iteration) {
        System.out.println("iteration:\t" + iteration);

        long start = System.currentTimeMillis();
        Graph graph = new Graph(edges);
        for (int i = 0; i < edges * 2; i += 2) {
            int from = edges_data[i];
            int to = edges_data[i + 1];
            graph.addEdge(from, to, (byte)1);
        }
        long loaded = System.currentTimeMillis();

        graph.calculateShortestPath(0, 6);
        graph.calculateShortestPath(4, 7);
        graph.calculateShortestPath(7, 0);
        graph.calculateShortestPath(16232, 15536);
        graph.calculateShortestPath(15047, 15389);
        graph.calculateShortestPath(15047, 17972);
        graph.calculateShortestPath(10631, 10630);
        graph.calculateShortestPath(956, 1092);
        graph.calculateShortestPath(10631, 10630);
        graph.calculateShortestPath(797, 816);
        graph.calculateShortestPath(29, 1175);

        long end = System.currentTimeMillis();

        long timeToLoad = loaded - start;
        long timeToSearch = end - loaded;        
        long total = end - start;

        System.out.println("load:\t" + timeToLoad);
        System.out.println("search:\t" + timeToSearch);
        System.out.println("total:\t" + total);
    }

    public static void main(String... args) {
        if(args.length < 1){
            System.exit(1);
        }

        int edges = Integer.parseInt(args[0]);
        int iterations = args.length > 1 ? Integer.parseInt(args[1]) : 1;

        int[] edges_data = DataLoader.load(edges);

        for (int i = 0; i < iterations; i++)
            iterateTest(edges, edges_data, i);
    }
}
