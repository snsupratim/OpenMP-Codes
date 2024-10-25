class MyRunnable implements Runnable {
    public void run() {
        for (int i = 1; i <= 2; i++) {
            String threadName = Thread.currentThread().getName(); // Get the current thread name
            System.out.println("Runnable Thread " + threadName + " - Count: " + i);
            try {
                Thread.sleep(500); // Sleep for 500 milliseconds
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class Multithread {
    public static void main(String[] args) {
        Thread t1 = new Thread(new MyRunnable());
        Thread t2 = new Thread(new MyRunnable());

        t1.start(); // Start the first thread
        t2.start(); // Start the second thread
    }
}
