# Debugging Workshop

## Why do we need a debugger?
We could just stare at the code, but this might take a long time (or possibly forever).
We could also use print statements. But this lacks many of the useful features of a debugger, which include:
* Stepping through the code line by line
* Stopping the program at particular points called breakpoints
* Inspecting the value of variables at those points

## Breakpoints
Stop the program at places where you might think there is a problem. Click next to the line number to set a breakpoint at that line. You can disable the breakpoint by clicking again.
![breakpoint xcode](images/breakpointxcode.png)
![breakpoint vs](images/breakpointvs.png)
If we run our code with debugging, the program will stop right **before** running the line of code that we set our breakpoint to. 
For example, if we have the following:
```cpp
bool fill = false;
fill = true; // breakpoint set here
```
When our program stops at the breakpoint, the second line has not run yet. So the value of `fill` is still `false` until we continue or step to the next line. There should be a box at the bottom that tells you the value of variables. You can also hover over variables in your program to get the value. No more print statements whew!

##  Step into
You want to see what happens to the values of different variables as you run each line of the program. To do this, we can click "step into." This looks like:
![step into xcode](images/stepintoxcode.png)
![step into vs](images/stepintocs.png)
If you come to a line where you call a function, "step into" will take you into that function and start at that function's first line.
For example, if we are in `printRectangle` and we step into `printLine`, we will stop at the first line of `printLine`.
```cpp
void printLine(int width, bool fill) {
    for (int i = 0; i < width; i++) { // this is where we will stop if we step into printLine
        if (i != 0 && i != width && !fill) {
            cout << " ";
        } else {
            cout << "*";
        }
    }
    cout << endl;
}

void printRectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        bool fill = false;
        if (i == 0 || i == height - 1) {
            fill = true;
        }
        printLine(width, fill); // breakpoint set here
    }
}
```
