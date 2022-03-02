#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(int ac, char *av[])
{
	Display *dpy;
	int screen;
	Window win;
	XEvent event;

	dpy = XOpenDisplay(NULL);

	if(dpy == NULL)
	{
		fprintf(stderr, "Cannot open display\n");
		exit (1);
	}

	screen = DefaultScreen(dpy);

	win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen), 100, 100, 500, 300, 1,
		       	BlackPixel(dpy, screen), BlackPixel(dpy, screen));

	XSelectInput(dpy, win, ExposureMask | KeyPressMask);
      	XMapWindow(dpy, win);

	while(1)
	{
		XNextEvent(dpy, &event);
	}

	return 0;
}
//gcc -o foo main.c -lX11 && ./foo