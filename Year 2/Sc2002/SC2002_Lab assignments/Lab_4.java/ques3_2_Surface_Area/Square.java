package ques3_2_Surface_Area;

public class Square implements Shape{
    private int length;

    public Square(int length) {
        this.length = length;
    }

    @Override
    public double area() {
        return length * length;
    }
}