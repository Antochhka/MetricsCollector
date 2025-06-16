#include <iostream>

#include "RandomEvent.hpp"

int main()
{
    MetricsCollector mc;

    for (int i = 0; i < 5; i++)
    {
        cout << "service operation | " << "tread id " << this_thread::get_id() << endl;
        add_random_event(mc);
        this_thread::sleep_for(1s);
    }

    return 0;
}