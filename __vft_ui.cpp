#include <iostream>
#include <cstring>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


using namespace std;

void drawTest(){
	int width, height;
	width = 500;
	height = 500;
	unsigned char* image = stbi_load("icon.png", &width, &height, 0, STBI_rgb_alpha);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	
	stbi_image_free(image);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}


int main(int argc, char const *argv[])
{
	GLFWwindow* window;
	if (glfwInit())
	{
	    window = glfwCreateWindow(640, 640, "My Title", NULL, NULL);

		if (!window)
		{
			glfwTerminate();
			exit(1);
		}

	    glfwMakeContextCurrent(window);
		GLFWimage images[1];
		images[0].pixels = stbi_load("icon.png", &images[0].width, &images[0].height, 0, 4);
		 
		glfwSetWindowIcon(window, 1, images);

		stbi_image_free(images[0].pixels);

		unsigned char pixels[5 * 5 * 4];
		memset(pixels, 0xff, sizeof(pixels));
		 
		GLFWimage image;
		image.width = 5;
		image.height = 5;
		image.pixels = pixels;
		 
		GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);

		glfwSetCursor(window, cursor);


		drawTest();

	}

	while (!glfwWindowShouldClose(window))
    { 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(0);
}