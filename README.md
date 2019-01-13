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
When our program stops at the breakpoint, the second line has not run yet. So the value of `fill` is still `false` until we continue or step to the next line. 

## What can we see once we've stopped at a line?
* Values of variables
  * There should be a box at the bottom that tells you the value of variables in the current scope. You can also hover over variables in your program to get the value. No more print statements whew!
  ![variables xcode](images/variablesxcode.png)
  ![variables vs](images/variablesvs.png)
* Stack
  * You can see what function(s) you're inside of. 
  ![stack xcode](images/stackxcode.png)
  ![stack vs](images/stackvs.png)
  
## Continue
To continue to the next breakpoint, click "continue." Everything in between will be run, but you don't stop at each line. 
![continue xcode](images/continuexcode.png)
![continue vs](images/continuevs.png)
For example, if we are at the first breakpoint in the following code snippet and we click "continue," we will run the code until the second breakpoint where we stop.
```cpp
void printRectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        bool fill = false;
        if (i == 0 || i == height - 1) { // first breakpoint set here
            fill = true;
        }
        printLine(width, fill); // second breakpoint set here
    }
}
```

##  Step into
To run each line of code one by one, click "step into."

![step into xcode](images/stepintoxcode.png)
![step into vs](images/stepintovs.png)

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
With breakpoints, "continue," and "step into," you can already step through your program and see how variables change. The next features are ones you can use to step through your program more quickly. There are also even more features of debuggers but these are the ones we think you might use. 

## Step over

![step over vs](images/stepovervs.png)

If you come to a line where you call a function, "step over" will continue until after that function has finished being run. 
For example, if we are in `printRectangle` and we step over `printLine`, we will continue to the top of the for loop to check the condition `i < height`.
```cpp
void printLine(int width, bool fill) {
    for (int i = 0; i < width; i++) {
        if (i != 0 && i != width && !fill) {
            cout << " ";
        } else {
            cout << "*";
        }
    }
    cout << endl;
}

void printRectangle(int height, int width) {
    for (int i = 0; i < height; i++) { // all of printLine will be run and we will stop here
        bool fill = false;
        if (i == 0 || i == height - 1) {
            fill = true;
        }
        printLine(width, fill); // breakpoint set here
    }
}
```

## Step out
If you are inside a function and would like to continue until you exit that function, use "step out."

![step out vs](images/stepoutvs.png)

For example, let's say you have stepped into the `printLine(width, fill)` function while debugging printRectangle. Now, as you are inside printLine, use "step out" if you want to skip the rest of printLine and continue to what happens after the `printLine(width, fill)` line finishes, back in the function printRectangle.

## Watchpoints
Watchpoints are used to track any changes to the value of a variable. Instead of stopping execution when execution hits a particular line or function like a breakpoint does, watchpoints stop execution when the data of interest changes. Watchpoints are especially useful when you have variables that are changed on multiple lines or multiple if statements, or when you think you have a bug that relates to specific variables.

Note: you must set a breakpoint and start debugging the program before setting a watchpoint.

In XCode, while debugging, right-click the variable of interest listed in the bottom left window and select watch "<variable-name>".

![watchpoint xcode](images/watchpointxcode.png)

In Visual Studio, there are two ways to watch a variable: go to Debug tab -> New Breakpoint -> Data Breakpoint and put the address of the variable you are interested in (i.e. &fill). By default this will be a regular watchpoint that breaks execution when value changes, but if you're interested, there are additional options like "Conditional expression" which allows you to choose to break when some condition is true (i.e. fill == false) or just when the value changes, and also an option for "Hit Count" which may be useful if you have a number variable and you want it to break when it hits a certain value.
Or, right-click the variable (in the bottom left window or in the code) and select Add Watch, which sets a default watchpoint that breaks when the value changes.

![watchpoint vs](images/watchpointvs.png)

## Debugging the sample program

Okay, so how to fix the bug in this program? The problem is that the right side of the rectangle is not printed out. Looking at the code, we can guess that we are printing a " " when we should be printing a "\*". So, we can set a breakpoint at the line `cout << " "` to see why the space is printed out.

![debug breakpoint xcode](images/debugvs.png)
![debug breakpoint vs](images/debugxcode.png)

If you continue or step until `i = 7` (the rightmost index, where the right side of the rectangle should be), you'll see that this breakpoint is still hit. Looking at the if condition and the values of the variables, you see that i = 7 but width = 8. So, by debugging, you see that the error is the if condition should be checking for `i != width - 1` rather than `i != width`.

## Try it yourself!

Now that you know what breakpoints and watchpoints are and how to step into, step over, step out, and continue, try it yourself on the buggy code in file lemonadeChange_bug.cpp.

[lemonade stand](images/lemonadeStand.png)

The question is from https://leetcode.com/problems/lemonade-change/ :
 
At a lemonade stand, each lemonade costs $5. 
 
Each customer will only buy one lemonade and must pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer (i.e. if customer pays with $10, give back $5. if customer pays with $20, give back $15). You are given an array of integers that represents customers coming in that order and paying with a bill of that value (i.e. {5, 10, 5} means first a customer came and paid with a 5, then a second customer came and paid with a $10, and later a 3rd customer came and paid with a $5.)

Note that you don't have any change in hand at first.
 
Return true if and only if you can provide every customer with correct change.
 
The code in lemonadeChange_bug.cpp is not correct. Use your newly acquired debugging skills to pass all the test cases (the first one works already).
```
int twoCustomerTest[2] = { 5, 10 }; // first customer pays with a 5, then second customer pays with 10
assert( lemonadeChange(twoCustomerTest, 2) ); // you should have change for the second customer with the $5 from the first customer
    
int threeCustomerTest[3] = { 5, 10, 20 };
assert( lemonadeChange(threeCustomerTest, 3) == false ); // you should not have enough change for the 3rd customer
    
int fiveCustomerTest[5] = { 5, 10, 5, 20, 5 };
assert( lemonadeChange(fiveCustomerTest, 5) == false );
```
