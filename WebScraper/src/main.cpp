#include <cpr/cpr.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <Document.h>
#include <Node.h>
#include <vector>
#include <fstream>


struct SiteData {
    std::string content_type;
    std::string html;
    SiteData(std::string content, std::string html):content_type(content),html(html) {

    }
};

SiteData getHtmlData(std::string link) {
    cpr::Response data = cpr::Get(cpr::Url{ link });
    if (data.status_code == 200) {
        return {data.header["content-type"],data.text};
    }
    
}

void downloadData(std::string link) {
    std::ofstream file("01.webm", std::ios::binary);
    cpr::Response r = cpr::Download(file, cpr::Url(link));
    fmt::print(fmt::fg(fmt::color::blue), "Status Code {}\n", r.status_code);
}


int main() {

    SiteData data = getHtmlData("https://en.wikipedia.org/wiki/Baka");
    downloadData("https://i.4cdn.org/gif/1654157956526.webm");
    CDocument page;
    page.parse(data.html.c_str());
    //fmt::print("{} \n", r.text);
    CSelection selector = page.find("a");
    size_t z = selector.nodeNum();
    for (int i = 0; i < z; i++) {
        fmt::print(fmt::fg(fmt::color::red), "New Loop Chunk\n");
        fmt::print("{}\n", selector.nodeAt(i).attribute("href"));
    }

	return EXIT_SUCCESS;
}