#ifndef GRAPHICS_H
#define GRAPHICS_H

struct Color{
    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

    float r;
    float g;
    float b;
    float a;
};

class Graphics
{
    public:
        Graphics();
        virtual ~Graphics();

        void drawQuad(float, float, float, Color);
        void drawTriangle(float, float, float, Color);

    protected:

    private:
};

#endif // GRAPHICS_H
