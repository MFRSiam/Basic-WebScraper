#pragma once

#include <cpr/cpr.h>
#include <Document.h>
#include <Node.h>
#include <vector>


class Scrapper
{
private:
    std::string url;
    std::vector<std::string> embededUrl;
    bool urlStatus;
    int responseStatus;
    std::vector<std::string> downloadTypes;
public:
    Scrapper();
    Scrapper(std::string url);

    std::vector<std::string> getAncorTags();
    
};

