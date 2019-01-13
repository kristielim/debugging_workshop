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
```
bool fill = false;
fill = true; // breakpoint set here
```
When our program stops at the breakpoint, the second line has not run yet. So the value of `fill` is still `false` until we continue or step to the next line. 

##  Stepping through the program
