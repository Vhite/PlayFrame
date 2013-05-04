#include "Image.h"
#include "Definitions.h"

int LoadImage(const char* fileName, Image* image);

Image::Image()
{
    fa = &Free;
    LoadImage("sprites/nosprite.bmp",this);
    rectangle.w = surface->w;
    rectangle.h = surface->h;
    rectangle.x = (SCREEN_W/2)-(rectangle.w/2);
    rectangle.y = (SCREEN_H/2)-(rectangle.h/2);
}

Image::Image(const char* fileName)
{
    fa = &Free;
    LoadImage(fileName,this);
    rectangle.w = surface->w;
    rectangle.h = surface->h;
    rectangle.x = (SCREEN_W/2)-(rectangle.w/2);
    rectangle.y = (SCREEN_H/2)-(rectangle.h/2);
}

Image::Image(const char* fileName, int x, int y)
{
    fa = &Free;
    LoadImage(fileName,this);
    rectangle.w = surface->w;
    rectangle.h = surface->h;
    rectangle.x = x;
    rectangle.y = y;
}

Image::~Image()
{

}

void Image::Free()
{
    SDL_FreeSurface(surface);
}
