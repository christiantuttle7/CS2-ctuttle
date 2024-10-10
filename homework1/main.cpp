

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
        cout << "1. Print movies" << endl;
        cout << "2. Add a movie" << endl;
        cout << "3. Remove movie" << endl;
        cout << "4. Search for a movie" << endl;
        cout << "5. Export movies to a file" << endl;
        cout << "6. Exit Program" << endl;

        int userInput;
        
    //get user input
        cin >> userInput;
        cin.ignore();
        
        //switch that will call on the function the user wants
        switch (userInput){
            case 1:
                nice.printMovies();
                break;
            case 2:
                nice.addMovie();
                break;
            case 3:
                nice.removeMovie();
                break;
            case 4:
                nice.searchForMovie();
                break;
            case 5:
                nice.exportMovies();
                break;
            case 6:
                keepGoing = false;
                break;

        }

    }

    return 0;
}
