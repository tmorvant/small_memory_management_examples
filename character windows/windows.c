/**
 * @class windows
 * @author tmorvant
 * @date 02/02/2020
 * @file windows.c
 * @brief Struct containg parameters detailing the corners of the output and the character to represent
 */

#include <stdio.h>


struct window {
	unsigned xlow, ylow, xhigh, yhigh;
	char wch;
};

unsigned wxhigh, wxlow, wyhigh, wylow; //Four global variables used to keep track of the corners of the window to output.  Probably not needed but helpful

/**
 * @brief Iterates through a line and fills it with spaces, then reiterates through to fill wih the characters in the array of window structs
 * @param W
 * @param Wsize
 * @param x1
 * @param x2
 * @param y
 * @param line
 */
void fill_line(struct window W[], unsigned Wsize, unsigned x1, unsigned x2, unsigned y, char line[]) {
	
	int i = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = 0; j < Wsize; j++) {
			line[i] = ' ';
		} 
	}
	for (int i = x1; i <= x2; i++) {
		for (int j = 0; j < Wsize; j++) {
			if (i >= W[j].xlow && W[j].xhigh >= i && W[j].ylow <= y && W[j].yhigh>= y) {
				line[i] = W[j].wch;
			}
		}
	}
	
	return;
}


/**
 * @brief Reads console input in a specific format to read the corners of the output and the number of windows and characters to output
 * @param W
 * @param wmax
 * @return Returns the length of the window array
 */
unsigned fill_windows(struct window W[], unsigned wmax) {
	unsigned length;
	scanf("%d,%d %d,%d", &wxlow, &wylow, &wxhigh, &wyhigh);
	scanf("%d", &length);
	for (int i = 0; i < length; i++) {
		scanf("%d,%d %d,%d %c", &W[i].xlow, &W[i].ylow, &W[i].xhigh, &W[i].yhigh, &W[i].wch);
		//printf("%d, %d, %d, %d, %c", W[i].xlow
	}
	return length;
}


/**
 * @brief Creates an array of windows, and fills the array with the arrays created in fill_windows().  Then iterates through the lines of future output to fill each line with fill_line() and print the result.
 * @return 0 
 */
int main() {
	
	struct window windows[100];
	unsigned windowssize = fill_windows(windows, 100);
	
	char line[wxhigh - wxlow + 1];
	
	for(int i = wylow; i <= wyhigh; i++) {
		
		fill_line(windows, windowssize, wxlow, wxhigh, i, line);
		//printf("%c", line[0]);
		for(int j = 0; j < wxhigh - wxlow + 1; j++) {
			printf("%c", line[j]);
		}
		printf("\n");
	}
	return 0;
}