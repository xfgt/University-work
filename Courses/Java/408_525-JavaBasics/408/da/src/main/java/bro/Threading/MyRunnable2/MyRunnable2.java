package bro.Threading.MyRunnable2;

public class MyRunnable2 implements Runnable{

    private final String text;

    public MyRunnable2(String text) {
        this.text = text;
    }

    @Override
    public void run() {
        for(int i = 0; i < 4; i++){
            try {
                Thread.sleep(1000);
                System.out.println(this.text + ": [" + Thread.currentThread().getName() + "] -> " + i);
            }catch (InterruptedException e){
                e.printStackTrace(); // https://www.geeksforgeeks.org/java/java-program-to-print-stack-trace/
                System.out.println("Thread was interrupted");
            }
        }
    }
}
