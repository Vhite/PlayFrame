#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL.h>

using namespace std;

#include "Definitions.h"
#include "Image.h"

int Initialization();
int Finalize();
int UpdateScreen();
int DrawImage(Image image);
int LoadImage(const char* fileName, Image* image);
void EventLoop(bool* done);

SDL_Surface* screen;    // Target of graphic output.
Image image;   // Mainly for testing.

FILE* messageLog;   // Output for error and other messages.

int main (int argc, char** argv)
{
    messageLog = fopen("log.txt","w");

    if(Initialization() == 1)
    return 1;

    bool done = false;
    while (!done)
    {
        EventLoop(&done);
        UpdateScreen();
        SDL_Flip(screen);
    }

    Finalize();
    return 0;
}

int Initialization()
{
    atexit(SDL_Quit);

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(messageLog, "Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 16,
                              SDL_HWSURFACE|SDL_DOUBLEBUF);

    if (!screen){
        fprintf(messageLog,"Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

int Finalize()
{
    fprintf(messageLog,"Exited cleanly\n");

    if(fclose(messageLog) == EOF)
    return 1;

    return 0;
}

int UpdateScreen()
{
    DrawImage(image);
    return 0;
}

int DrawImage(Image image)  // Test
{

    if(SDL_BlitSurface(image.surface, 0, screen, &image.rectangle) == 1)
    {
        fprintf(messageLog, "Error in drawing of surface.\n");
        return 1;
    }
    return 0;
}

int LoadImage(const char* fileName,Image* image)
{
    image->surface = SDL_LoadBMP(fileName);
    if(image->surface == NULL)
    {
        fprintf(messageLog,"Error loading an image.\n");
        return 1;
    }
    return 0;
}

void EventLoop(bool* done)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                *done = true;
                break;

            case SDL_KEYDOWN:
                {
                    if (KEY == SDLK_ESCAPE)
                        *done = true;
                    break;
                }
        }
    }
}
