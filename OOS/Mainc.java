class ComplexNumber {
    private double real;
    private double imaginary;

    public ComplexNumber() {
        this.real = 0;
        this.imaginary = 0;
    }

    public ComplexNumber(double real) {
        this.real = real;
        this.imaginary = 0;
    }

    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public ComplexNumber add(ComplexNumber other) {
        return new ComplexNumber(this.real + other.real, this.imaginary + other.imaginary);
    }

    public ComplexNumber multiply(ComplexNumber other) {
        double realPart = this.real * other.real - this.imaginary * other.imaginary;
        double imaginaryPart = this.real * other.imaginary + this.imaginary * other.real;
        return new ComplexNumber(realPart, imaginaryPart);
    }

    @Override
    public String toString() {
        return real + (imaginary >= 0 ? "+" : "") + imaginary + "i";
    }
}

public class Mainc {
    public static void main(String[] args) {
        ComplexNumber c1 = new ComplexNumber(3, 2);
        ComplexNumber c2 = new ComplexNumber(4, -2);

        ComplexNumber sum = c1.add(c2);
        ComplexNumber product = c1.multiply(c2);

        System.out.println("Sum: " + sum);
        System.out.println("Product: " + product);
    }
}

