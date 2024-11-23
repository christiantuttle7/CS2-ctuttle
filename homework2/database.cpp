
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
void databases::database::printMedia(){
    int mediaType;
    cout << endl;
    cout << "What type of media would you like to display" << endl;
    cout << "1. Movies\n2. Music\n3. TV Shows" << endl;
    cin >> mediaType;


    //display movies
    if(mediaType == 1){
        cout << "All Movies" << endl;
        for(int i = 0; i < numberOfMovies; i++){
            cout << "Movie " << i+1 <<": " << endl;
            cout << "Title: " <<movieDatabase[i]->getTitle() << endl;
            cout << "Director: " <<movieDatabase[i]->getDirector() << endl;
            cout <<"ID: " << movieDatabase[i]->getId() << endl;
            cout <<"Genre: " <<movieDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<movieDatabase[i]->getYear() << endl;
            cout <<"Rating: " <<movieDatabase[i]->getRating() << endl;
            cout << endl;
        }
    }
    //display music
    else if(mediaType == 2){
        for(int i = 0; i < numberOfMovies; i++){
            cout << "Album " << i+1 <<": " << endl;
            cout << "Title: " <<musicDatabase[i]->getTitle() << endl;
            cout << "Composer: " <<musicDatabase[i]->getComposer() << endl;
            cout <<"ID: " << musicDatabase[i]->getId() << endl;
            cout <<"Genre: " <<musicDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<musicDatabase[i]->getYear() << endl;
            cout <<"Number Of Tracks: " <<musicDatabase[i]->getNumOfTracks() << endl;
            cout <<"Total Playtime: " <<musicDatabase[i]->getTotalPlaytime() << endl;
            cout << endl;
        }

    }
    //display tv shows
    else{
        for(int i = 0; i < numberOfTvShows; i++){
            cout << "Album " << i+1 <<": " << endl;
            cout << "Title: " <<tvshowDatabase[i]->getTitle() << endl;
            cout <<"ID: " << tvshowDatabase[i]->getId() << endl;
            cout <<"Genre: " <<tvshowDatabase[i]->getGenre() << endl;
            cout <<"Year: " <<tvshowDatabase[i]->getYear() << endl;
            cout <<"Number Of Episodes: " <<tvshowDatabase[i]->getNumOfEpisodes() << endl;
            cout <<"Rating: " <<tvshowDatabase[i]->getRating() << endl;
            cout << endl;
        }
    }
    
}



