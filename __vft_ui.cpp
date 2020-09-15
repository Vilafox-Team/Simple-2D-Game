#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


using namespace std;

void drawTest(){
	int width, height, spriteW, spriteH;
	float posX, posY;
	width = 500;
	height = 500;
	spriteH = height;
	spriteW = width;
	posX = 0;
	posY = 0;

	const float verts[] = {
        posX, posY,
        posX + spriteW, posY,
        posX + spriteW, posY + spriteH,
        posX, posY + spriteH
    };
    const float tw = float(width) / spriteW;
    const float th = float(height) / spriteH;
    const int numPerRow = width / spriteW;
    const float tx = (0 % numPerRow) * tw;
    const float ty = (0 / numPerRow + 1) * th;
    const float texVerts[] = {
        tx, ty,
        tx + tw, ty,
        tx + tw, ty + th,
        tx, ty + th
    };
        
	GLFWimage images[1];
	images[0].pixels = stbi_load("icon.png", &images[0].width, &images[0].height, 0, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, images[0].pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(images[0].pixels);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glTexCoordPointer(2, GL_FLOAT, 0, texVerts);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

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
 
		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

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