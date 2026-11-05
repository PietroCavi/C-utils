This utils directory contains 5 utils:

1. **`array_list.h`** : a simple generic array_list implementation
2. **`terminal_screen.h`**: a way to display array of pixels on the terminal
3. **`parallel_unit.h`**: a simple interface to create very basic thread pools with POSIX threads
4. **`timerino.h`**: a stopwatch utility to measure execution times
5. **`polly.h`**: an extremely primitive way of polling keyboard inputs on the terminal (it's basically a system wide key logger)

These utils aim to take away the little inconveniences that you can usually encounter while writing C code, they usually lack security controls and personally I would not consider them "safe", they are made for personal projects where code safety is not a concern. While writing code like this usually apply a simple principle, which is: "If a malloc fails... you have bigger fishes to fry than handling the NULL pointer".

Having said that I still of course check for memory leaks, unallocated semaphores, and the moment there aren't any. These utilities don't use sockets in any capacity, so when I'm talking about safety I'm talking about crashes of course.

My only goal is to provide a simplest interface possible for things that should be simple by design!

## Plans:

&nbsp;&nbsp;&nbsp;&nbsp;[-] Add a brief documentation for every utils

