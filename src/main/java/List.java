public class List {

    int elementsSize;
    int size;
    int[] elements;

    public List(int size){
        size = size < 10 ? 10 : size;
        this.elementsSize = size;
        this.elements = new int[size];
        this.size = 0;
    }

    public boolean isEmpty(){
        return this.size == 0;
    }

    private void increaseCapacity(){
        int newSize = (int)(this.size * 1.5);
        int[] newElements = new int[newSize];
        for(int i = 0; i < this.size; i++){
            newElements[i] = this.elements[i];
        }
        this.elementsSize = newSize;

        this.elements = newElements;
    }

    boolean contains(int element){
        for(int i = 0; i < this.size; i++){
            if(this.elements[i] == element){
                return true;
            }
        }
        return false;
    }

    void add(int element){
        if(this.elementsSize == this.size){
            increaseCapacity();
        }
        this.elements[this.size++] = element;
    }

    int get(int index){
        return this.elements[index];
    }
}
