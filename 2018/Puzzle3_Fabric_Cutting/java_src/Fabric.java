public class Fabric {
    private int id;
    private int left;
    private int width;
    private int top;
    private int height;
    private int overlap;

    public Fabric(int id, int left, int width, int top, int height)
    {
        this.id = id;
        this.left = left;
        this.width = width;
        this.height = height;
        this.top = top;
    }

    public int getHeight() {
        return height;
    }

    public int getId() {
        return id;
    }

    public int getLeft() {
        return left;
    }

    public int getTop() {
        return top;
    }

    public int getWidth() {
        return width;
    }

    public int getOverlap() {
        return overlap;
    }

    public void set_overlap(int value) {
        this.overlap = value;
    }
}
