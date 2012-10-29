Description
-----------

Simple demo application for the optimizer. Takes an image as first parameter, then displays a HSV-variation in Firefox, asks for a score, and tries to optimize. Repeat.

Requirements, Building, Usage
-----------------------------

The optimizer has to live parellel to this directory. Needs a UNIXoid OS with ImageMagick and Firefox right now.

To build, issue `make`.

Sample invocation: `./bin/optimize-hsv path/to/lena.png` 

Firefox will open with a sample image. Rate it (on any scale you like) and press F5. If you don't want to press F5 all the time, install a plugin like *Auto Reload*.
