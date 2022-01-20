
#include "contiki.h"
#include <stdio.h>
#include "dev/leds.h"
#include "sys/etimer.h"
#include "counter.h"
#include "dev/gpio-hal.h"

PROCESS(led_process, "LED Process");
AUTOSTART_PROCESSES(&led_process);

static struct etimer timer;
static int count = 0;

PROCESS_THREAD(led_process, ev, data) {

    PROCESS_BEGIN();
   
    while(1) {
      
     	etimer_set(&timer, CLOCK_SECOND);
     	PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
     	count = next_round(count);
     	if (count < 6) 
     	{
     	printf("Remaining time : %d\n", 6-count);
     	leds_on(LEDS_RED);
	leds_off(LEDS_GREEN);

     	}
     	else 
     	{
     	printf("Remaining time : %d\n", 11-count);
     	leds_off(LEDS_RED);
     	leds_on(LEDS_GREEN);
        }
   }
   
   
    PROCESS_END();
}


