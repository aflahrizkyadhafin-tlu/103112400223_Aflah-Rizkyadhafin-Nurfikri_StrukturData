#include "DLLPlaylist.h"

int main()
{
    List songList;
    createList(songList);

    Song A;
    A.Artist = "Harvest";
    A.Title = "Nozomu";
    A.DurationSec = 180;
    A.PlayCount = 2;
    A.Rating = 4.5;
    insertFirst(songList, A);
    A.Artist = "Fantasi Depresi";
    A.Title = "Rina Hime";
    A.DurationSec = 120;
    A.PlayCount = 15;
    A.Rating = 4.4;
    insertFirst(songList, A);
    A.Artist = "Kataomoi";
    A.Title = "Nekodachi";
    A.DurationSec = 140;
    A.PlayCount = 10;
    A.Rating = 4.2;
    insertBefore(songList, songList.tail, A);

    viewList(songList);

    return 0;
}