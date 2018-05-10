#include "sounds.h"
#include<iostream>
using namespace std;

ISoundEngine* engine = createIrrKlangDevice();

sounds::sounds()
{
    //ctor
}

sounds::~sounds()
{
    engine->drop();
}
void sounds::playMusic(char* File)
{
    engine->play2D(File,true);//false no sounds are played
}

void sounds::playSound(char* File)
{
    engine->play2D(File, false, false); // first false = repeat, 2nd false = going to play?
}

void sounds::stopAllSounds()
{

}

int sounds::initSounds()
{
    if(!engine){
        cout<< "Could not Start the Soumd Engine\n"<<endl;
        return 0;
    }
    return 1;
}
