#include "Scrapper.h"

Scrapper::Scrapper()
{
    this->urlStatus = false;
    this->responseStatus = 0;
}

Scrapper::Scrapper(std::string url) : urlStatus(true),url(url)
{
    data = cpr::Get(cpr::Url{ url });
    if (data.status_code == 200) {
        this->responseStatus = 200;
    }
    else {
        fmt::print(fmt::fg(fmt::color::red), "Error Has Occured Response From The Given Url {}", data.status_code);
    }
    PageParsedData.parse(data.text.c_str());
    CSelection Selector = PageParsedData.find("a");
    ancorTags = Selector.nodeNum();
    for (size_t i = 0; i < ancorTags; i++) {
        embededUrl.push_back(Selector.nodeAt(i).attribute("href"));
    }
}

Scrapper::~Scrapper()
{
}

std::vector<std::string> Scrapper::getAncorTags()
{
    
    return embededUrl;
}

void Scrapper::insertTypeToLookFor(std::string type)
{
}

void Scrapper::initiateDownload()
{
}

void Scrapper::initiateDownload(std::string path)
{
}

int Scrapper::getNumberOfAncorTags()
{
    return 0;
}

int Scrapper::getNumberOfRequiredTags()
{
    return 0;
}
