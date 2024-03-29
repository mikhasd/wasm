public class Graph {
    private final int edgesSize;
    private final byte[] edges;

    public Graph(int edges){
        this.edgesSize = edges;
        this.edges = new byte[edges * edges];
    }


    private int calc_offset(int x, int y){
        return x + this.edgesSize * y;
    }

    public void addEdge(int from, int to, byte weight){
        this.edges[calc_offset( from, to)] = weight;
        this.edges[calc_offset( to, from)] = weight;
    }

    public byte getWeight(int from, int to){
        return this.edges[calc_offset(from, to)];
    }

    List getNeighbors(int vertex){
        List neighbors = new List(this.edgesSize / 2);
        for(int i = 0; i< this.edgesSize; i ++){
            if(vertex != i){
                byte weight = getWeight(i, vertex);
                if(weight > 0){
                    neighbors.add(i);
                }
            }
        }
        return neighbors;
    }

    private int[] calculateCostTable(Graph this, int from){
        byte[] costs = new byte[this.edgesSize];
        int[] source = new int[this.edgesSize];
        for(int i = 0; i < this.edgesSize; i++){
            costs[i] = -1;
            source[i] = -1;
        }

        costs[from] = 0;
        source[from] = from;

        PriorityQueue queue = new PriorityQueue();

        queue.push(from, 0);

        while(!queue.isEmpty()){
            int current = queue.pop();
            byte currentCost = costs[current];

            List neighbors = getNeighbors(current);
            for(int i = 0; i < neighbors.size; i++){
                int neighbor = neighbors.get(i);
                byte cost = (byte) (currentCost + this.getWeight(neighbor, current));
                int neighbor_cost = costs[neighbor];

                if(neighbor_cost == -1 || neighbor_cost > cost){
                    costs[neighbor] = cost;
                    source[neighbor] = current;
                    queue.push(neighbor, cost);
                }
            }
        }
        
        return source;
    }

    public List calculateShortestPath(int from, int to){
        List path = new List(10);
        path.add(to);

        int[] source = calculateCostTable(from);

        int previous = source[to];

        while(previous != -1 && previous != from){
            path.add(previous);
            previous = source[previous];
        }

        if(previous == -1){
            return new List(0);
        } else {
            path.add(previous);
            return path;
        }
    }
}
