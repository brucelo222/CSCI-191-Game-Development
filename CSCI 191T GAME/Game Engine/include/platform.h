#ifndef PLATFORM_H
#define PLATFORM_H


class platform
{
    public:
        platform();
        virtual ~platform();
        void initPlatform(float,float,float,float);
        float yTop;
        float yBottom;
        float xRight;
        float xLeft;
    protected:

    private:
};

#endif // PLATFORM_H
