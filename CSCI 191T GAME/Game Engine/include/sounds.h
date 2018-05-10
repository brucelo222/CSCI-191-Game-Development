#ifndef SOUNDS_H
#define SOUNDS_H

#include <Klang/irrKlang.h>
#pragma comment(lib,"irrKlang.lib")//link your dll to the program

using namespace irrklang;
using namespace std;

class sounds
{
    public:
        sounds();
        virtual ~sounds();

        void playMusic (char *);
        void playSound (char *);
        void stopAllSounds();
        int initSounds();

    protected:

    private:
};

#endif // SOUNDS_H
