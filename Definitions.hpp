/**
 * Definitions header
 * File for extra functions, structs and macros that do not require a class
*/
//definitions fpr math functions and any ancilliary structures or program wide functions.
#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

/**
 * hitbox position centering macro
 * @param x x or y position of hitbox
 * @param length how long that side x (width) or y (height) is 
 */
#ifndef HitBoxPos
//corrected hitbox
//centers on x or y of point inputted
//Note: in SDL - is left + is right
#define HitBoxPos(x,length) (x-(length/2))
//uncorrected
//#define HitBoxPos(x,length) (x)
#endif

//walls will be left justified for ease of use




#endif