class Math {
    private int a, b;

    public Math(int _a, int _b) {
        a = _a;
        b = _b;
    }

    public int max() { return a > b ? a : b;}
    public int min() { return a < b ? a : b;}
    public float avg() { return (a + b) / 2;}
}

class Ex1 {
    public static void main(String[] args) {
        Math math = new Math(2, 3);
        System.out.println("max: " + math.max());
        System.out.println("min: " + math.min());
        System.out.println("avg: " + math.avg());
    }
}
