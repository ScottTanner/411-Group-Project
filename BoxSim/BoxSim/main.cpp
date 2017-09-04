#include<allegro5\allegro.h>
#include<allegro5\allegro_native_dialog.h>

int main()
{

	ALLEGRO_DISPLAY *display;

	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
	}

	display = al_create_display(800, 600);

	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not create Allegro 5 Window", NULL, NULL);
	}

	al_destroy_display(display);

	return 0;


}