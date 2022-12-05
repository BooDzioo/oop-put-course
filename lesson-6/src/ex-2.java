interface Number {
    public double doubleValue();
}

class Logarithm implements Number {
    private double base, argument;

    @Override
    public double doubleValue() {
        return java.lang.Math.log(this.argument) / java.lang.Math.log(this.base);
    }

    public Logarithm(double inputBase, double inputArgument) throws IllegalArgumentException {
        if (inputBase <= 0) {
            throw new IllegalArgumentException("Base should be greater than 0, your base: " + inputBase);
        }
        if (inputBase == 1) {
            throw new IllegalArgumentException("Base should not equal 1, your base: " + inputBase);
        }
        if (inputArgument <= 0) {
            throw new IllegalArgumentException("Argument should be grater than 0, your base: " + inputArgument);
        }

        this.base = inputBase;
        this.argument = inputArgument;
    }
}

class Ex2 {
    public static void main(String[] args) throws Exception {
        try {
            Logarithm log = new Logarithm(0.5, 8);
            System.out.println(log.doubleValue());
        } catch(IllegalArgumentException exception) {
            System.out.println(exception);
            throw new Exception("Logarithm exception: " + exception);
        }
    }
}

