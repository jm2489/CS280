public class Complex {
    private double r;
    private double i;

    public Complex(double r, double i) {
        this.r = r;
        this.i = i;
    }

    public Complex add(Complex other) {
        return new Complex(this.r + other.r, this.i + other.i);
    }

    public Complex subtract(Complex other) {
        return new Complex(this.r - other.r, this.i - other.i);
    }

    public Complex multiply(Complex other) {
        return new Complex(this.r * other.r - this.i * other.i, this.r * other.i + this.i * other.r);
    }

    public Complex divide(Complex other) {
        double denom = other.r * other.r + other.i * other.i;
        return new Complex((this.r * other.r + this.i * other.i) / denom, (this.i * other.r - this.r * other.i) / denom);
    }

    @Override
    public String toString() {
        return String.format("(%.2f, %.2fj)", r, i);
    }

    public static void main(String[] args) {
        Complex a = new Complex(2, 3);
        Complex b = new Complex(1, -1);
        System.out.println(a + " + " + b + " = " + a.add(b));
        System.out.println(a + " - " + b + " = " + a.subtract(b));
        System.out.println(a + " * " + b + " = " + a.multiply(b));
        System.out.println(a + " / " + b + " = " + a.divide(b));
    }
}
