#include "texture.h"

void texture_render(texture* texture, SDL_Renderer* renderer, int x, int y) {
    SDL_FRect rect = { x, y, texture->w, texture->h };
    SDL_RenderTexture(renderer, texture->handle, NULL, &rect);
}

texture* texture_initialize(SDL_Texture* handle, int w, int h) {
    texture* result = malloc(sizeof(texture));
    result->w = w;
    result->h = h;
    result->handle = handle;
    return result;
}

void texture_free(texture* texture) {
    SDL_DestroyTexture(texture->handle);
    free(texture);
}