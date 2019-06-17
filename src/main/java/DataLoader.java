import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.concurrent.atomic.AtomicInteger;

import static java.lang.Integer.parseInt;

public enum DataLoader {
    ;
    public static int[] load(int edges) {
        final AtomicInteger edgesRead = new AtomicInteger();
        int[] data = new int[(edges + 1) * 2];
        BufferedReader reader = getDataReader();
        reader.lines()
                .filter(line -> line.charAt(0) != '#')
                .map(line -> line.split("\t"))
                .map(vertices -> new int[]{
                        parseInt(vertices[0]),
                        parseInt(vertices[1])
                })
                .filter(vertices -> vertices[0] < edges && vertices[1] < edges)
                .limit(edges)
                .forEach(vertices -> {
                    data[edgesRead.getAndIncrement()] = vertices[0];
                    data[edgesRead.getAndIncrement()] = vertices[1];
                });


        return data;
    }

    private static BufferedReader getDataReader() {
        InputStream roadNetStream = Thread.currentThread().getContextClassLoader().getResourceAsStream("data.txt");
        Objects.requireNonNull(roadNetStream, "Data file not found");
        return new BufferedReader(new InputStreamReader(roadNetStream));
    }
}
