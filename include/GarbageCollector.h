#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include "Image.h"


class GarbageCollector
{
    public:
        GarbageCollector();
        ~GarbageCollector();

        int AddImage(Image* image);

        void (*(Image::*imageFreeFunctions))();
        int imageCounter;
    protected:
    private:
};

#endif // GARBAGECOLLECTOR_H
