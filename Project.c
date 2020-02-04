//#include "App.h"
//#include "Os.h"
int main(void)
{
	/* Initialize and start the Os Scheduler*/
	//Os_init();
	/* Initialize Application */
	Init_Task();

	while(1)
    {
		/* Run the Scheduler engine to start switching between different tasks */
		Os_engine();
	}
}
