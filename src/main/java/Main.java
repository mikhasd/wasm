public class Main {
    public static void main(String... args) {
        int edges = Integer.parseInt(args[0]);
        int iterations = args.length > 1 ? Integer.parseInt(args[1]) : 1;

        int[] edges_data = DataLoader.load(edges);

        for (int i = 0; i < iterations; i++)
            iterateTest(edges, edges_data);
    }

    private static void iterateTest(int edges, int[] edges_data) {
        long start = System.currentTimeMillis();
        Graph graph = new Graph(edges);
        for (int i = 0; i < edges * 2; i += 2) {
            int from = edges_data[i];
            int to = edges_data[i + 1];
            graph.addEdge(from, to, 1);
        }
        calculate_path(graph, 0, 6);
        calculate_path(graph, 4, 7);
        calculate_path(graph, 7, 0);
        calculate_path(graph, 16232, 15536);
        calculate_path(graph, 15047, 15389);
        calculate_path(graph, 15047, 17972);
        calculate_path(graph, 10631, 10630);
        calculate_path(graph, 956, 1092);

        long end = System.currentTimeMillis();
        long total = end - start;
        System.out.println("It took " + total + "ms");
    }

    static void calculate_path(Graph graph, int from, int to) {
        graph.calculateShortestPath(from, to);
    }
}
