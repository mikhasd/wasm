public class PriorityQueue {

    private static class Node {
        int data;
        int priority;
        Node next;
    }

    int size;
    Node head;

    public PriorityQueue() {
        this.size = 0;
        Node head = new Node();
        head.data = 0;
        head.priority = 0;
        head.next = head;
        this.head = head;
    }

    public int pop() {
        if (this.size == 0) {
            return -1;
        }

        Node node = this.head.next;
        int val = node.data;
        this.head.next = node.next;
        this.size--;
        return val;
    }

    void push(int data, int priority) {
        Node head = this.head;

        Node node = new Node();
        node.data = data;
        node.priority = priority;


        Node prev = head;
        Node tmp = head.next;

        while (tmp != head && tmp.priority < priority) {
            prev = tmp;
            tmp = tmp.next;
        }

        prev.next = node;
        node.next = tmp;
        this.size++;
    }

    boolean isEmpty() {
        return this.size == 0;
    }
}
