#include "lodepng.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 
int i, j; 
 
void preparation(unsigned char* p, int h, int w) { 
    for (i = 0; i < h; i++) 
        for (j = 0; j < w; j++) { 
            if (p[w * i + j] < 100) 
                p[w * i + j] = 0; 
            if (p[w * i + j] > 160) 
                p[w * i + j] = 255; 
        } 
 
} 
char* loadPng(const char* filename, int* width, int* height) { 
 
  unsigned char* image = NULL; 
 // unsigned int width, height; 
 
  int error = lodepng_decode32_file(&image, width, height, filename); 
  if(error) 
  { 
    printf("error %u: %s\n", error, lodepng_error_text(error)); 
  } 
 
  return (image); 
} 
 
void writePng(const char* filename, const unsigned char* image, unsigned width, unsigned height) { 
  unsigned error; 
  unsigned char* png; 
  size_t pngsize; 
  LodePNGState state; 
 
  lodepng_state_init(&state); 
  /*optionally customize the state*/ 
 
  error = lodepng_encode(&png, &pngsize, image, width, height, &state); 
  if(!error) lodepng_save_file(png, pngsize, filename); 
 
  /*if there's an error, display it*/ 
  if(error) printf("error %u: %s\n", error, lodepng_error_text(error)); 
 
  lodepng_state_cleanup(&state); 
  free(png); 
} 
/*void get_pixel(int x, int y, int *r, int *g, int *b, int *a, char*image, int width ) 
{ 
 
   *r =  image[4 * width * y + 4 * x + 0]; 
   *g =  image[4 * width * y + 4 * x + 1]; 
   *b =  image[4 * width * y + 4 * x + 2]; 
   *a =  image[4 * width * y + 4 * x + 3]; 
 
   return; 
} 
 
void set_pixel (int x, int y, int *r, int *g, int *b, int *a, char*image, int width){ 
   *r =  image[4 * width * y + 4 * x + 0]; 
   *g =  image[4 * width * y + 4 * x + 1]; 
   *b =  image[4 * width * y + 4 * x + 2]; 
   *a =  image[4 * width * y + 4 * x + 3]; 
 
}*/ 
void fGause(unsigned char* p, unsigned char* l, int h, int w) { 
    for (i = 2; i < h - 1; i++) 
        for (j = 2; j < w - 1; j++) { 
            l[4 * i * w + 4 * j + 0] = 0.09 * p[4 * (i-1) * w + 4 *(j-1) + 0] + 0.12 * p[4 * (i-1) * w + 4 * j + 0] + 0.09 * p[4 * (i-1) * w + 4 * (j+1) + 0] + 0.12 * p[4 * i * w + 4 * (j-1) + 0] + 0.15 * p[4 * i * w + 4 * j + 0] + 0.12 * p[4 * i * w + 4 * (j+1) + 0] + 0.09 * p[4 * (i+1) * w + 4 * (j-1) + 0] + 0.12* p[4 * (i+1) * w + 4 * j + 0] + 0.09 * p[4 * (i+1) * w + 4 * (j+1) + 0]; 
            l[4 * i * w + 4 * j + 1] = 0.09 * p[4 * (i-1) * w + 4 *(j-1) + 1] + 0.12 * p[4 * (i-1) * w + 4 * j + 1] + 0.09 * p[4 * (i-1) * w + 4 * (j+1) + 1] + 0.12 * p[4 * i * w + 4 * (j-1) + 1] + 0.15 * p[4 * i * w + 4 * j + 1] + 0.12 * p[4 * i * w + 4 * (j+1) + 1] + 0.09 * p[4 * (i+1) * w + 4 * (j-1) + 1] + 0.12* p[4 * (i+1) * w + 4 * j + 1] + 0.09 * p[4 * (i+1) * w + 4 * (j+1) + 1]; 
            l[4 * i * w + 4 * j + 2] = 0.09 * p[4 * (i-1) * w + 4 *(j-1) + 2] + 0.12 * p[4 * (i-1) * w + 4 * j + 2] + 0.09 * p[4 * (i-1) * w + 4 * (j+1) + 2] + 0.12 * p[4 * i * w + 4 * (j-1) + 2] + 0.15 * p[4 * i * w + 4 * j + 2] + 0.12 * p[4 * i * w + 4 * (j+1) + 2] + 0.09 * p[4 * (i+1) * w + 4 * (j-1) + 2] + 0.12* p[4 * (i+1) * w + 4 * j + 2] + 0.09 * p[4 * (i+1) * w + 4 * (j+1) + 2]; 
            //l[4 * i * w + 4 * j + 3] = 0.09 * p[4 * (i-1) * w + 4 *(j-1) + 3] + 0.12 * p[4 * (i-1) * w + 4 * j + 3] + 0.09 * p[4 * (i-1) * w + 4 * (j+1) + 3] + 0.12 * p[4 * i * w + 4 * (j-1) + 3] + 0.15 * p[4 * i * w + 4 * j + 3] + 0.12 * p[4 * i * w + 4 * (j+1) + 3] + 0.09 * p[4 * (i+1) * w + 4 * (j-1) + 3] + 0.12* p[4 * (i+1) * w + 4 * j + 3] + 0.09 * p[4 * (i+1) * w + 4 * (j+1) + 3]; 
        } 
    return; 
} 
 
void colouring(unsigned char* f, unsigned char* mcod, int h, int w, int n) { 
    for (i = 1; i < w * h; i++) { 
        mcod[i * n] = 230 +f[i] + 9.5 * f[i - 1]; 
        mcod[i * n + 1] = f[i]-100; 
        mcod[i * n + 2] = 200 + 0.07*f[i]; 
        mcod[i * n + 3] = 255; 
    } 
    return; 
} 
 
int main() { 
    char* filename = "picture.png"; 
    int w, h, n=4; 
    int k = 0; 
    printf("%d \n", 1); 
    char* pic = loadPng(filename, &w, &h); 
    if (pic == NULL) { 
        printf("ERROR: can't read file %s\n", filename); 
        return -1;
} 
     printf("%d \n", 2); 
     unsigned char* opic = (unsigned char*)malloc(w * h * sizeof(unsigned char)); 
  printf("%d \n", 3); 
    unsigned char* piccopy = (unsigned char*)malloc(w * h * sizeof(unsigned char)); 
     printf("%d \n", 4); 
    unsigned char* mcopic = (unsigned char*)malloc(w * h * n * sizeof(unsigned char)); 
     printf("%d \n", 5); 
    for (i = 0; i < h * w; i++) { 
        opic[k] = 0.299 * pic[4*i] + 0.587 * pic[4*i + 1] + 0.114 * pic[4*i + 2]; 
        k++; 
    } 
     printf("%d \n", 6); 
     //printf("\n"); 
          preparation(opic, h, w); 
     printf("%d \n", 7); 
     fGause(opic, piccopy, h, w); 
     printf("%d \n", 8); 
     colouring(piccopy, mcopic, h, w, n); 
     printf("%d \n", 9); 
 
     char* new_image = "picture2.png"; 
     printf("%d \n", 10); 
     writePng(new_image, mcopic, w, h); 
     printf("%d \n", 11); 
     free(pic); 
     free(opic); 
     free(piccopy); 
     free(mcopic); 
}
