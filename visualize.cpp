#include <iostream>
#include <cstdio>
#include <vector>
#include <SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

struct point {
  int x, y;

  point() {
    x = y = 0;
  }

  point(int a, int b) {
    x = a;
    y = b;
  }
};

struct segment {
  point start, end;

  segment() {
    start = point();
    end = point();
  }

  segment(int a, int b, int c, int d) {
    start = point(a, b);
    end = point(c, d);
  }
                         
};

int main() {
  int n, a, b, c, d;
  vector<segment> v;
  cin >> n;
  for (auto i = 0; i < n; ++i) {
    cin >> a >> b >> c >> d; 
    v.push_back(segment(a, b, c, d));
  }
  
  SDL_Window* wind = NULL;
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    return 1;
  }
  wind = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if (wind == NULL) {
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    return 1;
  }

  SDL_Renderer* rend = SDL_CreateRenderer( wind, -1, SDL_RENDERER_ACCELERATED );
  if( rend == NULL ) {
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    return 1;
  }
  SDL_Event e;

  bool quit = false;
  while( !quit ) {
    while( SDL_PollEvent( &e ) != 0 ) {
      if( e.type == SDL_QUIT ) {
        quit = true;
      }
    }

    SDL_SetRenderDrawColor(rend, 0xFF, 0xFF, 0xFF, 0xFF);        
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x50, 0x50);        
    for (auto i = 0; i < n; ++i) {
      SDL_RenderDrawLine( rend, v[i].start.x, SCREEN_HEIGHT - v[i].start.y, v[i].end.x, SCREEN_HEIGHT - v[i].end.y);
    }
    SDL_RenderPresent(rend);
  }

  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(wind);
  SDL_Quit();

  return 0;
}
