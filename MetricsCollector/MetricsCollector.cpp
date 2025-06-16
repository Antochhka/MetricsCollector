#include "MetricsCollector.hpp"

#include <chrono>
#include <fstream>
#include <sstream>
#include <thread>

using namespace std;
using namespace chrono;

MetricsCollector::MetricsCollector()
{
    work_thread = thread([this]() { this->work_process(); });
}

MetricsCollector::~MetricsCollector()
{
    this->flag = true;
    if (work_thread.joinable()) work_thread.join();
}

void MetricsCollector::add_metric(shared_ptr<IMetric> metric)
{
    lock_guard<mutex> guard(mtx);
    metrics.push_back(metric);
}

void MetricsCollector::write_to_file(const string& filename,
                                     const vector<shared_ptr<IMetric>>& metrics_copy)
{
    ofstream file(filename, ios::app);
    if (file.is_open())
    {
        file << create_log(metrics_copy);
    }
    file.close();
}

string MetricsCollector::create_log(const vector<shared_ptr<IMetric>>& metrics_copy)
{
    if (metrics_copy.empty()) return "";

    string res = metrics_copy[0]->get_time() + " ";
    for (const auto& metric : metrics_copy)
    {
        res += "\"" + metric->get_name() + "\" " + metric->get_value() + " ";
    }
    res += "\n";

    return res;
}

void MetricsCollector::work_process()
{
    while (!flag)
    {
        this_thread::sleep_for(2ms);
        vector<shared_ptr<IMetric>> metrics_copy;
        {
            lock_guard<mutex> lock(mtx);
            metrics_copy = metrics;
            metrics.clear();
        }

        if (!metrics_copy.empty())
        {
            this->process_message();
            this->write_to_file("log.txt", metrics_copy);
        }
    }
}

 void MetricsCollector::process_message() {
        cout << "saving logs in log.txt | " << "thread id " <<  this_thread::get_id() << endl;
    }
