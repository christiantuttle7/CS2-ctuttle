
#include "database.h"



int main(){



    //create object  
    databases::database nice;
    

    //while this is true the program will keep asking the user what they would like to do
    bool keepGoing = true;

    while(keepGoing){
        
        //printing user interface
        cout << endl;
        cout << "What would you like to do (enter number)?" << endl;
        cout << "1. Print media" << endl;
        cout << "2. Add media" << endl;
        cout << "3. Remove media" << endl;
        cout << "4. Search for media" << endl;
        cout << "5. Export mdias to a file" << endl;
        cout << "6. Exit Program" << endl;

        int userInput;
        
    //get user input
        cin >> userInput;
        cin.ignore();
        
        //switch that will call on the function the user wants
        switch (userInput){
            case 1:
                nice.printMedia();
                break;
            case 2:
                nice.addMedia();
                break;
            case 3:
                nice.removeMedia();
                break;
            case 4:
                nice.searchMedia();
                break;
            case 5:
                nice.exportMedia();
                break;
            case 6:
                keepGoing = false;
                break;

        }

    }

    return 0;
}
