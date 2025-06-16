#include "RandomEvent.hpp"

#include <random>

void add_random_event(MetricsCollector& metrics)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist_metric(1, 3);
    static std::uniform_real_distribution<> dist_CPU_usage(0, CORES);
    static std::uniform_int_distribution<> dist_HTTP_reguest(20, 150);
    static std::uniform_int_distribution<> dist_RAM_usage(500, 8000);

    int random_int = dist_metric(gen);

    double random_CPU_usage = dist_CPU_usage(gen);
    metrics.add_metric(make_shared<Metric<double>>("CPU", random_CPU_usage));

    int random_HTTP_request = dist_HTTP_reguest(gen);
    metrics.add_metric(make_shared<Metric<int>>("HTTP request", random_HTTP_request));

    int random_RAM_usage = dist_RAM_usage(gen);
    metrics.add_metric(make_shared<Metric<int>>("RAM", random_RAM_usage));
}
