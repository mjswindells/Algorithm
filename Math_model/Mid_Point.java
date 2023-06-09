class Mid_Point {
    static int i = 1;

    public static void main(String[] args) {
        cal(1.0, 2.0, -0.2, 5.0);
    }

    public static double mid(double a, double b) {
        double t = (a + b) / 2.0;
        t = Math.pow(t, 3) - 3;
        return t;
    }

    public static void cal(double a, double b, double fa, double fb) {
        double c = (a + b) / 2.0;
        System.out.println(i++ + " " + c);

        if (Math.abs(fb - fa) < 0.000000001) {
            return;
        } else {
            double fc = mid(a, b);

            if (fc < 0) {
                cal(c, b, fc, fb);
                return;
            } else {
                cal(a, c, fa, fc);
                return;
            }
        }
    }
}