void databases::database::addMedia(){
    string tempTitle, tempTitleId,  tempGenre, tempDirector;
    int tempYear;
    float tempRating;

    int choice;
    cout << "What type of media would you like to add: \n1. Movie\n2. Music\n3. TV show" << endl;
    cin >> choice;   
    
    //First asking the user some questions that pertain to all media
    //title
    cout << "What is the title of the media? " ;
    getline(cin, tempTitle);
    

    //title ID
    cout <<"What is the id of th media? ";
    getline(cin, tempTitleId);

    //year
    cout << "What is the year?";
    cin >> tempYear;
    cin.ignore();


    //genre
    cout << "What is the genre? ";
    getline(cin, tempGenre);


    if(choice == 1){
        movieDatabase[numberOfMovies]->setTitle(tempTitle);
        movieDatabase[numberOfMovies]->setID(tempTitleId);
        movieDatabase[numberOfMovies]->setYear(tempYear);

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
    if(choice == 2){
        musicDatabase[numberOfMusic]->setTitle(tempTitle);
        musicDatabase[numberOfMusic]->setID(tempTitleId);
        musicDatabase[numberOfMusic]->setYear(tempYear);


         //composer
         string tempComposer;
        cout <<"Who is the composer? ";
        getline(cin, tempComposer);
        cin.ignore();
        musicDatabase[numberOfMusic]->setComposer(tempComposer);

        //number of trracks
        int tempNumOfTracks;
        cout << "Whats the number of tracks? ";
        cin >> tempNumOfTracks;
        musicDatabase[numberOfMusic]->setNumOfTracks(tempNumOfTracks);

        //playtime
        int tempPlaytime;
        cout << "Whats the total playtime? ";
        cin >> tempPlaytime;
        cin.ignore();
        musicDatabase[numberOfMusic]->setTotalPlaytime(tempPlaytime);

        //increment number of music
        numberOfMusic++;
        cout << "Music Added" << endl;


    }

        if(choice == 3){
        tvshowDatabase[numberOfTvShows]->setTitle(tempTitle);
        tvshowDatabase[numberOfTvShows]->setID(tempTitleId);
        tvshowDatabase[numberOfTvShows]->setYear(tempYear);


         //composer
         string tempGenre;
        cout <<"What is the genre? ";
        getline(cin, tempGenre);
        tvshowDatabase[numberOfMusic]->setGenre(tempGenre);

        //number of trracks
        int tempNumOfEps;
        cout << "Whats the number of tracks? ";
        cin >> tempNumOfEps;
        tvshowDatabase[numberOfMusic]->setNumOfEpisodes(tempNumOfEps);

        //playtime
        float tempRating;
        cout << "Whats the rating? ";
        cin >> tempRating;
        cin.ignore();
        tvshowDatabase[numberOfMusic]->setRating(tempRating);

        //increment number of music
        numberOfTvShows++;
        cout << "Music Added" << endl;


    }



}


void databases::database::searchMediaById(){
    string searchInput;

    bool mediaFoundBool = false;
    int mediaFoundType;
    int mediaFoundNum = 0;

    
    cout <<"What is the title or titleID of the movie you want: ";
    getline(cin, searchInput);

    //go through every movie and see if the search input matches te movie
    for(int i = 0; i < numberOfMovies; i++){
        if(movieDatabase[i]->getId() == searchInput||
            movieDatabase[i]->getGenre() == searchInput ||
            movieDatabase[i]->getTitle() == searchInput ){
            mediaFoundBool = true;
            mediaFoundNum = i;
            mediaFoundType = 1;
        }
    }

    //go through every music and see if the search input matches te movie
    for(int i = 0; i < numberOfMusic; i++){
        if(musicDatabase[i]->getId() == searchInput||
            musicDatabase[i]->getGenre() == searchInput ||
            musicDatabase[i]->getTitle() == searchInput){
            mediaFoundBool = true;
            mediaFoundNum = i;
            mediaFoundType = 2;
        }
    }

    //go through every tv show and see if the search input matches te movie
    for(int i = 0; i < numberOfMovies; i++){
        if(tvshowDatabase[i]->getId() == searchInput||
            tvshowDatabase[i]->getGenre() == searchInput ||
            movieDatabase[i]->getTitle() == searchInput ){
            mediaFoundBool = true;
            mediaFoundNum = i;
            mediaFoundType = 3;
        }
    }

    if(mediaFoundBool){
        cout << "\nMedia Found!" << endl;
        if(mediaFoundType == 1){
            cout << "Title: " <<movieDatabase[mediaFoundNum]->getTitle() << endl;
            cout << "Director: " <<movieDatabase[mediaFoundNum]->getDirector() << endl;
            cout <<"ID: " << movieDatabase[mediaFoundNum]->getId() << endl;
            cout <<"Genre: " <<movieDatabase[mediaFoundNum]->getGenre() << endl;
            cout <<"Year: " <<movieDatabase[mediaFoundNum]->getYear() << endl;
            cout <<"Rating: " <<movieDatabase[mediaFoundNum]->getRating() << endl;
            cout << endl;

        }
        if(mediaFoundType == 2){
            cout << "Title: " <<musicDatabase[mediaFoundNum]->getTitle() << endl;
            cout << "Composer: " <<musicDatabase[mediaFoundNum]->getComposer() << endl;
            cout <<"ID: " << musicDatabase[mediaFoundNum]->getId() << endl;
            cout <<"Genre: " <<musicDatabase[mediaFoundNum]->getGenre() << endl;
            cout <<"Year: " <<musicDatabase[mediaFoundNum]->getYear() << endl;
            cout << "Number of Tracks: " << musicDatabase[mediaFoundNum]->getNumOfTracks() << endl;
            cout <<"Playtime: " <<musicDatabase[mediaFoundNum]->getTotalPlaytime() << endl;
            cout << endl;
        }
        if(mediaFoundType == 3){
            cout << "Title: " <<tvshowDatabase[mediaFoundNum]->getTitle() << endl;
            cout <<"ID: " << tvshowDatabase[mediaFoundNum]->getId() << endl;
            cout <<"Genre: " <<tvshowDatabase[mediaFoundNum]->getGenre() << endl;
            cout <<"Year: " <<tvshowDatabase[mediaFoundNum]->getYear() << endl;
            cout <<"Rating: " <<tvshowDatabase[mediaFoundNum]->getRating() << endl;
            cout << "Number of Episodes: " <<tvshowDatabase[mediaFoundNum]->getNumOfEpisodes() << endl;
            cout << endl;
        }
    }


    
}

void databases::database::removeMedia(){
    
    //finding out the id of the movie the user would like to delete
    bool mediaFound = false;
    int mediaType;
    string chosenMedia;
    cout <<"What is the ID of the movie you would like to remove: ";
    cin >>chosenMedia;
    cin.ignore();
    int chosenMediaNumber;

    //finding out which movie has the id the user provided
    for(int k = 0; k < numberOfMovies; k++){
        if(movieDatabase[k]->getId() == chosenMedia){
            chosenMediaNumber = k;
            mediaType = 1;
            mediaFound = true;
        }
        if(musicDatabase[k]->getId() == chosenMedia){
            chosenMediaNumber = k;
            mediaType =2;
            mediaFound = true;
        }
        if(tvshowDatabase[k]->getId() == chosenMedia){
            chosenMediaNumber = k;
            mediaType = 3;
            mediaFound = true;
        }
    }
    
    //move every media that is ahead of the movie being deleted down by 1
    if(mediaFound){
        //if chosen media is a movie
        if(mediaType == 1){
            for(int i = chosenMediaNumber; i < numberOfMovies; i++){
                movieDatabase[i]->setDirector(movieDatabase[i+1]->getDirector());
                movieDatabase[i]->setTitle(movieDatabase[i+1]->getTitle());
                movieDatabase[i]->setID(movieDatabase[i+1]->getId());
                movieDatabase[i]->setGenre(movieDatabase[i+1]->getGenre());
                movieDatabase[i]->setYear(movieDatabase[i+1]->getYear());
                movieDatabase[i]->setRating(movieDatabase[i+1]->getRating());
            }
            numberOfMovies --;
            std::cout << "Movie Removed" << endl;;
        }
        //if chosen media is music
        if(mediaType == 2){
            for(int i = chosenMediaNumber; i < numberOfMovies; i++){
                musicDatabase[i]->setComposer(musicDatabase[i+1]->getComposer());
                musicDatabase[i]->setTitle(musicDatabase[i+1]->getTitle());
                musicDatabase[i]->setID(musicDatabase[i+1]->getId());
                musicDatabase[i]->setGenre(musicDatabase[i+1]->getGenre());
                musicDatabase[i]->setYear(musicDatabase[i+1]->getYear());
                musicDatabase[i]->setNumOfTracks(musicDatabase[i+1]->getNumOfTracks());
                musicDatabase[i]->setTotalPlaytime(musicDatabase[i+1]->getTotalPlaytime());
            }
            numberOfMusic --;
            std::cout << "Music Removed" << endl;;
        }
        //if chosen media is a tv show
        if(mediaType == 3){
            for(int i = chosenMediaNumber; i < numberOfMovies; i++){
                tvshowDatabase[i]->setNumOfEpisodes(tvshowDatabase[i+1]->getNumOfEpisodes());
                tvshowDatabase[i]->setTitle(tvshowDatabase[i+1]->getTitle());
                tvshowDatabase[i]->setID(tvshowDatabase[i+1]->getId());
                tvshowDatabase[i]->setGenre(tvshowDatabase[i+1]->getGenre());
                tvshowDatabase[i]->setYear(tvshowDatabase[i+1]->getYear());
                tvshowDatabase[i]->setRating(tvshowDatabase[i+1]->getRating());
               
            }
            numberOfMusic --;
            std::cout << "Music Removed" << endl;;
            
        }
    }
    else{
        cout << "Media Not Found " << endl;
    }
   

}





void databases::database::exportMovies(){
    ofstream movieExport ("moviesExport.csv");

    //exporting the movie list to a different csv.
    for(int i = 0; i < numberOfMovies; i++){
        
        movieExport <<movieDatabase[i]->getId() << ',';
        movieExport  <<movieDatabase[i]->getTitle() << ',';
        movieExport << movieDatabase[i]->getYear() << ',';
        movieExport  <<movieDatabase[i]->getGenre() << ',';
        movieExport  <<movieDatabase[i]->getRating() << ',';
        movieExport  <<movieDatabase[i]->getDirector() << endl;
        
    }

    
    movieExport.close();
}


void databases::database::exportMusic(){
    ofstream musicExport ("moviesExport.csv");

    //exporting the movie list to a different csv.
    for(int i = 0; i < numberOfMovies; i++){
        
        musicExport <<musicDatabase[i]->getId() << ',';
        musicExport  <<musicDatabase[i]->getTitle() << ',';
        musicExport << musicDatabase[i]->getYear() << ',';
        musicExport  <<musicDatabase[i]->getGenre() << ',';
        musicExport  <<musicDatabase[i]->getComposer() << ',';
        musicExport  <<musicDatabase[i]->getTotalPlaytime() << ',';
        musicExport  <<musicDatabase[i]->getNumOfTracks() << endl;
        
    }

    
    musicExport.close();
}



void databases::database::exportTvShows(){
    ofstream tvshowExport ("moviesExport.csv");

    //exporting the movie list to a different csv.
    for(int i = 0; i < numberOfMovies; i++){
        
        tvshowExport <<tvshowDatabase[i]->getId() << ',';
        tvshowExport  <<tvshowDatabase[i]->getTitle() << ',';
        tvshowExport << tvshowDatabase[i]->getYear() << ',';
        tvshowExport  <<tvshowDatabase[i]->getGenre() << ',';
        tvshowExport  << tvshowDatabase[i]->getRating() << ',';
        tvshowExport  << tvshowDatabase[i]->getNumOfEpisodes() << endl;
        
    }

    
    tvshowExport.close();
}


