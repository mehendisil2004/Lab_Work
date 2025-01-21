class Complex {
    int real;
    int imaginary;

    Complex() {
        real = 0;
        imaginary = 0;
    }

    Complex(int real) {
        this.real = real;
        imaginary = 0;
    }

    Complex(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    void addComplex(Complex ob1, Complex ob2) {
        int realSum = ob1.real + ob2.real;
        int imaginarySum = ob1.imaginary + ob2.imaginary;
        System.out.println(realSum + "+" + imaginarySum + "i");
    }

    void productComplex(Complex ob1, Complex ob2) {
        int realPart = ob1.real * ob2.real - ob1.imaginary * ob2.imaginary;
        int imaginaryPart = ob1.real * ob2.imaginary + ob1.imaginary * ob2.real;
        System.out.println(realPart + "+" + imaginaryPart + "i");
    }

    public static void main(String[] args) {
        Complex ob1 = new Complex(3, 2);  
        Complex ob2 = new Complex(4, -2);
        Complex ob3 = new Complex();

        System.out.println("Number after adding:");
        ob3.addComplex(ob1, ob2);

        System.out.println("Number after multiplying:");
        ob3.productComplex(ob1, ob2);
    }
}
