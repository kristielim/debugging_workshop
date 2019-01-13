/*
 
question from https://leetcode.com/problems/lemonade-change/
 
 At a lemonade stand, each lemonade costs $5. 
 
 Each customer will only buy one lemonade and must pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer (i.e. if customer pays with $10, give back $5. if customer pays with $20, give back $15).
 
 Note that you don't have any change in hand at first.
 
 Return true if and only if you can provide every customer with correct change.
 
 
 Debugging Workshop:
 3 test cases are provided for you (the first one passes already). Use your newly acquired debugging skills to fix the next two cases.
 
 */


#include <iostream>
#include <assert.h>

using namespace std;

int lemonadeChange(int customers[], int nCustomers){
    int fives = 0;
    int tens = 0;
    for ( int i = 0; i < nCustomers; ++i ) {
        if( customers[i] == 5 )
            fives++;
        else if ( customers[i] == 10 ) {
            tens++;
        }
        else if ( customers[i] == 20 ) {
            if( tens > 0 ) /* it's better to give a $10 and a $5 as change,
                            rather than 3 $5s so you have more 5s to make change later */
            {
                tens--;
                fives--;
            }
            else
                fives -= 3;
        }
        else
            return false;
    }
    
    if( fives < 0 || tens < 0 ) return false;
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    int twoCustomerTest[2] = { 5, 10 }; // first customer pays with a 5, then second customer pays with 10
    assert( lemonadeChange(twoCustomerTest, 2) ); // you should have change for the second customer with the $5 from the first customer
    
    int threeCustomerTest[3] = { 5, 10, 20 };
    assert( lemonadeChange(threeCustomerTest, 3) == false ); // you should not have enough change for the 3rd customer
    
    int fiveCustomerTest[5] = { 5, 10, 5, 20, 5 };
    assert( lemonadeChange(fiveCustomerTest, 5) == false );
    
    std::cout << "Woohoo, passed all tests" << std::endl;
    return 0;
}
