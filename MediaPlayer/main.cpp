#include <iostream>

using namespace std;
#include "MediaPlayer.h"

int main()
{
    cout << "Hello world!" << endl;
    MediaPlayer player;

    //Open the mediaplayer
    player.openPlayer();

    //add songs to the playlist
    player.addToPlaylist("Shape of You","Ed Sheeran", 4.30, 0);
    player.addToPlaylist("Treat you Better", "Shawn Mendes", 3.30, 1);
    player.addToPlaylist("Vachinde", "Madhu Priya", 4.0, 0);
    player.addToPlaylist("Animals", "Martin Garrix", 3.0, 1);
    player.addToPlaylist("Sahore Bahubali", "Keeravani", 5.0, 5);

    //Display playlist
    cout<< "Playlist:\n";
    player.displayPlaylist();

    //go to a particular song
    if(player.goToSong("Sahore Bahubali"))
        player.displayCurrentSong();
    else cout <<"Song not found \n" ;

    //display first song
    if(player.goToFirst()) player.displayCurrentSong();
    else cout <<"Cannot navigate to the first song \n" ;

    //display last song
    if(player.goToLast()) player.displayCurrentSong();
    else cout <<"Cannot navigate to the last song \n" ;

    //go to next song
    //if(player.goToNext()) player.displayCurrentSong();
    //else cout <<"Cannot navigate to the next song \n" ;

    //go to previous song
    if(player.goToPrev()) player.displayCurrentSong();
    else cout <<"Cannot navigate to the previous song \n" ;
    if(player.goToPrev()) player.displayCurrentSong();
    else cout <<"Cannot navigate to the previous song \n" ;

    //go to next song
    if(player.goToNext()) player.displayCurrentSong();
    else cout <<"Cannot navigate to the next song \n" ;

    //reverse the playlist
    cout<< "Playlist reversed \n" ;
    player.reversePlaylist();
    player.displayPlaylist();

    //sort by the title
    cout<< "Playlist sorted by the title \n";
    player.sortTitle();
    player.displayPlaylist();

    //sort by the duration
    cout<< "Playlist sorted by the duration \n";
    player.sortDuration();
    player.displayPlaylist();

    cout<< "Shape of You removed from the list \n";
    player.removeFromPlaylist("Shape of You");
    player.displayPlaylist();

    return 0;
}
