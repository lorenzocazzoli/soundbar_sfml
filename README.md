# soundbar_sfml
Simple sfml soundbar

## Theory
Like sprites with textures the sounds load soundBuffer objects.
The program uses standard implementation of windows, sounds, text and sprites from SFML.

## Working
The program opens a window using SFML/Window.hpp standard methods, loads sounds from the source directory into sound buffers, loads the buffers into sounds

In the main game loop (found in soundbar.hpp) a switch controls mouse click position and plays the correspondant sound effect.
There are also the standard controls to close the window.

## Future Objectives
- Set the grid precisely
- Optimize mouse position control (avoiding unnecessary loops)
- Allow or block sound effect overlapping as decided by the user
- Cmake implementation
- Add links to tutorials and instructions in this README
- Add index and internal links in the README
- Add images in the README

### Impossible tasks we may try
- Desktop icon and link setup
- Installer to simply use the program in other linux machines
- Add possibility to choose and modify the audio files played
