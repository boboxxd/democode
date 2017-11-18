//
// Created by hhit on 17-11-17.
//

#include <iostream>

extern "C"
{
#include<SDL2/SDL.h>
};

//deciding how to position our images
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

//The SDL Error Logger
void logSDLError(std::ostream &os,const std::string &msg)
{
    os<<msg<<"error:"<<SDL_GetError()<<std::endl;
}

//The Texture Loading Function
SDL_Texture* loadTexture(const std::string &file,SDL_Renderer *ren)
{
    SDL_Texture *texture= nullptr;
    SDL_Surface *loadImage=SDL_LoadBMP(file.c_str());
    if(loadImage!= nullptr)
    {
        texture=SDL_CreateTextureFromSurface(ren,loadImage);
        SDL_FreeSurface(loadImage);
        if(texture== nullptr)
        {
            logSDLError(std::cout,"CreateTextureFromSurface");
        }
    }else
    {
        logSDLError(std::cout, "LoadBMP");
    }
    return texture;
}

//
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

