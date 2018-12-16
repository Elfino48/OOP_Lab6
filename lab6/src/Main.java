import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        System.out.print("Введите значения переменных X, N и M: ");
        Scanner sc = new Scanner(System.in);

        while(true) {
            // Приймаємо дані з консолі
            int x = sc.nextInt();
            int n = sc.nextInt();
            int m = sc.nextInt();


            double res = 0;

            try {
                res = calculate(x, n, m);
                System.out.println(res);
            } catch (ExpressionException e) {
                System.out.println(e.getMessage());
            }
        }


    }

    private static double fact(int n) throws ExpressionException {

        // У разі, якщо n < 1, викликаємо виняток через неможливість порахувати факторіал
        if(n < 1) throw new ExpressionException("Число" +
                " n меньше 1, невозможно подсчитать факториал." +
                "\nВведите корректные значения X, N и M:");

        double res = 1;

        for ( int i = 1; i <= n; i++ ){
            res *= i;
        }

        return res;
    }

    private static double calculate(int x, int n, int m) throws ExpressionException {
        // У разі, якщо n == m, викликаємо виняток
        if ( n == m ){
            throw new ExpressionException("Деление на ноль.\n" +
                    "Введите корректные значения X, N и M");
        }

        return Math.pow(Math.atan(x+1),2) - (fact(n))/(n-m);
    }

}

