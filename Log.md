<h1> GraphicProcessor Progress Log </h1>

This log descibes the process of how the final product for the individual project course at Avans Hogeschool was made.
At the start I'll take a look at what idea's I have for this project, this will influence the choice between OpenGL and OpenCL. <br>
After that I will do more research on the prefered API, and then I will formulate the definitive goal for this project.<br>
At the end the entire development process from start to finish will be described.

<h2> Table of Contents </h2>

1. [OpenGL or OpenCL?](#GLCL)
2. [Information on OpenGL ](#GL)
3. [Goal](#Goal)
4. [Plan](#Plan)
5. [Path to Goal ](#PtG)

<a name="GLCL"></a>
## OpenGL or OpenCL?

Upon googling the differences between those two environments, <br>
one of the first things that pops up is the following: <br>

OpenGL is mostly used for computer graphics, it is a graphics API. <br>
OpenCL is mostly used for parallel computing, it is a computation API. <br>

Since I prefer to produce something visual rather than just performing calculations.
It would also be nice to create something that I could use to make my room look nicer.
An added bonus is that there seem to be more examples for OpenGL than for OpenCL.

<a name="GL"></a>
## Information on OpenGL

Sources: <br>
https://en.wikipedia.org/wiki/OpenGL <br>
https://learnopengl.com/Getting-started/OpenGL <br>
https://www.khronos.org/opengl/wiki/Getting_Started#Downloading_OpenGL <br>
https://www.absingh.com/opengl/

Fun Examples: <br>

1. Terrain generation: https://www.codeproject.com/Articles/14154/OpenGL-Terrain-Generation-An-Introduction <br>
[Later found out this tutorial is too old to be compiled with the current VS version] <br>

Example terrain: <br>
![Simple terrain](/Images/SimpleTerrain.jpg)

2. 3D Water: <br>
   https://www.gamedev.net/reference/articles/article915.asp <br>
   Water generation seems to rely on Perlin Noise algorithm quite often.

<a name="Goal"></a>
## Goal

Maybe creating a water pool with some terrain around it? possibly with user interaction, maybe flying through the created terrain?

<a name="Plan"></a>
## Plan

1. Following the swiftless OpenGL tutorial 1 - 24
2. Following the swiftless terrain OpenGL tutorial

<a name="PtG"></a>
## Path to Goal

[25-04-2020] <br>
Started researching how 3D water is created in OpenGL <br>
Started trying out: https://www.gamedev.net/reference/articles/article915.asp <br>
Finished part 1 of the tutorial <br>
Found out that the tutorial does not uses OpenGL. <br>
Started looking at: https://github.com/gametutorials/tutorials/tree/master/OpenGL/Height%20Map <br>
Started looking at Examples\Terrain+Water_tutorial\Height Map + Started creating my own

[26-04-2020] <br>
Continued creating my own 3D terrain (Loading in RAW file)

[29-04-2020] <br>
The example file is not easy to read, so I tried finding other tutorials. <br>
https://www2.unil.ch/biomapper/opengl/Landscapes.html <br>
Started WaterScape2 following: https://www.swiftless.com/terraintuts.html

[01-05-2020] <br>
Installed freeglut, glew and glfw.
freeglut is the newer version of GLUT (1998), but isn't standard installed in VS19. <br>
documentation for the installation was mostly deprecated. <br>
Drew multiple 3D forms, in different color patterns, finished part 6 of https://www.swiftless.com/opengltuts.html openGL tutorial

[10-05-2020] <br>
Continued with the swiftless tutorial, finished part 7 (Rotation)<br>
Tried to convert the project to C because a lot of the OpenGL functions can't be implemented within a class.<br>
However, once the entire project was in C, it gave over 100 linking errors which I didn't understand, so I reverted the changes.

[11-05-2020] <br>
Did part 8, learned about single / double / triple and quadro buffering, and applied double buffering to the project. <br>
Completed part 9, learned about blending. <br>
Completed part 10 (Scaling) <br>
Finished part 11 (lightning) <br>
Finished part 12 (Light on material (colors)) <br>

[15-05-2020] <br>

<img src="/Images/BueShadyCube.png" width="200"> <br>

Finished part 13 - 15
Part 16 started but not finished, the texture won't load for some reason.

[20-05-2020] <br>
Note to future self, don't update the IDE you're using in the middle of project development! <br>
The VS project broke today, even though the paths and libraries were still there. <br>
StackOverflow, came up with the following solution: <br>

`Tools > NuGet Package Manager > Package Manager Console` <br>
`Install-Package nupengl.core` <br>

Started wondering if this would have been the easiest way to install OpenGL on VS in the first place. <br>

[29-05-2020] <br>
<img src="/Images/GrassSquare.png" width="200"> <br>

Fixed the fact that the texture won't appear on the square, the reason for it not showing up was a corrupt texture file. <br>
Finished part 16 <br>
Started part 17, GPU usage goes to 100% in taskmanager, but the screen stays blank. <br>
I do not yet know, how to solve this problem.

[30-05-2020] <br>
<img src="/Images/RotatingGrassCube.png" width="200">
<img src="/Images/GrassTeaPot.png" width="290"> 
<img src="/Images/TTGC.png" width="200">
<br>

Solved yesterdays problem, turned out the old texture buffer needed to be deleted in order for the cube to render. <br>
Finished part 17 <br>
Implemented an FPS counter after noticing that the cube would sometimes seem to suddenly move faster or slower. <br>
The FPS counter confirmed this, I will do some research on FPS capping later on in development, since it isn't a priority right now. <br>
Completed part 18, resulting in two turning grass textured cubes. <br>

[02-06-2020] <br>
<img src="/Images/cubeLandScape.png" width="700"> <br>
Part 19 completed, fullscreen mode added. <br>
Part 20 (MipMap generation) was already implemented, but they explained it better in this part, so it was an interesting short read. <br>
Part 21 completed, used display lists to contain multiple cubes withing one object. <br>
Part 22 completed, first part of the tutorial about cameras, end result moving through a small cube filled landscape  <br> 
(shown in the screenshot above) <br>

[06-06-2020] <br>
Part 23 completed, resulting in an acceptable mouse movement in de cube environment. <br>
Used: <br>
`extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
    }` <br>
To make the application runs on Nvidea graphics instead of the intergrated graphics card. <br>

[07-06-2020] <br>
<img src="/Images/RawRender.png" width="500"> <br>
Completed part 1 - 3 of the terrain tutorial resulting in the above image. <br>

[12-06-2020] <br>
<img src="/Images/WhiteScape.png" width="500"> <br>

Finished part 4, resulting in all dots being connected, this resulted in the above image. <br>
Started part 5, resulting in a "Cannot open LIBC.lib file" problem in the jpg library. <br>

[13-06-2020] <br>
Tried resolving the "Cannot open LIBC.lib file" problem, without succes.  <br> It would probably be a good idea to look into other libraries, 
even though this one is widely recommended. <br>

[15-06-2020] <br>
Resumed the search for a solution to the LIBC.lib problem, howevever I didn't find a solution to it just yet. <br>
The only widely used solution seems to be, making VS ignore the LIBC.lib dependency. <br>
However this causes multiple functions (fprints, sprits etc) to be unknown to the linker. <br>
So it only seems to move the problem, instead of removing it. <br>
