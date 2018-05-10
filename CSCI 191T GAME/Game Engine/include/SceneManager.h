#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

enum SceneState{TITLE,LEVEL1,LEVEL2,LEVEL3,PAUSE,RETRY,HELP};

class SceneManager
{
    public:
        SceneManager();
        virtual ~SceneManager();

        SceneState getScene(){return _sceneManager;};
        void setScene(SceneState newScene){_sceneManager = newScene;};
    private:

        SceneState _sceneManager;

};

#endif // SCENEMANAGER_H
