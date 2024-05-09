#include <iostream>
#include <string>
using namespace std;

enum ImageVideoType
{
	JPEG,
	PNG,
	GIF,
	MP4,
	MP3,
	AVI,
	INVALID
};

class IMedia
{
public:
	virtual void createItem(ImageVideoType typeArg, string dateArg, string sizeArg) = 0;
};

class Image :public IMedia
{
private:
	ImageVideoType type;
	string date, size;
public:
	void createItem(ImageVideoType typeArg, string dateArg, string sizeArg)
	{
		this->type = typeArg;
		this->date = dateArg;
		this->size = sizeArg;

	}
};

class Video: public IMedia
{
private:
	ImageVideoType type;
	string date, size;
public:
	void createItem(ImageVideoType typeArg, string dateArg, string sizeArg)
	{
		this->type = typeArg;
		this->date = dateArg;
		this->size = sizeArg;
	}
};

class IShareableApplication
{
public:
	virtual void sendMediaItem(IMedia* media) = 0;
};

class Bluetooth: public IShareableApplication
{
public:
	void sendMediaItem(IMedia* media) {}
};

class Whatsapp : public IShareableApplication
{
public:
	void sendMediaItem(IMedia* media) {}
};

class MailBox : public IShareableApplication
{
public:
	void sendMediaItem(IMedia* media) {}
};

class Gallery
{
public:
	void addMediaItem(IMedia* media) {}
	void shareMediaItem(IShareableApplication* application) {}
};

int main()
{
	Gallery gallery;
	Image image;
	Video video;
	Bluetooth bluetooth;
	image.createItem(JPEG, "08/05/2024", "8MB");
	video.createItem(AVI, "08/05/2024", "100MB");
	gallery.addMediaItem(&image);
	gallery.addMediaItem(&video);
	gallery.shareMediaItem(&bluetooth);
}

