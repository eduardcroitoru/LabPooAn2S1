#ifndef SINGLETONEMENU_H
#define SINGLETONEMENU_H
#include <iostream>
#include "Singer.h"
#include "Song.h"
#include "Playlist.h"
#include "ListaCantece.h"
#include "Album.h"
#include<bits/stdc++.h>
#include <typeinfo>

class SingletoneMenu
{
private:
    static SingletoneMenu* object;
public:
    SingletoneMenu* getInstance(){
        if(!object)
            object=new SingletoneMenu;
        return object;
    }
    void meniu();
    SingletoneMenu();
    ~SingletoneMenu();
};

#endif
