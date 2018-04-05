#ifndef STAGECHANGE_H
#define STAGECHANGE_H
#include <GLLight.h>
#include <Model.h>
#include <Inputs.h>
#include <parallax.h>
#include <player.h>
#include <skyBox.h>
#include <fallingObject.h>

class stageChange
{
    public:
        stageChange();
        virtual ~stageChange();
        int stagePro;

        void nextStage();

    protected:

    private:
};

#endif // STAGECHANGE_H
