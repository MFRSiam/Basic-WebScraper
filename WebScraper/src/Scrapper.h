#pragma once

#include <cpr/cpr.h>
#include <Document.h>
#include <Node.h>
#include <vector>
#include <fmt/core.h>
#include <fmt/color.h>


class Scrapper
{
private:
    // Private Variables
    std::string url;
    std::vector<std::string> embededUrl;
    bool urlStatus;
    int responseStatus;
    std::vector<std::string> downloadTypes;
    cpr::Response data;
    // Private Functions

public:
    Scrapper();
    Scrapper(std::string url);
    ~Scrapper();


    std::vector<std::string> getAncorTags();
    void insertTypeToLookFor(std::string type);


    void initiateDownload();
    void initiateDownload(std::string path);
    

    int getNumberOfAncorTags();
    int getNumberOfRequiredTags();


};

