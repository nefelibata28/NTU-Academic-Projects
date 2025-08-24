package ques3_2_Surface_Area;

public class Cube implements Shape{
    private int length;

    public Cube(int length) {
        this.length = length;
    }

    @Override
    public double area() {
        Square square = new Square(length);
        return 4 * square.area() + new Square(length).area();
    }
}