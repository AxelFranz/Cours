import javax.swing.*;

public class App {
    public static void main(String[] args) {
        JFrame window = new JFrame("Hello World");
        window.setSize(200,100);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
        PointModele point = new PointModele(3,5);
    }
}
