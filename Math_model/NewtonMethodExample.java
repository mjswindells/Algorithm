import java.util.function.*;

public class NewtonMethodExample {
    static int i=1;
    public static void main(String[] args) {
        Function<Double, Double> function = x -> Math.pow(x, 3) - 3;
        Function<Double, Double> derivative = x -> 3 * Math.pow(x, 2);
        
        double initialGuess = 1.5;
        
        double root = findRoot(function, derivative, initialGuess);
        
        System.out.println(i++ + " " + root);
    }
    
    public static double findRoot(Function<Double, Double> function, Function<Double, Double> derivative, double initialGuess) {
        double x = initialGuess;
        double tolerance = 0.0000000001;
        
        while (Math.abs(function.apply(x)) > tolerance) {
            System.out.println(i++ + " " + x);
            x = x - function.apply(x) / derivative.apply(x);
        }
        
        return x;
    }
}
