package bro.Threading.MyRunnable1;

public class MyRunnable1 implements Runnable{
    @Override
    public void run() {
        // here we add the code which we want to run on a separate Thread


        for(int i = 1; i <= 3; i++){


            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Interrupted exception: Thread was interrupted");
            }

            if(i == 3){
                System.out.println("Time's up!");
                // Here the thread won't exit until the main thread is done.

                // if daemon(true) and want to exit after time
                System.exit(0);
            }


        }




    }
}
