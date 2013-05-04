#include "GarbageCollector.h"
#include<stdlib.h>

GarbageCollector::GarbageCollector()
{//TODO: nieco s tym sprav
    imageCounter = 0;
    imageFreeFunctions = (void (*(Image::*)))malloc(sizeof(void (*(Image::*))*imageCounter))8;       // Points on Image::Free of every image created
}

GarbageCollector::~GarbageCollector()
{
    //dtor
}

int GarbageCollector::AddImage(Image* image)
{
    imageCounter++;
    imageFreeFunctions = (void (**)())realloc(imageFreeFunctions,sizeof(void *)*imageCounter);
    imageFreeFunctions[imageCounter] = image->fa;

    return 0;
}
