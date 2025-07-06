# SDL3 Template

<p>This template is what I use for my SDL3 projects. The template comes with the entire SDL3 library including SDL3_ttf (text rendering) and SDL3_image (texture rendering). The template is the entire repository.</p><br><br>

<h2>What to do first</h2>

<ul>
  <li>SDL3 library included, no need to download library</li><br>
  <li>Windows: Use a terminal that allows you to use Makefiles. Then, edit the Makefile by changing the output executable's extension to ".exe".</li>
  <li>Linux: Optional: delete DLL's inside build folder.</li>
  <li>Mac: Not tested; change output executable's extension to the Mac equivalent of an ".exe"?</li>
</ul>

<h2>What comes with the template</h2>

<p>As said, text and texture rendering capabilities come with the template. The C files are inside the src folder and their respective header files are inside the include folder. The config files contain constant color values so that instead of hard-coding RGB values, you can just use the COLORS struct to reference a color. Add/remove colors to your liking. Config.h contains variables such as the window name and desired FPS which you will definitely need to change. The template comes with an assets folder in which a free font has been given. The Makefile places the resulting executable inside the build folder. If you are on Windows, do not move any of the DLL's or the executable. If you are on LInux or Mac, you can not only delete the DLL's but also place the executable anywhere. To create a new function, you will need to declare it inside the header file and then define it inside the C file (this is demonstrated with game_functions.c and its header file).</p>
