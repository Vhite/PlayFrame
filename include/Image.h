#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

class Image
{
    public:
        Image();
        Image(const char* fileName);
        Image(const char* fileName, int x, int y);
        ~Image();

        void Free();
        void (Image::*fa)();

        SDL_Surface* surface;
        SDL_Rect rectangle;
    protected:
    private:
};

#endif // IMAGE_H
