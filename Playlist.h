#ifndef DESKTOP_PLAYLIST_H
#define DESKTOP_PLAYLIST_H
#include <string>
#include <vector>
#include <ostream>
#include "Song.h"
#include "ListaCantece.h"

class Playlist : public ListaCantece{
public:
    Playlist();
    Playlist(const vector<Song> &songs, float durata);
    virtual ~Playlist();

    const vector<Song> &getSongs() const;
    void setSongs(const vector<Song> &songs);
    float getDurata() const;
    void setDurata(float durata);

    Playlist &operator=(const Playlist& ob);

    Playlist operator+(const Song& p);
    Playlist operator-(const Song& p);
    friend ostream &operator<<(ostream &os, const Playlist &playlist);

    Song playRandom();  // intoarce un song aleator
};


#endif
