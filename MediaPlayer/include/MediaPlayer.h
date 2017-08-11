#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <iostream>
#include <list>
using namespace std;

struct Song{
    int ID;
    string title;
    string singer;
    float duration;

};

class MediaPlayer
{
    public:
        MediaPlayer();
        virtual ~MediaPlayer();
        void openPlayer();
        void addToPlaylist(string songName, string singer, float duration, int position);
        bool removeFromPlaylist (string songName);
        bool goToFirst();
        bool goToLast();
        bool goToPrev();
        bool goToNext();
        bool goToSong (string songTitle);
        void reversePlaylist();
        void sortTitle();
        void sortDuration();
        void displayPlaylist();
        void displayCurrentSong();
    protected:

    private:
        Song s;
        static int songID;
        list<Song> playlist;
        list<Song>::iterator it;

};


#endif // MEDIAPLAYER_H
