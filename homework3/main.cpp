#include <iostream>
#include "list.h"
#include <sstream>
#include <cmath>
#include <cassert>
using namespace std;

int rpn(string);
void test();

int main(int argc, char* argv[]){

    //to be able to 
    if(argc == 3 && (string)argv[1] == "-p")
    {
        cout << rpn(argv[2]) << endl;

        return 0;
    }

    //asking user for the string
    cout << "Enter an RPN Expression: ";
    string RPN;
    getline(cin, RPN);
    //getting the result from the rpn function and giving it back to user
    int result = rpn(RPN);
    cout << "Answer:" << result << endl;

    //test function to check a few cases
    test();
    

    
    return 0;
}

int rpn(string rpn){
    //creating object
    List rpnList;

    //putting the rpn string into a stringstream (makes it easier to go one by one)
    stringstream rpnstream(rpn);
    string temp;
    


    while(rpnstream >> temp){

        //if the string is not one of the operators then it must be an int and be pushed to the list
        if(temp != "+"  && temp != "-" && temp != "*" && temp != "/"){
            //converting the string to an int (using another strigstream)
            stringstream intConversion(temp);
            int intToPush;
            intConversion >> intToPush; 

            //pushing to the list
            rpnList.push(intToPush);
        }else{
            //getting the first two nodes in the list
            int intOne = rpnList.pop();
            int intTwo = rpnList.pop();
            
            //do the correct operation and push the result back to the list
            if(temp == "*")rpnList.push(intTwo * intOne);
            if(temp == "+")rpnList.push(intTwo + intOne);
            if(temp == "-")rpnList.push(intTwo - intOne);
            if(temp == "/")rpnList.push(intTwo / intOne);

        }
        
    }
    //return answer
    return rpnList.top();

}


void test(){
    string testOne = "3 4 + 5 6 - * ";
    string testTwo = "10 5 / 3 -";
    string testThree = "2 5 + 2 - 8 9 + +";
    assert(rpn(testOne) == -7);
    assert(rpn(testTwo) == -1);
    assert(rpn(testThree) == 22);
    cout << "All test cases passed";
}