#ifndef H_BITMAP_IMAGE_HEADER
#define H_BITMAP_IMAGE_HEADER

class bitmapImage;

/*
	Name: 
	    Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 6

	Description: 
	A class for working with the Windows Bitmap File Format.
	Supports bit depths of 16, 24, and 32 with uncompressed pixel data.

	This does not support compressed bitmaps or bit depths of 1,4, or 8.  
	Compression is rarely used with this file format, though.

	Colors can be specified in RGB format (red, green, and blue
	intensity values)
		Red, Green, Blue colors range from 0-255
			(0 -> off to 255 -> full intensity)
		For red, it would be (255, 0, 0) and in hex, (0xff0000).
			As a single value, 0xff0000 is 16,711,680
		For green, it would be (0, 255, 0) and in hex, (0x00ff00).
			As a single value, 0x00ff00 is 65,280
 */

class bitmapImage
{
private:
	int	width, height;
	int	**pixelData;
	void	freePixelData();

public:
	// create empty bitmap object
	bitmapImage();

	// create bitmap object from file 'filename'.
	bitmapImage(const char* filename);

	// create empty bitmap object of size width by height
	bitmapImage(int w, int h);

	// destructor
	virtual ~bitmapImage();

	// set (for empty object) bitmap size
	void setSize(int width, int height);

	// loads uncompressed bitmaps with color depths of
	// 16,24, and 32 returns 0, if successfully loaded.
	int loadFromBitmapFile(const char*filename);

	// saves bitmaps using 24 bit color depth (typical default)
	void saveToBitmapFile(const char* filename) const;

	// saves using the specified depth of 16, 24, or 32
	void saveToBitmapFile(const char* filename, int bitDepth) const;

	// get bitmap object height
	int getHeight() const;

	// get bitmap object width
	int getWidth() const;

	// get 'red' part of color value
	int getRed(int color) const;

	// get 'green' part of color value
	int getGreen(int color) const;

	// get 'blue' part of color value
	int getBlue(int color) const;

	// convert red, green, and blue values to single color value
	int getColorForRGB(int red, int green, int blue) const;

	// get contents of (x,y) in image map
	int getPixel(int x, int y) const;

	// set contents of (x,y) in image map with specified color
	void setPixel(int x, int y, int color);

	// set contents of entire image map with specified color
	void fillWith(int color);

	// set contents of rectangle within image map with specified color
	void fillRect(int left, int top, int width, int height, int color);

	// set contents of (x,y) in image map with specified color in RGB format
	void setPixelRGB(int x, int y, int red, int green, int blue);

};

#endif

