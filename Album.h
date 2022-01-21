#ifndef DESKTOP_ALBUM_H
#define DESKTOP_ALBUM_H

#include <ostream>
#include "Playlist.h"
#include "Singer.h"
#include "Song.h"
class Album : public ListaCantece{
private:
    string albumname;
    Singer cantaret;
public:
    Album();

    virtual ~Album();

    Album(const vector<Song> &songs, float durata, const string &albumname, const Singer &cantaret);

    friend ostream &operator<<(ostream &os, const Album &album);
    Album operator+(const Song& p);
    Song playRandom();

    void setAlbumname(const string &albumname);

    void setCantaret(const Singer &cantaret);

    const string &getAlbumname() const;

    const Singer &getCantaret() const;
};


#endif
