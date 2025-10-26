# Single-threading and multithreading

Threading - Allows a program to run multiple tasks simultaneously.\
Helps improve performance with time-consuming operations\
(File I/O, network communications, or any background tasks).

* How to create a Thread:
  * Option 1: Extend the Thread class (simple, but limited)
  * Option 2: Implement the Runnable interface (better)

<hr>

### Information about construction (`Runnable`, `Thread`)
1. We instantiate our class implementing the `Runnable` interface. (`@Override run()`)
```java
public class MyRunnable1 implements Runnable {
    @Override
    public void run() {
        // here we add the code which we want to run on a separate Thread
    }
}
```

2. We instantiate `Thread` object and construct it with our `Runnable` object as an **argument**.
```java
MyRunnable1 myRunnable1 = new MyRunnable1(); // implements Runnable interface (.run() method)

Thread thread = new Thread(myRunnable1);
// Thread object constructor accepts a class implementing the Runnable interface. (has run() method overriden)
```
<hr>

### Occurring problems 

We need to separate the 5-second timer from our `main` program (main thread). 
We do achieve that by moving the logic into a separate class implementing the `Runnable` interface.

* **Umbrella after rain**
   * After doing `thread.start()`, we are expected to input a string in order to end the program even when the timer was already finished.
   * Another case is that whether we decide to wait the timer without entering an input it goes `"Time's up!"` and the program (main thread) won't end until it receives an input.
   
    **Fix:** 
    * We can set a daemon thread to `true`. Daemon thread will end when the main is over.\
       We do it with `thread.setDaemon(true)` before `thread.start()`.
    * Additionally we add `System.exit(0)` in the overridden `run()` method of `MyRunnable1` 
```java
...
        
if(i == 10){
System.out.println("Time's up!");
// Here the thread won't exit until the main thread is done.

    // if daemon(true) and want to exit after time
    System.exit(0);
}

    ...
```
<hr>





### Multithreading

Enables a program to run multiple threads concurrently\
Thread - A set of instructions that run independently
Useful for background tasks or time-consuming operations.

1. We create the threads with anonymous constructor passing to it a string just for a name.
```java
Thread thread0 = new Thread(new MyRunnable2("THIS IS THREAD 0")); // anonymous
Thread thread1 = new Thread(new MyRunnable2("THIS IS THREAD 1")); // anonymous

            System.out.println("Game start!");

            thread0.start();
            thread1.start();

            System.out.println("Game over!");
```

Inside `MyRunnable2`:
```java
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
                // THIS IS THREAD X: [Thread-Y] -> i
                
            }catch (InterruptedException e){
                System.out.println("Thread was interrupted");
            }
        }
    }
}
```


2. Output (we've got a problem):
```
Game start!
Game over!
THIS IS THREAD 0: [Thread-0] -> 0
THIS IS THREAD 1: [Thread-1] -> 0
```

3.Fixing the problem
```java
...
try{
    
    // The main thread will wait the others to finish.
    thread0.join();
    thread1.join();

} catch (InterruptedException e){
    System.out.println("Thread was interrupted");
}
```

4. Output (fix)
```
Game start!
THIS IS THREAD 0: [Thread-0] -> 0
THIS IS THREAD 1: [Thread-1] -> 0
THIS IS THREAD 1: [Thread-1] -> 1
THIS IS THREAD 0: [Thread-0] -> 1
THIS IS THREAD 0: [Thread-0] -> 2
THIS IS THREAD 1: [Thread-1] -> 2
THIS IS THREAD 1: [Thread-1] -> 3
THIS IS THREAD 0: [Thread-0] -> 3
Game over!
```

More information [here](https://medium.com/@harshanacz/java-multithreading-a-deep-dive-in-one-article-538fce73fe33).\
*-xfgt*