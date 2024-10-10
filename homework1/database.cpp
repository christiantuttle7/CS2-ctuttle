
#include "database.h"







databases::database::database(){

    //allocate memory
    for(int i = 0; i <100; i++){
        movieDatabase[i] = new movies::movie;
    }
    

    //opening file
    ifstream movieFile ("movies.csv");

    //each line of the file will be put into this string
    string tempLine;

    string xtitleId;
    string xtitle;
    int xyear;
    string xdirector;
    string xgenre;
    float xrating;


    int movieCounter = 0;    
    while( getline(movieFile, tempLine, '\n')){
        stringstream line(tempLine);
        
        
        //get the title id and store it
        getline(line, xtitleId, ',' );
        movieDatabase[movieCounter]->setTitleID(xtitleId);

        
        //get the title and store it
        getline(line, xtitle, ',' );
        movieDatabase[movieCounter]->setTitle(xtitle);

        //get the year, store as an int
        line >> xyear;
        line.ignore();

        movieDatabase[movieCounter]->setYear(xyear);

        //get the genre and store it
        getline(line, xgenre, ',');
        movieDatabase[movieCounter]->setGenre(xgenre);

        //get the rating, store as float
        line >> xrating;
        line.ignore();
        movieDatabase[movieCounter]->setRating(xrating);


        //get Director and store it
        getline(line, xdirector, ',');
        movieDatabase[movieCounter]->setDirector(xdirector);

        movieCounter++;

        


    }

    numberOfMovies = movieCounter;

    
}

//deconstructor
databases::database::~database(){
    for(int i = 0; i < 100; i++){
        delete movieDatabase[i];
    }
}





//print out all of the movies
void databases::database::printMovies(){
    for(int i = 0; i < numberOfMovies; i++){
        cout << "Movie " << i+1 <<": " << endl;
        cout << "Title: " <<movieDatabase[i]->getTitle() << endl;
        cout << "Director: " <<movieDatabase[i]->getDirector() << endl;
        cout <<"ID: " << movieDatabase[i]->getTitleID() << endl;
        cout <<"Genre: " <<movieDatabase[i]->getGenre() << endl;
        cout <<"Year: " <<movieDatabase[i]->getYear() << endl;
        cout <<"Rating: " <<movieDatabase[i]->getRating() << endl;
        cout << endl;
    }
}



void databases::database::addMovie(){
    string tempTitle, tempTitleId,  tempGenre, tempDirector;
    int tempYear;
    float tempRating;

    
    //title
    cout << "What is the title of the movie? " ;
    getline(cin, tempTitle);
    movieDatabase[numberOfMovies]->setTitle(tempTitle);

    //title ID
    cout <<"What is the title id? ";
    getline(cin, tempTitleId);
    movieDatabase[numberOfMovies]->setTitleID(tempTitleId);

    //year
    cout << "What is the year?";
    cin >> tempYear;
    cin.ignore();
    movieDatabase[numberOfMovies]->setYear(tempYear);

    //genre
    cout << "What is the genre? ";
    getline(cin, tempGenre);
    movieDatabase[numberOfMovies]->setGenre(tempGenre);

    //rating
    cout <<"What is the rating? ";
    cin >> tempRating;
    cin.ignore();
    movieDatabase[numberOfMovies]->setRating(tempRating);

    //director
    cout << "Who is the director? ";
    getline(cin, tempDirector);
    movieDatabase[numberOfMovies]->setDirector(tempDirector);

    numberOfMovies++;
    cout << "Movie Added" << endl;
}


void databases::database::searchForMovie(){
    string searchInput;
    bool movieFoundBool = false;
    int movieFoundNum = 0;

    
    cout <<"What is the title or titleID of the movie you want: ";
    getline(cin, searchInput);
    //go through every movie and see if the search input matches te movie
    for(int i = 0; i < numberOfMovies; i++){
        if(movieDatabase[i]->getTitle() == searchInput || movieDatabase[i]->getTitleID() == searchInput){
            movieFoundBool = true;
            movieFoundNum = i;
        }
    }
    //if movies found display the movie
    if(movieFoundBool){
        cout << "\nMovie Found!" << endl;
        cout << "Title: " <<movieDatabase[movieFoundNum]->getTitle() << endl;
        cout << "Director: " <<movieDatabase[movieFoundNum]->getDirector() << endl;
        cout <<"ID: " << movieDatabase[movieFoundNum]->getTitleID() << endl;
        cout <<"Genre: " <<movieDatabase[movieFoundNum]->getGenre() << endl;
        cout <<"Year: " <<movieDatabase[movieFoundNum]->getYear() << endl;
        cout <<"Rating: " <<movieDatabase[movieFoundNum]->getRating() << endl;
        cout << endl;

    }else{
        cout << "Movie Not Found :(" << endl;
    }
}

void databases::database::removeMovie(){
    
    //finding out the id of the movie the user would like to delete
    bool movieFound = false;
    string chosenMovie;
    cout <<"What is the ID of the movie you would like to remove: ";
    cin >>chosenMovie;
    cin.ignore();
    int chosenMovieNumber;

    //finding out which movie has the id provided
    for(int k = 0; k < numberOfMovies; k++){
        if(movieDatabase[k]->getTitleID() == chosenMovie){
            chosenMovieNumber = k;
            movieFound = true;
        }
    }
    
    //move every movie that is ahead of the movie being deleted down by 1
    if(movieFound){
        for(int i = chosenMovieNumber; i < numberOfMovies; i++){
            movieDatabase[i]->setDirector(movieDatabase[i+1]->getDirector());
            movieDatabase[i]->setTitle(movieDatabase[i+1]->getTitle());
            movieDatabase[i]->setTitleID(movieDatabase[i+1]->getTitleID());
            movieDatabase[i]->setGenre(movieDatabase[i+1]->getGenre());
            movieDatabase[i]->setYear(movieDatabase[i+1]->getYear());
            movieDatabase[i]->setRating(movieDatabase[i+1]->getRating());
        }

    
        numberOfMovies --;
        std::cout << "Movie Removed" << endl;;
    
    }
    else{
        cout << "Movie Not Found " << endl;
    }
   

}


void databases::database::exportMovies(){
    ofstream movieExport ("moviesExport.csv");

    //exporting the movie list to a different csv.
    for(int i = 0; i < numberOfMovies; i++){
        
        movieExport <<movieDatabase[i]->getTitleID() << ',';
        movieExport  <<movieDatabase[i]->getTitle() << ',';
        movieExport << movieDatabase[i]->getYear() << ',';
        movieExport  <<movieDatabase[i]->getGenre() << ',';
        movieExport  <<movieDatabase[i]->getRating() << ',';
        movieExport  <<movieDatabase[i]->getDirector() << endl;
        
    }
    movieExport.close();
}



